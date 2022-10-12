//
// Created by usman on 10/10/22.
//

#ifndef CPPALGORITHMS_MINPATHSUM_H
#define CPPALGORITHMS_MINPATHSUM_H

#include <vector>
#include <limits>
using namespace std;
class MinPathSum {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (rows ==0) return 0;
        int cols = grid[0].size();

        int MAX = numeric_limits<int>::max();

        for (int i =0; i < rows; i++) {
            for (int j=0; j < cols; j++) {
                int tmpA = MAX, tmpB = MAX;
                if (j != 0) {
                    tmpA = grid[i][j-1];
                }
                if (i > 0) {
                    tmpB = grid[i-1][j];
                }
                if (i ==0 && j ==0) {
                    continue;
                }
                grid[i][j] += min(tmpA, tmpB);
            }
        }
        return grid[rows-1][cols-1];
    }
};

#endif //CPPALGORITHMS_MINPATHSUM_H
