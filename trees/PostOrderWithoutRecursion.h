//
// Created by usman on 11/3/21.
//

#ifndef CPPALGORITHMS_POSTORDERWITHOUTRECURSION_H
#define CPPALGORITHMS_POSTORDERWITHOUTRECURSION_H

#include "../utils/TreeNode.h"
#include <vector>
#include <stack>

using namespace std;
class PostOrderWithoutRecursion{
public:
    vector<int> postorder_traversal(TreeNode* root){
        typedef pair<TreeNode*, int> ThePair;
        int NONE_DONE=2;
        int ONE_DONE=1;
        int BOTH_DONE=0;
        stack<ThePair> theStack;
        theStack.push(ThePair(root, NONE_DONE));
        vector<int> res;
        while (!theStack.empty()) {
            if (theStack.top().second == BOTH_DONE) {
                res.push_back(theStack.top().first->label);
                theStack.pop();
            } else {
                ThePair & thePair = theStack.top();
                if (thePair.second == NONE_DONE) {
                    if (thePair.first->left_ptr != nullptr) {
                        theStack.push(ThePair(thePair.first->left_ptr, NONE_DONE));
                    }
                    thePair.second = ONE_DONE;
                } else {
                    if (thePair.first->right_ptr != nullptr) {
                        theStack.push(ThePair(thePair.first->right_ptr, NONE_DONE));
                    }
                    thePair.second = BOTH_DONE;
                }
            }
        }
        return res;
    }
};

#endif //CPPALGORITHMS_POSTORDERWITHOUTRECURSION_H
