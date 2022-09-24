//
// Created by USMAN QADIR on 9/15/22.
//

#ifndef CPPALGORITHMS_INORDERBINARYTREEITERATOR_H
#define CPPALGORITHMS_INORDERBINARYTREEITERATOR_H
#include <vector>
using namespace std;
class BinaryTreeNode {
public:
    int value;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int value) {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class InOrderBinaryTreeIterator {
    void inOrderTraversal(BinaryTreeNode * node, vector<int> & data) {
        if (node == nullptr) return;
        inOrderTraversal(node->left, data);
        data.push_back(node->value);
        inOrderTraversal(node->right, data);
    }
public:
    vector<int> implement_tree_iterator(BinaryTreeNode *root, vector<string> &operations) {
        // Write your code here.
        vector<int> res;
        vector<int> data;
        inOrderTraversal(root, data);
        int index =0;
        for (string & op: operations) {
            if (op == "next()") {
                if (index < data.size()) {
                    res.push_back(data[index++]);
                } else res.push_back(0);
            } else {
                if (index < data.size()) {
                    res.push_back(1);
                } else res.push_back(0);
            }
        }
        return res;
    }
};

#endif //CPPALGORITHMS_INORDERBINARYTREEITERATOR_H
