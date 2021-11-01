//
// Created by usman on 10/31/21.
//

#ifndef CPPALGORITHMS_BINARYTREETRAVERSAL_H
#define CPPALGORITHMS_BINARYTREETRAVERSAL_H

#endif //CPPALGORITHMS_BINARYTREETRAVERSAL_H
#include <vector>
#include "../utils/TreeNode.h"
using namespace std;

class BinaryTreeTraversal {
public:
    vector<int> preorder(TreeNode* root) {
        vector<int> res;
        traverse(root, res);
        return res;
    }

    void traverse(TreeNode * node, vector<int> & res) {
        if (node == nullptr) {
            return;
        }
        res.push_back(node->label);
        traverse(node->left_ptr, res);
        traverse(node->right_ptr, res);
    }
};