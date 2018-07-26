cmake_minimum_required(VERSION 3.8)
project(cheri_compressed_cap C)
set(CMAKE_C_STANDARD 11)

add_compile_options(-pedantic -Wall -Wextra)
add_library(cheri_compressed_cap cheri_compressed_cap.c cheri_compressed_cap.h)
