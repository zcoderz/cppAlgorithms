//
// Created by usman on 11/2/21.
//

#ifndef CPPALGORITHMS_NODE_H
#define CPPALGORITHMS_NODE_H
class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
#endif //CPPALGORITHMS_NODE_H
