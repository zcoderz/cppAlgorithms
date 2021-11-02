//
// Created by usman on 11/2/21.
//

#ifndef CPPALGORITHMS_MAXPATHSUM_H
#define CPPALGORITHMS_MAXPATHSUM_H

#include "../utils/TreeNode.h"
#include <limits>

class MaxPathSum {
public:
    int maxPathSumV = std::numeric_limits<int>::min();
    int maxPathSum(TreeNode* root) {
        if (root  == nullptr) return 0;
        maxPathSumInternal(root);
        return maxPathSumV;
    }


    int maxPathSumInternal(TreeNode * node) {
        if (node == nullptr) return 0;
        int leftIncrease = max(maxPathSumInternal(node->left_ptr), 0);
        int rightIncrease = max(maxPathSumInternal(node->right_ptr), 0);
        int sum = leftIncrease + rightIncrease + node->label;
        return max(node->label + rightIncrease, node->label + leftIncrease);
    }
};

#endif //CPPALGORITHMS_MAXPATHSUM_H
