/*-
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (c) 2018-2025 Alex Richardson
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
#define CC_FORMAT_LOWER 128r
#define CC_FORMAT_UPPER 128R
#define CC128R_CAP_SIZE 16
#define CC128R_CAP_BITS 128
#define CC128R_ADDR_WIDTH 64
#define CC128R_LEN_WIDTH 65

#define CC128R_MANTISSA_WIDTH 14
// Max exponent is the largest exponent _required_, not that can be encoded.
#define CC128R_MAX_EXPONENT 52
#define CC128R_CURSOR_MASK 0xFFFFFFFFFFFFFFFF
#define CC128R_MAX_ADDRESS_PLUS_ONE ((cc128r_length_t)1u << CC128R_ADDR_WIDTH)
#define CC128R_NULL_TOP CC128R_MAX_ADDRESS_PLUS_ONE
#define CC128R_NULL_LENGTH CC128R_MAX_ADDRESS_PLUS_ONE
#define CC128R_MAX_LENGTH CC128R_MAX_ADDRESS_PLUS_ONE
#define CC128R_MAX_TOP CC128R_MAX_ADDRESS_PLUS_ONE
#define CC128R_MAX_ADDR UINT64_MAX
/* Special otypes are allocated upwards from 0 */
#define CC128R_SPECIAL_OTYPE_VAL(val) (val##u)
#define CC128R_SPECIAL_OTYPE_VAL_SIGNED(val) (val##u)

/* Use __uint128 to represent 65 bit length */
__extension__ typedef unsigned __int128 cc128r_length_t;
__extension__ typedef signed __int128 cc128r_offset_t;
typedef uint64_t cc128r_addr_t;
typedef int64_t cc128r_saddr_t;
#include "cheri_compressed_cap_macros.h"

/* ignore ISO C restricts enumerator values to range of 'int' */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
enum {
    _CC_FIELD(RESERVED1, 127, 121),
    _CC_FIELD(UPERMS, 120, 117),
    _CC_FIELD(FLAGS, 115, 116),
    _CC_FIELD(HWPERMS, 116, 108),
    // TODO: Level should be separate: _CC_FIELD(LEVEL, 107, 107)
    _CC_FIELD(RESERVED0, 107, 92),
    _CC_FIELD(OTYPE, 91, 91),
    _CC_FIELD(EBT, 90, 64),

    _CC_FIELD(EXPONENT_FORMAT, 90, 90),
    // The FIELD_INTERNAL_EXPONENT_SIZE name is currently required by various static assertions.
    _CC_N(FIELD_INTERNAL_EXPONENT_SIZE) = _CC_N(FIELD_EXPONENT_FORMAT_SIZE),
    _CC_FIELD(TOP_ENCODED, 89, 78),
    _CC_FIELD(BOTTOM_ENCODED, 77, 64),

    // Top/bottom offsets depending in INTERNAL_EXPONENT flag:
    // Without internal exponent:
    _CC_FIELD(EXP_ZERO_TOP, 89, 78),
    _CC_FIELD(EXP_ZERO_BOTTOM, 77, 64),
    // With internal exponent:
    _CC_FIELD(EXP_NONZERO_TOP, 89, 81),
    _CC_FIELD(EXPONENT_HIGH_PART, 80, 78),
    _CC_FIELD(EXP_NONZERO_BOTTOM, 77, 67),
    _CC_FIELD(EXPONENT_LOW_PART, 66, 64),
};
#pragma GCC diagnostic pop

#define CC128R_OTYPE_BITS CC128R_FIELD_OTYPE_SIZE
#define CC128R_BOT_WIDTH CC128R_FIELD_EXP_ZERO_BOTTOM_SIZE
#define CC128R_BOT_INTERNAL_EXP_WIDTH CC128R_FIELD_EXP_NONZERO_BOTTOM_SIZE
#define CC128R_EXP_LOW_WIDTH CC128R_FIELD_EXPONENT_LOW_PART_SIZE

