//
// Created by usman on 11/22/22.
//

#ifndef CPPALGORITHMS_LASTSTONEWEIGHTTWO_H
#define CPPALGORITHMS_LASTSTONEWEIGHTTWO_H

#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;

class LastStoneWeightTwo {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum/2;
        int noOfStones = stones.size();
        vector<vector<int>> dp(noOfStones+1, vector<int> (target+1));
        for (int i =1; i <= noOfStones; i++) {
            for (int j =1; j <= target; j++) {
                if (stones[i-1] > j) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-stones[i-1]] + stones[i-1]);
                }
            }
        }

        return sum - 2 * dp[noOfStones][target];
    }
};
#endif //CPPALGORITHMS_LASTSTONEWEIGHTTWO_H
