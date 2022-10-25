//
// Created by USMAN QADIR on 10/22/22.
//

#ifndef CPPALGORITHMS_PAINTHOUSETWO_H
#define CPPALGORITHMS_PAINTHOUSETWO_H
#include <vector>
#include <climits>
#include <algorithm>
#include <limits>
using namespace std;

class PaintHouseTwo {

    int minCostIIEfficient(vector<vector<int>>& costs) {
        int n = costs.size();
        int k = costs[0].size();

        vector<int>leftMin(k); //denotes min of elements left of the given index
        vector<int>rightMin(k); //denotes min of elements right of the given index
        vector<int>prevMin(costs[0]); //min costs from prior row
        vector<int>currMin(k);

        for (int i=1; i<n; i++){
            leftMin[0] = INT_MAX;
            rightMin[k-1] = INT_MAX;
            for (int j=1; j<k; j++) {
                leftMin[j] = min(prevMin[j-1], leftMin[j-1]); //j-1 so that its left of current index
                rightMin[k-1-j] = min(prevMin[k-j], rightMin[k-j]); //k-1-j (as the index reflects from right index
            }

            currMin[0] = costs[i][0] + rightMin[0];
            currMin[k-1] = costs[i][k-1] + leftMin[k-1];
            for(int j=1; j<k-1; j++)
                currMin[j] = costs[i][j]+min(leftMin[j], rightMin[j]);

            swap(currMin, prevMin);
        }
        return *min_element(prevMin.begin(), prevMin.end());
    }

    int minCostII(vector<vector<int>>& costs) {
        int houses = costs.size();
        if (houses ==0) return 0;
        int colors = costs[0].size();
        if (colors == 0) return 0;
        vector<vector<int>> dp(houses, vector<int> (colors, numeric_limits<int>::max()));
        for (int color =0; color <  colors; color++) {
            dp[0][color] = costs[0][color];
        }
        for (int i =1; i < houses; i++) {
            for (int j = 0; j < colors; j++) {
                for (int z = 0; z < colors; z++) {
                    if (z==j) continue;
                    dp[i][j] = min (dp[i][j], dp[i-1][z] + costs[i][j]);
                }
            }
        }
        return *min_element(dp[houses-1].begin(), dp[houses-1].end());
    }
};
#endif //CPPALGORITHMS_PAINTHOUSETWO_H
