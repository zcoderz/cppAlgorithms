//
// Created by usman on 1/18/23.
//

#ifndef CPPALGORITHMS_KTHSMALLESTINMULTIPLICATIONTABLE_H
#define CPPALGORITHMS_KTHSMALLESTINMULTIPLICATIONTABLE_H

#include <algorithm>
using namespace std;

class KthSmallestInMultiplicationTable {

    /**
     * The query asks what is the kth largest number in the matrix table.
     * In 3x3 matrix data looks as
     *   1 2 3
     * 1 1 2 3
     * 2 2 4 6
     * 3 3 6 9
     * -------
     * if you are searching for the 7th largest number in the matrix
     * you can do a binary search over range 1 to m*n
     * say if you search for 6
     * in first row you see, min(6/1, 3) = 3 values
     * in second row you see min(6/2, 3) = 3 values
     * in 3rd row you see min (6/2, 3) = 2 values
     * hence 6 is the 8th smallest number
     * if you pick 5, you will get 6 numbers smaller than it,
     * hence you will converge towards 6 in binary search
     * @param numToCheck
     * @param rows
     * @param cols
     * @param kthNum
     * @return
     */
    bool possible(int numToCheck, int rows, int cols, int kthNum) {
        int count = 0;
        for (int row =1; row <= rows; row++) {
            count += min(numToCheck/row, cols);
        }
        return count >= kthNum;
    }

    int findKthNumber(int m, int n, int k) {
        int low = 1;
        int high = m*n;
        while (low < high) {
            //round the mid down 0,1 gets rounded to 0.
            //hence when mid doesn't match, move low up
            int mid = low + (high-low) /2;
            if(possible(mid, m, n, k)) {
                high = mid;
            } else {
                low=mid+1;
            }
        }
        return low;
    }
};

#endif //CPPALGORITHMS_KTHSMALLESTINMULTIPLICATIONTABLE_H
