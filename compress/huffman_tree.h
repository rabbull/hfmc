//
// Created by karl on 11/28/18.
//

#ifndef HUFFMAN_TREE_HUFFMAN_TREE_H
#define HUFFMAN_TREE_HUFFMAN_TREE_H

#include <algorithm>
#include <vector>
#include <queue>
#include "common.h"

template <typename __T>
class huffman {
private:
    struct node {
        unsigned long long freq = 0;
        node *lhc = nullptr;
        node *rhc = nullptr;
        node *father = nullptr;

        bool is_leaf() {
            return !lhc && !rhc;
        }

        node () = default;
        node (node *lhc, node *rhc) : lhc(lhc), rhc(rhc), freq(lhc->freq + rhc->freq) {}
    };
    
    template <typename _T>
    struct leaf_node : public node {
        _T key;

        explicit leaf_node(std::pair<_T, uint64_t> &p) : key(p.first) {
            this->freq = p.second;
        }
    };
    
    node *root = nullptr;

public:
    void build(freq_table<__T>& freq) {
        if (freq.size() == 1) {
            root = new node;
            root->lhc = new leaf_node(*freq.begin());
        }
        auto cmp = [](node *p, node* q) -> bool {
            return p->freq > q->freq;
        };
        std::priority_queue<node*, std::vector<node*>, decltype(cmp)> roots(cmp);
        for (auto freq_it = freq.begin(); freq_it != freq.end(); ++freq_it) {
            roots.push(new leaf_node(*freq_it));
        }
        while (roots.size() > 1) {
            auto p = roots.top();
            roots.pop();
            auto q = roots.top();
            roots.push(new node(p, q));
        }
        this->root = roots.top();
    }

    void dfs(code_table<__T> &table, node *curr, std::vector<bool>& code) {
        if (curr->is_leaf()) {
            table.setCode(((leaf_node<__T>*)curr)->key, code);
        } else {
            code.push_back(false);
            dfs(table, curr->lhc, code);
            *code.rbegin() = true;
            dfs(table, curr->rhc, code);
            code.resize(code.size() - 1);
        }
    }
    void generate_table_to(code_table<__T> &table) {
        std::vector<bool> code(0);
        dfs(table, root, code);
    }

    void clear(node * curr) {
        if (!curr) {
            return;
        }
        clear(curr -> lhc);
        clear(curr -> rhc);
        delete curr;
    }

    ~huffman() {
        clear(root);
    }
};


#endif //HUFFMAN_TREE_BINTREE_H
