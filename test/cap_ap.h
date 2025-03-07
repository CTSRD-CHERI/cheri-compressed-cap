#pragma once

#define CAP_AP_C _CC_N(PERM_CAPABILITY)
#define CAP_AP_W _CC_N(PERM_WRITE)
#define CAP_AP_R _CC_N(PERM_READ)
#define CAP_AP_X _CC_N(PERM_EXECUTE)
#define CAP_AP_ASR _CC_N(PERM_ACCESS_SYS_REGS)
#define CAP_AP_LM _CC_N(PERM_LOAD_MUTABLE)
#define CAP_AP_EL _CC_N(PERM_ELEVATE_LEVEL)
#define CAP_AP_SL _CC_N(PERM_STORE_LEVEL)

#define TEST_CASE_AP_COMP(_cr_arch_perm, _ap)                                                                          \
    TEST_CASE(#_cr_arch_perm " compress", "[compress]") {                                                              \
        _cc_cap_t cap = TestAPICC::make_null_derived_cap(0);                                                           \
        CHECK(_CC_EXTRACT_FIELD(cap.cr_pesbt, AP_M) == 0);                                                             \
        CHECK(_CC_EXTRACT_FIELD(cap.cr_pesbt, UPERMS) == 0);                                                           \
        CHECK(_cc_N(set_permissions)(&cap, (_cr_arch_perm)));                                                          \
        CHECK((cap.all_permissions() & (_cr_arch_perm)) == (_cr_arch_perm));                                           \
        CHECK(_CC_EXTRACT_FIELD(cap.cr_pesbt, AP_M) == (_ap));                                                         \
        CHECK(_CC_EXTRACT_FIELD(cap.cr_pesbt, UPERMS) == 0);                                                           \
    }

#define TEST_CASE_AP_DECOMP(_ap, _cr_arch_perm)                                                                        \
    TEST_CASE(#_ap " decompress", "[decompress]") {                                                                    \
        _cc_cap_t cap = TestAPICC::make_null_derived_cap(0);                                                           \
        CHECK(_CC_EXTRACT_FIELD(cap.cr_pesbt, AP_M) == 0);                                                             \
        CHECK(_CC_EXTRACT_FIELD(cap.cr_pesbt, UPERMS) == 0);                                                           \
        cap.cr_pesbt = _CC_DEPOSIT_FIELD(cap.cr_pesbt, (_ap), AP_M);                                                   \
        CHECK((cap.all_permissions() & (_cr_arch_perm)) == (_cr_arch_perm));                                           \
        CHECK(_CC_EXTRACT_FIELD(cap.cr_pesbt, AP_M) == (_ap));                                                         \
        CHECK(_CC_EXTRACT_FIELD(cap.cr_pesbt, UPERMS) == 0);                                                           \
    }
