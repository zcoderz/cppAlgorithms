//
// Created by usman on 9/21/22.
//

#ifndef CPPALGORITHMS_REORDERLIST_H
#define CPPALGORITHMS_REORDERLIST_H
class ReorderList {
public:
     struct ListNode {
             int val;
             ListNode *next;
             ListNode() : val(0), next(nullptr) {}
             ListNode(int x) : val(x), next(nullptr) {}
             ListNode(int x, ListNode *next) : val(x), next(next) {}
     };

    static void reorderList(ListNode*& left, ListNode* right, bool  & crossed) {
        if (right == nullptr) return;
        reorderList(left, right->next, crossed);
        if (left == right || left->next == right || crossed) {
            if (!crossed) {
                right->next = nullptr;
                crossed = true;
            }
            return;
        }//bilal was here
        ListNode * tmp = left->next;
        left->next = right;
        left = tmp;
        right->next = left;
    }

    static void reorderList(ListNode* head) {
        ListNode * tmp = head;
        bool crossed = false;
        reorderList(tmp, head, crossed);
    }
};
#endif //CPPALGORITHMS_REORDERLIST_H
