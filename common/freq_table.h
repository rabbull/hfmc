//
// Created by karl on 11/28/18.
//

#ifndef HUFFMAN_TREE_FREQ_TABLE_H
#define HUFFMAN_TREE_FREQ_TABLE_H

#include <cstdint>
#include <map>

template<typename __T>
class freq_table {
private:
    std::map<__T, uint64_t> freq;
    uint64_t total = 0;

public:
    uint64_t getFreq(const __T &key) {
        return freq[key];
    }

    void hit(const __T &key) {
        freq[key] += 1;
        total += 1;
    }

    uint64_t getTotal() {
        return total;
    }

    auto begin() {
        return freq.begin();
    }

    auto end() {
        return freq.end();
    }

    auto size() {
        return freq.size();
    }
};

#endif //HUFFMAN_TREE_FREQ_TABLE_H
