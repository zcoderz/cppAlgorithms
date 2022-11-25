//
// Created by usman on 11/22/22.
//

#ifndef CPPALGORITHMS_PROFITABLESCHEMES_H
#define CPPALGORITHMS_PROFITABLESCHEMES_H

#include <vector>
#include <iostream>
using namespace std;

class ProfitableSchemes {
public:
    /**
     * Knapsack solution!
     * @param n
     * @param minProfit
     * @param group
     * @param profit
     * @return
     */
    static int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int groupSz = group.size();
        vector<vector<int>> dp(n+1, vector<int> (minProfit+1));
        for (int i =0; i <= n; i++) dp[i][0]=1; //a profit of 0 is possible by any number of people

        for (int i =0; i < groupSz; i++) {
            //go in reverse so you dont update data which will be used in same loop
            //break when j==number of people needed for the group, since you will need this number of people atleast to make the profit
            //j - group[i]
            for (int j = n; j >= group[i]; j--) {
                for (int prof =0; prof <= minProfit; prof++) {
                    //include the ith profit
                    int profMod = min(minProfit, prof+profit[i]);
                    //increment from j - group[i] (number of people needed in this group) and profit excluding the profit[i]
                    dp[j][profMod] = (dp[j][profMod] + dp[j-group[i]][prof]) % 1000000007;
                }
            }
        }

        return dp[n][minProfit];
    }

    static void testMe() {
        vector<int> groups = {2,2};
        vector<int>profits = {2,3};
        int res = profitableSchemes(5, 3, groups, profits);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_PROFITABLESCHEMES_H
