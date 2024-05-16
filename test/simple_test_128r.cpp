#include "simple_test_common.cpp"

TEST_CASE("Reprentability with TOP>MAX_TOP", "[representable]") {
    auto cap = TestAPICC::make_max_perms_cap(0xffff002d01ffc000, 0xffff002d02013ff6, 0xffff002d027fc000);
    CHECK(cap.cr_pesbt == 0x1f3f00003ff7ff9);
    CHECK(!TestAPICC::sail_precise_is_representable(cap, 0));
    CHECK(!TestAPICC::fast_is_representable_new_addr(cap, 0));
    // The following line used to assert with cdp->_cr_top <= ((cc128_length_t)1u << 64)
    CHECK(!TestAPICC::precise_is_representable_new_addr(cap, 0));
    // Decode a new capability with the same pesbt value and check that the bounds differ (and are > MAX_TOP)
    const _cc_cap_t cap2 = TestAPICC::decompress_raw(cap.cr_pesbt, 0, false);
    CHECK(cap2.base() != cap.base());
    CHECK(cap2.top() != cap.top());
    CHECK(cap2.top() > _CC_MAX_TOP);
    CHECK(cap2.base() == 0xffffffffffffc000);
    CHECK(cap2.top() == (_CC_MAX_TOP | 0x7fc000));
}

TEST_CASE("New adjustment factors", "[bounds]") {
    // Regression test: the new format was still using the old V9 correctionTop algorithm.
    auto cap = TestAPICC::decompress_raw(0xd1ce2baa14c79148, 0x934bb9c2f0eb84d6, false);
    auto sail_cap = TestAPICC::sail_decode_raw(0xd1ce2baa14c79148, 0x934bb9c2f0eb84d6, false);
    CHECK(cap == sail_cap);
    // This previously reported base=0x934bb9c2f0eb5148 (5148 instead of 9148)
    CHECK(cap.base() == 0x934bb9c2f0eb9148);
    // This previously reported top=0x934bb9c2f0eb84d6 (84d6 instead of 931e)
    CHECK(cap.top() == 0x934bb9c2f0eb931e);
    // This previously reported offset=0x338e
    CHECK((int64_t)cap.offset() == -0xc72);
}

TEST_CASE("New adjustment factors 2", "[bounds]") {
    // Regression test: the new format was still using the old V9 correctionTop algorithm.
    // cursor: 0x3e6420dc58fe385b
    auto cap = TestAPICC::decompress_raw(0x1f1da60bcff2c08e, 0x3e6420dc58fe385b, false);
    auto sail_cap = TestAPICC::sail_decode_raw(0x1f1da60bcff2c08e, 0x3e6420dc58fe385b, false);
    CHECK(cap == sail_cap);
    // This previously reported base=0x3e6420dc58fe008e (008e instead of 408e)
    CHECK(cap.base() == 0x3e6420dc58fe408e);
    // This previously reported top=0x3e6420dc58fe0fcb (0fcb instead of 4fcb)
    CHECK(cap.top() == 0x3e6420dc58fe4fcb);
    // This previously reported offset=37cd
    CHECK((int64_t)cap.offset() == -0x833);
}

TEST_CASE("Malformed bounds return zero", "[bounds]") {
    // Regression test: this pesbt value did not report malformed bounds
    auto cap = TestAPICC::decompress_raw(0x5042f7ed6b1027a9, 0, false);
    auto sail_cap = TestAPICC::sail_decode_raw(0x5042f7ed6b1027a9, 0, false);
    CHECK(cap == sail_cap);
    CHECK(!cap.cr_bounds_valid);
    CHECK(cap.base() == 0);
    CHECK(cap.top() == 0);
    CHECK(cap.cr_exp == 51);
}

TEST_CASE("bounds encoding exponent 0", "[bounds]") {
    /* params are base, cursor, top */
    _cc_cap_t cap = CompressedCap128r::make_max_perms_cap(0x0, 0x10, 0x20);

    /*
     * EF == 1 -> exponent 0
     * { T, TE } == 0b0000_0010_0000
     * { B, BE } == 0
     * all of LCout, LMSB, c_t, c_b are 0
     *
     * top == 0x20, base == 0x0
     */
    CHECK(cap.cr_pesbt == 0x01f3f00004080000);
    cc128r_update_perms(&cap, 0);
    cc128r_update_uperms(&cap, 0);
    CHECK(cap.cr_pesbt == 0x0000000004080000);
}

TEST_CASE("bounds encoding exponent > 0", "[bounds]") {
    _cc_cap_t cap = CompressedCap128r::make_max_perms_cap(0x8000, 0x41DF, 0xA6400);

    /*
     * EF == 0 -> internal exponent
     * E = 52 - 45 = 7
     *
     * T[11:3] == 0 1001 1001
     * TE == 101
     * B[13:3] == 000 0010 0000
     * BE == 101
     *
     * LCout = 0, LMSB = 1
     * c_t = 0, c_b = 0
     */
    CHECK(cap.cr_pesbt == 0x01f3f00001334105);
    cc128r_update_perms(&cap, 0);
    cc128r_update_uperms(&cap, 0);
    CHECK(cap.cr_pesbt == 0x0000000001334105);
}
