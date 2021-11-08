//
// Created by usman on 11/4/21.
//

#ifndef CPPALGORITHMS_BALANCEDBSTFROMSORTEDARRAYTRYTWO_H
#define CPPALGORITHMS_BALANCEDBSTFROMSORTEDARRAYTRYTWO_H

#endif //CPPALGORITHMS_BALANCEDBSTFROMSORTEDARRAYTRYTWO_H

#include "../utils/TreeNode.h"

#include <stack>
using namespace std;

class BalancedBstFromSortedArrayTryTwo {
public:


    TreeNode * build_balanced_bst(vector<int> vec, int left, int right) {
        if (left > right) return nullptr;
        int mid = left + (right-left)/2;
        TreeNode * theNode = new TreeNode(vec[mid]);
        TreeNode * leftN = build_balanced_bst(vec, left, mid-1);
        TreeNode * rightN = build_balanced_bst(vec, mid+1, right);
        theNode->left_ptr = leftN;
        theNode->right_ptr = rightN;
        return theNode;
    }

    class TempNode {
    public:
        TempNode(TreeNode * node , int leftP, int rightP) : tnode(node), left(leftP), right(rightP){
        }
        TreeNode *tnode;
        int left, right;
    };

    TreeNode * sortedArrayToBST(vector<int> vec) {
        if (left > right) return nullptr;
        stack<TempNode> theStack;
        int left = 0;
        int right = vec.size()-1;
        int mid = left + (right - left) / 2;
        auto * tnode = new TreeNode(vec[mid]);
        TempNode node(tnode, left, right);
        theStack.push(node);
        while (!theStack.empty()) {
            node = theStack.top(); theStack.pop();
            mid = node.left + (node.right-node.left)/2;
            int rightL = mid+1;
            if (node.right >= rightL) {
                int newMid = rightL + (node.right-rightL)/2;
                auto * tempnode = new TreeNode(vec[newMid]);
                node.tnode->right_ptr=tempnode;
                TempNode nodeN(tempnode, rightL, node.right);
                theStack.push(nodeN);
            }
            int lRight = mid-1;
            if (node.left <= lRight) {
                int newMid = node.left + (lRight-node.left)/2;
                auto * tempnode = new TreeNode(vec[newMid]);
                node.tnode->left_ptr=tempnode;
                TempNode nodeN(tempnode, node.left, lRight);
                theStack.push(nodeN);
            }
        }
        return tnode;
    }


    TreeNode * build_balanced_bst(vector<int> a)
    {
        return build_balanced_bst(a, 0, a.size()-1);
    }
};