//
// Created by usman on 11/8/22.
//

#ifndef CPPALGORITHMS_LARGESTRECTANGLEINHISTOGRAM_H
#define CPPALGORITHMS_LARGESTRECTANGLEINHISTOGRAM_H

#include <vector>
#include <stack>
using namespace std;

class LargestRectangleInHistogram {
    int largestRectangleArea(vector<int>& heights) {
        stack<int> theStack; theStack.push(-1);
        int maxArea = 0;
        for (int i =0; i < heights.size(); i++) {
            while (theStack.top() !=-1 && heights[theStack.top()] >= heights[i]) {
                int theH = heights[theStack.top()]; theStack.pop();
                int width = i-(theStack.top()+1);
                maxArea = max( maxArea, theH * width);
            }
            theStack.push(i);
        }
        while (theStack.top() != -1) {
            int theH = heights[theStack.top()]; theStack.pop();
            int width = heights.size()- (theStack.top()+1);
            maxArea = max( maxArea, theH * width);
        }
        return maxArea;
    }
};

#endif //CPPALGORITHMS_LARGESTRECTANGLEINHISTOGRAM_H
