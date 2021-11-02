//
// Created by usman on 11/1/21.
//

#ifndef CPPALGORITHMS_PATHSEQUALTOTARGET_H
#define CPPALGORITHMS_PATHSEQUALTOTARGET_H

#include "../utils/TreeNode.h"
#include <unordered_map>

using namespace std;

class PathsEqualToTarget {
public:
    unordered_map<int, int> theMap;
    int count = 0;

    int pathSum(TreeNode* node, int targetSum) {
        theMap[0]=1;
        pathSum(node, targetSum, 0);
        return count;
    }
    void pathSum(TreeNode* node, int targetSum, int currSum) {
        if (node == nullptr) return;
        int val = currSum + node->label;
        auto iter = theMap.find(currSum-targetSum);
        if (iter != theMap.end()) {
            count += iter->second;
        }
        int ct = theMap[val];
        theMap[val] = ct + 1;
        pathSum(node->left_ptr, targetSum, val);
        pathSum(node->right_ptr, targetSum, val);
        if (ct == 0) {
            theMap.erase(val);
        } else {
            theMap[val] = ct;
        }
    }
};

#endif //CPPALGORITHMS_PATHSEQUALTOTARGET_H
