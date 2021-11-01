//
// Created by usman on 10/31/21.
//

#ifndef CPPALGORITHMS_TREENODE_H
#define CPPALGORITHMS_TREENODE_H

struct TreeNode{
    TreeNode() {}
    TreeNode(int data) {
        label = data;
    }
    int label;
    TreeNode* left_ptr;
    TreeNode* right_ptr;
};

#endif //CPPALGORITHMS_TREENODE_H
