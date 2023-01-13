#define TEST_CC_FORMAT_LOWER 128
#define TEST_CC_FORMAT_UPPER 128

#define HAVE_SAIL_SETBOUNDS_TEST_CASES
#include "setbounds_inputs_128.cpp"

#include "setbounds_test_common.cpp"

TEST_CASE("regression from cheritest", "[bounds]") {
    // The length of 0x0000000000ffffff should not be representable since it uses more than 14/23 bits
    // Therefore it should be rounded up but we were was not doing it correctly.
    // sail log:
    // 1 <-  t:1 s:0 perms:0x00078FFF type:0xFFFFFFFFFFFFFFFF offset:0xFFFFFFFFFF000000 base:0x0000000000000000
    // length:0x10000000000000000
    // PC: 0x900000004000114C op:0x48010848 (csetbounds)
    // 1 <-  t:1 s:0 perms:0x00078FFF type:0xFFFFFFFFFFFFFFFF offset:0x0000000000000000 base:0xFFFFFFFFFF000000
    // length:0x00000000001000000
    // qemu log:
    // 0x9000000040001148:  csetoffset	c1,c1,t0
    //    Write C01|v:1 s:0 p:00078fff b:0000000000000000 l:ffffffffffffffff
    //             |o:ffffffffff000000 t:3ffff
    // 0x900000004000114c:  csetbounds	c1,c1,at
    //    Write C01|v:1 s:0 p:00078fff b:ffffffffff000000 l:0000000000ffffff
    //             |o:0000000000000000 t:3ffff

    cc128_cap_t initial = make_max_perms_cap(0, 0xFFFFFFFFFF000000, CC128_MAX_LENGTH);
    cc128_cap_t with_bounds = check_bounds_exact<TestAPI128>(initial, 0xffffff, false);
    CHECK(with_bounds.cr_base == 0xFFFFFFFFFF000000);
    CHECK(with_bounds.offset() == 0x0000000000000000);
    CHECK(with_bounds.length() == 0x00000000001000000);
}

TEST_CASE("Old format setbounds regression with new format", "[old]") {
    // 0x9000000040000fdc:  cincoffsetimm	c3,c1,7
    //    Write C03|v:1 s:0 p:00078fff b:0000000000000000 l:ffffffffffffffff
    //             |o:0000000000000007 t:ffffff
    // 0x9000000040000fe0:  lui	a0,0x1000
    //    Write a0 = 0000000010000000
    // 0x9000000040000fe4:  csetbounds	c3,c3,a0
    //  -> crash
    auto cap = make_max_perms_cap(0, 7, CC128_MAX_LENGTH);
    uint64_t requested_length = 0x0000000010000000;
    cc128_cap_t with_bounds = check_bounds_exact<TestAPI128>(cap, requested_length, false);
    CHECK(with_bounds.cr_base == 0x0000000000000000);
    CHECK(with_bounds.offset() == 0x0000000000000007);
    // Higher precision in old format -> more exact bounds
    uint64_t expected_length = TESTING_OLD_FORMAT ? 0x0000000010000400 : 0x00000000010080000;
    CHECK(with_bounds.length() == expected_length);
}

TEST_CASE("Cheritest regression case", "[regression]") {
    // dli	$t0, 0x160600000
    // cgetdefault $c1
    // csetoffset $c1, $c1, $t0
    // dli	$t1, 0x300000
    // csetbounds $c1, $c1, $t1
    auto cap = make_max_perms_cap(0, 0x160600000, CC128_MAX_LENGTH);
    cc128_cap_t with_bounds = check_bounds_exact<TestAPI128>(cap, 0x300000, true);
    CHECK(with_bounds.cr_base == 0x160600000);
    CHECK(with_bounds.offset() == 0);
    CHECK(with_bounds.length() == 0x300000);
    CHECK(with_bounds.address() == cap.address());
}

TEST_CASE("Fuzzer assertion exact untagged", "[fuzz]") {
    // Regression test for an assertion found by fuzzing setbounds.
    constexpr uint64_t pesbt = UINT64_C(0x00f58dffffffffff);
    constexpr uint64_t base = UINT64_C(0xff80000000000000);
    constexpr uint64_t addr = UINT64_C(0xf806ffffffff3e0a);
    constexpr TestAPICC::length_t top = base;
    TestAPICC::cap_t decoded;
    TestAPICC::decompress_raw(pesbt, addr, false, &decoded);
    REQUIRE(decoded.base() == base);
    REQUIRE(decoded.top() == top);
    REQUIRE(decoded.address() == addr);
    {
        auto sail_setbounds_base_top = decoded;
        auto cc_setbounds_base_top = decoded;
        TestAPICC::sail_setbounds(&sail_setbounds_base_top, base, top);
        TestAPICC::setbounds(&cc_setbounds_base_top, base, top);
        CHECK(sail_setbounds_base_top == cc_setbounds_base_top);
    }
    {
        auto sail_setbounds_addr_top = decoded;
        auto cc_setbounds_addr_top = decoded;
        TestAPICC::sail_setbounds(&sail_setbounds_addr_top, addr, top);
        TestAPICC::setbounds(&cc_setbounds_addr_top, addr, top);
        CHECK(cc_setbounds_addr_top == cc_setbounds_addr_top);
    }

    do_csetbounds<TestAPICC>(decoded, decoded.top(), nullptr);
    decoded._cr_cursor = base;
    do_csetbounds<TestAPICC>(decoded, decoded.top(), nullptr);
}

TEST_CASE("TestRIG assertion untagged max cap", "[fuzz]") {
    // Regression test for an assertion found by fuzzing QEMU vs sail using testrig.
    // The length is too large, but this should be fine for untagged values.
    const TestAPICC::cap_t cap = TestAPICC::make_max_perms_cap(0, 0xfffffffffa119000, CC128_MAX_TOP);
    constexpr uint64_t req_len = UINT64_C(0xfffffffffa119000);
    CHECK(cap.address() == req_len);
    TestAPICC::cap_t untagged_cap = cap;
    untagged_cap.cr_tag = false;

    auto sail_setbounds_result = untagged_cap;
    auto cc_setbounds_result = untagged_cap;
    const TestAPICC::length_t req_top = (TestAPICC::length_t)cap.address() + req_len;
    TestAPICC::sail_setbounds(&sail_setbounds_result, cap.address(), req_top);
    TestAPICC::setbounds(&cc_setbounds_result, cap.address(), req_top);
    CHECK(sail_setbounds_result == cc_setbounds_result);

    do_csetbounds<TestAPICC>(untagged_cap, req_len, nullptr);
    untagged_cap._cr_cursor = untagged_cap.base();
    do_csetbounds<TestAPICC>(untagged_cap, req_len, nullptr);
}
