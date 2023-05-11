#define TEST_CC_FORMAT_LOWER 128m
#define TEST_CC_FORMAT_UPPER 128M
#define TEST_CC_IS_MORELLO

#include "setbounds_test_common.cpp"

TEST_CASE("Morello setbounds with high bits", "[bounds]") {
    // Check that Morello flags are ignored correctly.
    const TestAPICC::cap_t cap = TestAPICC::make_max_perms_cap(0, UINT64_C(0xFF00000000000944), _CC_N(MAX_LENGTH));
    REQUIRE(cap.address() == 0xFF00000000000944);
    bool was_exact = false;
    auto result = do_csetbounds<TestAPICC>(cap, &was_exact, 16);
    CHECK(result.address() == 0xFF00000000000944);
    CHECK(result.length() == 16);
    CHECK(result.base() == 0x944); // Base should not include the high 8 bits
    CHECK(result.top() == 0x954);  // Same for top
    CHECK(was_exact);
}
