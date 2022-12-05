//
// Created by usman on 12/4/22.
//

#ifndef CPPALGORITHMS_BINARYTREELONGESTCONSECUTIVESEQUENCETWO_H
#define CPPALGORITHMS_BINARYTREELONGESTCONSECUTIVESEQUENCETWO_H

#include <climits>
#include <utility>
#include <algorithm>
using namespace std;

class BinaryTreeLongestConsecutiveSequenceTwo {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    int maxDist = INT_MIN;
    pair<int, int> processTree(TreeNode* node) {
        if (node == nullptr) return {0,0};
        auto leftP = processTree(node->left);
        auto rightP = processTree(node->right);
        if (node->left != nullptr) {
            if (node->val == node->left->val-1) {
                leftP.second += 1; //increasing
            } else leftP.second = 0;
            if (node->val == node->left->val+1) {
                leftP.first += 1; //decreasing
            } else leftP.first = 0;
        }
        if (node->right != nullptr) {
            if (node->val == node->right->val-1) {
                rightP.second += 1; //increasing
            } else rightP.second = 0;
            if (node->val == node->right->val+1) {
                rightP.first += 1; //decreasing
            } else rightP.first = 0;
        }
        // cout << "node->val ==" << node->val << endl;
        // cout << "left ==" << leftP.first << " , " << leftP.second << endl;
        // cout << "right ==" << rightP.first << " , " << rightP.second << endl;

        maxDist = max (maxDist,max(leftP.first + rightP.second+1, leftP.second + rightP.first+1));
        //cout << "------" << "maxDist == " << maxDist << endl;

        return {max (leftP.first, rightP.first) , max(leftP.second, rightP.second)};
    }

    int longestConsecutive(TreeNode* root) {
        if (root == nullptr) return 0;
        processTree(root);
        return maxDist;
    }
};
#endif //CPPALGORITHMS_BINARYTREELONGESTCONSECUTIVESEQUENCETWO_H
