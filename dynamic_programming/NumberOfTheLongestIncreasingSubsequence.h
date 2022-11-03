//
// Created by usman on 10/26/22.
//

#ifndef CPPALGORITHMS_NUMBEROFTHELONGESTINCREASINGSUBSEQUENCE_H
#define CPPALGORITHMS_NUMBEROFTHELONGESTINCREASINGSUBSEQUENCE_H

#include <vector>
#include <unordered_map>
using namespace std;

/**
 *
 */
class LongestIncreasingSubsequence {
    int findNumberOfLIS(vector<int>& nums) {
        vector<pair<int,int>> dp(nums.size());
        dp[0] = make_pair(1,1);
        int maxCnt=0, maxLen=0;
        for (int i =0; i < nums.size(); i++) {
            dp[i]=make_pair(1,1);
            for (int j=0; j < i; j++) {
                if (nums[i]>nums[j] && dp[j].first >= dp[i].first -1) {
                    if (dp[i].first == dp[j].first +1) {
                        //found another longest sequence of same size, add count from that sequence in
                        dp[i].second += dp[j].second;
                    } else {
                        //increase longest length of sequence
                        dp[i] = dp[j]; dp[i].first += 1;
                    }
                }
            }
            if (dp[i].first > maxLen) {
                maxLen = dp[i].first;
                maxCnt = dp[i].second;
            } else if (dp[i].first == maxLen) {
                //1,2,4 or 1,2,3 ...both are of length 3, when the second sequence of length 3 is found
                //it should increment the count of occurrences that were of length 3
                maxCnt += dp[i].second;
            }
        }
        return maxCnt;
    }
};

#endif //CPPALGORITHMS_NUMBEROFTHELONGESTINCREASINGSUBSEQUENCE_H
