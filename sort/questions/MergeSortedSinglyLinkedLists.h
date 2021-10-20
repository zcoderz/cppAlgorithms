//
// Created by usman on 10/18/21.
//

#ifndef KICK_START_MERGESORTEDSINGLYLINKEDLISTS_H
#define KICK_START_MERGESORTEDSINGLYLINKEDLISTS_H

#endif //KICK_START_MERGESORTEDSINGLYLINKEDLISTS_H

#include <queue>
#include <utility>

using namespace std;

class SinglyLinkedListNode {
public:
    int data;
    SinglyLinkedListNode *next;

    SinglyLinkedListNode(int node_data) {
        this->data = node_data;
        this->next = nullptr;
    }
};

class MergeSortedSinglyLinkedList {

    SinglyLinkedListNode * merge(SinglyLinkedListNode * listA, SinglyLinkedListNode * listB) {
        if (listB == nullptr) return listA;
        if (listA == nullptr) return listB;
        auto * dummy = new SinglyLinkedListNode(0);
        SinglyLinkedListNode * tail = dummy;
        while (listA != nullptr || listB != nullptr) {
            if (listA == nullptr) {
                tail->next = listB;
                break;
            } else if (listB == nullptr) {
                tail->next = listA;
                break;
            } else {
                if (listA->data < listB->data) {
                    tail->next = listA;
                    listA = listA->next;
                } else {
                    tail->next = listB;
                    listB = listB->next;
                }
            }
            tail = tail->next;
        }
        SinglyLinkedListNode  * ret =  dummy->next;
        delete dummy;
        return ret;
    }

    SinglyLinkedListNode* merge_k_lists(vector<SinglyLinkedListNode*> lists) {
        if (lists.empty()) return nullptr;
        int low;
        int high = lists.size()-1;
        while (high != 0) {
            low = 0;
            while (low < high) {
                lists[low] = merge(lists[low], lists[high]);
                low++; high--;
            }
        }
        return lists[0];
    }

    SinglyLinkedListNode* merge_k_lists_pq(vector<SinglyLinkedListNode*> lists) {
        priority_queue<pair<int, int> , vector<pair<int, int>> , greater<pair<int, int>>> pq;
        for (int i =0; i < lists.size(); i++) {
            if (lists[i] == nullptr) continue;
            pq.push(pair<int, int> (lists[i]->data, i) );
        }
        SinglyLinkedListNode * head = nullptr;
        SinglyLinkedListNode * tail = nullptr;
        while (!pq.empty()) {
            pair<int, int> val = pq.top();
            pq.pop();
            SinglyLinkedListNode * temp = lists[val.second];
            if (head == nullptr) {
                head = temp;
            }
            if (tail != nullptr) {
                tail->next = temp;
            }
            lists[val.second] = temp->next;
            tail = temp;
            if (temp->next != nullptr) {
                pq.push(pair<int, int> (temp->next->data, val.second));
            }
        }
        return head;
    }
};