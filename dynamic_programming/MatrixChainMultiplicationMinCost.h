//
// Created by usman on 11/7/22.
//

#ifndef CPPALGORITHMS_MATRIXCHAINMULTIPLICATIONMINCOST_H
#define CPPALGORITHMS_MATRIXCHAINMULTIPLICATIONMINCOST_H

#include <vector>
#include <climits>

using namespace std;

class MatrixChainMultiplication {
    //dimensions of the matrix are given by rows in arr[i-1] and columns in arr[i]
    int calculateMatrixMinCost(vector<int> & arr) {
        int sz = arr.size();
        vector<vector<int>> dp(sz, vector<int> (sz, INT_MAX));
        for (int l =2; l < sz; l++) {
            for (int i=1; i <= sz-l; i++) {
                int j = i+l-1;
                for (int k=i; k < j; k++) {
                    //arr[i - 1] identifies starting row
                    //arr[k] signifies current column size
                    //arr[j] signifies ending column size
                    dp[i][j] = min (dp[i][j], dp[i][k] + dp[k+1][j] + arr[i - 1] * arr[k] * arr[j]);
                }
            }
        }
        return dp[1][sz-1];
    }
};
#endif //CPPALGORITHMS_MATRIXCHAINMULTIPLICATIONMINCOST_H
