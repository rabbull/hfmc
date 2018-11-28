cmake_minimum_required(VERSION 3.12)
project(huffman_tree)

set(CMAKE_CXX_STANDARD 17)

add_executable(huffman_tree main.cpp navigator/navigator_ui.cpp navigator/navigator_ui.h compress/compress.cpp compress/compress.h extract/common.h extract/extract.cpp extract/extract.h extract/extract_ui.cpp extract/extract_ui.h compress/compress_ui.cpp compress/compress_ui.h huffman.cpp huffman.h common/freq_table.h compress/common.h common/code_table.h compress/huffman_tree.h)