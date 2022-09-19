//
// Created by usman on 9/17/22.
//

#ifndef CPPALGORITHMS_LINKEDLISTGROUPREVERSE_H
#define CPPALGORITHMS_LINKEDLISTGROUPREVERSE_H

class LinkedListGroupReverse {

public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    static void reverseSimple(ListNode *head, int k) {
        ListNode * curr = head;
        ListNode * previous = nullptr;
        while (curr) {
            ListNode * tmp = curr->next;
            curr->next = previous;
            previous = curr;
            curr = tmp;
        }
    }

    static ListNode *reverseKGroup(ListNode *head, int k) {
        int count = 0;
        ListNode * stopNode = head;
        ListNode * startNode = head;
        ListNode * priorHead = nullptr;

        while (stopNode != nullptr) {
            count++;
            if (count == k || stopNode->next == nullptr) {
                //skipReverse is if last iteration has fewer than K, don't reverse.
                //bool skipReverse = count != k ;
                ListNode * nextHead = stopNode->next;
                if (priorHead == nullptr) {
                    head = stopNode;
                } else {
                    //if (!skipReverse) {
                    priorHead->next = stopNode;
                    //} else {
                    //    priorHead->next = startNode;
                    //}
                }
                stopNode->next = nullptr;
                //if (!skipReverse) {
                reverseSimple(startNode, k);
                //}
                priorHead = startNode;
                stopNode = nextHead;
                startNode = nextHead;
                count = 0;
            } else {
                stopNode = stopNode->next;
            }
        }
        return head;
    }

    static ListNode *reverse(ListNode *node, int k) {
        ListNode * nextN = node->next;
        for (int i =1; i < k; i++) {
             ListNode * tmp = nextN->next;
             nextN->next = node;
             node = nextN;
             nextN = tmp;
        }
        return node;
    }


    static ListNode *reverseKGroupRecursive(ListNode *head, int k) {
        if (head == nullptr) return nullptr;
        ListNode * node = head;
        int iterations = k;
        while (iterations > 1) {
            node = node->next;
            if (node == nullptr) return head;
            iterations--;
        }
        ListNode * nextNode = node->next;
        ListNode * thisHead = reverse(head, k);
        ListNode * nextHead = reverseKGroupRecursive(nextNode, k);
        head->next = nextHead;
        return thisHead;
    }
};

#endif //CPPALGORITHMS_LINKEDLISTGROUPREVERSE_H
