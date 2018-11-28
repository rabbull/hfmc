//
// Created by karl on 11/28/18.
//

#ifndef HUFFMAN_TREE_CODE_TABLE_H
#define HUFFMAN_TREE_CODE_TABLE_H

#include <map>
#include <vector>

template <typename __T>
class code_table {
private:
    std::map<__T, std::vector<bool>> code;

public:
    void setCode(const __T& key, const std::vector<bool> &code) {
        this->code[key] = code;
    }

    std::vector<bool>& getCode(const __T& key) const {
        return this->code[key];
    }
};

#endif //HUFFMAN_TREE_CODE_TABLE_H
