//
// Created by usman on 9/16/22.
//

#ifndef CPPALGORITHMS_TREEMIRRORIMAGE_H
#define CPPALGORITHMS_TREEMIRRORIMAGE_H

class TreeMirrorImage {
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


    void mirror_image(BinaryTreeNode *node) {
        if (node == nullptr) return;
        mirror_image(node->left);
        mirror_image(node->right);
        BinaryTreeNode *tmp = node->left;
        node->left = node->right;
        node->right = tmp;
    }

};

#endif //CPPALGORITHMS_TREEMIRRORIMAGE_H
