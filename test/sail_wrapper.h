#include "../cheri_compressed_cap.h"
#ifdef __cplusplus
extern "C" {
#endif
void sail_decode_128_mem(cc128_addr_t pesbt, cc128_addr_t cursor, bool tag, cc128_cap_t* cdp);
void sail_decode_128_raw(cc128_addr_t pesbt, cc128_addr_t cursor, bool tag, cc128_cap_t* cdp);
struct cc128_bounds_bits sail_extract_bounds_bits_128(cc128_addr_t pesbt);
cc128_addr_t sail_compress_128_raw(const cc128_cap_t* csp);
cc128_addr_t sail_compress_128_mem(const cc128_cap_t* csp);
cc128_addr_t sail_null_pesbt_128(void);

void sail_decode_64_mem(cc64_addr_t pesbt, cc64_addr_t cursor, bool tag, cc64_cap_t * cdp);
void sail_decode_64_raw(cc64_addr_t pesbt, cc64_addr_t cursor, bool tag, cc64_cap_t* cdp);
struct cc64_bounds_bits sail_extract_bounds_bits_64(uint32_t pesbt);
cc64_addr_t sail_compress_64_raw(const cc64_cap_t* csp);
cc64_addr_t sail_compress_64_mem(const cc64_cap_t* csp);
cc64_addr_t sail_null_pesbt_64(void);

#ifdef __cplusplus
}

class TestAPI128 : public CompressedCap128 {
    static inline void sail_decode_mem(addr_t pesbt, addr_t cursor, bool tag, cap_t* cdp) {
        return sail_decode_128_mem(pesbt, cursor, tag, cdp);
    }
    static inline void sail_decode_raw(addr_t pesbt, addr_t cursor, bool tag, cap_t* cdp) {
        return sail_decode_128_raw(pesbt, cursor, tag, cdp);
    }
    static inline bounds_bits sail_extract_bounds_bits(addr_t pesbt) { return sail_extract_bounds_bits_128(pesbt); }
    static inline addr_t sail_compress_raw(const cap_t* csp) { return sail_compress_128_raw(csp); }
    static inline addr_t sail_compress_mem(const cap_t* csp) { return sail_compress_128_mem(csp); }
    static inline addr_t sail_null_pesbt() { return sail_null_pesbt_128(); }
};

class TestAPI64 : public CompressedCap64 {};
#endif
