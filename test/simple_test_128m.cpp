#include "simple_test_common.cpp"

TEST_CASE("Fast representability check sign extended", "[fuzz]") {
    // Check that the fast representability check properly accounts for Morello sign extension on the address.
    checkRepCheckFails(/*pesbt=*/0xa1a04ffbffaff07, /*addr=*/0x01a4fe02410001ff,
                       /*expected_base=*/0xfeff000000000000, /*expected_top=*/0xff3ff80000000000,
                       /*new_addr=*/0);
}

TEST_CASE("Fast representability check zero length", "[fuzz]") {
    // Check that the fast representability check does not treat zero length caps as always representable.
    // This is not true if the cursor change results in a sign change on the resulting bounds.
    checkRepCheckFails(/*pesbt=*/0xaff000040070007, /*addr=*/0x0080000000800000,
                       /*expected_base=*/0xff80000000800007, /*expected_top=*/0xff80000000800007,
                       /*new_addr=*/0);
}

TEST_CASE("Fast representability zero length no sign change", "[fuzz]") {
    // Check that the fast representability check does not treat zero length caps as always representable.
    // Even when the sign of the cursor does not change the bounds interpretation could.
    checkRepCheckFails(/*pesbt=*/0xffff000040070007, /*addr=*/0x0029ffffff85ffff,
                       /*expected_base=*/0x0029ffffff860007, /*expected_top=*/0x0029ffffff860007,
                       /*new_addr=*/0);
}

TEST_CASE("Fuzzer-detected fast representability mismatch 1", "[fuzz]") {
    checkFastRepCheckSucceeds(/*pesbt=*/0x81000100bfe9ffd5, /*addr=*/0x0045000000000000,
                              /*expected_base=*/0xff40000000000000, /*expected_top=*/0x0ffa0000000000000,
                              /*new_addr=*/0);
}

TEST_CASE("Fast representability mismatch 2", "[fuzz]") {
    checkFastRepCheckSucceeds(/*pesbt=*/0x9a9a656625629a9d, /*addr=*/0x00100a9a9a9a9a9a,
                              /*expected_base=*/0xfe6a600000000000, /*expected_top=*/0xff95800000000000,
                              /*new_addr=*/0);
}

TEST_CASE("Morello set_addr should tag clear on invalid exponent", "[fuzz]") {
    // Even though the Morello spec CapIsRepresentable function does not take the invalid exponent into account,
    // the CapAdd function will clear the tag for these capabilities.
    auto cap = checkFastRepCheckSucceeds(/*pesbt=*/0x0000000000010004, /*addr=*/0x00000000003fffca,
                                         /*expected_base=*/0x0000000000000000, /*expected_top=*/_CC_MAX_TOP,
                                         /*new_addr=*/0x00000000003fffca, /*set_addr_should_retain_tag=*/false);
    // The exponent is beyond the valid range, but is_representable_with_addr should still return
    // true to match the Morello hardware. This can actually happen due to the settag instruction
    // and was seen in one of the autogenerated Morello tests...
    CHECK(!cap.cr_bounds_valid);
    CHECK(cap.cr_exp > _CC_MAX_EXPONENT);
    CHECK(cap.cr_exp == 51);
}

TEST_CASE("Zero exp cap with sign-changing new addr", "[fuzz]") {
    // Even though the resulting capability is representable with both the fast and the full check, set_addr should
    // detag since the MSB of the bounds changes from zero to one.
    auto cap = checkFastRepCheckSucceeds(/*pesbt=*/0x8000000060020484, /*addr=*/0x0000000000000000,
                                         /*expected_base=*/0x484, /*expected_top=*/0x2002,
                                         /*new_addr=*/0x00ffffffffffe484, /*set_addr_should_retain_tag=*/false);
    CHECK(cap.cr_exp == 0);
}

TEST_CASE("UBSan signed shift out-of-range in fast rep check", "[fuzz]") {
    // Avoid an UBSan error shifting a signed value by more than the bitwidth.
    auto cap = checkFastRepCheckSucceeds(/*pesbt=*/0x8000000000010007, /*addr=*/0x000000000040f0e0,
                                         /*expected_base=*/0, /*expected_top=*/0x4000000000000000,
                                         /*new_addr=*/0xffffffffffffffff);
    CHECK(cap.cr_exp == 48);
}

TEST_CASE("Invalid exponent caps should never be representable", "[fuzz]") {
    // For Morello the representability check should always fail if the input had an invalid exponent.
    // NB: calling the fast representability check directly succeeds since it does not take this into account, but the
    // overall check for IncOffset/SetAddr should fail.
    auto cap =
        checkFastRepCheckSucceeds(/*pesbt=*/0x00000000000000004, /*addr=*/0, /*expected_base=*/0,
                                  /*expected_top=*/_CC_MAX_TOP, /*new_addr=*/0, /*set_addr_should_retain_tag=*/false);
    CHECK(cap.cr_exp == 59);
    CHECK(!cap.cr_bounds_valid);
    // The precise check should also fail:
    CHECK(!TestAPICC::sail_precise_is_representable(cap, 0));
    CHECK(!_cc_N(_precise_is_representable_new_addr)(&cap, 0));
    CHECK(!cc128m_is_representable_with_addr(&cap, 0, /*precise_representable_check=*/true));
    // Calling cc128m_is_representable_with_addr should fail since it checks the exponent validity in addition to the
    // doing the fast representability check.
    CHECK(!cc128m_is_representable_with_addr(&cap, 0, /*precise_representable_check=*/false));
}

TEST_CASE("Invalid exponent caps should never be representable 2", "[fuzz]") {
    // For Morello the representability check should always fail if the input had an invalid exponent.
    // NB: calling the fast representability check directly succeeds since it does not take this into account, but the
    // overall check for IncOffset/SetAddr should fail.
    _cc_addr_t new_addr = 0x909090909090ff16;
    _cc_addr_t expected_base = 0x23f80000000000;
    _cc_length_t expected_top = 0x00080000000000000;
    TestAPICC::cap_t cap = TestAPICC::decompress_raw(0x300000000223ff, 0xff2b55feff39ffff, false);
    CHECK(cap.base() == expected_base);
    CHECK(cap.top() == expected_top);
    CHECK(cap.cr_exp == 40);
    // The fast rep check internal function passes, but actually changing the address will give us different bounds!
    CHECK(TestAPICC::sail_fast_is_representable(cap, new_addr));
    CHECK(_cc_N(_fast_is_representable_new_addr)(&cap, new_addr));
    // Calling is_representable_with_addr() should return false for both fast and precise check since this
    // also checks for the sign bit changing.
    CHECK(!_cc_N(is_representable_with_addr)(&cap, new_addr, /*precise_representable_check=*/false));
    CHECK(!_cc_N(is_representable_with_addr)(&cap, new_addr, /*precise_representable_check=*/true));
    TestAPICC::cap_t modified_cap = TestAPICC::decompress_raw(0x300000000223ff, new_addr, false);
    CHECK(modified_cap.base() == (expected_base | 0xff00000000000000));
    CHECK(modified_cap.top() == (expected_top | 0xff00000000000000));
    CHECK(modified_cap.cr_exp == 40);
}
