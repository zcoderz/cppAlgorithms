//
// Created by usman on 11/1/21.
//

#ifndef CPPALGORITHMS_ALLPATHSTHATSUMTOK_H
#define CPPALGORITHMS_ALLPATHSTHATSUMTOK_H

#include "../utils/TreeNode.h"
#include <vector>
using namespace std;

class AllPathsThatSumToK{
public:

    void allPathsThatSumToK(TreeNode *node, int currVal, int targetVal, vector<int> & currVec, vector<vector<int>> & res) {
        if (node->left_ptr == nullptr && node->right_ptr == nullptr) {
            currVal += node->label;
            currVec.push_back(node->label);
            if (currVal == targetVal) {
                res.push_back(currVec);
            }
            currVec.pop_back();
            return;
        }
        currVec.push_back(node->label);

        if (node->left_ptr != nullptr) {
            allPathsThatSumToK(node->left_ptr, currVal + node->label, targetVal, currVec, res);
        }

        if (node->right_ptr != nullptr) {
            allPathsThatSumToK(node->right_ptr, currVal + node->label, targetVal, currVec, res);
        }

        currVec.pop_back();
    }

    vector<vector<int>> all_paths_sum_k(TreeNode* root, int k){
        vector<vector<int>> res;
        vector<int> currVec;
        allPathsThatSumToK(root, 0, k, currVec, res);
        return res;
    }
};

#endif //CPPALGORITHMS_ALLPATHSTHATSUMTOK_H
