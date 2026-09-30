# cheri-compressed-cap ![CI](https://github.com/CTSRD-CHERI/cheri-compressed-cap/workflows/C/C++%20CI/badge.svg)
A C library to compress/decompress CHERI capabilities

See Section 3.4.4 and 3.4.5 of [the instruction set architecture document](https://www.cl.cam.ac.uk/techreports/UCAM-CL-TR-927.pdf) for an explanation of how the compression works.

## Usage instructions
Simply include `cheri_compressed_cap.h` in your C project and you can use the provided functions to compress and decompress your capabilities.

## Usage instructions (Rust)
A Rust wrapper is available in `./test/rust-cheri-compressed-cap/`.
Add the following dependency to your Cargo.toml.

```rust-cheri-compressed-cap = { git = "https://github.com/theturboturnip/cheri-compressed-cap" }```

This package assumes you are using a LLVM-based Rust compiler, and that you have a LLVM-based C compiler installed.
I have not managed to get this working on Windows:
- `cheri_compressed_cap_common.h` relies on standard C behaviour that expands enums to 64-bit if needed.
- MSVC does not comply with this behaviour, and Clang running on Windows tries to emulate this when building for `x86_64-pc-windows-msvc` even with the `-fno-ms-compatibility` flag turned on.
- Switching to the `x86_64-pc-windows-gnu` target results in another compile failure due to a lack of `string.h`, which is likely a skill issue on my part, but I gave up anyway

To get comprehensive documentation, run
```cargo doc --open```

## File Tree Documentation

NOTE: This was written on 20-Feb-2022, may be out of date.

Including `cheri_compressed_cap.h` will include a set of APIs:
- if `CC_IS_MORELLO` is #define-d, it will include APIs for Morello 128-bit compressed capabilities, and legacy 256-bit uncompressed capabilities.
- otherwise, it will include APIs for 64-bit compressed, 128-bit compressed, and legacy 256-bit uncompressed capabilities (which do not include Morello-specific features like extra permission bits).

`cheri_compressed_cap_{64,128}.h` define various lengths and enumerations (permission bits, objects types, etc.) before including the generic `cheri_compressed_cap_{common,macros}.h` files to fill out the API for that configuration.

The public C API for each type of capability includes: (X=capability width, so ccx=cc64 for 64-bit)
- `typedef ... ccx_length_t`, a type that can hold the maximum length encoded in a capability
- `typedef ... ccx_offset_t`, a type that can hold the maxmimum offset into a capability
- `typedef ... ccx_addr_t`, a type that can hold the maximum base address of a capability

- `CCX_PERM_ABC`, bitmasks corresponding to specific permission bits
  - Non-Morello versions include `GLOBAL`, `EXECUTE`, `LOAD`, `STORE`, `LOAD_CAP`, `STORE_CAP`, `STORE_LOCAL`, `SEAL`, `CINVOKE`, `UNSEAL`, `ACCESS_SYS_REGS`, `SETCID`

- `CCX_OTYPE_ABC`, values corresponding to reserved object types
  - Non-Morello versions include `UNSEALED`, `SENTRY`, `RESERVED2`, `RESERVED3`

- `typedef ... ccx_cap_t`, a structure holding all data from a decoded capability
- `typedef ... ccx_bounds_bits`, a structure holding all data for floating-point encoded bounds

- `ccx_addr_t ccx_compress_raw(const ccx_cap_t* src_cap)`
  - Generate the `pesbt` bits for a capability (the top bits which encode permissions, otype, bounds)
- `void ccx_decompress_raw(ccx_addr_t pesbt, ccx_addr_t cursor, bool tag, cap_t* out)`
  - Decompress a (pesbt, cursor) pair with a tag bit into a complete capability type
- `ccx_addr_t ccx_compress_mem(ccx_cap_t* src_cap)`
  - Generate the `pesbt` bits for a capability (the top bits which encode permissions, otype, bounds)
  - XORs `pebst` with a "null mask". I'm unsure what exactly this does, it may prevent it from being interpreted as an object?
- `void ccx_decompress_mem(ccx_addr_t pesbt, ccx_addr_t cursor, bool tag, cap_t* dest_cap)`
  - Decompress a (pesbt, cursor) pair with a tag bit into a complete capability type

- `uint32_t ccx_get_uperms(const ccx_cap_t* cap)`
  - Getter for software-defined permissions
- `uint32_t ccx_get_perms(const ccx_cap_t* cap)`
  - Getter for hardware-defined permissions
- `uint32_t ccx_get_otype(const ccx_cap_t* cap)`
  - Getter for object type
- `uint8_t ccx_get_reserved(const ccx_cap_t* cap)`
  - Getter for reserved-bits
- `uint8_t ccx_get_flags(const ccx_cap_t* cap)`
  - Getter for flags

- `void ccx_update_{uperms,perms,otype,reserved,flags}(ccx_cap_t* cap, ccx_addr_t value)`
  - Updater for various elements in the capability

- `ccx_bounds_bits extract_bounds_bits(ccx_addr_t pesbt)`
  - Extract the floating-point encoded bounds from pesbt
- `bool ccx_setbounds(ccx_cap_t* dest_cap, ccx_length_t req_len)`
  - Set the bounds for a capability to one which includes the range (dest_cap.cursor, dest_cap.cursor+req_len)
  - Returns true if the bounds is exactly represented, or false if the bounds is larger than that
- `bool ccx_is_representable_cap_exact(const ccx_cap_t* src_cap)`
  - Check if the range (base, top) for a capability is exactly encodable with the floating-point value
- `bool ccx_is_representable_new_addr(bool sealed, ccx_addr_t base, ccx_length_t length, ccx_addr_t cursor, ccx_addr_t new_cursor)`
  - Check if a capability with the given parameters would be representable with a change in cursor
- `ccx_cap_t ccx_make_max_perms_cap(ccx_addr_t base, ccx_addr_t cursor, ccx_length_t top)`
  - Generate a capability with maximum permissions for a (base, top) bounds and an address within that bounds
- `ccx_length_t ccx_get_representable_length(ccx_length_t length)`
  - Get the minimum representable length greater than or equal to a specific length
  - if `get_representable_length(l) == l`, the length is exactly representable (when using the correct alignment - see `get_required_alignment`)
- `ccx_length_t ccx_get_required_alignment(ccx_length_t length)`
  - Get the alignment required for a range of some `length` to be exactly represented
- `ccx_length_t ccx_get_alignment_mask(ccx_length_t length)`
  - Get a mask which aligns a range of some `length` such that it is exactly representable
  - Used for `get_representable_length`, `get_required_alignment`.
