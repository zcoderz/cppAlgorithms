//
// Created by usman on 11/29/22.
//

#ifndef CPPALGORITHMS_STONEGAMESTWO_H
#define CPPALGORITHMS_STONEGAMESTWO_H

#include <vector>
#include <numeric>
#include <iostream>
using namespace std;

class StoneGamnesTwo {
public:

    static int calculateGame(vector<int>& piles, vector<vector<int>> & dp, int index, int takeNo, bool  turn) {
        if (index >= piles.size()) return 0;
        if (dp[index][takeNo] != -1) return dp[index][takeNo];
        int maxRet = INT_MIN;
        int sum=0;
        for (int i=0; i < 2*takeNo && i+index < piles.size(); i++) {
            sum += piles[i+index];
            int other =  calculateGame(piles, dp, index+i+1, max(takeNo,i+1), !turn);
            maxRet = max (maxRet, sum-other);
        }
        dp[index][takeNo] = maxRet;
        return maxRet;
    }

    static int stoneGameII(vector<int>& piles) {
        int sum = accumulate(piles.begin(), piles.end(), 0);
        vector<vector<int>> dp(piles.size(), vector<int> (piles.size()+1, -1));
        sum += calculateGame(piles, dp, 0, 1, true);
        return sum/2;
    }

    static void testMe() {
        vector<int> piles = {1};
        int res = stoneGameII(piles);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_STONEGAMESTWO_H
