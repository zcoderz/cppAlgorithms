//
// Created by usman on 10/31/21.
//

#ifndef CPPALGORITHMS_LEVELORDERTRAVERSAL_H
#define CPPALGORITHMS_LEVELORDERTRAVERSAL_H

#include <vector>
#include <queue>
class LevelOrderTraversal {
public:
    vector<vector<int>> level_order_traversal(TreeNode* root) {
        if (root== nullptr) return {};
        vector<vector<int>> res;
        queue<TreeNode *> theQueue;
        theQueue.push(root);
        while (!theQueue.empty()) {
            vector<int> levelVals;
            int sz = theQueue.size();
            for (int i =0; i < sz; i++) {
                TreeNode * node =  theQueue.front(); theQueue.pop();
                levelVals.push_back(node->label);
                if (node->left_ptr != nullptr) {
                    theQueue.push(node->left_ptr);
                }
                if (node->right_ptr != nullptr) {
                    theQueue.push(node->right_ptr);
                }
            }
            res.push_back(levelVals);
        }
        return res;
    }
};

#endif //CPPALGORITHMS_LEVELORDERTRAVERSAL_H
