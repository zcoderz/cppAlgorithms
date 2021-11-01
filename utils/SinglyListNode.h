//
// Created by usman on 11/1/21.
//

#ifndef CPPALGORITHMS_SINGLYLISTNODE_H
#define CPPALGORITHMS_SINGLYLISTNODE_H
class SinglyLinkedListNode {
public:
    int data;
    SinglyLinkedListNode *next;

    SinglyLinkedListNode(int node_data) {
        this->data = node_data;
        this->next = nullptr;
    }
};
#endif //CPPALGORITHMS_SINGLYLISTNODE_H
