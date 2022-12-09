//
// Created by usman on 11/29/22.
//

#ifndef CPPALGORITHMS_STONEGAMEFOUR_H
#define CPPALGORITHMS_STONEGAMEFOUR_H

#include <cmath>
#include <vector>
using namespace std;
class StoneGameFour {
public:
    bool winnerSquareGameRec(int n, vector<int> & dp) {
        if (dp[n] != -1) return dp[n];
        double sq = sqrt(n);
        if (trunc(sq) == sq) {
            dp[n] = 1;
            return true;
        }
        for (int i = 1; i < sq; i++) {
            int rem = n - pow(i, 2);
            bool res = winnerSquareGameRec(rem, dp);
            if (!res) {
                dp[n] = 1;
                return true;
            }
        }
        dp[n] = 0;
        return false;
    }

    bool winnerSquareGame(int n) {
        vector<int> dp(n+1, -1);
        return winnerSquareGameRec(n, dp);
    }

    bool winnerSquareGameDP(int n) {
        vector<bool> dp(n+1);
        for (int i=n; i >=0; i--) {
            for (int k =1; i+(k*k) <=n; k++) {
                if (!dp[i+k*k]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};

#endif //CPPALGORITHMS_STONEGAMEFOUR_H
