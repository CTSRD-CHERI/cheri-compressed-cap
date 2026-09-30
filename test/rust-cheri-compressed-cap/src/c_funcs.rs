//! Import C functions.
//! 
//! Normally Rust warns us about using [u128], [i128] in FFI function arguments, because there isn't a well-defined ABI.
//! We initially tried to create a repr(C) struct that matched the ABI, but this seems impossible.
//! Clang (as of LLVM-13) defines [u128],[i128] as built-in types which are passed in two registers.
//! This cannot be replicated exactly by passing a struct - see `clang/lib/CodeGen/TargetInfo.cpp: X86_64ABIInfo::classify()`,
//! and [this godbolt example](https://godbolt.org/z/arn438z77).
//! 
//! Therefore, we instead use Rust native [u128], [i128] under the assumption that
//! 1. Rust is being compiled under LLVM
//! 2. Rust native u128, i128 are represented with LLVM's built-in 128-bit types
//! 3. The C code is also compiled with LLVM, using the built-in 128-bit types.
//! 4. The versions of LLVM used to compile Rust, C are ABI-compatible for 128-bit types.
//! 
//! Assumption 3 may not be necessary - maintaining compatibility with GCC is in Clang's interest, so GCC-compiled C may work just as well.
//! Assumption 4 is difficult to check, we're taking it on faith that LLVM doesn't do anything silly in the future.
//! 
//! Under all these assumptions, we can safely ignore Rust's "improper ctypes" warning.

use crate::CcxBoundsBits;

use paste::paste;

macro_rules! cap_c_funcs {
    ($ver:ident, $mod:path) => { paste! {
        pub(crate) fn [<$ver _compress_raw>](src_cap: *const $mod::Cap) -> $mod::Addr;
        pub(crate) fn [<$ver _decompress_raw>](pesbt: $mod::Addr, cursor: $mod::Addr, tag: bool, out_cap: *mut $mod::Cap);
        pub(crate) fn [<$ver _compress_mem>](src_cap: *const $mod::Cap) -> $mod::Addr;
        pub(crate) fn [<$ver _decompress_mem>](pesbt: $mod::Addr, cursor: $mod::Addr, tag: bool, out_cap: *mut $mod::Cap);

        /* Getters */
        pub(crate) fn [<$ver _get_uperms>](cap: *const $mod::Cap) -> u32;
        pub(crate) fn [<$ver _get_perms>](cap: *const $mod::Cap) -> u32;
        pub(crate) fn [<$ver _get_otype>](cap: *const $mod::Cap) -> u32;
        pub(crate) fn [<$ver _get_reserved>](cap: *const $mod::Cap) -> u8;
        pub(crate) fn [<$ver _get_flags>](cap: *const $mod::Cap) -> u8;

        /* Updaters */
        pub(crate) fn [<$ver _update_uperms>](cap: *mut $mod::Cap, value: $mod::Addr);
        pub(crate) fn [<$ver _update_perms>](cap: *mut $mod::Cap, value: $mod::Addr);
        pub(crate) fn [<$ver _update_otype>](cap: *mut $mod::Cap, value: $mod::Addr);
        pub(crate) fn [<$ver _update_reserved>](cap: *mut $mod::Cap, value: $mod::Addr);
        pub(crate) fn [<$ver _update_flags>](cap: *mut $mod::Cap, value: $mod::Addr);

        /* Misc */
        pub(crate) fn [<$ver _extract_bounds_bits>](pesbt: $mod::Addr) -> CcxBoundsBits;
        pub(crate) fn [<$ver _setbounds>](cap: *mut $mod::Cap, req_len: $mod::FfiLength) -> bool;
        pub(crate) fn [<$ver _is_representable_cap_exact>](cap: *const $mod::Cap) -> bool;
        pub(crate) fn [<$ver _is_representable_new_addr>](sealed: bool, base: $mod::Addr, length: $mod::FfiLength, cursor: $mod::Addr, new_cursor: $mod::Addr) -> bool;
        pub(crate) fn [<$ver _make_max_perms_cap>](base: $mod::Addr, cursor: $mod::Addr, top: $mod::FfiLength) -> $mod::Cap;
        pub(crate) fn [<$ver _get_representable_length>](length: $mod::FfiLength) -> $mod::FfiLength;
        pub(crate) fn [<$ver _get_required_alignment>](length: $mod::FfiLength) -> $mod::FfiLength;
        pub(crate) fn [<$ver _get_alignment_mask>](length: $mod::FfiLength) -> $mod::FfiLength;
    }};
}

#[link(name = "cheri_compressed_cap_lib")]
#[allow(improper_ctypes)]
extern "C" {
    cap_c_funcs!{cc64, crate::caps::cheriv9::cc64}
    cap_c_funcs!{cc64r, crate::caps::rvy::cc64}
    cap_c_funcs!{cc128, crate::caps::cheriv9::cc128}
    cap_c_funcs!{cc128r, crate::caps::rvy::cc128}
    cap_c_funcs!{cc128m, crate::caps::morello}
    // TODO 256
}