//
// Created by usman on 9/19/22.
//

#ifndef CPPALGORITHMS_ODDEVENLIST_H
#define CPPALGORITHMS_ODDEVENLIST_H

class OddEvenList {
    struct ListNode {
             int val;
             ListNode *next;
             ListNode() : val(0), next(nullptr) {}
             ListNode(int x) : val(x), next(nullptr) {}
             ListNode(int x, ListNode *next) : val(x), next(next) {}
         };
public:

    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) return nullptr;
        //keep two separate lists (even and odd lists).
        //move the even and odd lists ahead independently.
        //in the end attach even to odd.
        ListNode* even = head;
        ListNode* odd = head->next;
        ListNode* oddHead = odd;
        //odd is ahead of even, so checking whether odd is not null is sufficient
        while (odd != nullptr) {
            even->next = odd->next;
            if (even->next != nullptr)
                even = even->next;
            odd->next = even->next;
            odd = odd->next;
        }
        even->next = oddHead;
        return head;
    }

};

#endif //CPPALGORITHMS_ODDEVENLIST_H
