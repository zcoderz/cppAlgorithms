//
// Created by usman on 11/20/22.
//

#ifndef CPPALGORITHMS_KNIGHTPROBABILITYINCHESSBOARD_H
#define CPPALGORITHMS_KNIGHTPROBABILITYINCHESSBOARD_H

#include <vector>
using namespace std;

class KnightProbabilityInChessboard {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> dp(n, vector<double> (n));
        vector<vector<int>> moves = {{1,2}, {2,1}, {2,-1}, {1,-2}, {-1,-2}, {-2,-1}, {-2,1}, {-1,2}};
        dp[row][column] = 1;

        while ( k > 0) {
            vector<vector<double>> dp2(n, vector<double> (n));
            for (int i =0; i < n; i++) {
                for (int j =0; j < n; j++) {
                    for (vector<int> & move: moves)  {
                        pair loc = {move[0]+i, move[1]+j};
                        if (loc.first < 0 || loc.first >= n || loc.second < 0 || loc.second >= n ) continue;
                        dp2[loc.first][loc.second] += dp[i][j] / 8;
                    }
                }
            }
            swap(dp2, dp);
            k--;
        }
        double prob = 0;
        for (int i =0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                prob += dp[i][j];
            }
        }
        return prob;
    }
};

#endif //CPPALGORITHMS_KNIGHTPROBABILITYINCHESSBOARD_H
