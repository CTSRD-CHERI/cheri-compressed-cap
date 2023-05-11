#define TEST_CC_FORMAT_LOWER 128m
#define TEST_CC_FORMAT_UPPER 128M
#define TEST_CC_IS_MORELLO

#include "simple_test_common.cpp"

TEST_CASE("Fast representability check sign extended", "[fuzz]") {
    // Check that the fast representability check properly accounts for Morello sign extension on the address.
    checkRepCheckFails(/*pesbt=*/0xa1a04fffffdff00, /*addr=*/0x01a4fe02410001ff,
                       /*expected_base=*/0xfeff000000000000, /*expected_top=*/0xff3ff80000000000,
                       /*new_addr=*/0);
}

TEST_CASE("Fast representability check zero length", "[fuzz]") {
    // Check that the fast representability check does treat zero length caps as always representable
    // This is not true if the cursor change results in a sign change on the resulting bounds.
    checkRepCheckFails(/*pesbt=*/0xaff000000000000, /*addr=*/0x0080000000800000,
                       /*expected_base=*/0xff80000000800007, /*expected_top=*/0xff80000000800007,
                       /*new_addr=*/0);
}

TEST_CASE("Fast representability zero length no sign change", "[fuzz]") {
    // Check that the fast representability check does treat zero length caps as always representable
    // Even when the sign of the cursor does not change the bounds interpretation could.
    checkRepCheckFails(/*pesbt=*/0xffff000000000000, /*addr=*/0x0029ffffff85ffff,
                       /*expected_base=*/0x0029ffffff860007, /*expected_top=*/0x0029ffffff860007,
                       /*new_addr=*/0);
}

TEST_CASE("Fuzzer-detected fast representability mismatch 1", "[fuzz]") {
    checkFastRepCheckSucceeds(/*pesbt=*/0x81000100ffeeffd2, /*addr=*/0x0045000000000000,
                              /*expected_base=*/0xff40000000000000, /*expected_top=*/0x0ffa0000000000000,
                              /*new_addr=*/0);
}

TEST_CASE("Fast representability mismatch 2", "[fuzz]") {
    checkFastRepCheckSucceeds(/*pesbt=*/0x9a9a656665659a9a, /*addr=*/0x00100a9a9a9a9a9a,
                              /*expected_base=*/0xfe6a600000000000, /*expected_top=*/0xff95800000000000,
                              /*new_addr=*/0);
}
