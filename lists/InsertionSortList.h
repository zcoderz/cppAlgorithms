//
// Created by usman on 9/21/22.
//

#ifndef CPPALGORITHMS_INSERTIONSORTLIST_H
#define CPPALGORITHMS_INSERTIONSORTLIST_H
class InsertionSortList {
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

public:
    ListNode* insertionSortList(ListNode* head) {
        //create new ordered list, move items to it. ensure that items in the new list are ordered.
        auto * sentinel = new ListNode();
        ListNode * curr = head;
        while (curr != nullptr) {
            ListNode * prior = sentinel;
            ListNode * nextPos = prior->next;
            while (nextPos != nullptr && nextPos->val < curr->val) {
                //find the position in new list where curr item should go
                prior = nextPos;
                nextPos = nextPos->next;
            }
            ListNode * tmp = curr->next;
            prior->next = curr;
            curr->next = nextPos;
            curr = tmp;
        }
        ListNode * orderedList =  sentinel->next;
        delete sentinel;
        return orderedList;
    }

};
#endif //CPPALGORITHMS_INSERTIONSORTLIST_H
