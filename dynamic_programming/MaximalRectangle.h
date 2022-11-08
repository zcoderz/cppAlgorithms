//
// Created by usman on 11/8/22.
//

#ifndef CPPALGORITHMS_MAXIMALRECTANGLE_H
#define CPPALGORITHMS_MAXIMALRECTANGLE_H

#include <vector>
#include <stack>
using namespace std;

class MaximalRectangle {
public:
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

    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int maxArea = 0;
        for (int k =0; k < rows; k++) {
            vector<int> rowData(cols);
            for (int i =k; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    rowData[j] = (matrix[i][j] == '0' ? 0 : rowData[j] + 1);
                }
                maxArea = max(maxArea, largestRectangleArea(rowData));
            }
        }
        return maxArea;
    }

    static void testMe() {

    }
};

#endif //CPPALGORITHMS_MAXIMALRECTANGLE_H
