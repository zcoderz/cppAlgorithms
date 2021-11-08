//
// Created by usman on 11/4/21.
//

#ifndef CPPALGORITHMS_KTHSMALLESTFROMBST_H
#define CPPALGORITHMS_KTHSMALLESTFROMBST_H

#include "../utils/TreeNode.h"
#include <stack>

using namespace std;

class KthSmallestFromBst {
public:

    int itemNo = 0;
    int val = 0;

    bool kth_smallest_element_internal(TreeNode* node, int k) {
        if (node == nullptr) return false;

        bool found = kth_smallest_element_internal(node->left_ptr, k);
        if (found) return found;
        itemNo++;
        if (itemNo ==k) {
            val = node->label;
            return true;
        }
        return kth_smallest_element_internal(node->right_ptr, k);
    }

    int kth_smallest_element_stack(TreeNode* node, int k) {
        if (node == nullptr) return false;
        stack<TreeNode*> theStack;

        while (node != nullptr || !theStack.empty()) {
            while (node != nullptr) {
                theStack.push(node);
                node = node->left_ptr;
            }
            node = theStack.top(); theStack.pop();
            k--;
            if (k ==0) {
                return node->label;
            }
            node = node->right_ptr;
        }
        return -1;
    }

    int kth_smallest_element(TreeNode* node, int k) {
        kth_smallest_element_internal(node, k);
        return val;
    }
};

#endif //CPPALGORITHMS_KTHSMALLESTFROMBST_H
