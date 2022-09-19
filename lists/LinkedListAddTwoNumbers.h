//
// Created by usman on 9/19/22.
//

#ifndef CPPALGORITHMS_LINKEDLISTADDTWONUMBERS_H
#define CPPALGORITHMS_LINKEDLISTADDTWONUMBERS_H

class LinkedListAddTwoNumbers {
    struct ListNode {
             int val;
             ListNode *next;
             ListNode() : val(0), next(nullptr) {}
             ListNode(int x) : val(x), next(nullptr) {}
             ListNode(int x, ListNode *next) : val(x), next(next) {}
         };

    ListNode* addTwoNumbersSimple(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry != 0) {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        return dummyHead->next;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carryOver) {
        if (l1== nullptr && l2== nullptr && carryOver ==0) return nullptr;
        int total = carryOver;
        if (l1 != nullptr) {
            total += l1->val;
        }
        if (l2 != nullptr) {
            total += l2->val;
        }
        int val = total %10;
        ListNode *l1Next = l1== nullptr? l1 : l1->next;
        ListNode *l2Next = l2== nullptr? l2 : l2->next;
        ListNode * next = addTwoNumbers(l1Next, l2Next, total/10);

        auto * currNode = new ListNode(val);
        currNode->next = next;
        return currNode;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addTwoNumbers(l1,l2, 0);
    }
};

#endif //CPPALGORITHMS_LINKEDLISTADDTWONUMBERS_H
