/*-
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (c) 2018 Lawrence Esswood
 * Copyright (c) 2018 Alex Richardson
 * All rights reserved.
 *
 * This software was developed by SRI International and the University of
 * Cambridge Computer Laboratory under DARPA/AFRL contract FA8750-10-C-0237
 * ("CTSRD"), as part of the DARPA CRASH research programme.
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
#ifndef CHERI_COMPRESSED_CAP_H
#define CHERI_COMPRESSED_CAP_H

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <sys/param.h> /* for MIN() */

// QEMU already provides cap_register_t but if used in other programs
// we want to define it here:
#ifndef HAVE_CAP_REGISTER_T
struct cap_register {
    /* offset = cursor - base */
    uint64_t cr_offset; /* Capability offset */
    uint64_t cr_base;   /* Capability base addr */
    unsigned __int128 _cr_length; /* Capability length */
    uint32_t cr_perms;  /* Permissions */
    uint32_t cr_uperms; /* User Permissions */
    uint64_t cr_pesbt;  /* Perms, E, Sealed, Bot, & Top bits (128-bit) */
    uint32_t cr_otype;  /* Object Type, 24 bits */
    uint8_t cr_tag;     /* Tag */
    uint8_t _sbit_for_memory; /* sealed flag */
};
typedef struct cap_register cap_register_t;

#endif


#ifdef CC128_OLD_FORMAT
// These constants are for a cheri concentrate format for 128. They give either
// 22 bits or 20 bits of precision depending on object size They give 20 bits
// for types
#define CC_L_IE_OFF 45
#define CC_L_LH_OFF 44
#define CC_L_B_OFF 0
#define CC_L_T_OFF 23
#define CC_L_S_OFF 46

#define CC_L_OHI_OFF 32
#define CC_L_OLO_OFF 11
#define CC_L_TYPES 24

#define CC_L_BWIDTH 23
#define CC_L_SEALED_BWIDTH (CC_L_BWIDTH - (CC_L_TYPES / 2))
#define CC_L_EWIDTH 7
#define CC_L_LOWWIDTH (CC_L_EWIDTH >> 1)
#define CC_L_LOWMASK ((1 << CC_L_LOWWIDTH) - 1)

#define CC128_OTYPE_BITS CC_L_TYPES

#define CC_SEAL_MODE_UNSEALED 0
#define CC_SEAL_MODE_SEALED 1
#define CC_SEAL_MODE_SENTRY 3

#define CC128_BOT_WIDTH CC_L_BWIDTH
#define CC128_EXP_LOW_WIDTH CC_L_LOWWIDTH
/* Whatever NULL would encode to is this constant. We mask on store/load so this
 * is invisibly keeps null 0 whatever we choose it to be */
#define CC128_NULL_XOR_MASK 0x200001000005
#else

// Offsets based on capBitsToCapability() from cheri_prelude_128.sail
// (Note: we subtract 64 since we only access the high 64 bits when (de)compressing)
#define CC128_FIELD(name, last, start) \
    CC128_FIELD_ ## name ## _START = (start - 64), \
    CC128_FIELD_ ## name ## _LAST = (last - 64), \
    CC128_FIELD_ ## name ## _SIZE = CC128_FIELD_ ## name ## _LAST - CC128_FIELD_ ## name ## _START + 1, \
    CC128_FIELD_ ## name ## _MASK0 = (UINT64_C(1) << CC128_FIELD_ ## name ## _SIZE) - 1, \
    CC128_FIELD_ ## name ## _MASK64 = (uint64_t)CC128_FIELD_ ## name ## _MASK0 << CC128_FIELD_ ## name ## _START, \
    CC128_FIELD_ ## name ## _MAX_VALUE = CC128_FIELD_ ## name ## _MASK0

enum {
    CC128_FIELD(UPERMS, 127, 124),
    CC128_FIELD(HWPERMS, 123, 112),
    CC128_FIELD(RESERVED, 111, 109),
    CC128_FIELD(OTYPE, 108, 91),
    CC128_FIELD(INTERNAL_EXPONENT, 90, 90),
    CC128_FIELD(TOP_ENCODED, 89, 78),
    CC128_FIELD(BOTTOM_ENCODED, 77, 64),

    // Top/bottom offsets depending in INTERNAL_EXPONENT flag:
    CC128_FIELD(EXP_ZERO_TOP, 89, 78),
    CC128_FIELD(EXP_NONZERO_TOP, 89, 81),
    CC128_FIELD(EXP_ZERO_BOTTOM, 77, 64),
    CC128_FIELD(EXP_NONZERO_BOTTOM, 77, 67),
    CC128_FIELD(EXPONENT_HIGH_PART, 80, 78),
    CC128_FIELD(EXPONENT_LOW_PART, 66, 64),
};

