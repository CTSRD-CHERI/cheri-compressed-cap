/*-
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (c) 2018-2025 Alex Richardson
 * Copyright (c) 2024 Codasip
 *
 * This software was developed by SRI International and the University of
 * Cambridge Computer Laboratory under DARPA/AFRL contract FA8750-10-C-0237
 * ("CTSRD"), as part of the DARPA CRASH research programme.
 *
 * This software was developed by SRI International and the University of
 * Cambridge Computer Laboratory (Department of Computer Science and
 * Technology) under DARPA contract HR0011-18-C-0016 ("ECATS"), as part of the
 * DARPA SSITH research programme.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

// CHERI compressed capability format for the RISC-V standard

// The following macros are expected to be defined
#define CC_FORMAT_LOWER 64r
#define CC_FORMAT_UPPER 64R
#define CC64R_CAP_SIZE 8
#define CC64R_CAP_BITS 64
#define CC64R_ADDR_WIDTH 32
#define CC64R_LEN_WIDTH 33

#define CC64R_MANTISSA_WIDTH 10
// Max exponent is the largest exponent _required_, not that can be encoded.
#define CC64R_MAX_EXPONENT 24
#define CC64R_CURSOR_MASK 0xFFFFFFFF
#define CC64R_MAX_ADDRESS_PLUS_ONE ((cc64r_length_t)1u << CC64R_ADDR_WIDTH)
#define CC64R_NULL_TOP CC64R_MAX_ADDRESS_PLUS_ONE
#define CC64R_NULL_LENGTH CC64R_MAX_ADDRESS_PLUS_ONE
#define CC64R_MAX_LENGTH CC64R_MAX_ADDRESS_PLUS_ONE
#define CC64R_MAX_TOP CC64R_MAX_ADDRESS_PLUS_ONE
#define CC64R_MAX_ADDR UINT32_MAX

/* Special otypes are allocated upwards from 0 */
#define CC64R_SPECIAL_OTYPE_VAL(val) (val##u)
#define CC64R_SPECIAL_OTYPE_VAL_SIGNED(val) (val##u)

/* Use uint64_t to represent 33 bit length */
typedef uint64_t cc64r_length_t;
typedef int64_t cc64r_offset_t;
typedef uint32_t cc64r_addr_t;
typedef int32_t cc64r_saddr_t;
#include "cheri_compressed_cap_macros.h"

/* ignore ISO C restricts enumerator values to range of 'int' */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
enum {
    _CC_FIELD(UPERMS, 63, 62),
    _CC_FIELD(HWPERMS, 61, 57),
    _CC_FIELD(FLAGS, 57, 57),     // For now pretend that the M bit is always present, not just for X caps
    _CC_FIELD(RESERVED1, 56, 56), // Actually the CL field, but reserverd to match sail
    // TODO: Level should be separate: _CC_FIELD(LEVEL, 56, 56)
    _CC_FIELD(RESERVED0, 55, 53),
    _CC_FIELD(OTYPE, 52, 52),
    _CC_FIELD(EBT, 51, 32),

    _CC_FIELD(EXPONENT_FORMAT, 51, 51),
    _CC_FIELD(LEN_MSB, 50, 50), // Either MSB of exponent or MSB of length depending on EXPONENT_FORMAT.
    // The FIELD_INTERNAL_EXPONENT_SIZE name is currently required by various static assertions.
    _CC_N(FIELD_INTERNAL_EXPONENT_SIZE) = _CC_N(FIELD_EXPONENT_FORMAT_SIZE),
    _CC_FIELD(TOP_ENCODED, 49, 42),
    _CC_FIELD(BOTTOM_ENCODED, 41, 32),

    // Top/bottom offsets depending on INTERNAL_EXPONENT flag:
    // Without internal exponent:
    _CC_FIELD(EXP_ZERO_TOP, 49, 42),
    _CC_FIELD(EXP_ZERO_BOTTOM, 41, 32),
    // With internal exponent:
    _CC_FIELD(EXP_NONZERO_TOP, 49, 44),
    _CC_FIELD(EXPONENT_HIGH_PART, 43, 42),
    _CC_FIELD(EXP_NONZERO_BOTTOM, 41, 34),
    _CC_FIELD(EXPONENT_LOW_PART, 33, 32),
};
#pragma GCC diagnostic pop

