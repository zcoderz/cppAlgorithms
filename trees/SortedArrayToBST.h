//
// Created by usman on 11/1/21.
//

#ifndef CPPALGORITHMS_SORTEDARRAYTOBST_H
#define CPPALGORITHMS_SORTEDARRAYTOBST_H
#include "../utils/TreeNode.h"
#include <limits>

using namespace std;

class SortedArrayToBST{
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int index = 0;
        return processBST(index, nums, 0, nums.size()-1);
    }

    TreeNode * processBST(int & index, vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int mid = left + (right-left) / 2;
        TreeNode * leftN = processBST(index, nums, left, mid-1);
        TreeNode * root = new TreeNode(nums[index++]);
        TreeNode * rightN = processBST(index, nums, mid+1, right);
        root->left_ptr = leftN;
        root->right_ptr = rightN;
        return root;
    }


};

#endif //CPPALGORITHMS_SORTEDARRAYTOBST_H
