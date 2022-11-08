//
// Created by usman on 11/7/22.
//

#ifndef CPPALGORITHMS_RANGESUMQUERY2D_H
#define CPPALGORITHMS_RANGESUMQUERY2D_H

#include <vector>
#include <memory>
#include <iostream>
using namespace std;

class NumMatrix {
public:
    typedef shared_ptr<vector<vector<int>>> SP;
    SP dp;
    vector<vector<int>> & origMatrix;
    NumMatrix(vector<vector<int>>& matrix)  : origMatrix(matrix){
        int rows = matrix.size();
        int cols = matrix[0].size();
        dp = SP(new vector<vector<int>> (rows+1, vector<int>(cols+1)));
        for (int i =1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                int c = (*dp)[i][j-1];
                int b = (*dp)[i-1][j-1];
                int a = (*dp)[i-1][j];
                int curr = matrix[i-1][j-1];
                (*dp)[i][j] = curr + a + c - b;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int a = (*dp)[row2+1][col2+1];
        int b = (*dp)[row2+1][col1];
        int c = (*dp)[row1][col2+1];
        int d = (*dp)[row1][col1];
        return a-b-c+d;
    }

    static void testMe() {
        vector<vector<int>> matrix = {{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}};
        NumMatrix numMatrix (matrix);

        int res = numMatrix.sumRegion(2, 1, 4, 3);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_RANGESUMQUERY2D_H
