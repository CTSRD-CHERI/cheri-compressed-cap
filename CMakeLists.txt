cmake_minimum_required(VERSION 3.10)
project(cheri_compressed_cap C CXX)
set(CMAKE_C_STANDARD_REQUIRED 11)
set(CMAKE_CXX_STANDARD_REQUIRED 14)
if(APPLE AND NOT (CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang"))
    # XXX: ugly hack, would be nice if llvm could find this
    include_directories(SYSTEM /Library/Developer/CommandLineTools/usr/include/c++/v1)
endif()

include(CMakePushCheckState)
include(CheckCCompilerFlag)
include(CheckCXXCompilerFlag)
include(GNUInstallDirs)

macro(check_sanitizer_flag _flag _var)
    cmake_push_check_state()
    set(CMAKE_REQUIRED_LIBRARIES ${_flag})
    # CMAKE_REQUIRED_LINK_OPTIONS needs cmake 3.13
    set(CMAKE_REQUIRED_LINK_OPTIONS ${_flag})
    set(CMAKE_REQUIRED_DEFINITIONS ${_flag})
    set(CMAKE_REQUIRED_FLAGS ${_flag})
    check_cxx_compiler_flag(${_flag} ${_var})
    cmake_pop_check_state()
endmacro()

cmake_push_check_state()
check_sanitizer_flag(-fsanitize=undefined HAVE_UBSAN)
check_sanitizer_flag(-fsanitize=address HAVE_ASAN)
check_sanitizer_flag(-fsanitize=memory HAVE_MSAN)
# XXX: needs instrumented system libraries
set(HAVE_MSAN FALSE)
# Check for libfuzzer compiler support and runtime libraries.
cmake_push_check_state()
set(CMAKE_REQUIRED_LIBRARIES -fsanitize=fuzzer)
set(CMAKE_REQUIRED_DEFINITIONS -fsanitize=fuzzer)
set(CMAKE_REQUIRED_LINK_OPTIONS -fsanitize=fuzzer)
set(CMAKE_REQUIRED_FLAGS -fsanitize=fuzzer)
check_cxx_source_compiles([=[
#include <stddef.h>
#include <stdint.h>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
  (void)Data;
  (void)Size;
  return 0;
}
]=] HAVE_LIBFUZZER)
cmake_pop_check_state()

check_c_compiler_flag(-Wunused-but-set-variable HAVE_UNUSED_BUT_SET_VARIABLE)
if (HAVE_UNUSED_BUT_SET_VARIABLE)
    add_compile_options(-DHAVE_UNUSED_BUT_SET_VARIABLE)
endif()

if (HAVE_UBSAN)
    add_compile_options(-fsanitize=undefined)
    if (${CMAKE_VERSION} VERSION_GREATER 3.12)
        add_link_options(-fsanitize=undefined)
    else()
        link_libraries(-fsanitize=undefined)
    endif()
endif()

add_compile_options(-fno-common)
add_compile_options(-Wall -Wextra -Wno-c11-extensions -Wno-padded -Wno-gnu-statement-expression)
add_compile_options($<$<COMPILE_LANGUAGE:CXX>:-Wno-old-style-cast>
                    $<$<COMPILE_LANGUAGE:CXX>:-Wno-c++98-compat-pedantic>
                    $<$<COMPILE_LANGUAGE:CXX>:-Wno-c++98-c++11-compat-binary-literal>)

# Cannot use -Wpedantic with GCC since that flags use of __int128, so only add it for Clang
if(${CMAKE_CXX_COMPILER_ID} MATCHES "Clang")
    add_compile_options(-Wpedantic)
endif()
check_c_compiler_flag(-Wundef HAVE_WUNDEF)
if (HAVE_WUNDEF)
    add_compile_options(-Werror=undef)
endif()


# TODO: -Weverything
add_library(cheri_compressed_cap14 cheri_compressed_cap.c cheri_compressed_cap.h)

# Test against sail generated C code:
# This needs GMP (and CMake doesn't include a find module)
find_package(PkgConfig)
pkg_check_modules(PC_GMP gmp)
find_path(GMP_INCLUDE_DIR gmp.h
          HINTS ${PC_GMP_INCLUDEDIR} ${PC_GMP_INCLUDE_DIRS}
          PATH_SUFFIXES gmp)
message(STATUS "GMP include dir: ${GMP_INCLUDE_DIR}")
find_library(GMP_LIBRARY NAMES gmp
             HINTS ${PC_GMPL_LIBDIR} ${PC_GMP_LIBRARY_DIRS})
message(STATUS "GMP library: ${GMP_LIBRARY}")

if (NOT GMP_LIBRARY)
    message(FATAL_ERROR "Cannot find GMP library")
endif()
if (NOT GMP_INCLUDE_DIR)
    message(FATAL_ERROR "Cannot find GMP includes")
endif()
add_library(GMP::GMP UNKNOWN IMPORTED)
set_target_properties(GMP::GMP PROPERTIES
  IMPORTED_LOCATION "${GMP_LIBRARY}"
  INTERFACE_INCLUDE_DIRECTORIES "${GMP_INCLUDE_DIR}"
)

function(add_sail_wrapper _format _suffix _sanitizer_flags)
    add_library(sail_wrapper_${_format}${_suffix} STATIC test/sail_wrapper_${_format}.c test/contrib/sail.c test/contrib/sail_failure.c)
    if (_sanitizer_flags)
        target_compile_options(sail_wrapper_${_format}${_suffix} PRIVATE "${_sanitizer_flags}")
        target_link_libraries(sail_wrapper_${_format}${_suffix} PRIVATE "${_sanitizer_flags}")
    endif()
    target_link_libraries(sail_wrapper_${_format}${_suffix} PUBLIC GMP::GMP)  # needs GMP, should propagate to all users
    target_compile_options(sail_wrapper_${_format}${_suffix} PRIVATE -Wno-unused-function -Wno-unused-parameter -Wno-sign-compare -Wno-unused-label -Wno-gnu-binary-literal)
endfunction()

function(add_sail_wrappers _format)
    add_sail_wrapper(${_format} "" "")
    if (HAVE_ASAN)
        add_sail_wrapper(${_format} "-asan-ubsan" "-fsanitize=undefined,address")
    endif()
    if (HAVE_MSAN)
        add_sail_wrapper(${_format} "-msan-ubsan" "-fsanitize=undefined,memory")
    endif()
endfunction()

add_sail_wrappers(64)
add_sail_wrappers(64r)
add_sail_wrappers(128)
add_sail_wrappers(128m)
add_sail_wrappers(128r)


function(add_decompress_cap _format)
    string(TOUPPER ${_format} _format_upper)
    add_executable(decompress_cap_${_format} decompress_cap_common.cpp)
    target_compile_definitions(decompress_cap_${_format} PRIVATE
            CAP_FORMAT=${_format}
            CAP_FORMAT_UPPER=${_format_upper}
    )
    install(TARGETS decompress_cap_${_format} RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
    add_executable(decompress_cap_sail_${_format} decompress_cap_common.cpp)
    target_compile_definitions(decompress_cap_sail_${_format} PRIVATE
            DECOMPRESS_WITH_SAIL_GENERATED_CODE=1
            CAP_FORMAT=${_format}
            CAP_FORMAT_UPPER=${_format_upper}
    )
    target_link_libraries(decompress_cap_sail_${_format} PRIVATE sail_wrapper_${_format})
endfunction()

add_decompress_cap(64)
add_decompress_cap(64r)
add_decompress_cap(128)
add_decompress_cap(128m)
add_decompress_cap(128r)

enable_testing()

# See https://github.com/catchorg/Catch2/blob/devel/docs/cmake-integration.md
Include(FetchContent)
FetchContent_Declare(Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.7.1
)
FetchContent_MakeAvailable(Catch2)
list(APPEND CMAKE_MODULE_PATH ${Catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)

function(add_format_test_definions _target _format)
    target_compile_definitions(${_target} PRIVATE "TEST_CC_FORMAT_LOWER=${_format}")
    target_compile_definitions(${_target} PRIVATE "TEST_CC_FORMAT_UPPER=$<UPPER_CASE:${_format}>")
    if (_format STREQUAL "128m")
        target_compile_definitions(${_target} PRIVATE "TEST_CC_IS_MORELLO")
    elseif (_format STREQUAL "256")
        target_compile_definitions(${_target} PRIVATE "TEST_CC_IS_CHERI256")
    endif()
endfunction()

function(add_cc_test _format _target _suffix _sanitizer_flags)
    add_executable(${_target}_${_format}${_suffix} test/${_target}_${_format}.cpp)
    add_format_test_definions(${_target}_${_format}${_suffix} ${_format})
    if (_sanitizer_flags)
        target_compile_options(${_target}_${_format}${_suffix} PRIVATE "${_sanitizer_flags}")
        target_link_libraries(${_target}_${_format}${_suffix} PRIVATE "${_sanitizer_flags}")
    endif()
    if (NOT _format STREQUAL "256")
        target_link_libraries(${_target}_${_format}${_suffix} PRIVATE sail_wrapper_${_format}${_suffix})
    endif()
    target_link_libraries(${_target}_${_format}${_suffix} PRIVATE Catch2::Catch2WithMain)
    catch_discover_tests(${_target}_${_format}${_suffix})
    add_test(NAME test-${_target}_${_format}${_suffix} COMMAND ${_target}_${_format}${_suffix})
endfunction()

function(add_cc_tests_target _format _target)
    add_cc_test(${_format} ${_target} "" "")
    if (HAVE_ASAN)
        add_cc_test(${_format} ${_target} "-asan-ubsan" "-fsanitize=undefined,address;-fno-sanitize-recover=undefined")
    endif()
    if (HAVE_MSAN)
        add_cc_test(${_format} ${_target} "-msan-ubsan" "-fsanitize=undefined,memory;-fno-sanitize-recover=undefined")
    endif()
endfunction()

function(add_cc_tests _format)
    add_cc_tests_target(${_format} simple_test)
    if (NOT _format STREQUAL "256")
        add_cc_tests_target(${_format} setbounds_test)
        add_cc_tests_target(${_format} random_inputs_test)
    endif()
endfunction()

add_cc_tests(64)
add_cc_tests(64r)
add_cc_tests(128)
add_cc_tests(128m)
add_cc_tests(128r)
add_cc_tests(256)

function(add_fuzz_tests _format)
    if (HAVE_LIBFUZZER)
        if (HAVE_ASAN)
            add_sail_wrapper(${_format} "-fuzzer-asan-ubsan" "-fsanitize=undefined,address,fuzzer;-fno-sanitize-recover=undefined")
            add_executable(fuzz_decompress_${_format}-asan test/fuzz_decompress.cpp)
            add_format_test_definions(fuzz_decompress_${_format}-asan ${_format})
            target_compile_options(fuzz_decompress_${_format}-asan PRIVATE -UNDEBUG)
            target_compile_options(fuzz_decompress_${_format}-asan PRIVATE -fsanitize=undefined,address,fuzzer -fno-sanitize-recover=undefined)
            target_link_libraries(fuzz_decompress_${_format}-asan PRIVATE -fsanitize=undefined,address,fuzzer -fno-sanitize-recover=undefined)
            target_link_libraries(fuzz_decompress_${_format}-asan PRIVATE sail_wrapper_${_format}-fuzzer-asan-ubsan)
        endif()
        if (HAVE_MSAN)
            add_sail_wrapper(${_format} "-fuzzer-msan-ubsan" "-fsanitize=undefined,memory,fuzzer")
            add_executable(fuzz_decompress_${_format}-msan test/fuzz_decompress.cpp)
            add_format_test_definions(fuzz_decompress_${_format}-msan ${_format})
            target_compile_options(fuzz_decompress_${_format}-msan PRIVATE -fsanitize=undefined,memory,fuzzer -fno-sanitize-recover=undefined)
            target_link_libraries(fuzz_decompress_${_format}-msan PRIVATE -fsanitize=undefined,memory,fuzzer -fno-sanitize-recover=undefined)
            target_link_libraries(fuzz_decompress_${_format}-msan PRIVATE sail_wrapper_${_format}-fuzzer-msan-ubsan)
        endif()
    endif()
endfunction()

add_fuzz_tests(64)
add_fuzz_tests(64r)
add_fuzz_tests(128)
add_fuzz_tests(128m)
add_fuzz_tests(128r)
