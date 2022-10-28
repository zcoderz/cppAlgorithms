//
// Created by usman on 10/28/22.
//

#ifndef CPPALGORITHMS_LONGESTLINEOFCONSECUTIVEONES_H
#define CPPALGORITHMS_LONGESTLINEOFCONSECUTIVEONES_H

#include <vector>
#include <iostream>
using namespace std;

class LongestLineOfConsecutiveOnes {
public:
    static int longestLine(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        if (cols==0) return 0;
        vector<vector<int>> dp(cols, vector<int>(4)), dpPrior(cols, vector<int>(4));
        //0--horizontal, 1--vertical, 2--diagonal, 3--anti diagonal
        int maxOnes = 0;
        for (int i =0; i < rows; i++) {
            for (int j=0; j < cols; j++) {
                fill_n(dp[j].begin(), dp[j].size(), 0);
                if (mat[i][j]==1) {
                    for (int z =0; z < 4; z++) {
                        if (z==0) {
                            dp[j][0] = (j>0) ? dp[j - 1][0] + 1 : 1;
                        } else if (z==1) {
                            dp[j][1] = (i>0) ? dpPrior[j][1] + 1 : 1;
                        } else if (z==2) {
                            dp[j][2] = (i > 0 && j > 0) ? dpPrior[j-1][2] + 1 : 1;
                        } else if (z==3) {
                            dp[j][3] = (i > 0 && j < cols-1) ? dpPrior[j+1][3] + 1 : 1;
                        }
                    }
                }
                auto it = max_element(std::begin(dp[j]), std::end(dp[j]));
                maxOnes = max(*it, maxOnes);
            }
            swap (dp, dpPrior);
        }
        return maxOnes;
    }

    static void testMe() {
        vector<vector<int>> mat = {{0,1,0},{0,1,0},{0,1,0},{0,1,0},{0,1,0}};
        int v = longestLine(mat);
        cout << v << endl;
    }
};

#endif //CPPALGORITHMS_LONGESTLINEOFCONSECUTIVEONES_H
