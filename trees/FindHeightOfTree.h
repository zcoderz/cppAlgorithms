//
// Created by usman on 11/4/21.
//

#ifndef CPPALGORITHMS_FINDHEIGHTOFTREE_H
#define CPPALGORITHMS_FINDHEIGHTOFTREE_H
#include "../utils/TreeNodeNArray.h"

class FindHeight {
public:
    int find_height(TreeNodeA * node) {
        if (node  == nullptr || node->children.empty()) return 0;
        int maxHt = 0;
        for (TreeNodeA * child : node->children) {
            int ht = find_height(child);
            maxHt = max(maxHt, ht);
        }
        return maxHt + 1;
    }
};
#endif //CPPALGORITHMS_FINDHEIGHTOFTREE_H