#define CC64R_OTYPE_BITS CC64R_FIELD_OTYPE_SIZE
#define CC64R_BOT_WIDTH CC64R_FIELD_EXP_ZERO_BOTTOM_SIZE
#define CC64R_BOT_INTERNAL_EXP_WIDTH CC64R_FIELD_EXP_NONZERO_BOTTOM_SIZE
#define CC64R_EXP_LOW_WIDTH CC64R_FIELD_EXPONENT_LOW_PART_SIZE

#define CC64R_PERM_CAPABILITY (1 << 0)
#define CC64R_PERM_WRITE (1 << 1)
#define CC64R_PERM_READ (1 << 2)
#define CC64R_PERM_EXECUTE (1 << 3)
#define CC64R_PERM_ACCESS_SYS_REGS (1 << 4)
#define CC64R_PERM_LOAD_MUTABLE (1 << 5)
#define CC64R_PERM_ELEVATE_LEVEL (1 << 6)
#define CC64R_PERM_STORE_LEVEL (1 << 7)

// Note: shift by one 1 due to level currently being part of perms
#define CC64R_HIGHEST_PERM (CC64R_PERM_STORE_LEVEL << 1)

#define CC64R_PERMS_ALL (0x9)  // See Infinite Capability in the spec: 0x8 or 0x9 depending on mode.
#define CC64R_UPERMS_ALL (0x3) // 2 bits
_CC_STATIC_ASSERT_SAME(CC64R_UPERMS_ALL, CC64R_FIELD_UPERMS_MAX_VALUE);
#define CC64R_UPERMS_SHFT (6)
#define CC64R_UPERMS_MEM_SHFT (0)
#define CC64R_MAX_UPERM (1)

// Currently, only one type (sentry) is defined.
// However, other extensions (e.g. CHERIoT) define additional otypes beyond this.
enum _CC_N(OTypes) {
    CC64R_MAX_REPRESENTABLE_OTYPE = ((1u << CC64R_OTYPE_BITS) - 1u),
    _CC_SPECIAL_OTYPE(OTYPE_UNSEALED, 0),
    _CC_SPECIAL_OTYPE(OTYPE_SENTRY, 1),
    _CC_N(MIN_RESERVED_OTYPE) = _CC_N(OTYPE_UNSEALED),
    _CC_N(MAX_RESERVED_OTYPE) = _CC_N(OTYPE_SENTRY),
};

#define CC64R_LS_SPECIAL_OTYPES(ITEM, ...)                                                                             \
    ITEM(OTYPE_UNSEALED, __VA_ARGS__)                                                                                  \
    ITEM(OTYPE_SENTRY, __VA_ARGS__)

_CC_STATIC_ASSERT_SAME(CC64R_MANTISSA_WIDTH, CC64R_FIELD_EXP_ZERO_BOTTOM_SIZE);

// The RISC-V extension uses an "exponent zero" flag.
#define CC64R_ENCODE_IE(IE) _CC_ENCODE_FIELD(!(IE), EXPONENT_FORMAT)
#define CC64R_EXTRACT_IE(value) (!_CC_EXTRACT_FIELD(value, EXPONENT_FORMAT))
// The exponent bits in memory are subtracted from the max exponent when decoding in the IE case.
#define _CC64R_ENCODE_EXPONENT_RAW(e_enc) _CC_ENCODE_SPLIT_EXPONENT(e_enc) | _CC_ENCODE_FIELD(((e_enc) >> 4), LEN_MSB)
#define _CC64R_EXTRACT_EXPONENT_RAW(pesbt)                                                                             \
    ((_CC_EXTRACT_FIELD(pesbt, LEN_MSB) << 4) | _CC_EXTRACT_SPLIT_EXPONENT(pesbt))
#define CC64R_ENCODE_EXPONENT(E) _CC64R_ENCODE_EXPONENT_RAW(CC64R_MAX_EXPONENT - (E))
#define CC64R_EXTRACT_EXPONENT(pesbt) (CC64R_MAX_EXPONENT - _CC64R_EXTRACT_EXPONENT_RAW(pesbt))
#define CC64R_RESERVED_FIELDS 2
#define CC64R_RESERVED_BITS (CC128R_FIELD_RESERVED0_SIZE + CC128R_FIELD_RESERVED1_SIZE)
#define CC64R_HAS_BASE_TOP_SPECIAL_CASES 1
#define CC64R_USES_V9_PERMISSION_ENCODING 1 // FIXME: this is not actually true
#define CC64R_USES_V9_CORRECTION_FACTORS 0
#define CC64R_USES_LEN_MSB 1

#include "cheri_compressed_cap_common.h"
#include "cheri_compressed_cap_riscv_common.h"

#undef CC_FORMAT_LOWER
#undef CC_FORMAT_UPPER
