//
// Created by usman on 11/1/21.
//

#ifndef CPPALGORITHMS_RIGHTSIDEVIEWOFABINARYTREE_H
#define CPPALGORITHMS_RIGHTSIDEVIEWOFABINARYTREE_H

#include <vector>
#include <unordered_set>

class RightSideViewOfBinaryTree{
public:

    void processRS(TreeNode * node, vector<int> & res, unordered_set<int> & level, int currLevel) {
        if (node == nullptr) {
            return;
        }
        if (level.find(currLevel) == level.end()) {
            res.push_back(node->label);
            level.insert(currLevel);
        }
        processRS(node->right_ptr, res, level, currLevel + 1);
        processRS(node->left_ptr, res, level, currLevel + 1);
    }

    vector<int> right_view(TreeNode* root) {
        vector<int> res;
        unordered_set<int> level;
        processRS(root, res, level, 0);
        return res;
    }


};

#endif //CPPALGORITHMS_RIGHTSIDEVIEWOFABINARYTREE_H
