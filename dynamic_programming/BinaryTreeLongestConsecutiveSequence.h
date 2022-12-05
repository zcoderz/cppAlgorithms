//
// Created by usman on 12/4/22.
//

#ifndef CPPALGORITHMS_BINARYTREELONGESTCONSECUTIVESEQUENCE_H
#define CPPALGORITHMS_BINARYTREELONGESTCONSECUTIVESEQUENCE_H

#include "../utils/TreeNode.h"
#include <algorithm>
#include <cstdlib>
#include <climits>

using namespace std;
class BinaryTreeLongestConsecutiveSequence {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    int maxLength = INT_MIN;

    void longestConsecutive(TreeNode* node, int priorV, bool left, int len) {
        if (node == nullptr) return;

        int lenPlusOne = node->val == priorV+1 ? len + 1 : 1;

        maxLength = max(maxLength, lenPlusOne);
        //int nextLen = left ? lenPlusOne : 1;
        longestConsecutive(node->left, node->val, true, lenPlusOne);

        //nextLen = left ? 1 : lenPlusOne;
        longestConsecutive(node->right, node->val, false, lenPlusOne);
    }

    int longestConsecutive(TreeNode* root) {
        if (root == nullptr) return 0;
        longestConsecutive(root, root->val, true, 1);
        return maxLength;
    }
};

#endif //CPPALGORITHMS_BINARYTREELONGESTCONSECUTIVESEQUENCE_H