#define CC128R_PERM_CAPABILITY (1 << 0)
#define CC128R_PERM_WRITE (1 << 1)
#define CC128R_PERM_READ (1 << 2)
#define CC128R_PERM_EXECUTE (1 << 3)
#define CC128R_PERM_ACCESS_SYS_REGS (1 << 4)
#define CC128R_PERM_LOAD_MUTABLE (1 << 5)
#define CC128R_PERM_ELEVATE_LEVEL (1 << 6)
#define CC128R_PERM_STORE_LEVEL (1 << 7)

// Note: shift by one 1 due to level currently being part of perms
#define CC128R_HIGHEST_PERM (CC128R_PERM_STORE_LEVEL << 1)

_CC_STATIC_ASSERT(CC128R_HIGHEST_PERM < CC128R_FIELD_HWPERMS_MAX_VALUE, "permissions not representable?");
_CC_STATIC_ASSERT((CC128R_HIGHEST_PERM << 1) > CC128R_FIELD_HWPERMS_MAX_VALUE, "all permission bits should be used");

#define CC128R_PERMS_ALL (0x13f) /* 0b100111111 since SL and EL are not supported in sail yet. */
#define CC128R_UPERMS_ALL (0xf)  /* 4 bits */
_CC_STATIC_ASSERT_SAME(CC128R_PERMS_ALL,
                       CC128R_FIELD_HWPERMS_MAX_VALUE & ~(CC128R_PERM_ELEVATE_LEVEL | CC128R_PERM_STORE_LEVEL));
_CC_STATIC_ASSERT_SAME(CC128R_UPERMS_ALL, CC128R_FIELD_UPERMS_MAX_VALUE);
#define CC128R_UPERMS_SHFT (6)
#define CC128R_UPERMS_MEM_SHFT (0)
#define CC128R_MAX_UPERM (3)

// Currently, only one type (sentry) is defined.
// However, other extensions (e.g. CHERIoT) define additional otypes beyond this.
enum _CC_N(OTypes) {
    CC128R_MAX_REPRESENTABLE_OTYPE = ((1u << CC128R_OTYPE_BITS) - 1u),
    _CC_SPECIAL_OTYPE(OTYPE_UNSEALED, 0),
    _CC_SPECIAL_OTYPE(OTYPE_SENTRY, 1),
    _CC_N(MIN_RESERVED_OTYPE) = _CC_N(OTYPE_UNSEALED),
    _CC_N(MAX_RESERVED_OTYPE) = _CC_N(OTYPE_SENTRY),
};

#define CC128R_LS_SPECIAL_OTYPES(ITEM, ...)                                                                            \
    ITEM(OTYPE_UNSEALED, __VA_ARGS__)                                                                                  \
    ITEM(OTYPE_SENTRY, __VA_ARGS__)

_CC_STATIC_ASSERT_SAME(CC128R_MANTISSA_WIDTH, CC128R_FIELD_EXP_ZERO_BOTTOM_SIZE);

// The RISC-V extension uses an "exponent zero" flag.
#define CC128R_ENCODE_IE(IE) _CC_ENCODE_FIELD(!(IE), EXPONENT_FORMAT)
#define CC128R_EXTRACT_IE(value) (!_CC_EXTRACT_FIELD(value, EXPONENT_FORMAT))
// The exponent bits in memory are subtracted from the max exponent when decoding in the IE case.
#define CC128R_ENCODE_EXPONENT(E) _CC_ENCODE_SPLIT_EXPONENT(CC128R_MAX_EXPONENT - (E))
#define CC128R_EXTRACT_EXPONENT(pesbt) (CC128R_MAX_EXPONENT - _CC_EXTRACT_SPLIT_EXPONENT(pesbt))
#define CC128R_RESERVED_FIELDS 2
#define CC128R_RESERVED_BITS (CC128R_FIELD_RESERVED0_SIZE + CC128R_FIELD_RESERVED1_SIZE)
#define CC128R_HAS_BASE_TOP_SPECIAL_CASES 1
#define CC128R_USES_V9_CORRECTION_FACTORS 0
#define CC128R_USES_LEN_MSB 0

#include "cheri_compressed_cap_common.h"
#include "cheri_compressed_cap_riscv_common.h"
