//
// Created by usman on 10/29/22.
//

#ifndef CPPALGORITHMS_OUTOFBOUNDPATHS_H
#define CPPALGORITHMS_OUTOFBOUNDPATHS_H

#include <vector>
#include <iostream>
using namespace std;

class OutOfBoundPaths {
public:
    static int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>> dp(m, vector<int>(n)); dp[startRow][startColumn] = 1;
        int outBounds = 0;
        int MOD = 1000000000 + 7;
        while (maxMove > 0) {
            vector<vector<int>> dpTmp(m, vector<int>(n));
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (i==0) outBounds = (outBounds+dp[i][j]) % MOD;
                    if (i==m-1) outBounds = (outBounds + dp[i][j]) % MOD;
                    if (j==0) outBounds = ( outBounds + dp[i][j]) % MOD;
                    if (j==n-1) outBounds  = ( outBounds +  dp[i][j]) % MOD;
                    dpTmp[i][j] = ((( (i > 0) ? dp[i-1][j]: 0) + ( (j > 0) ? dp[i][j-1]: 0)) % MOD + (((i < m-1) ? dp[i+1][j]: 0) +
                                                                                                      ((j < n-1) ? dp[i][j+1] : 0)) % MOD) % MOD ;
                }
            }
            dp = std::move(dpTmp);
            maxMove--;
        }
        return outBounds;
    }

    static void testMe() {
        int res = findPaths(2, 2, 2, 0, 0);
        cout << res << endl;
    }

};

#endif //CPPALGORITHMS_OUTOFBOUNDPATHS_H
