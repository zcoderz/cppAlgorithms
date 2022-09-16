//
// Created by usman on 9/16/22.
//

#ifndef CPPALGORITHMS_LARGESTBST_H
#define CPPALGORITHMS_LARGESTBST_H

#include <algorithm>
#include <limits>
using namespace std;

class LargestBST {
public:
    struct TreeNode {
             int val;
             TreeNode *left;
             TreeNode *right;
             TreeNode() : val(0), left(nullptr), right(nullptr) {}
             TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
             TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
         };

    /**
     * Creating a struct to manage tree details makes the problem much easier
     */
    struct NodeInfo {
        int minValue = numeric_limits<int>::max();
        int maxValue = numeric_limits<int>::min();
        int numNodes =0;
        bool isBst = true;
    };


    int largestBSTSubtree(TreeNode* node) {
        return largestBSTSubtreeNodeBased(node).numNodes;
    }

    NodeInfo largestBSTSubtreeNodeBased(TreeNode* node) {
        if (node == nullptr) {
            return {};
        }

        //get info for left and right nodes
        auto leftInfo = largestBSTSubtreeNodeBased(node->left);
        auto rightInfo = largestBSTSubtreeNodeBased(node->right);

        if (leftInfo.isBst && rightInfo.isBst && node->val > leftInfo.maxValue && node->val < rightInfo.minValue) {
            //if both left and right nodes are bst and current node is more that max of left node and less than min of right node
            //then this node must also be a bst
            NodeInfo currNodeInfo;
            currNodeInfo.numNodes = leftInfo.numNodes + rightInfo.numNodes+1;
            currNodeInfo.minValue = min(node->val, leftInfo.minValue);
            currNodeInfo.maxValue = max(node->val, rightInfo.maxValue);
            return currNodeInfo;
        }
        //the node is nota  bst. however, return max bst nodes found so far in the recursion
        NodeInfo nodeInfo;
        nodeInfo.isBst = false;
        nodeInfo.numNodes = max(leftInfo.numNodes, rightInfo.numNodes);
        return nodeInfo;
    }


};
#endif //CPPALGORITHMS_LARGESTBST_H
