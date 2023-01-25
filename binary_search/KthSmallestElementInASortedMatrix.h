//
// Created by usman on 1/24/23.
//

#ifndef CPPALGORITHMS_KTHSMALLESTELEMENTINASORTEDMATRIX_H
#define CPPALGORITHMS_KTHSMALLESTELEMENTINASORTEDMATRIX_H

#include <vector>

using namespace std;

class KthSmallestElementInASortedMatrix {
public:

    /**
     * returns true if there are k or more numbers less or equal than midVal
     * @param matrix
     * @param k
     * @param midVal
     * @return
     */
    bool possible(vector<vector<int>>& matrix, int k, int midVal) {
        int col = matrix[0].size()-1;
        int cnt=0; //tracks the number of items less than or equal to midVal
        //move from 1st row right end down to last row.
        //since columns are sorted ascending, where you break a column on one row, the same column
        //on next row must be same or greater
        for (int i =0; i < matrix.size(); i++) {
            //break when the value in matrix is same or less than midVal
            while (col >=0 && matrix[i][col] > midVal) col--;
            //count number of cells that are equal or less than midVal
            cnt += (col+1);
        }
        //returns true if the number of cells is greater or equal than K
        return cnt >= k;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int col = matrix[0].size()-1;
        int row = matrix.size()-1;

        //left is smaller number , right is larger number. converge left and right.
        int left = matrix[0][0];
        int right = matrix[row][col];
        while (right > left) {
            int mid = left + (right - left) / 2;
            if (possible(matrix, k, mid)) {
                right=mid;
            } else {
                left=mid+1;
            }
        }
        return left;
    }
};

#endif //CPPALGORITHMS_KTHSMALLESTELEMENTINASORTEDMATRIX_H