#define CC128_ENCODE_FIELD(value, name) \
    ((uint64_t)((value) & CC128_FIELD_ ## name ## _MAX_VALUE) << CC128_FIELD_ ## name ## _START)

#define CC128_EXTRACT_FIELD(value, name) \
    cc128_getbits((value), CC128_FIELD_ ## name ## _START, CC128_FIELD_ ## name ## _SIZE)

#define CC128_OTYPE_BITS CC128_FIELD_OTYPE_SIZE
#define CC128_BOT_WIDTH CC128_FIELD_BOTTOM_ENCODED_SIZE
#define CC128_EXP_LOW_WIDTH CC128_FIELD_EXPONENT_LOW_PART_SIZE

/* From sail:
let null_cap : Capability = struct {
  tag                    = false,
  uperms                 = zeros(),
  permit_set_CID         = false,
  access_system_regs     = false,
  permit_unseal          = false,
  permit_ccall           = false,
  permit_seal            = false,
  permit_store_local_cap = false,
  permit_store_cap       = false,
  permit_load_cap        = false,
  permit_store           = false,
  permit_load            = false,
  permit_execute         = false,
  global                 = false,
  reserved               = zeros(),
  internal_e             = true,
  E                      = resetE,
  sealed                 = false,
  B                      = zeros(),
  T                      = resetT,
  otype                  = ones(),
  address                = zeros()
}
 */
enum {
    CC128_RESET_EXP = 51, // actually 52 but that is implied by the IE flag
    // For a NULL capability we use the internal exponent and need bit 12 in top set
    // to get to 2^65
    CC128_RESET_TOP = 1u << (12 - CC128_FIELD_EXPONENT_HIGH_PART_SIZE),
    CC128_NULL_PESBT =
        CC128_ENCODE_FIELD(0, UPERMS) |
        CC128_ENCODE_FIELD(0, HWPERMS) |
        CC128_ENCODE_FIELD(0, RESERVED) |
        CC128_ENCODE_FIELD(1, INTERNAL_EXPONENT) |
        CC128_ENCODE_FIELD(UINT64_C(~0), OTYPE) |
        CC128_ENCODE_FIELD(CC128_RESET_TOP, EXP_NONZERO_TOP) |
        CC128_ENCODE_FIELD(0, EXP_NONZERO_BOTTOM) |
        CC128_ENCODE_FIELD(CC128_RESET_EXP >> CC128_FIELD_EXPONENT_LOW_PART_SIZE, EXPONENT_HIGH_PART) |
        CC128_ENCODE_FIELD(CC128_RESET_EXP & CC128_FIELD_EXPONENT_LOW_PART_MAX_VALUE, EXPONENT_LOW_PART)
};
// Whatever NULL would encode to is this constant. We mask on store/load so this
// invisibly keeps null 0 whatever we choose it to be.
// #define CC128_NULL_XOR_MASK 0x1ffff8000000
#define CC128_NULL_XOR_MASK 0x00001ffffc018003
_Static_assert(CC128_NULL_XOR_MASK == CC128_NULL_PESBT, "");

#endif

#define CAP_MAX_ADDRESS_PLUS_ONE ((unsigned __int128)1u << 64)

#define CC128_PERM_GLOBAL          (1 << 0)
#define CC128_PERM_EXECUTE         (1 << 1)
#define CC128_PERM_LOAD            (1 << 2)
#define CC128_PERM_STORE           (1 << 3)
#define CC128_PERM_LOAD_CAP        (1 << 4)
#define CC128_PERM_STORE_CAP       (1 << 5)
#define CC128_PERM_STORE_LOCAL     (1 << 6)
#define CC128_PERM_SEAL            (1 << 7)
#define CC128_PERM_CCALL           (1 << 8)
#define CC128_PERM_UNSEAL          (1 << 9)
#define CC128_PERM_ACCESS_SYS_REGS (1 << 10)
#define CC128_PERM_SETCID          (1 << 11)
#define CC128_PERM_RESERVED4       (1 << 12)
#define CC128_PERM_RESERVED5       (1 << 13)
#define CC128_PERM_RESERVED6       (1 << 14)

#define CC128_PERMS_ALL            (0xfff)     /* [0...11] */
#define CC128_UPERMS_ALL           (0xf)       /* [15...18] */
#define CC128_UPERMS_SHFT          (15)
#define CC128_UPERMS_MEM_SHFT      (12)
#define CC128_MAX_UPERM            (3)
#define CC128_NULL_TOP_VALUE CAP_MAX_ADDRESS_PLUS_ONE
#define CC128_NULL_LENGTH CAP_MAX_ADDRESS_PLUS_ONE


/* For CHERI256 all permissions are shifted by one since the sealed bit comes first */
#define CC256_PERMS_COUNT          (12)
#define CC256_UPERMS_COUNT         (20)
#define CC256_PERMS_MEM_SHFT       (1)  /* sealed bit comes first */
#define CC256_UPERMS_MEM_SHFT      (CC256_PERMS_MEM_SHFT + CC256_PERMS_COUNT)
#define CC256_PERMS_ALL_BITS       ((1 << CC256_PERMS_COUNT) - 1) /* 12 bits */
#define CC256_UPERMS_ALL_BITS      ((1 << CC256_UPERMS_COUNT) - 1) /* 19 bits */
#define CC256_MAX_UPERM            (19)
#define CC256_OTYPE_ALL_BITS       ((1 << 24) - 1)
#define CC256_OTYPE_MEM_SHFT       (32)
#define CC256_OTYPE_BITS           (24)
#define CC256_NULL_LENGTH ((unsigned __int128)UINT64_MAX)





#define CC_SPECIAL_OTYPE(name, subtract) \
    CAP_ ## name = (CAP_MAX_REPRESENTABLE_OTYPE - subtract ## u), \
    CC128_ ## name = (CC128_MAX_REPRESENTABLE_OTYPE - subtract ## u), \
    CC256_ ## name = (CC256_MAX_REPRESENTABLE_OTYPE - subtract ## u)

enum CC_OTypes {
    CC128_MAX_REPRESENTABLE_OTYPE = ((1u << CC128_OTYPE_BITS) - 1u),
    CC256_MAX_REPRESENTABLE_OTYPE = ((1u << CC256_OTYPE_BITS) - 1u),
#ifdef CHERI_128
    CAP_MAX_REPRESENTABLE_OTYPE = CC128_MAX_REPRESENTABLE_OTYPE,
#else
    CAP_MAX_REPRESENTABLE_OTYPE = CC256_MAX_REPRESENTABLE_OTYPE,
#endif
    CC_SPECIAL_OTYPE(OTYPE_UNSEALED, 0),
    CC_SPECIAL_OTYPE(OTYPE_SENTRY, 1),
    CC_SPECIAL_OTYPE(OTYPE_RESERVED2, 2),
    CC_SPECIAL_OTYPE(OTYPE_RESERVED3, 3),
    CC_SPECIAL_OTYPE(LAST_SPECIAL_OTYPE, 3),
    CC_SPECIAL_OTYPE(MAX_SEALED_OTYPE, 4)

};
// Rerserve the top four otypes for various special capabilities
#define CAP_FIRST_SPECIAL_OTYPE_SIGN_EXTENDED ((uint64_t)-1)
#define CAP_OTYPE_UNSEALED (CAP_MAX_REPRESENTABLE_OTYPE - 0u)
#define CAP_OTYPE_SENTRY (CAP_MAX_REPRESENTABLE_OTYPE - 1u)
#define CAP_OTYPE_RESERVED2 (CAP_MAX_REPRESENTABLE_OTYPE - 2u)
#define CAP_OTYPE_RESERVED3 (CAP_MAX_REPRESENTABLE_OTYPE - 3u)
#define CAP_LAST_SPECIAL_OTYPE CAP_OTYPE_RESERVED3
#define CAP_LAST_SPECIAL_OTYPE_SIGN_EXTENDED ((uint64_t)-3)
#define CAP_MAX_SEALED_OTYPE (CAP_LAST_SPECIAL_OTYPE - 1u)

// Rerserve the top four otypes for various special capabilities
#define CAP_FIRST_SPECIAL_OTYPE_SIGN_EXTENDED ((uint64_t)-1)
#define CAP_OTYPE_UNSEALED (CAP_MAX_REPRESENTABLE_OTYPE - 0u)
#define CAP_OTYPE_SENTRY (CAP_MAX_REPRESENTABLE_OTYPE - 1u)
#define CAP_OTYPE_RESERVED2 (CAP_MAX_REPRESENTABLE_OTYPE - 2u)
#define CAP_OTYPE_RESERVED3 (CAP_MAX_REPRESENTABLE_OTYPE - 3u)
#define CAP_LAST_SPECIAL_OTYPE CAP_OTYPE_RESERVED3
#define CAP_LAST_SPECIAL_OTYPE_SIGN_EXTENDED ((uint64_t)-3)
#define CAP_MAX_SEALED_OTYPE (CAP_LAST_SPECIAL_OTYPE - 1u)

/* Avoid pulling in code that uses cr_pesbt when building QEMU256 */
#ifndef CHERI_COMPRESSED_CONSTANTS_ONLY

/* Returns the index of the most significant bit set in x */
static inline uint32_t cc128_idx_MSNZ(uint64_t x) {
    /*
     * XXX For HOST_X86_64
     *
     * uint64_t r;
     *
     * asm("bsrq %1,%q0" : "+r" (r) : "rm" (x));
     *
     * return (uint32_t)r;
     *
     * XXX This isn't quite right. %q0 needs to be pushed/popped?
     */
#if defined(__has_builtin)
#if __has_builtin(__builtin_clzll)
#define HAVE___BUILTIN_CLZ
#endif
#elif defined(__GNUC__)
#define HAVE___BUILTIN_CLZ
#endif

#ifndef HAVE___BUILTIN_CLZ
/* floor(log2(x)) != floor(log2(y)) */
#warning "__builtin_clzll not supported using slower path"
#define ld_neq(x, y) (((x) ^ (y)) > ((x) & (y)))

    uint32_t r = ld_neq(x, x & 0x5555555555555555ull) + (ld_neq(x, x & 0x3333333333333333ull) << 1) +
                 (ld_neq(x, x & 0x0f0f0f0f0f0f0f0full) << 2) + (ld_neq(x, x & 0x00ff00ff00ff00ffull) << 3) +
                 (ld_neq(x, x & 0x0000ffff0000ffffull) << 4) + (ld_neq(x, x & 0x00000000ffffffffull) << 5);

#undef ld_neq
#else
    assert(x != 0);
    uint32_t r = 63u - (uint32_t)__builtin_clzll(x);
    // printf("%s: %016llx = %d (__builtin_clzll(x) = %d, 63 - clz = %d)\n", __func__, x, r, __builtin_clzll(x), 63 -
    // __builtin_clzll(x));
#endif
    return r;
}

/*
 * e = idxMSNZ( (rlength + (rlength >> 6)) >> 19 )
 * where (rlength + (rlength >> 6)) needs to be a 65 bit integer
 */
static inline uint32_t cc128_compute_e(uint64_t rlength, uint32_t bwidth) {
    if (rlength < (1u << (bwidth - 1)))
        return 0;

    return (cc128_idx_MSNZ(rlength) - (bwidth - 2));
}

static inline uint64_t cc128_getbits(uint64_t src, uint32_t str, uint32_t sz) {
    return ((src >> str) & ((UINT64_C(1) << sz) - UINT64_C(1)));
}

/*
 * These formats are from cheri concentrate, but I have added an extra sealing
 * mode in order to allow precise sealing of zero offset objects Unsealed CC-L:
 *  perms:    63-48 (16 bits)
 *  S:        47-46 (2 bits) = 0
 *  IE:       45    (1 bit)
 *  LH:       44    (1 bit)
 *  T:        43-23 (21 bit)
 *  B:        22-0  (23 bits)
 *
 * Sealed1 CC-L:
 *  perms:    63-49  (15 bits)
 *  unused:   48     (1 bit)
 *  S:        47-46  (2 bits) = 1
 *  IE:       45     (1 bit)
 *  LH:       44     (1 bit)
 *  otype.hi: 43-34  (10 bits)
 *  T:        33-23  (11 bits)
 *  otype.lo: 22-13  (10 bits)
 *  B:        12-0   (13 bits)
 *
 *  Call-only "sentry" capability
 *  perms:    63-48 (16 bits)
 *  S:        47-46 (2 bits) = 3
 *  IE:       45    (1 bit)
 *  LH:       44    (1 bit)
 *  T:        43-23 (21 bit)
 *  B:        22-0  (23 bits)
 *
 * Sealed2 CC-L:
 *  perms:    63-49 (15 bits)
 *  unused:   48    (1 bit)
 *  S:        47-46 (2 bits) = 2
 *  IE:       45    (1 bit)
 *  LH:       44    (1 bit)
 *  T:        43-23 (21 bits)
 *  otype     22-3  (20 bits)
 *  B:        2-0   (3 bits) (completely implied by cursor. Keep 3 bits for
 * exponent)
 */

static inline void decompress_128cap_already_xored(uint64_t pesbt, uint64_t cursor, cap_register_t* cdp) {


#ifdef CC128_OLD_FORMAT
    cdp->cr_perms = cc128_getbits(pesbt, 48, 12);
    cdp->cr_uperms = cc128_getbits(pesbt, 60, 4);

    uint8_t seal_mode = (uint8_t)cc128_getbits(pesbt, CC_L_S_OFF, 2);

    uint32_t BWidth = seal_mode == CC_SEAL_MODE_SEALED ? CC_L_SEALED_BWIDTH : CC_L_BWIDTH;
    uint32_t BMask = (1 << BWidth) - 1;
    uint32_t TMask = BMask >> 2;

    uint8_t IE = (uint8_t)cc128_getbits(pesbt, CC_L_IE_OFF, 1);
    uint8_t LH = (uint8_t)cc128_getbits(pesbt, CC_L_LH_OFF, 1);

    uint8_t E, L_msb;
    uint32_t B = cc128_getbits(pesbt, CC_L_B_OFF, BWidth);
    uint32_t T = cc128_getbits(pesbt, CC_L_T_OFF, BWidth - 2);

    if (IE) {
        E = ((((LH << CC_L_LOWWIDTH) | (B & CC_L_LOWMASK)) << CC_L_LOWWIDTH) | (T & CC_L_LOWMASK)) +
            1; // Offset by 1. We don't need to encode E=0
        E = MIN(64 - BWidth + 2, E);
        B &= ~CC_L_LOWMASK;
        T &= ~CC_L_LOWMASK;
        L_msb = 1;
    } else {
        E = 0;
        L_msb = LH;
    }

    uint32_t type = CAP_OTYPE_UNSEALED;

    if (seal_mode == CC_SEAL_MODE_UNSEALED) {
        // TODO: remove extra bit for unsealed caps and always store otype
        type = CAP_OTYPE_UNSEALED;
    } else if (seal_mode == CC_SEAL_MODE_SEALED) {
        type = (cc128_getbits(pesbt, CC_L_OHI_OFF, CC_L_TYPES / 2) << (CC_L_TYPES / 2)) |
               cc128_getbits(pesbt, CC_L_OLO_OFF, CC_L_TYPES / 2);
    } else if (seal_mode == CC_SEAL_MODE_SENTRY) {
        type = CAP_OTYPE_SENTRY;
    }

    cdp->cr_otype = type;
#else
    cdp->cr_perms = (uint32_t)CC128_EXTRACT_FIELD(pesbt, HWPERMS);
    cdp->cr_uperms = (uint32_t)CC128_EXTRACT_FIELD(pesbt, UPERMS);
    uint32_t BWidth = CC128_BOT_WIDTH;
    uint32_t BMask = (1u << BWidth) - 1;
    uint32_t TMask = BMask >> 2;

    bool IE = (bool)CC128_EXTRACT_FIELD(pesbt, INTERNAL_EXPONENT);

    uint8_t E, L_msb;
    uint32_t B;
    uint32_t T;

    if (IE) {
        E = (uint8_t)(CC128_EXTRACT_FIELD(pesbt, EXPONENT_LOW_PART) |
            (CC128_EXTRACT_FIELD(pesbt, EXPONENT_HIGH_PART) << CC128_FIELD_EXPONENT_LOW_PART_SIZE));
        // Do not offset by 1! We also need to encode E=0 even with IE
        // Also allow nonsense values over 64 - BWidth + 2: this is expected by sail-generated tests
        // E = MIN(64 - BWidth + 2, E);
        B = (uint32_t)CC128_EXTRACT_FIELD(pesbt, EXP_NONZERO_BOTTOM) << CC128_FIELD_EXPONENT_LOW_PART_SIZE;
        T = (uint32_t)CC128_EXTRACT_FIELD(pesbt, EXP_NONZERO_TOP) << CC128_FIELD_EXPONENT_HIGH_PART_SIZE;
        L_msb = 1;
    } else {
        E = 0;
        L_msb = 0;
        B = (uint32_t)CC128_EXTRACT_FIELD(pesbt, EXP_ZERO_BOTTOM);
        T = (uint32_t)CC128_EXTRACT_FIELD(pesbt, EXP_ZERO_TOP);
    }
    cdp->cr_otype = (uint32_t)CC128_EXTRACT_FIELD(pesbt, OTYPE);
#endif

    /*
        Reconstruct top two bits of T given T = B + len and:
        1) the top two bits of B
        2) most significant two bits of length derived from format above
        3) carry out of B[20..0] + len[20..0] that is implied if T[20..0] < B[20..0]
    */
    uint8_t L_carry = T < (B & TMask) ? 1 : 0;
    uint8_t T_infer = ((B >> (BWidth - 2)) + L_carry + L_msb) & 0x3;

    T |= ((uint32_t)T_infer) << (BWidth - 2);

    uint32_t amid = (cursor >> E) & BMask;
    uint32_t r = (((B >> (BWidth - 3)) - 1) << (BWidth - 3)) & BMask;

    int64_t ct, cb;

    if (amid < r) {
        ct = T < r ? INT64_C(0) : INT64_C(-1);
        cb = B < r ? INT64_C(0) : INT64_C(-1);
    } else {
        ct = T < r ? INT64_C(1) : INT64_C(0);
        cb = B < r ? INT64_C(1) : INT64_C(0);
    }

    uint8_t shift = (uint8_t)(E + BWidth);

    uint64_t cursor_top = shift >= 64 ? 0 : cursor >> shift;
    // Top is 65 bits -> use __int128 which is quite efficient (seems better than
    // a separate boolean flag unless you spend a lot of time optimizing that).
    unsigned __int128 top = (unsigned __int128)(((cursor_top + (uint64_t)(int64_t)ct) << BWidth) | (uint64_t)T) << E;
    uint64_t base = (((cursor_top + (uint64_t)(int64_t)cb) << BWidth) | (uint64_t)B) << E;

    // Pretend that top is a 65 bit integer

    top &= ((unsigned __int128)1 << 65) - 1; // pretend that top is 65 bits
    const uint64_t top_high = (top >> 64);
    assert(top_high <= 1); // should be at most 1 bit over

    // TODO: should really store top and not length!
    cdp->_cr_length = top - base;
    if (top < base) {
        // This can happen for invalid capabilities with arbitrary bit patterns
        assert((signed __int128)cdp->_cr_length < 0); // must be negative
    }
    cdp->cr_offset = cursor - base;
    cdp->cr_base = base;
}

/*
 * Decompress a 128-bit capability.
 */
static inline void decompress_128cap(uint64_t pesbt, uint64_t cursor, cap_register_t* cdp) {

    cdp->cr_pesbt = pesbt;
    decompress_128cap_already_xored(pesbt ^ CC128_NULL_XOR_MASK, cursor, cdp);
}

static inline bool cc128_is_cap_sealed(const cap_register_t* cp) { return cp->cr_otype <= CAP_MAX_SEALED_OTYPE; }

/*
 * Compress a capability to 128 bits.
 */
static inline uint64_t compress_128cap(const cap_register_t* csp) {
#ifdef CC128_OLD_FORMAT
    int seal_mode = csp->cr_otype <= CAP_MAX_SEALED_OTYPE ? CC_SEAL_MODE_SEALED : CC_SEAL_MODE_UNSEALED;
    if (csp->cr_otype == CAP_OTYPE_SENTRY)
        seal_mode = CC_SEAL_MODE_SENTRY;

    uint8_t LH;
    uint32_t BWidth = seal_mode == CC_SEAL_MODE_SEALED ? CC_L_SEALED_BWIDTH : CC_L_BWIDTH;
#else
    uint32_t BWidth = CC128_BOT_WIDTH;
#endif
    uint32_t BMask = (1u << BWidth) - 1;
    uint32_t TMask = BMask >> 2;

    uint64_t base = csp->cr_base;
    unsigned __int128 top = csp->cr_base + csp->_cr_length;
    uint64_t length64 = (uint64_t)csp->_cr_length;

    bool IE;
    uint32_t Te, Be;
    uint8_t E;

    if (top > UINT64_MAX) {
        top = CAP_MAX_ADDRESS_PLUS_ONE; // Actually 1 << 64
        length64++;

        // Length of 0 is 1 << 64.
        if (length64 == 0) {
            assert(csp->_cr_length > UINT64_MAX); // should really be > 1 << 64
            E = (uint8_t)(64 - BWidth + 2);
        } else {
            E = (uint8_t)cc128_compute_e(length64, BWidth);
        }

        Te = (1ULL << (64 - E)) & TMask;
    } else {
        E = (uint8_t)cc128_compute_e(length64, BWidth);
        Te = (top >> E) & TMask;
    }

    Be = (base >> E) & BMask;
    IE = E != 0;


#ifdef CC128_OLD_FORMAT
    if (IE) {
        E -= 1; // Don't need to encode E=0
        LH = E >> (2 * CC_L_LOWWIDTH);
        Be |= (E >> CC_L_LOWWIDTH) & CC_L_LOWMASK;
        Te |= E & CC_L_LOWMASK;
    } else {
        LH = (length64 >> (BWidth - 2)) & 1;
    }
    if (seal_mode == CC_SEAL_MODE_SEALED) {
        uint64_t hi = ((uint64_t)csp->cr_otype >> (CC_L_TYPES / 2)) & ((1 << (CC_L_TYPES / 2)) - 1);
        uint64_t lo = (uint64_t)csp->cr_otype & ((1 << (CC_L_TYPES / 2)) - 1);
        Te |= hi << (CC_L_SEALED_BWIDTH - 2);
        Be |= lo << CC_L_SEALED_BWIDTH;
    }
    // assert(seal_mode <= 3);
    uint64_t perms = ((uint64_t)csp->cr_uperms << CC128_UPERMS_MEM_SHFT) | (uint64_t)csp->cr_perms;
    uint64_t pesbt =
        ((((((((((perms << 2) | (uint64_t)seal_mode) << 1) | (uint64_t)IE) << 1) | (uint64_t)LH) << (CC_L_BWIDTH - 2)) |
           (uint64_t)Te)
          << CC_L_BWIDTH) |
         (uint64_t)Be);
#else
    if (IE) {
        // Split E between T and B
        Te |= (E >> CC128_FIELD_EXPONENT_LOW_PART_SIZE) & CC128_FIELD_EXPONENT_HIGH_PART_MAX_VALUE;
        Be |= E & CC128_FIELD_EXPONENT_LOW_PART_MAX_VALUE;
    }
    uint64_t pesbt =
        CC128_ENCODE_FIELD(csp->cr_uperms, UPERMS) |
        CC128_ENCODE_FIELD(csp->cr_perms, HWPERMS) |
        CC128_ENCODE_FIELD(csp->cr_otype, OTYPE) |
        CC128_ENCODE_FIELD(IE, INTERNAL_EXPONENT) |
        CC128_ENCODE_FIELD(Te, TOP_ENCODED) |
        CC128_ENCODE_FIELD(Be, BOTTOM_ENCODED);
    // For untagged values we add the initially loaded reserved bits in the reserved field:
    if (!csp->cr_tag)
        pesbt |= CC128_EXTRACT_FIELD(csp->cr_pesbt, RESERVED);
#endif
    pesbt ^= CC128_NULL_XOR_MASK;

    return pesbt;
}

/*
 * Define the following to do the is_representable() check by simply
 * compressing and decompressing the capability and checking to
 * see if it is the same.
 */
// #define SIMPLE_REPRESENT_CHECK

#ifndef SIMPLE_REPRESENT_CHECK
static inline bool cc128_all_ones(uint64_t offset, uint32_t e, uint32_t bwidth) {
    uint64_t Itop;
    uint32_t shift = e + bwidth;

    if (shift >= 63)
        return false;
    Itop = offset >> shift;
    return Itop == (0xfffffffffffffffful >> shift);
}

static inline bool cc128_all_zeroes(uint64_t offset, uint32_t e, uint32_t bwidth) {
    uint32_t shift = e + bwidth;
    uint64_t Itop;

    if (shift >= 63)
        Itop = 0ul;
    else
        Itop = offset >> shift;
    return Itop == 0ul;
}
#endif /* ! SIMPLE_REPRESENT_CHECK */

/*
 * Check to see if a memory region is representable by a compressed
 * capability. It is representable if:
 *
 *   representable = (inRange && inLimits) || (E >= 44)
 *
 * where:
 *
 *   E = compression exponent (see cc128_compute_e() above)
 *
 *   inRange = -s < i < s  where i is the increment (or offset)
 *   (In other words, all the bits of i<63, E+20> are the same.)
 *
 *   inLimits = (i < 0) ? (Imid >= (R - Amid)) && (R != Amid) : (R - Amid - 1)
 *   where Imid = i<E+19, E>, Amid = a<E+19, E>, R = B - 2^12 and a =
 *   base + offset.
 */
static inline bool cc128_is_representable(bool sealed, uint64_t base, uint64_t length, uint64_t offset,
                                          uint64_t new_offset) {
#ifdef CC128_OLD_FORMAT
    // I change the precision going between unsealed->sealed so the fast check
    // doesn't work. Instead just compress/decompress.
    if (sealed) {

        cap_register_t c;
        uint64_t pesbt;

        /* Simply compress and uncompress to check. */

#define MAGIC_TYPE 0b1011011101

        c.cr_base = base;
        c._cr_length = length;
        c.cr_offset = new_offset;
        c.cr_otype = sealed ? 0 : CAP_OTYPE_UNSEALED; // important to set as compress assumes this is in bounds

        pesbt = compress_128cap(&c);
        decompress_128cap(pesbt, base + new_offset, &c);

        if (c.cr_base != base || c._cr_length != length || c.cr_offset != new_offset)
            return false;

        return true;
    }
#else
    (void)sealed; // no longer used since otype is always present
#endif // CC128_OLD_FORMAT

    uint32_t bwidth = CC128_BOT_WIDTH;
    uint32_t highest_exp = (64 - bwidth + 2);

    uint32_t e;

    // If top is 0xffff... we assume we meant it to be 1 << 64
    if (base + length == UINT64_C(~0)) {
        length++;
        if (length == 0) {
            return true; // maximum length is always representable
        }
    }

    e = cc128_compute_e(length, bwidth);

    int64_t b, r, Imid, Amid;
    bool inRange, inLimits;
    int64_t inc = (int64_t)(new_offset - offset);

#define MOD_MASK ((UINT64_C(1) << bwidth) - UINT64_C(1))

    /* Check for the boundary cases. */

    b = (int64_t)((base >> e) & MOD_MASK);
    Imid = (int64_t)((uint64_t)(inc >> e) & MOD_MASK);
    Amid = (int64_t)(((base + offset) >> e) & MOD_MASK);

    r = (int64_t)(((uint64_t)((b >> (bwidth - 3)) - 1) << (bwidth - 3)) & MOD_MASK);

    /* inRange, test if bits are all the same */
    inRange = cc128_all_ones((uint64_t)inc, e, bwidth) || cc128_all_zeroes((uint64_t)inc, e, bwidth);

    /* inLimits */
    if (inc >= 0) {
        inLimits = ((uint64_t)Imid < (((uint64_t)(r - Amid - 1l)) & MOD_MASK));
    } else {
        inLimits = ((uint64_t)Imid >= (((uint64_t)(r - Amid)) & MOD_MASK)) && (r != Amid);
    }
#undef MOD_MASK

    return ((inRange && inLimits) || (e >= highest_exp));
}


/* Also support decoding of the raw 256-bit capabilities */
typedef union _inmemory_chericap256 {
    uint8_t bytes[32];
    uint32_t u32s[8];
    uint64_t u64s[4];
} inmemory_chericap256;

static inline void decompress_256cap(inmemory_chericap256 mem, cap_register_t* cdp) {
    /* See CHERI ISA: Figure 3.1: 256-bit memory representation of a capability */
#ifndef CHERI_128
    cdp->_sbit_for_memory = mem.u64s[0] & 1;
#endif
    cdp->cr_perms = (mem.u64s[0] >> CC256_PERMS_MEM_SHFT) & CC256_PERMS_ALL_BITS;
    cdp->cr_uperms = (mem.u64s[0] >> CC256_UPERMS_MEM_SHFT) & CC256_UPERMS_ALL_BITS;
    cdp->cr_otype = (mem.u64s[0] >> CC256_OTYPE_MEM_SHFT) ^ CC256_OTYPE_ALL_BITS;
    cdp->cr_base = mem.u64s[2];
    /* Length is xor'ed with -1 to ensure that NULL is all zeroes in memory */
    cdp->_cr_length = mem.u64s[3] ^ CC256_NULL_LENGTH;
    /* TODO: should just have a cr_cursor instead... But that's not the way QEMU works */
    cdp->cr_offset = mem.u64s[1] - cdp->cr_base;
}

static inline void compress_256cap(inmemory_chericap256* buffer, const cap_register_t* csp) {
    buffer->u64s[0] =
#ifndef CHERI_128
        csp->_sbit_for_memory |
#endif
        ((csp->cr_perms & CC256_PERMS_ALL_BITS) << CC256_PERMS_MEM_SHFT) |
        ((csp->cr_uperms & CC256_UPERMS_ALL_BITS) << CC256_UPERMS_MEM_SHFT) |
        ((uint64_t)(csp->cr_otype ^ CC256_OTYPE_ALL_BITS) << CC256_OTYPE_MEM_SHFT);
    buffer->u64s[1] = csp->cr_base + csp->cr_offset;
    buffer->u64s[2] = csp->cr_base;
    uint64_t length64 = csp->_cr_length > UINT64_MAX ? UINT64_MAX : (uint64_t)csp->_cr_length;
    buffer->u64s[3] = length64 ^ CC256_NULL_LENGTH;
}

#endif /* CHERI_COMPRESSED_CONSTANTS_ONLY */
#endif /* CHERI_COMPRESSED_CAP_H */
