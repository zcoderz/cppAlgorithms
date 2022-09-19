//
// Created by usman on 9/17/22.
//

#ifndef CPPALGORITHMS_LONGESTVALIDPARENTHESES_H
#define CPPALGORITHMS_LONGESTVALIDPARENTHESES_H


#include <stack>
#include <string>
using namespace std;
class LongestValidParentheses {
public:

    int longestValidParentheses(string s) {

        int left=0, right = 0;
        int maxBalanced = 0;

        for (int i =0; i < s.length(); i++) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
                if (left == right) {
                    maxBalanced = max(maxBalanced, 2*left);
                }
                if (right > left) {
                    left = 0; right = 0;
                }
            }
        }
        left = 0; right = 0;
        for (int i = s.length()-1; i >=0 ; i--) {
            if (s[i] == ')') {
                right++;
            } else {
                left++;
                if (left == right) {
                    maxBalanced = max(maxBalanced, 2*left);
                }
                if (left > right) {
                    left = 0; right = 0;
                }
            }
        }
        return maxBalanced;
    }

    int longestValidParenthesesStackOne(string s) {
        stack<int> theStack;
        int maxBalanced = 0;
        theStack.push(-1);
        for (int i =0; i < s.length(); i++) {
            if (s[i] == '(') {
                theStack.push(i);
            } else {
                theStack.pop();
                if (!theStack.empty()) {
                    maxBalanced = max(maxBalanced, i - theStack.top());
                } else {
                    theStack.push(i);
                }
            }
        }
        return maxBalanced;
    }

    int longestValidParenthesesStackTwo(string s) {
        stack<int> theStack;
        int maxBalanced = 0;
        int validFrom = -1;
        for (int i =0; i < s.length(); i++) {
            if (s[i] == '(') {
                theStack.push(i); //push open index
            } else {
                if (!theStack.empty()) {
                    theStack.pop(); //pop last open index
                    //if the stack is empty then take start from prior valid from
                    //so that we can capture total for patters such as ()()
                    int iStartIndex = theStack.empty() ? validFrom : theStack.top();
                    maxBalanced = max(maxBalanced, i - iStartIndex);
                } else {
                    validFrom = i; //move the valid from forward on every mismatch
                }
            }
        }
        return maxBalanced;
    }
};
#endif //CPPALGORITHMS_LONGESTVALIDPARENTHESES_H
