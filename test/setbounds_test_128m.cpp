#define TEST_CC_FORMAT_LOWER 128m
#define TEST_CC_FORMAT_UPPER 128M
#define TEST_CC_IS_MORELLO

#include "setbounds_test_common.cpp"

TEST_CASE("Morello setbounds with high bits", "[bounds]") {
    // Check that Morello flags are not changed when we set the base to exclude them.
    TestAPICC::cap_t cap = TestAPICC::make_max_perms_cap(0, UINT64_C(0xFF00000000000944), _CC_N(MAX_LENGTH));
    REQUIRE(cap.address() == 0xFF00000000000944);
    bool was_exact = TestAPICC::setbounds(&cap, 16);
    CHECK(cap.address() == 0xFF00000000000944);
    CHECK(cap.length() == 16);
    CHECK(cap.base() == 0x944); // Base should not include the high 8 bits
    CHECK(cap.top() == 0x954);  // Same for top
    CHECK(cap.cr_tag);
    CHECK(was_exact);
}
