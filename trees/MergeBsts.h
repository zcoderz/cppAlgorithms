//
// Created by usman on 11/3/21.
//

#ifndef CPPALGORITHMS_MERGEBSTS_H
#define CPPALGORITHMS_MERGEBSTS_H

#include "../utils/TreeNode.h"

class MergeBsts {
public:


    void convertBstToList(TreeNode *node, TreeNode *&prev, TreeNode *&head) {
        if (node == nullptr) return;
        //cout << "inside node "  << node->val << endl;
        if (node->left_ptr == nullptr && head == nullptr) {
            //cout << "setting head as"  << node->val << endl;
            head = node;
            prev = node;
            return;
        }
        //cout << node->val << endl;
        convertBstToList(node->left_ptr, prev, head);
        prev->right_ptr = node;
        prev = node;
        convertBstToList(node->right_ptr, prev, head);
    }

    int getCount(TreeNode * node) {
        int ct = 0;
        while (node != nullptr) {
            ct++;
            node = node->right_ptr;
        }
        return ct;
    }

    TreeNode * generateBstFromList(int left, int right, TreeNode * & node) {
        if (left > right) return nullptr;
        int mid = left + (right-left)/2;
        TreeNode * leftN = generateBstFromList(left, mid-1, node);
        TreeNode * currNode = node; node = node->right_ptr;
        TreeNode * rightN = generateBstFromList(mid+1, right, node);
        currNode->left_ptr = leftN;
        currNode->right_ptr = rightN;
        return currNode;
    }

    TreeNode * generateBstFromList(TreeNode * head) {
        int count = getCount(head);
        return generateBstFromList(0, count-1, head);
    }

    void mergeLists(TreeNode *listA, TreeNode *listB, TreeNode *&listMerged) {
        auto * dummy = new TreeNode(0);
        TreeNode * previous = dummy;
        while (listA != nullptr || listB != nullptr) {
            if (listA == nullptr) {
                previous->right_ptr = listB;
                return;
            }
            if (listB == nullptr) {
                previous->right_ptr = listA;
                return;
            }
            if (listA->label < listB->label) {
                previous->right_ptr = listA;
                listA = listA->right_ptr;
            } else {
                previous->right_ptr = listB;
                listB = listB->right_ptr;
            }
            previous = previous->right_ptr;
        }
        listMerged = dummy->right_ptr;
    }

    TreeNode * merge_two_BSTs(TreeNode *root1, TreeNode *root2) {
        TreeNode *listA = nullptr;
        TreeNode *previous=nullptr;
        convertBstToList(root1, previous, listA);

        TreeNode *listB=nullptr;
        previous = nullptr;
        convertBstToList(root2, previous, listB);

        TreeNode *listMerged=nullptr;
        mergeLists(listA, listB, listMerged);

        TreeNode *bst = generateBstFromList(listMerged);
        return bst;
    }
};

#endif //CPPALGORITHMS_MERGEBSTS_H
