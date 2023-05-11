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

TEST_CASE("Fuzzer generated behaviour difference 1", "[fuzz]") {
    // Check that Morello flags are not set if setbounds overflows (found by fuzzer).
    TestAPICC::cap_t cap = TestAPICC::make_max_perms_cap(0x000001fffffebef8, 0xff0001ffffff0011, 0x0000001fffffec0f8);
    cap.cr_tag = false;
    uint64_t req_len = UINT64_C(0xffffff7272727272);
    bool was_exact = false;
    CHECK(cap.cr_exp == 0);
    auto result = do_csetbounds<TestAPICC>(cap, &was_exact, req_len);
    CHECK(result.address() == 0xff0001ffffff0011);
    CHECK(result.base() == 0x0000000000000000);
    CHECK(result.top() == (CC128M_MAX_ADDRESS_PLUS_ONE | 0x0020000000000000));
    CHECK(result.length() == (CC128M_MAX_ADDRESS_PLUS_ONE | 0x0020000000000000));
    CHECK(result.cr_exp == 50);
    CHECK(!was_exact);
}
