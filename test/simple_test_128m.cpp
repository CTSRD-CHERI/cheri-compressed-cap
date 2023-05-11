#define TEST_CC_FORMAT_LOWER 128m
#define TEST_CC_FORMAT_UPPER 128M
#define TEST_CC_IS_MORELLO

#include "simple_test_common.cpp"

TEST_CASE("Fast representability check sign extended", "[fuzz]") {
    // Check that the fast representability check properly accounts for Morello sign extension on the address.
    TestAPICC::cap_t cap;
    TestAPICC::decompress_raw(0xa1a04fffffdff00, 0x01a4fe02410001ff, false, &cap);
    CHECK(cap.base() == 0xfeff000000000000);
    CHECK(cap.top() == 0xff3ff80000000000);
    TestAPICC::addr_t new_addr = 0;
    bool sail_fast_rep = TestAPICC::sail_fast_is_representable(&cap, new_addr);
    bool cc_fast_rep = _cc_N(fast_is_representable_new_addr)(&cap, new_addr);
    CHECK(sail_fast_rep == cc_fast_rep);
    CHECK(!cc_fast_rep);
    // It should also not be representable if we do the full check.
    CHECK(!_cc_N(is_representable_with_addr_impl)(&cap, new_addr, /*slow_representable_check=*/true));
}

TEST_CASE("Fast representability check zero length", "[fuzz]") {
    // Check that the fast representability check does treat zero length caps as always representable
    // This is not true if the cursor change results in a sign change on the resulting bounds.
    TestAPICC::cap_t cap;
    TestAPICC::decompress_raw(0xaff000000000000, 0x0080000000800000, false, &cap);
    CHECK(cap.base() == 0xff80000000800007);
    CHECK(cap.top() == 0xff80000000800007);
    TestAPICC::addr_t new_addr = 0;
    bool sail_fast_rep = TestAPICC::sail_fast_is_representable(&cap, new_addr);
    bool cc_fast_rep = _cc_N(fast_is_representable_new_addr)(&cap, new_addr);
    CHECK(sail_fast_rep == cc_fast_rep);
    CHECK(!cc_fast_rep);
    // It should also not be representable if we do the full check.
    CHECK(!_cc_N(is_representable_with_addr_impl)(&cap, new_addr, /*slow_representable_check=*/true));
}

TEST_CASE("Fast representability zero length no sign change", "[fuzz]") {
    // Check that the fast representability check does treat zero length caps as always representable
    // Even when the sign of the cursor does not change the bounds interpretation could.
    TestAPICC::cap_t cap;
    TestAPICC::decompress_raw(0xffff000000000000, 0x0029ffffff85ffff, false, &cap);
    CHECK(cap.base() == 0x0029ffffff860007);
    CHECK(cap.top() == 0x0029ffffff860007);
    TestAPICC::addr_t new_addr = 0;
    bool sail_fast_rep = TestAPICC::sail_fast_is_representable(&cap, new_addr);
    bool cc_fast_rep = _cc_N(fast_is_representable_new_addr)(&cap, new_addr);
    CHECK(sail_fast_rep == cc_fast_rep);
    CHECK(!cc_fast_rep);
    // It should also not be representable if we do the full check since the bounds interpretation changes.
    CHECK(!_cc_N(is_representable_with_addr_impl)(&cap, new_addr, /*slow_representable_check=*/true));
    _cc_N(set_addr)(&cap, new_addr);
    CHECK(cap.base() == 7);
    CHECK(cap.top() == 7);
}

TEST_CASE("Fuzzer-detected fast representability mismatch 1", "[fuzz]") {
    TestAPICC::cap_t cap;
    TestAPICC::decompress_raw(0x81000100ffeeffd2, 0x0045000000000000, false, &cap);
    CHECK(cap.base() == 0xff40000000000000);
    CHECK(cap.top() == 0x0ffa0000000000000);
    TestAPICC::addr_t new_addr = 0;
    bool sail_fast_rep = TestAPICC::sail_fast_is_representable(&cap, new_addr);
    bool cc_fast_rep = _cc_N(fast_is_representable_new_addr)(&cap, new_addr);
    CHECK(sail_fast_rep == cc_fast_rep);
    CHECK(cc_fast_rep);
    // It should also not be representable if we do the full check since the bounds interpretation changes.
    CHECK(_cc_N(is_representable_with_addr_impl)(&cap, new_addr, /*slow_representable_check=*/true));
    _cc_N(set_addr)(&cap, new_addr);
    CHECK(cap.base() == 0xff40000000000000);
    CHECK(cap.top() == 0x0ffa0000000000000);
}

TEST_CASE("Fast representability mismatch 2", "[fuzz]") {
    TestAPICC::cap_t cap;
    TestAPICC::decompress_raw(0x9a9a656665659a9a, 0x00100a9a9a9a9a9a, false, &cap);
    CHECK(cap.base() == 0xfe6a600000000000);
    CHECK(cap.top() == 0xff95800000000000);
    TestAPICC::addr_t new_addr = 0;
    bool sail_fast_rep = TestAPICC::sail_fast_is_representable(&cap, new_addr);
    bool cc_fast_rep = _cc_N(fast_is_representable_new_addr)(&cap, new_addr);
    CHECK(sail_fast_rep == cc_fast_rep);
    CHECK(cc_fast_rep);
    // It should also not be representable if we do the full check since the bounds interpretation changes.
    CHECK(_cc_N(is_representable_with_addr_impl)(&cap, new_addr, /*slow_representable_check=*/true));
    _cc_N(set_addr)(&cap, new_addr);
    CHECK(cap.base() == 0xfe6a600000000000);
    CHECK(cap.top() == 0xff95800000000000);
}
