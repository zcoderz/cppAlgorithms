//
// Created by usman on 11/3/21.
//

#ifndef CPPALGORITHMS_BINARYTREETODOUBLELINKEDLIST_H
#define CPPALGORITHMS_BINARYTREETODOUBLELINKEDLIST_H

#include "../utils/TreeNode.h"

class BinaryTreeToDoubleLinkedList{
public:


    TreeNode * binary_tree_to_cdll(TreeNode* node) {
        if (node == nullptr) return nullptr;
        TreeNode * first = node;
        TreeNode * last = node;

        if (node->left_ptr != nullptr) {
            TreeNode * left = binary_tree_to_cdll(node->left_ptr);
            node->left_ptr = left->left_ptr;
            left->left_ptr->right_ptr=node;
            first=left;
        }

        if (node->right_ptr != nullptr) {
            TreeNode * right = binary_tree_to_cdll(node->right_ptr);
            last = right->left_ptr;
            node->right_ptr=right;
            right->left_ptr=node;
        }

        first->left_ptr = last;
        last->right_ptr = first;

        return first;
    }

    /**
     * this is a tricky one
     * in each call you are merging left <--> node <--> right
     * handle the cases where any or none of left and right are null
     * properly merge the pointers
     * recursion handles the cases automatically
     * @param node
     * @return
     */
    TreeNode* binary_tree_to_cdll_complicated(TreeNode* node){
        if (node == nullptr) return nullptr;
        if (node->left_ptr == nullptr && node->right_ptr== nullptr) {
            node->right_ptr = node;
            node->left_ptr = node;
            return node;
        }
        TreeNode * left = binary_tree_to_cdll(node->left_ptr);
        TreeNode * right = binary_tree_to_cdll(node->right_ptr);

        if (left == nullptr) {
            TreeNode * tail = right->left_ptr;
            tail->right_ptr=node;
            node->left_ptr= tail;
            node->right_ptr= right;
            right->left_ptr=node;
            return node;
        }

        if (right == nullptr) {
            TreeNode * tail = left->left_ptr;
            tail->right_ptr=node;
            node->left_ptr=tail;
            left->left_ptr= node;
            node->right_ptr=left;
            return left;
        }

        TreeNode * tail1 = left->left_ptr;
        TreeNode * tail2 = right->left_ptr;
        tail2->right_ptr=left;
        left->left_ptr= tail2;
        tail1->right_ptr=node;
        node->left_ptr=tail1;

        return left;
    }
};

#endif //CPPALGORITHMS_BINARYTREETODOUBLELINKEDLIST_H
