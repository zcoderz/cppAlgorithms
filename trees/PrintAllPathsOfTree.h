//
// Created by usman on 11/2/21.
//

#ifndef CPPALGORITHMS_PRINTALLPATHSOFTREE_H
#define CPPALGORITHMS_PRINTALLPATHSOFTREE_H

#include <vector>

using namespace std;

class PrintAllPathsOfTree {
public:
    vector<vector<int> > allPathsOfABinaryTree(TreeNode* root){
        vector<vector<int>>  res; vector<int> currPath;
        if (root != nullptr) {
            processPrinting(root, res,currPath);
        }
        return res;
    }

    void processPrinting(TreeNode* node, vector<vector<int>> & res, vector<int> currPath) {
        if (node->left_ptr == nullptr && node->right_ptr == nullptr) {
            currPath.push_back(node->label);
            res.push_back(currPath);
            currPath.pop_back();
            return;
        }

        currPath.push_back(node->label);
        if (node->left_ptr != nullptr) {
            processPrinting(node->left_ptr, res, currPath);
        }

        if (node->right_ptr != nullptr) {
            processPrinting(node->right_ptr, res, currPath);
        }

        currPath.pop_back();
    }
 };

#endif //CPPALGORITHMS_PRINTALLPATHSOFTREE_H
