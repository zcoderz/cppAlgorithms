//
// Created by usman on 11/17/21.
//

#ifndef CPPALGORITHMS_UNIQUEPATHS_H
#define CPPALGORITHMS_UNIQUEPATHS_H

#include <vector>

using namespace std;

class UniquePaths {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] ==1) return 0;
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        vector<int> priorRow(cols, 0);
        vector<int> firstCol(rows, 0);

        //update the first row
        for (int i = 0; i < cols; i++) {
            if (obstacleGrid[0][i]==1) {
                //std::fill(priorRow.begin()+i, priorRow.end(),  0);
                break;
            }
            priorRow[i] =1;
        }
        //update the first column
        for (int i = 0; i < rows; i++) {
            if (obstacleGrid[i][0]==1) {
                //std::fill(firstCol.begin()+i, firstCol.end(), 0);
                break;
            }
            firstCol[i] =1;
        }

        for (int i =1 ; i < rows; i++) {
            vector<int> currRow(cols, 0);
            for (int j =1 ; j < cols; j++) {
                if (obstacleGrid[i][j] != 1) {
                    currRow[j] = (j == 1 ? firstCol[i] : currRow[j-1]) + priorRow[j];
                }
            }
            priorRow = move(currRow);
        }

        if (cols ==1) {
            return firstCol[rows-1];
        }

        return priorRow[cols-1];
    }
};

#endif //CPPALGORITHMS_UNIQUEPATHS_H
