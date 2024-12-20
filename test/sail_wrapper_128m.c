/*-
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (c) 2020 Alex Richardson
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

#include "contrib/sail.h"

/* Provide the Morello-specific APIs for sail_wrapper_common.c */

#define SAIL_COMPRESSION_GENERATED_C_FILE "contrib/sail_compression_128m.c"
// Two 65-bit bounds and a bool (for exactness)
#define sail_bounds_tuple ztuple_z8z5bvzCz0z5bvzCz0z5boolz9

#define SAIL_WRAPPER_CC_IS_MORELLO
#define SAIL_WRAPPER_CC_FORMAT_LOWER 128m
#define SAIL_WRAPPER_CC_FORMAT_UPPER 128M

/* CHERI-64 uses uint64_t, CHERI-128 uses lbits */
typedef lbits sail_cap_bits;
#define SAIL_COMPRESSION_INDIRECT_BITS
static void create_sail_cap_bits(sail_cap_bits* bits) { create_lbits(bits); }
static void kill_sail_cap_bits(sail_cap_bits* bits) { kill_lbits(bits); }
static void pesbt_and_addr_to_sail_cap_bits(sail_cap_bits* out, uint64_t pesbt, uint64_t cursor) {
    lbits sail_pesbt;
    lbits sail_cursor;
    CREATE_OF(lbits, fbits)(&sail_pesbt, pesbt, 64, true);
    CREATE_OF(lbits, fbits)(&sail_cursor, cursor, 64, true);
    CREATE(lbits)(out);
    append(out, sail_pesbt, sail_cursor);
    KILL(lbits)(&sail_pesbt);
    KILL(lbits)(&sail_cursor);
}
static void cc_length_t_to_sail_cap_bits(sail_cap_bits* out, unsigned __int128 len) {
    lbits len_high;
    lbits len_low;
    CREATE_OF(lbits, fbits)(&len_high, len >> 64, 1, true);
    CREATE_OF(lbits, fbits)(&len_low, (uint64_t)len, 64, true);
    append(out, len_high, len_low);
    KILL(lbits)(&len_high);
    KILL(lbits)(&len_low);
}

static inline uint64_t extract_bits(lbits op, uint64_t start, uint64_t len);
static inline uint64_t extract_sail_cap_bits(sail_cap_bits* bits, uint64_t start, uint64_t len) {
    return extract_bits(*bits, start, len);
}

#include "sail_wrapper_common.c"

/* Exported API */
struct cc128m_bounds_bits sail_extract_bounds_bits_128m(uint64_t pesbt) {
    lbits sailcap = to_sail_cap(pesbt, 0, false);
    struct cc128m_bounds_bits result = {.E = sailgen_CapGetExponent(sailcap),
                                        .B = sailgen_CapGetBottom(sailcap),
                                        .T = sailgen_CapGetTop(sailcap),
                                        .IE = sailgen_CapIsInternalExponent(sailcap)};
    KILL(lbits)(&sailcap);
    return result;
}

uint64_t sail_compress_128m_raw(const cc128m_cap_t* csp) { return sail_compress_common_raw(csp); }
uint64_t sail_compress_128m_mem(const cc128m_cap_t* csp) { return sail_compress_common_mem(csp); }

bool sail_setbounds_128m(cc128m_cap_t* cap, cc128m_length_t req_len) {
    lbits sail_len;
    CREATE(sail_cap_bits)(&sail_len);
    cc_length_t_to_sail_cap_bits(&sail_len, req_len);
    lbits sail_result;
    CREATE(lbits)(&sail_result);
    lbits capbits = cap_t_to_sail_cap(cap);
    sailgen_doCSetBounds(&sail_result, capbits, sail_len);
    KILL(lbits)(&sail_len);
    KILL(lbits)(&capbits);
    _cc_cap_t tmp = from_sail_cap(&sail_result);
    // Check if the resulting bounds were exact. The sail code does not return the value of lostBot/Top, so we check the
    // resulting bounds against the expected values. NB: We have to compare the low 56 bits of base and top since the
    // high bits and change of sign are not included in the exactness check.
    cc128_length_t req_base = sailgen_CapBoundsAddress(cap->_cr_cursor);
    cc128_length_t req_top = sailgen_CapBoundsAddress((cc128_length_t)cap->_cr_cursor + req_len);
    bool exact = sailgen_CapBoundsAddress(tmp._cr_top) == req_top && sailgen_CapBoundsAddress(tmp.cr_base) == req_base;
    *cap = tmp;
    KILL(lbits)(&sail_result);
    return exact;
}

bool sail_fast_is_representable_128m(const cc128m_cap_t* cap, cc128m_addr_t new_addr) {
    lbits sailcap = cap_t_to_sail_cap(cap);
    uint64_t increment = new_addr - cap->_cr_cursor;
    bool result = sailgen_CapIsRepresentableFast(sailcap, increment);
    KILL(lbits)(&sailcap);
    return result;
}

bool sail_precise_is_representable_128m(const cc128m_cap_t* cap, cc128m_addr_t new_addr) {
    lbits sailcap = cap_t_to_sail_cap(cap);
    bool result = sailgen_CapIsRepresentable(sailcap, new_addr);
    KILL(lbits)(&sailcap);
    return result;
}

_cc_cap_t sail_reset_capability_128m(void) {
    _cc_cap_t result;
    return from_sail_cap(&zCMAX);
    return result;
}

_cc_addr_t sail_null_pesbt_128m(void) {
    return 0; // Morello does not invert capabilities when loading/storing to/from memory
}

_cc_addr_t sail_reset_pesbt_128m(void) { return extract_bits(zCMAX, 64, 64); }
