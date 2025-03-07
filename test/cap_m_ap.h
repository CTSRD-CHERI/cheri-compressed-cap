#pragma once

#define CAP_AP_C _CC_N(PERM_CAPABILITY)
#define CAP_AP_W _CC_N(PERM_WRITE)
#define CAP_AP_R _CC_N(PERM_READ)
#define CAP_AP_X _CC_N(PERM_EXECUTE)
#define CAP_AP_ASR _CC_N(PERM_ACCESS_SYS_REGS)
#define CAP_AP_LM _CC_N(PERM_LOAD_MUTABLE)
#define CAP_AP_EL _CC_N(PERM_ELEVATE_LEVEL)
#define CAP_AP_SL _CC_N(PERM_STORE_LEVEL)

#define LVB_0 0
#define LVB_1 1

#define TEST_CASE_M_AP_COMP(_cr_lvbits, _cr_m, _cr_arch_perm, _ap)                                                     \
    TEST_CASE(#_cr_lvbits "-" #_cr_arch_perm "-" #_cr_m " compress", "[compress]") {                                   \
        _cc_cap_t cap = TestAPICC::make_null_derived_cap(0);                                                           \
        CHECK(_CC_EXTRACT_FIELD(cap.cr_pesbt, AP_M) == 0);                                                             \
        CHECK(_CC_EXTRACT_FIELD(cap.cr_pesbt, SDP) == 0);                                                              \
        CHECK(_cc_N(set_permissions)(&cap, (_cr_arch_perm)));                                                          \
        const bool has_x = cap.has_permissions(_CC_N(PERM_EXECUTE));                                                   \
        CHECK(_cc_N(set_execution_mode)(&cap, (_cc_mode)(_cr_m)) == has_x);                                            \
        CHECK((cap.all_permissions() & (_cr_arch_perm)) == (_cr_arch_perm));                                           \
        CHECK(_CC_EXTRACT_FIELD(cap.cr_pesbt, AP_M) == (_ap));                                                         \
        CHECK(_CC_EXTRACT_FIELD(cap.cr_pesbt, SDP) == 0);                                                              \
    }

#define TEST_CASE_M_AP_DECOMP(_cr_lvbits, _ap, _cr_m, _cr_arch_perm)                                                   \
    TEST_CASE(#_cr_lvbits "-" #_ap "-" #_cr_m " decompress", "[decompress]") {                                         \
        _cc_cap_t cap = TestAPICC::make_null_derived_cap(0);                                                           \
        CHECK(_CC_EXTRACT_FIELD(cap.cr_pesbt, AP_M) == 0);                                                             \
        CHECK(_CC_EXTRACT_FIELD(cap.cr_pesbt, SDP) == 0);                                                              \
        /* For RV32 the mode is already included in _ap, for RV64 we have to add it */                                 \
        _cc_addr_t ap_m = (_ap);                                                                                       \
        if (_CC_ADDR_WIDTH == 64) {                                                                                    \
            cap.cr_pesbt = _CC_DEPOSIT_FIELD(cap.cr_pesbt, (_cr_m), MODE);                                             \
            ap_m |= (_cr_m) << CC128R_FIELD_AP_SIZE;                                                                   \
        }                                                                                                              \
        cap.cr_pesbt = _CC_DEPOSIT_FIELD(cap.cr_pesbt, ap_m, AP_M);                                                    \
        CHECK((cap.all_permissions() & (_cr_arch_perm)) == (_cr_arch_perm));                                           \
        CHECK(_cc_N(get_execution_mode)(&cap) == (_cc_mode)(_cr_m));                                                   \
        CHECK(_CC_EXTRACT_FIELD(cap.cr_pesbt, AP_M) == ap_m);                                                          \
        CHECK(_CC_EXTRACT_FIELD(cap.cr_pesbt, SDP) == 0);                                                              \
    }
