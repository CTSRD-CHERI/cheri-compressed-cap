#define TEST_CC_FORMAT_LOWER 128r
#define TEST_CC_FORMAT_UPPER 128R

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
