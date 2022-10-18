//
// Created by USMAN QADIR on 10/17/22.
//

#ifndef CPPALGORITHMS_HOUSEROBBERTHREE_H
#define CPPALGORITHMS_HOUSEROBBERTHREE_H
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

class HouseRobberThree {
     struct TreeNode {
           int val;
           TreeNode *left;
           TreeNode *right;
           TreeNode() : val(0), left(nullptr), right(nullptr) {}
           TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
           TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
     };

    int rob(TreeNode* root) {
        unordered_map<int, pair<int, int>> parentToChildMap;
        queue<pair<int, TreeNode*>> theQueue;
        int index=0;
        theQueue.emplace(index,root);
        vector<int> dataVec; dataVec.push_back(root->val);
        while (!theQueue.empty()) {
            auto [nodeIndex, node] = theQueue.front(); theQueue.pop();
            int leftIndex=-1,rightIndex=-1;
            if(node->left != nullptr) {
                leftIndex = ++index;
                theQueue.push(make_pair(leftIndex, node->left));
                dataVec.push_back(node->left->val);
            }
            if (node->right != nullptr) {
                rightIndex = ++index;
                theQueue.push(make_pair(rightIndex, node->right));
                dataVec.push_back(node->right->val);
            }
            parentToChildMap[nodeIndex] = make_pair(leftIndex, rightIndex);
        }
        vector<int> robberIncluded(index+1);
        vector<int> robberNotIncluded(index+1);
        for (; index >=0; index--) {
            auto [leftC, rightC] = parentToChildMap[index];
            robberIncluded[index] = dataVec[index] + (leftC == -1 ? 0: robberNotIncluded[leftC]) +
                                    (rightC == -1? 0: robberNotIncluded[rightC]);
            robberNotIncluded[index] = ( (leftC == -1 ? 0: max(robberNotIncluded[leftC], robberIncluded[leftC])) +
                                         (rightC == -1 ? 0: max(robberNotIncluded[rightC], robberIncluded[rightC])));
        }
        return max(robberIncluded[0], robberNotIncluded[0]);
    }
};
#endif //CPPALGORITHMS_HOUSEROBBERTHREE_H
