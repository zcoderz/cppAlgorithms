//
// Created by usman on 11/23/21.
//

#ifndef CPPALGORITHMS_MINCOSTTOCUTSTICKS_H
#define CPPALGORITHMS_MINCOSTTOCUTSTICKS_H

#include <limits>

using namespace std;
class MinCostToCutSticks {
public:

    int minCost(int n, vector<int> & cuts) {
        //add sentinels
        cuts.push_back(0);
        cuts.push_back(n);
        //sort cuts so you can process them in order from right to left
        sort(begin(cuts), end(cuts));
        vector<vector<int>> dp(cuts.size(), vector<int>(cuts.size(), 0));
        for (int left = cuts.size() - 1; left >= 0; left--) {
            for (int right = left+1; right < cuts.size() ; right++) {
                //find the min cost to process between cuts left and right
                for (int cutPoint = left+1; cutPoint < right; cutPoint++) {
                    int cost = cuts[right] - cuts[left];
                    // recursively call left side and right side
                    int remaining = dp[left][cutPoint] + dp[cutPoint][right];
                    dp[left][right] = min(remaining + cost, dp[left][right] == 0 ? numeric_limits<int>::max(): dp[left][right]);
                }
            }
        }
        return dp[0][cuts.size() - 1];
    }

    int dfs(vector<int>& cuts, int i, int j, vector<vector<optional<int>>> & dp) {
        if (j - i <= 1)
            return 0;
        if (dp[i][j] == nullopt) {
            dp[i][j] = numeric_limits<int>::max();
            for (auto k = i + 1; k < j; ++k)
                dp[i][j] = min(dp[i][j].value(),
                               cuts[j] - cuts[i] + dfs(cuts, i, k, dp) + dfs(cuts, k, j, dp));
        }
        return dp[i][j].value();
    }

    int minCostRec(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(begin(cuts), end(cuts));
        vector<vector<optional<int>>> dp(cuts.size(), vector<optional<int>> (cuts.size()));
        return dfs(cuts, 0, cuts.size() - 1, dp);
    }
};
#endif //CPPALGORITHMS_MINCOSTTOCUTSTICKS_H
