//
// Created by karl on 11/27/18.
//

#include <fstream>
#include <map>
#include <iostream>
#include "compress.h"
#include "common.h"
#include "huffman_tree.h"

template <typename __T>
void stat_freq(std::istream &is, bool &single_byte_flag, freq_table<__T> &freq);

template <typename __T>
void build_tree();

void reset_ifstream(std::ifstream &fs, const std::string& path, std::_Ios_Openmode mode);

void compress_mode() {
    std::string path;
    std::cin >> path;
    compress(path);
}

void compress(const std::string &in_path) {
    std::ifstream ifs(in_path, std::ios::in);
    bool single_byte_flag;
    freq_table<short> freq;
    stat_freq<short>(ifs, single_byte_flag, freq);
    reset_ifstream(ifs, in_path, std::ios::in);
    huffman<short> tree;
    tree.build(freq);
    delete &freq;

}

template <typename __T>
void stat_freq(std::istream &is, bool &single_byte_flag, freq_table<__T> &freq) {
    __T temp = 0;
    char buff;
    int n = sizeof (__T) / sizeof (char);
    int cnt = 0;

    while(is.read(&buff, 1)) {
        if (cnt) {
            temp <<= 8;
        }
        cnt += 1;
        temp |= buff;

        if (cnt == n) {
            cnt = 0;
            freq.hit(temp);
            temp = 0;
        }
    }

    single_byte_flag = (cnt != 0);
    if (cnt != 0) {
        while (cnt != n) {
            temp <<= 8;
            cnt += 1;
        }
        freq.hit(temp);
    }
}

void reset_ifstream(std::ifstream &fs, const std::string& path, std::_Ios_Openmode mode) {
    fs.close();
    fs.open(path, mode);
}
