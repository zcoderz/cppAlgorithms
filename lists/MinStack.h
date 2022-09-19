//
// Created by usman on 9/17/22.
//

#ifndef CPPALGORITHMS_MINSTACK_H
#define CPPALGORITHMS_MINSTACK_H

#include <stack>

using namespace std;
class MinStack {
    stack<int> minValues;
    stack<int> data;
public:
    MinStack() {

    }

    void push(int val) {
        data.push(val);
        if (val < minValues.top() || minValues.empty()) {
            minValues.push(val);
        }
    }

    void pop() {
        int val = data.top(); data.pop();
        if (minValues.top() == val) {
            minValues.pop();
        }
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return minValues.top();
    }
};

#endif //CPPALGORITHMS_MINSTACK_H
