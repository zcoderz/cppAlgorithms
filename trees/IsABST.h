//
// Created by usman on 11/2/21.
//

#ifndef CPPALGORITHMS_ISABST_H
#define CPPALGORITHMS_ISABST_H

#include "../utils/TreeNode.h"

class IsABST {
public:
    bool isBST(TreeNode* root){
        return isBst(root, true);
    }

    bool isBst(TreeNode * node, long min, long max) {
        if (node == nullptr) return true;
        if (node->label > min and node->label < max) {
            return isBst(node->left_ptr, min, node->label) && isBst(node->right_ptr, node->label, max);
        }
        return false;
    }

    pair<bool , int> isBstComplex(TreeNode * node, bool  isLeft) {
        if (node == nullptr) {
            return {true, 0};
        }
        pair<bool, int> left = isBstComplex(node->left_ptr, true);
        pair<bool, int> right = isBstComplex(node->right_ptr, false);
        if (!left.first || !right.first || (node->left_ptr != nullptr && left.second > node->label)
                                           || (node->right_ptr != nullptr && right.second < node->label)) {
            return {false, 0};
        }
        int maxV = 0;
        if (isLeft) {
            maxV = node->right_ptr == nullptr ? node->label : max(node->label, right.second);
        } else {
            maxV = node->left_ptr == nullptr ? node->label : min(node->label, left.second);
        }
        return {true, maxV};
    }
};

#endif //CPPALGORITHMS_ISABST_H
