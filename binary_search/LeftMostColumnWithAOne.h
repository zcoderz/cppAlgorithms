//
// Created by usman on 1/15/23.
//

#ifndef CPPALGORITHMS_LEFTMOSTCOLUMNWITHAONE_H
#define CPPALGORITHMS_LEFTMOSTCOLUMNWITHAONE_H

#include <vector>
using namespace std;
class LeftMost {
    class BinaryMatrix {
    public:
        int get(int row, int col);
        vector<int> dimensions();
    };

    int binarySearch(BinaryMatrix & binaryMatrix, int right, int row) {
        int left = 0;
        while (right > left) {
            int mid = left + (right-left)/2;
            if (binaryMatrix.get(row, mid)==1) {
                right=mid;
            } else {
                left=mid+1;
            }
        }
        return left;
    }

    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        auto res = binaryMatrix.dimensions();
        int rows = res[0];
        int cols = res[1];
        int leftMost = cols; //start from right end + 1
        for (int i =0; i < rows ; i++) {
            leftMost = binarySearch(binaryMatrix, leftMost, i);
        }
        return leftMost == cols ? -1 : leftMost;
    }
};
#endif //CPPALGORITHMS_LEFTMOSTCOLUMNWITHAONE_H
