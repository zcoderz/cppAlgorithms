//
// Created by usman on 11/1/21.
//

#ifndef CPPALGORITHMS_BINARYTREEFROMPREORDER_H
#define CPPALGORITHMS_BINARYTREEFROMPREORDER_H

#include "../utils/TreeNode.h"
#include <limits>
#include <stack>

/**
 * https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
 *
 */
class BinaryTreeFromPreOrder {
public:
    TreeNode* build_binary_search_tree(vector<int> preorder) {

        return process(preorder);
    }

    TreeNode * process(vector<int> & preorder) {
        if (preorder.empty()) return nullptr;

        stack<TreeNode*> stack;
        int index = 0;
        TreeNode * root;
        while (index < preorder.size()) {
            int data = preorder[index];
            TreeNode *node = new TreeNode();
            node->label = data;
            if (stack.empty()) {
                stack.push(node);
                root = node;
            } else {
                TreeNode * parent = stack.top();
                while (!stack.empty() && stack.top()->label < data) {
                    parent = stack.top();
                    stack.pop();
                }
                if (parent->label > data) {
                    parent->left_ptr = node;
                } else {
                    parent->right_ptr = node;
                }
                stack.push(node);
            }
            index++;
        }
        return root;
    }

    TreeNode * processR(int low, int right, int & index, vector<int> & preorder) {
        if (index >= preorder.size() || preorder[index] > right || preorder[index] < low) return nullptr;

        int data = preorder[index++];
        TreeNode * node = new TreeNode();
        node->label = data;

        node->left_ptr = processR(low, data, index, preorder);
        node->right_ptr = processR(data, right, index, preorder);

        return node;
    }
};
#endif //CPPALGORITHMS_BINARYTREEFROMPREORDER_H
