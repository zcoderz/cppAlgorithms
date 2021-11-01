//
// Created by usman on 10/31/21.
//

#ifndef CPPALGORITHMS_DIAMETEROFABINARYTREE_H
#define CPPALGORITHMS_DIAMETEROFABINARYTREE_H
class DiameterofABinaryTree {
public:
    int maxD =0;
    int binary_tree_diameter(TreeNode* root) {
        binary_tree_diameter_local(root);
        return maxD;
    }

    int binary_tree_diameter_local(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = binary_tree_diameter_local(root->left_ptr);
        int right = binary_tree_diameter_local(root->right_ptr);
        maxD = max(maxD, left+right);
        return max(left, right) + 1;
    }
};
#endif //CPPALGORITHMS_DIAMETEROFABINARYTREE_H
