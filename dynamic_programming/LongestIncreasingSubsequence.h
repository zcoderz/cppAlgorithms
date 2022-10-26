//
// Created by usman on 10/25/22.
//

#ifndef CPPALGORITHMS_LONGESTINCREASINGSUBSEQUENCE_H
#define CPPALGORITHMS_LONGESTINCREASINGSUBSEQUENCE_H
#include <vector>
#include <iostream>
using namespace std;

class LongestIncreasingSubsequence {
public:
    static int lengthOfLISDP(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0]=1;
        int maxSz=1;
        for (int i=1; i < nums.size(); i++) {
            for (int j=0; j < i; j++) {
                dp[i] = max(dp[i], (nums[i] > nums[j] ? dp[j]+1 : 1));
            }
            maxSz = max(maxSz, dp[i]);
        }
        return maxSz;
    }

    static int lengthOfLIS(vector<int>& nums) {
        vector<int> orderedNums; orderedNums.push_back(nums[0]);

        for (int i=1; i < nums.size(); i++) {
            if (nums[i] > orderedNums.back()) {
                orderedNums.push_back(nums[i]);
            } else {
                int left =0; int right = orderedNums.size()-1;
                while (left < right) {
                    int mid = (left + (right-left)/2);
                    //move left forward because we want right to be at the next larger number
                    if (orderedNums[mid] < nums[i]) {
                        left = mid+1;
                    } else if (orderedNums[mid] > nums[i]) {
                        right = mid;
                    } else {
                        left = right = mid;
                    }
                }
                orderedNums[right] = nums[i];
            }
        }
        return orderedNums.size();
    }

    static void testMe() {
        vector<int> data = {10,9,2,5,3,4};
        int val = lengthOfLIS(data);
        cout << val << endl;
    }

};
#endif //CPPALGORITHMS_LONGESTINCREASINGSUBSEQUENCE_H
