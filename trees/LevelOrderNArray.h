//
// Created by usman on 10/31/21.
//

#ifndef CPPALGORITHMS_LEVELORDERNARRAY_H
#define CPPALGORITHMS_LEVELORDERNARRAY_H

#endif //CPPALGORITHMS_LEVELORDERNARRAY_H
#include "../utils/TreeNodeNArray.h"

#include <vector>
#include <queue>

class LevelOrderNArray{
public:

    vector<vector<int>> level_order(TreeNodeA* root) {
        if (root== nullptr) return {};
        vector<vector<int>> res;
        queue<TreeNodeA *> theQueue;
        theQueue.push(root);
        while (!theQueue.empty()) {
            vector<int> levelVals;
            int sz = theQueue.size();
            for (int i =0; i < sz; i++) {
                TreeNodeA * node =  theQueue.front(); theQueue.pop();
                levelVals.push_back(node->label);
                vector<TreeNodeA*> child = node->children;
                for (TreeNodeA * theChild : child) {
                    theQueue.push(theChild);
                }
            }
            res.push_back(levelVals);
        }
        return res;
    }
};