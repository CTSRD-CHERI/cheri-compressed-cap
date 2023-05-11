#define TEST_CC_FORMAT_LOWER 64
#define TEST_CC_FORMAT_UPPER 64

#include "simple_test_common.cpp"

TEST_CASE("Fast representability mismatch", "[fuzz]") {
    TestAPICC::cap_t cap;
    TestAPICC::decompress_raw(0, 8, false, &cap);
    CHECK(cap.base() == 0);
    CHECK(cap.top() == 0);
    TestAPICC::addr_t new_addr = 0;
    bool sail_fast_rep = TestAPICC::sail_fast_is_representable(&cap, new_addr);
    bool cc_fast_rep = _cc_N(fast_is_representable_new_addr)(&cap, new_addr);
    CHECK(sail_fast_rep == cc_fast_rep);
    CHECK(cc_fast_rep);
    // It should also not be representable if we do the full check since the bounds interpretation changes.
    CHECK(_cc_N(is_representable_with_addr_impl)(&cap, new_addr, /*slow_representable_check=*/true));
    _cc_N(set_addr)(&cap, new_addr);
    CHECK(cap.base() == 0);
    CHECK(cap.top() == 0);
}
