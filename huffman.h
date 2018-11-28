//
// Created by karl on 11/27/18.
//

#ifndef HUFFMAN_TREE_HUFFMAN_H
#define HUFFMAN_TREE_HUFFMAN_H

#include <vector>

class huffman {
private:
    class node {
        int freq;
        std::vector<bool> code;
        node *father;
        node *lhc;
        node *rhc;
    };

    node *root;
};


#endif //HUFFMAN_TREE_HUFFMAN_TREE_H
