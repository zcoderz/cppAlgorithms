//
// Created by usman on 11/2/21.
//

#ifndef CPPALGORITHMS_UPSIDEDOWN_H
#define CPPALGORITHMS_UPSIDEDOWN_H

/**
 * https://leetcode.com/problems/binary-tree-upside-down/
 * Interesting problem!!!
 * Solidifies recursion concepts very well.
 */
class UpsideDown{
public:
    TreeNode * newNode = nullptr;

    TreeNode * flipUpsideDown(TreeNode* root){
        if(root == nullptr) return nullptr;
        if (root->left_ptr == nullptr) return root;
        flipUpsideDownInternal(root);
        return newNode;
    }

    TreeNode * flipUpsideDownIterative(TreeNode* root){
        if (root == nullptr) {
            return nullptr;
        }
        if (root->left_ptr == nullptr) {
            return root;
        }
        TreeNode* nextL = nullptr;
        TreeNode* nextR = nullptr;
        while (true) {
            TreeNode *nextRoot = root->left_ptr;
            TreeNode *nextLL = root->right_ptr;
            TreeNode *nextRR = root;

            root->left_ptr = nextL;
            root->right_ptr = nextR;

            if (nextRoot== nullptr) {
                return root;
            } else {
                root= nextRoot;
                nextL = nextLL;
                nextR = nextRR;
            }
        }
    }

    void flipUpsideDownInternal(TreeNode* root){
        if (root->left_ptr != nullptr) {
            //recuse down to the last node with a left pointer
            flipUpsideDownInternal(root->left_ptr);
        } else {
            newNode = root;
            return;
        }
        //swap left pointer nodes
        //this is tricky to think about at first. but its not that complicated.
        //you are unwinding on call stack. you are inverting the pointers on the stack unwind
        //by assigning parent nodes as child nodes "root->left_ptr->right_ptr = root;"
        root->left_ptr->left_ptr = root->right_ptr;
        root->left_ptr->right_ptr = root;
        //set the root pointers to null to prevent cycles
        //the root pointers left pointer with get updated correctly
        //automatically during stack unwind in the call stack before current one
        root->left_ptr = nullptr;
        root->right_ptr = nullptr;
    }

};

#endif //CPPALGORITHMS_UPSIDEDOWN_H
