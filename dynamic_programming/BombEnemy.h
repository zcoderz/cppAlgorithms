//
// Created by usman on 10/31/22.
//

#ifndef CPPALGORITHMS_BOMBENEMY_H
#define CPPALGORITHMS_BOMBENEMY_H

#include <vector>
using namespace std;

class BombEnemy {
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        if (cols == 0) return 0;
        vector<int> dpCol(cols);
        int maxEnemies = 0;
        int rowEnemy =0;
        for (int i =0; i < rows; i++) {
            for (int j=0; j < cols; j++) {
                if (j==0 || grid[i][j-1]=='W') {
                    rowEnemy =0;
                    int tmpCol=j;
                    while (tmpCol < cols && grid[i][tmpCol]!='W') {
                        if (grid[i][tmpCol++] =='E')
                            rowEnemy++;
                    }
                }
                if (i==0 || grid[i-1][j]=='W') {
                    dpCol[j]=0;
                    int tmpRow=i;
                    while (tmpRow < rows && grid[tmpRow][j]!='W') {
                        if (grid[tmpRow++][j] =='E')
                            dpCol[j]++;
                    }
                }
                if (grid[i][j]=='0')
                    maxEnemies = max(maxEnemies, rowEnemy + dpCol[j]);
            }
        }
        return maxEnemies;
    }
};
#endif //CPPALGORITHMS_BOMBENEMY_H
