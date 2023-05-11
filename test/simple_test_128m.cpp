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
