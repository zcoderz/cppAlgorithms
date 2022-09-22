//
// Created by usman on 9/21/22.
//

#ifndef CPPALGORITHMS_PARTITIONLIST_H
#define CPPALGORITHMS_PARTITIONLIST_H

class PartitionList {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
   };


    static ListNode* partition(ListNode* head, int x) {
        ListNode * partition = head;
        ListNode * prior = head;
        while (partition != nullptr && partition->val < x) {
            prior = partition;
            partition = partition->next;
        }
        if (partition == nullptr) return head; //partition node not found
        if (partition == head) {
            head = head->next; // if partition was the head, move head next
        } else {
            prior->next = partition->next; //adjust list pointers to take partition out
        }

        auto * sentinel = new ListNode; //sentinel to denote start of list
        auto * left = sentinel;
        auto * right = partition;
        ListNode * curr = head;
        while (curr != nullptr) {
            if (curr->val < x) {
                left->next = curr;
                left = curr;
            } else {
                right->next = curr;
                right = curr;
            }
            curr = curr->next;
        }
        left->next = partition; right->next = nullptr;
        ListNode * tmp = sentinel->next;
        delete sentinel;
        return tmp;
    }
};

#endif //CPPALGORITHMS_PARTITIONLIST_H
