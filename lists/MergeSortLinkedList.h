//
// Created by usman on 9/19/22.
//

#ifndef CPPALGORITHMS_MERGESORTLINKEDLIST_H
#define CPPALGORITHMS_MERGESORTLINKEDLIST_H

class MergeSortLinkedList {


public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    static ListNode * sortListIterative(ListNode * head) {
        if (head== nullptr || head->next== nullptr) return head;

        ListNode * mid = split(head);
        ListNode * nextHalf = mid->next;
        mid->next = nullptr;

        ListNode * leftList = sortList(head);
        ListNode * rightList = sortList(nextHalf);

        return merge(leftList, rightList);
    }

    static ListNode * sortList(ListNode * head) {
        if (head== nullptr || head->next== nullptr) return head;

        ListNode * mid = split(head);
        ListNode * nextHalf = mid->next;
        mid->next = nullptr;

        ListNode * leftList = sortList(head);
        ListNode * rightList = sortList(nextHalf);

        return merge(leftList, rightList);
    }

    static ListNode * merge(ListNode * list1, ListNode * list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        ListNode * head, * curr;
        if (list1->val < list2->val) {
            head = list1;
            curr = list1;
            list1 = list1->next;
        } else {
            head = list2;
            curr = list2;
            list2 = list2->next;
        }

        while (list1 != nullptr || list2 != nullptr) {
            if (list1 == nullptr) {
                curr->next= list2;
                return head;
            }
            if (list2 == nullptr) {
                curr->next= list1;
                return head;
            }
            if (list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        return head;
    }


    static ListNode * split(ListNode * head) {
        if (head == nullptr) return head;
        auto slow = head;
        auto fast = head->next;

        while (fast != nullptr) {
            fast = fast->next;
            if (fast != nullptr) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        return slow;
    }

    static ListNode * mergeRecursive(ListNode * list1, ListNode * list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        ListNode * result;
        ListNode * next;
        if (list1->val < list2->val) {
            result = list1;
            next = mergeRecursive(list1->next, list2);
        } else {
            result = list2;
            next = mergeRecursive(list1, list2->next);
        }
        result->next = next;
        return result;
    }

};

#endif //CPPALGORITHMS_MERGESORTLINKEDLIST_H
