// SPDX-License-Identifier: BSD-2-Clause

// ISAv9 uses a direct 1:1 mapping of bits to permissions with user permissions shifted by a fixed offset
static inline _cc_addr_t _cc_N(get_all_permissions)(const _cc_cap_t* cap) {
    return ((_cc_addr_t)(_CC_EXTRACT_FIELD(cap->cr_pesbt, UPERMS) & _CC_N(UPERMS_ALL)) << _CC_N(UPERMS_SHFT)) |
           (_CC_EXTRACT_FIELD(cap->cr_pesbt, HWPERMS) & _CC_N(PERMS_ALL));
}
static inline bool _cc_N(set_permissions)(_cc_cap_t* cap, _cc_addr_t permissions) {
    _cc_api_requirement((permissions & _CC_N(PERMS_MASK)) == permissions, "invalid permissions");
    _cc_addr_t arch_perms = permissions & _CC_N(PERMS_ALL);
    _cc_addr_t sw_perms = (permissions >> _CC_N(UPERMS_SHFT)) & _CC_N(UPERMS_ALL);
    cap->cr_pesbt = _CC_DEPOSIT_FIELD(cap->cr_pesbt, arch_perms, HWPERMS);
    cap->cr_pesbt = _CC_DEPOSIT_FIELD(cap->cr_pesbt, sw_perms, UPERMS);
    return true; // all permissions are representable
}
