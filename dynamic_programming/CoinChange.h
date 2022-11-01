//
// Created by usman on 11/17/21.
//

#ifndef CPPALGORITHMS_COINCHANGE_H
#define CPPALGORITHMS_COINCHANGE_H
#include <vector>
#include <algorithm>
#include <limits>
#include <climits>
using namespace std;

class CoinChange {
public:

    int coinChange1(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX); dp[0]=0;
        for (int i=1; i <= amount; i++) {
            for (int coin : coins) {
                if (i-coin < 0) continue;
                dp[i] = min(dp[i], (dp[i-coin] == INT_MAX ? INT_MAX : dp[i-coin] + 1));
            }
        }
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> combinations(amount+1, numeric_limits<int>::max());
        sort(coins.begin(), coins.end());
        combinations[0] = 0;
        for (int i =0; i <= amount; i++) {
            for (int coin : coins) {
                if ((i-coin) < 0) break;
                if (combinations[i-coin] == numeric_limits<int>::max()) continue;
                combinations[i] = min(combinations[i], combinations[i-coin] + 1);
            }
        }
        return combinations[amount] == numeric_limits<int>::max() ? -1 : combinations[amount];
    }
};

#endif //CPPALGORITHMS_COINCHANGE_H
