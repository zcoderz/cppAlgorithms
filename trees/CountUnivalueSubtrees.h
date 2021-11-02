//
// Created by usman on 11/1/21.
//

#ifndef CPPALGORITHMS_COUNTUNIVALUESUBTREES_H
#define CPPALGORITHMS_COUNTUNIVALUESUBTREES_H

class CountUniValueSubTrees {
public:
    int count = 0;

    int countUnivalSubtrees(TreeNode* root) {
        processUnivalSubtrees(root);
        return count;
    }

    bool processUnivalSubtrees(TreeNode * node) {
        if (node == nullptr) {
            return true;
        }
        if (node->left_ptr == nullptr && node->right_ptr == nullptr) {
            count++;
            return true;
        }
        bool  leftUni = processUnivalSubtrees(node->left_ptr);
        bool  rightUni = processUnivalSubtrees(node->right_ptr);
        bool valsSame = node->left_ptr == nullptr || (node->left_ptr->label == node->label);
        valsSame = valsSame & (node->right_ptr == nullptr || (node->right_ptr->label == node->label));

        if (leftUni && rightUni && valsSame) {
            count++;
            return true;
        }
        return false;
    }
};
#endif //CPPALGORITHMS_COUNTUNIVALUESUBTREES_H
