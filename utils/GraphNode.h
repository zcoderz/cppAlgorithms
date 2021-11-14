//
// Created by usman on 11/14/21.
//

#ifndef CPPALGORITHMS_GRAPHNODE_H
#define CPPALGORITHMS_GRAPHNODE_H
struct GNode
{
    int val;
    vector<GNode *> neighbours;
    GNode(int _val = 0)
    {
        val = _val;
        neighbours.clear();
    }
};
#endif //CPPALGORITHMS_GRAPHNODE_H
