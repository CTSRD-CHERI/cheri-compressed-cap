/*-
 * SPDX-License-Identifier: BSD-2-Clause
 *
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
#include <err.h>
#include <errno.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>

#include "cheri_compressed_cap.h"
// #include "cheri_compressed_cap.h"
#ifdef DECOMPRESS_WITH_SAIL_GENERATED_CODE
#include "test/sail_wrapper.h"
#endif

static const char* otype_suffix(uint32_t otype) {
    // clang-format off
    switch (otype) {
#define OTYPE_CASE(Name, ...)                                                                                          \
    case CC64_##Name: return " (CC64_" #Name ")";
    CC64_LS_SPECIAL_OTYPES(OTYPE_CASE, )
    default: return "";
    }
    // clang-format on
}

static void dump_cap_fields(const cc64_cap_t* result) {
    fprintf(stderr, "Permissions: 0x%" PRIx32 "\n", cc64_get_perms(result)); // TODO: decode perms
    fprintf(stderr, "Base:        0x%08" PRIx32 "\n", result->cr_base);
    fprintf(stderr, "Offset:      0x%08" PRIx32 "\n", result->_cr_cursor - result->cr_base);
    fprintf(stderr, "Cursor:      0x%08" PRIx32 "\n", result->_cr_cursor);
    cc64_length_t length = result->_cr_top - result->cr_base;
    fprintf(stderr, "Length:     0x%" PRIx32 "%08" PRIx32 " %s\n", (uint32_t)(length >> 32), (uint32_t)length,
            length > UINT32_MAX ? " (greater than UINT32_MAX)" : "");
    cc64_length_t top_full = result->_cr_top;
    fprintf(stderr, "Top:        0x%" PRIx32 "%08" PRIx32 " %s\n", (uint32_t)(top_full >> 32), (uint32_t)top_full,
            top_full > UINT32_MAX ? " (greater than UINT32_MAX)" : "");
    fprintf(stderr, "Sealed:      %d\n", cc64_is_cap_sealed(result) ? 1 : 0);
    uint32_t otype = cc64_get_otype(result);
    fprintf(stderr, "OType:       0x%" PRIx32 "%s\n", otype, otype_suffix(otype));
    fprintf(stderr, "OType:       0x%" PRIx32 "\n", otype);
    fprintf(stderr, "Flags:       0x%" PRIx8 "\n", cc64_get_flags(result));
    fprintf(stderr, "Reserved:    0x%" PRIx8 "\n", cc64_get_reserved(result));
    fprintf(stderr, "Valid decompress: %s", result->cr_bounds_valid ? "yes" : "no");
    fprintf(stderr, "\n");
}

int main(int argc, char** argv) {
    // fprintf(stderr, "CC64_NULL_XOR_MASK=0x%lx\n", (long)CC64_NULL_XOR_MASK);
    // fprintf(stderr, "CC64_NULL_PESBT   =0x%lx\n", (long)CC64_NULL_PESBT);
    if (argc < 3) {
        fprintf(stderr, "Usage: %s PESBT CURSOR\n", argv[0]);
        return EXIT_FAILURE;
    }
    errno = 0;
    char* end;
    uint32_t pesbt = strtoull(argv[1], &end, 16);
    if (errno != 0 || !end || *end != '\0') {
        err(EX_DATAERR, "pesbt not a valid hex number: %s", argv[1]);
    }
    uint32_t cursor = strtoull(argv[2], &end, 16);
    if (errno != 0 || !end || *end != '\0') {
        err(EX_DATAERR, "cursor not a valid hex number: %s", argv[2]);
    }
    printf("Decompressing pesbt = %08" PRIx32 ", cursor = %08" PRIx32 "\n", pesbt, cursor);
#ifdef DECOMPRESS_WITH_SAIL_GENERATED_CODE
    cc64_cap_t result = sail_decode_64_mem(pesbt, cursor, false);
#else
    cc64_cap_t result;
    memset(&result, 0, sizeof(result));
    cc64_decompress_mem(pesbt, cursor, false, &result);
#endif
    dump_cap_fields(&result);
#ifdef DECOMPRESS_WITH_SAIL_GENERATED_CODE
    uint32_t rt_pesbt = sail_compress_64_mem(&result);
#else
    uint32_t rt_pesbt = cc64_compress_mem(&result);
#endif
    printf("Re-compressed pesbt = %08" PRIx32 "%s\n", rt_pesbt, pesbt == rt_pesbt ? "" : " - WAS DESTRUCTIVE");
    return EXIT_SUCCESS;
}
