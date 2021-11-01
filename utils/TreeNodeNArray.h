//
// Created by usman on 10/31/21.
//

#ifndef CPPALGORITHMS_TREENODENARRAY_H
#define CPPALGORITHMS_TREENODENARRAY_H

struct TreeNodeA
{
    int label;
    vector<TreeNodeA*> children;
    TreeNodeA(int label)
    {
        this->label = label;
        children.clear();
    }
};

#endif //CPPALGORITHMS_TREENODENARRAY_H
