//
// Created by usman on 12/5/22.
//

#ifndef CPPALGORITHMS_LARGESTBSTSUBTREE_H
#define CPPALGORITHMS_LARGESTBSTSUBTREE_H

#include <climits>
#include <algorithm>
#include <iostream>
#include <utility>
#include <tuple>
using namespace std;

/**
 * This problem is much more tricky than it seems at first.
 * The trick is that for each node you need to return back to caller :
 * ---- Whether it forms a binary tree
 * ---- Maximum number of BST nodes under and including that node
 * ---- The minimum value under and including that node
 * ---- The maximum value under and including that node
 *
 * Cant solve this problem if you look from the node down to right or left children only because
 * to follow a BST property the entire BST on left and right must conform based on the node in parent
 * and it conforms based on the MIN AND MAX values under that tree!!!!
 */
class LargestBSTSubtree {
     struct TreeNode {
             int val;
             TreeNode *left;
             TreeNode *right;
             TreeNode() : val(0), left(nullptr), right(nullptr) {}
             TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
             TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
         };

public:

    tuple<bool, int, int, int> processTree(TreeNode* node, int minV, int maxV) {
        if (node == nullptr) {
            //isBst,NoNodes,MinValue,MaxValue
            return {true, 0, INT_MAX, INT_MIN};
        }
        auto [leftIsBst, leftNodes, leftMin, leftMax] = processTree(node->left, minV, node->val);
        auto [rightIsBst, rightNodes, rightMin, rightMax] = processTree(node->right, node->val, maxV);
        if (leftIsBst && (node->left == nullptr || node->val > leftMax) &&
            (rightIsBst&& (node->right == nullptr || rightMin > node->val))) {
            return {true, leftNodes+rightNodes+1, min(leftMin, node->val), max(rightMax, node->val)};
        }
        return {false, max(leftNodes, rightNodes), INT_MAX, INT_MIN};
    }

    int largestBSTSubtree(TreeNode* root) {
        auto [isBst, maxNodes, leftMin, leftMax]  = processTree(root, INT_MIN, INT_MAX);
        return maxNodes;
    }
};

#endif //CPPALGORITHMS_LARGESTBSTSUBTREE_H
