#include "../cheri_compressed_cap.h"
#ifdef __cplusplus
extern "C" {
#endif
void sail_decode_128_mem(cc128_addr_t pesbt, cc128_addr_t cursor, bool tag, cc128_cap_t* cdp);
void sail_decode_128_raw(cc128_addr_t pesbt, cc128_addr_t cursor, bool tag, cc128_cap_t* cdp);
struct cc128_bounds_bits sail_extract_bounds_bits_128(cc128_addr_t pesbt);
cc128_addr_t sail_compress_128_raw(const cap_register_t* csp);
cc128_addr_t sail_compress_128_mem(const cap_register_t* csp);
cc128_addr_t sail_null_pesbt_128(void);

void sail_decode_64_mem(cc64_addr_t pesbt, cc64_addr_t cursor, bool tag, cc64_cap_t * cdp);
void sail_decode_64_raw(cc64_addr_t pesbt, cc64_addr_t cursor, bool tag, cc64_cap_t* cdp);
struct cc64_bounds_bits sail_extract_bounds_bits_64(uint32_t pesbt);
cc64_addr_t sail_compress_64_raw(const cap_register_t* csp);
cc64_addr_t sail_compress_64_mem(const cap_register_t* csp);
cc64_addr_t sail_null_pesbt_64(void);

#ifdef __cplusplus
}
#endif
