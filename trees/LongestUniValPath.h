//
// Created by usman on 11/1/21.
//

#ifndef CPPALGORITHMS_LONGESTUNIVALPATH_H
#define CPPALGORITHMS_LONGESTUNIVALPATH_H
class LongestUniValPath {
public:
    int maxPath =0;
    int longestUnivaluePath(TreeNode* root) {
        processUnivalSubtrees(root);
        return maxPath;
    }

    int processUnivalSubtrees(TreeNode * node) {
        if (node == nullptr) {
            return 0;
        }

        int  left = processUnivalSubtrees(node->left_ptr);
        int  right = processUnivalSubtrees(node->right_ptr);
        int leftTotal = 0;
        if (node->left_ptr != nullptr && (node->left_ptr->label == node->label)) {
            leftTotal += left + 1;
        }
        int rightTotal = 0;
        if (node->right_ptr != nullptr && (node->right_ptr->label == node->label)) {
            rightTotal += right + 1;
        }
        maxPath = max(maxPath, leftTotal + rightTotal);
        return max(rightTotal, leftTotal);
    }
};
#endif //CPPALGORITHMS_LONGESTUNIVALPATH_H
