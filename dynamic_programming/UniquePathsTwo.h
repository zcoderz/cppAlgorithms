//
// Created by usman on 10/17/22.
//

#ifndef CPPALGORITHMS_UNIQUEPATHSTWO_H
#define CPPALGORITHMS_UNIQUEPATHSTWO_H
#include <vector>
#include <iostream>
using namespace std;
class UniquePathsTwo {
public:
    static int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        if (rows==0) return 0;
        int cols = obstacleGrid[0].size();
        if (cols ==0) return 0;
        vector<int> dp (cols, 0); dp[0]=1;
        for (int i =0; i < rows; i++) {
            for (int j =0; j < cols; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j]=0;
                } else if (j !=0) {
                    dp[j]+=dp[j-1];
                }
            }
        }
        return dp[cols-1];
    }

    static void testMe() {
        vector<vector<int>> obst = {{0,0,0},{0,1,0},{0,0,0}};
        int res = uniquePathsWithObstacles(obst);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_UNIQUEPATHSTWO_H
