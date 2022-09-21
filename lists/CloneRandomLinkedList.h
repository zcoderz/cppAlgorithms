//
// Created by usman on 9/20/22.
//

#ifndef CPPALGORITHMS_CLONERANDOMLINKEDLIST_H
#define CPPALGORITHMS_CLONERANDOMLINKEDLIST_H

#include <unordered_map>

using namespace std;
class CloneRandomLinkedList {
public:
    class Node {
    public:
        int val;
        Node* next;
        Node* random;

        Node(int _val) {
            val = _val;
            next = nullptr;
            random = nullptr;
        }
    };

    static Node *copyRandomList(Node *head) {
        Node * curr = head;
        while (curr != nullptr) {
            Node * temp = new Node(curr->val);
            temp->next = curr->next;
            curr->next = temp;
            curr = temp->next;
        }
        curr = head;
        while (curr != nullptr) {
            if (curr->random != nullptr) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        curr = head;
        Node * nextHead = curr == nullptr ? nullptr : curr->next;
        while (curr != nullptr) {
            Node * currCpy = curr->next;
            Node * currCpyNext = currCpy->next == nullptr ? nullptr : currCpy->next->next;
            curr->next = curr->next->next;
            curr = curr->next;
            currCpy->next = currCpyNext;
        }
        return nextHead;
    }

    static Node *copyRandomListViaMap(Node *head) {
        Node * curr = head;
        Node * newHead = nullptr;
        unordered_map<Node *, Node *> mapFromOldToNew;
        Node *currCopyNode = nullptr;
        while (curr != nullptr) {
            auto iter = mapFromOldToNew.find(curr);
            Node * temp;
            if (iter != mapFromOldToNew.end()) {
                temp = iter->second;
            }  else {
                temp = new Node(curr->val);
                mapFromOldToNew[curr] = temp;
            }
            Node * rand = curr->random;
            if (rand != nullptr) {
                iter = mapFromOldToNew.find(curr->random);
                if (iter != mapFromOldToNew.end()) {
                    temp->random = iter->second;
                } else {
                    auto * newRandom = new Node(rand->val);
                    mapFromOldToNew[rand] = newRandom;
                    temp->random = newRandom;
                }
            }
            if (newHead == nullptr) {
                newHead = temp;
            }
            if (currCopyNode != nullptr) {
                currCopyNode->next = temp;
            }
            currCopyNode = temp;
            curr = curr->next;
        }
        return newHead;
    }

};
#endif //CPPALGORITHMS_CLONERANDOMLINKEDLIST_H
