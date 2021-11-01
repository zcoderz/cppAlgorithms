//
// Created by usman on 11/1/21.
//

#ifndef CPPALGORITHMS_SORTEDLISTTOBINARYSEARCHTREE_H
#define CPPALGORITHMS_SORTEDLISTTOBINARYSEARCHTREE_H
#include "../utils/SinglyListNode.h"
#include "../utils/TreeNode.h"

/**
 * https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
 * Excellent question to practice.
 * Recurse in an in order fashion using the size of the list to create the BST tree
 */
class SortedListToBST{

    SinglyLinkedListNode * theNode;
    TreeNode * processBST(int left, int right) {
        if (left > right) return nullptr;
        int mid = left + (right-left) / 2;
        TreeNode * leftNode = processBST(left, mid-1);
        TreeNode * currNode = new TreeNode();
        currNode->label = theNode->data; theNode = theNode->next;
        TreeNode * rightNode = processBST(mid+1, right);
        currNode->left_ptr = leftNode;
        currNode->right_ptr = rightNode;
        return currNode;
    }

    TreeNode* sorted_list_to_bst(SinglyLinkedListNode* head) {
        theNode = head;
        SinglyLinkedListNode* tmp = head;
        int sz = 0;
        while (tmp != nullptr) {
            tmp = tmp->next;
            sz++;
        }
        return processBST(0, sz-1);
    }
};

#endif //CPPALGORITHMS_SORTEDLISTTOBINARYSEARCHTREE_H
