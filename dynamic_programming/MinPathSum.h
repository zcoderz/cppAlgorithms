//
// Created by usman on 10/28/22.
//

#ifndef CPPALGORITHMS_MINPATHSUM_H
#define CPPALGORITHMS_MINPATHSUM_H

#include <vector>
#include <climits>

using namespace std;

class MinPathSum {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        if (cols==0) return 0;
        vector<int> dp(cols), dpPrior(cols, INT_MAX);
        for (int i =0; i < rows; i++) {
            for (int j=0; j < cols; j++) {
                if (j > 0) {
                    dp[j] = min(dp[j - 1], dpPrior[j]) + grid[i][j];
                } else if (i > 0) {
                    dp[j] = dpPrior[j] + grid[i][j]; //for first cols starting from second row and on
                } else {
                    dp[j] = grid[i][j]; //for [0][0]
                }
            }
            swap(dp, dpPrior);
        }
        return dpPrior[rows-1][cols-1];
    }
};

#endif //CPPALGORITHMS_MINPATHSUM_H
