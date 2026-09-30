fn main() {
    println!("cargo:rerun-if-changed=../../cheri_compressed_cap.h");
    println!("cargo:rerun-if-changed=../../cheri_compressed_cap_lib.c");
    println!("cargo:rerun-if-changed=../../cheri_compressed_cap_common.h");
    println!("cargo:rerun-if-changed=../../cheri_compressed_cap_macros.h");
    println!("cargo:rerun-if-changed=../../cheri_compressed_cap_64.h");
    println!("cargo:rerun-if-changed=../../cheri_compressed_cap_64r.h");
    println!("cargo:rerun-if-changed=../../cheri_compressed_cap_128.h");
    println!("cargo:rerun-if-changed=../../cheri_compressed_cap_128r.h");
    println!("cargo:rerun-if-changed=../../cheri_compressed_cap_128m.h");

    // Compile cheri_compressed_cap.c
    let mut builder = cc::Build::new();
    builder
        .file("../../cheri_compressed_cap_lib.c")
        .flag_if_supported("-Wno-unused-function")
        // .flag_if_supported("-fno-ms-compatibility")
        .compiler("clang");

    if !builder.get_compiler().is_like_clang() {
        panic!("For interoperability between Rust and C 128-bit types, we assume the Rust and C are both compiled with LLVM.");
    }

    builder.compile("cheri_compressed_cap_lib");
}
