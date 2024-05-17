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
