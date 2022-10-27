//
// Created by usman on 10/26/22.
//

#ifndef CPPALGORITHMS_MAXLENGTHPAIRCHAIN_H
#define CPPALGORITHMS_MAXLENGTHPAIRCHAIN_H

#include <vector>
#include <algorithm>
using namespace std;

class MaxLengthPairChain {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int longestLengthPair =1;
        sort(pairs.begin(), pairs.end(), [] (vector<int> &a, vector<int> &b) { return a[1] < b[1];});
        vector<int> dp(pairs.size()); dp[0] = 1;
        for (int i=1; i < pairs.size(); i++) {
            dp[i]=1;
            for (int j=0; j < i; j++) {
                if (pairs[j][1] < pairs[i][0]) {
                    dp[i] = max(dp[i], dp[j] +1);
                }
            }
            longestLengthPair = max(longestLengthPair, dp[i]);
        }
        return longestLengthPair;
    }
};

#endif //CPPALGORITHMS_MAXLENGTHPAIRCHAIN_H
