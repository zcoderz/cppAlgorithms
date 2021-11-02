//
// Created by usman on 11/1/21.
//

#ifndef CPPALGORITHMS_BSTFROMINORDERANDPOSTORDERTRAVERSAL_H
#define CPPALGORITHMS_BSTFROMINORDERANDPOSTORDERTRAVERSAL_H
#include "../utils/TreeNode.h"

class BinaryTreeFromInorderAndPostOrderTraversal {
public:
    unordered_map<int, int> itemCords;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i =0; i < inorder.size(); i++) {
            itemCords[inorder[i]] = i;
        }
        int currPostOrderIndex = postorder.size()-1;
        return processPostOrderTraversal(postorder, 0, inorder.size()-1, currPostOrderIndex);
    }

    TreeNode * processPostOrderTraversal(vector<int> & postorder, int left, int right, int & index) {
        if (left > right || index >= postorder.size()) return nullptr;
        int inOrderIndex = itemCords.find(postorder[index])->second;
        //out of bounds
        if (inOrderIndex < left || inOrderIndex > right) return nullptr;
        int val = postorder[index--];
        TreeNode * midNode = new TreeNode(val);
        TreeNode * rightNode = processPostOrderTraversal(postorder, inOrderIndex+1, right, index);
        TreeNode * leftNode = processPostOrderTraversal(postorder, left, inOrderIndex-1, index);
        midNode->left_ptr = leftNode;
        midNode->right_ptr = rightNode;
        return midNode;
    }
};

#endif //CPPALGORITHMS_BSTFROMINORDERANDPOSTORDERTRAVERSAL_H
