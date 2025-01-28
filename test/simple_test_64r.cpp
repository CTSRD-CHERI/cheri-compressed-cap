#include "simple_test_common.cpp"

TEST_CASE("bounds encoding, internal exponent, T8 = 1", "[bounds]") {
    /* params are base, cursor, top */
    _cc_cap_t cap = CompressedCap64r::make_max_perms_cap(0x0, 0x1000, 0x8000);

    /*
     * 11 SDP
     * 01001 AP quadrant 1, almighty, integer mode
     * 0000 reserved
     * 0 S
     * 0 EF
     * 1 T8
     * 000000 T[7:2]
     * 00 TE
     * 00000000 B[9:2]
     * 01 BE
     *
     * internal exponent, E = 24 - 0b10001 = 7
     * LCout = 0, LMSB = 1
     * c_t = 0, c_b = 0
     */
    CHECK(cap.cr_pesbt == 0xd2040001);
    cc64r_update_perms(&cap, 0);
    cc64r_update_uperms(&cap, 0);
    CHECK(cap.cr_pesbt == 0x00040001);
}

TEST_CASE("bounds encoding, exponent > 0, T8==0", "[bounds]") {
    _cc_cap_t cap = CompressedCap64r::make_max_perms_cap(0x4C000000, 0x90000000, 0xAC000000);

    /*
     * 00 SDP
     * 01001 AP quadrant 1, almighty, integer mode
     * 0000 reserved
     * 0 S
     * 0 EF
     * 0 T8
     * 101100 T[7:2]
     * 00 TE
     * 01001100 B[9:2]
     * 10 BE
     *
     * internal exponent, E = 24 - 0b00010 = 22
     * LCout = 0, LMSB = 1
     * c_t = 0, c_b = 0
     */
    CHECK(cap.cr_pesbt == 0xd202c132);
    cc64r_update_perms(&cap, 0);
    cc64r_update_uperms(&cap, 0);
    CHECK(cap.cr_pesbt == 0x0002c132);
}

TEST_CASE("bounds encoding, exponent > 0, T8==0, c_b==-1", "[bounds]") {
    _cc_cap_t cap = CompressedCap64r::make_max_perms_cap(0x9F000000, 0xA0000000, 0xAC000000);

    /*
     * 00 SDP
     * 01001 AP quadrant 1, almighty, integer mode
     * 0000 reserved
     * 0 S
     * 0 EF
     * 0 T8
     * 100000 T[7:2]
     * 01 TE
     * 11111000 B[9:2]
     * 01 BE
     *
     * internal exponent, E = 24 - 0b00101 = 19
     * LCout = 1, LMSB = 1
     * A < R is true, B < R is false, T < R is true
     * c_t = 0, c_b = -1
     */
    CHECK(cap.cr_pesbt == 0xd20207e1);
    cc64r_update_perms(&cap, 0);
    cc64r_update_uperms(&cap, 0);
    CHECK(cap.cr_pesbt == 0x000207e1);
}

TEST_CASE("Incorrect bounds bits", "[bounds]") {
    // Regression test: the new format was still using the old V9 correctionTop algorithm.
    constexpr _cc_addr_t input_pesbt = 0x97bd62bc;
    constexpr _cc_addr_t input_cursor = 0xb43a7561;
    auto bounds_bits = TestAPICC::extract_bounds_bits(input_pesbt);
    auto sail_bounds_bits = TestAPICC::sail_extract_bounds_bits(input_pesbt);
    CHECK(bounds_bits == sail_bounds_bits);
    CHECK(bounds_bits.E == 0);
    CHECK(bounds_bits.IE == 0);
    CHECK(bounds_bits.B == 700);
    CHECK(bounds_bits.T == 88); // Previously reported 856
    auto cap = TestAPICC::decompress_raw(input_pesbt, input_cursor, false);
    auto sail_cap = TestAPICC::sail_decode_raw(input_pesbt, input_cursor, false);
    CHECK(cap == sail_cap);
    CHECK(cap.base() == 0x000000b43a72bc);
    // This previously reported top=0x000000000b43a7358 (72bc instead of 7458)
    CHECK(cap.top() == 0x000000000b43a7458);
    CHECK((int64_t)cap.offset() == 0x2a5);
}
