//
// Created by usman on 9/16/22.
//

#ifndef CPPALGORITHMS_CLONEBINARYTREE_H
#define CPPALGORITHMS_CLONEBINARYTREE_H

class CloneBinaryTree {
public:
    class BinaryTreeNode {
    public:
        int value;
        BinaryTreeNode *left;
        BinaryTreeNode *right;

        BinaryTreeNode(int value) {
            this->value = value;
            this->left = nullptr;
            this->right = nullptr;
        }
    };


    BinaryTreeNode *clone_tree(BinaryTreeNode *node) {
        if (node == nullptr) return nullptr;
        BinaryTreeNode * theN = new BinaryTreeNode(node->value);
        theN->left = clone_tree(node->left);
        theN->right = clone_tree(node->right);
        return theN;
    }

};
#endif //CPPALGORITHMS_CLONEBINARYTREE_H
