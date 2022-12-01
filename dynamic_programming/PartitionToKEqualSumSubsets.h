//
// Created by usman on 11/30/22.
//

#ifndef CPPALGORITHMS_PARTITIONTOKEQUALSUMSUBSETS_H
#define CPPALGORITHMS_PARTITIONTOKEQUALSUMSUBSETS_H

#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

/**
 * This problem is beautiful!!!
 * optimizing against test cases is tricky...avoiding repeats + memorization helps speed it up.
 */
class PartitionToKEqualSumSubsets {
public:

    static bool numEqualSubSets(int target, int current, vector<int>& nums, int mask, int numMatches, int k,
                                int startingIndex, unordered_set<int> &memo) {
        if (memo.find(mask) != memo.end()) return false;
        int newCurrent = current == target ? 0 : current;
        if (newCurrent != current) {
            startingIndex=0;
            numMatches++;
        }
        if (numMatches==k) return true;

        for (int i =startingIndex; i < nums.size(); i++) {
            if (((1<<i) & mask) != 0) continue;

            if ((newCurrent+nums[i]) > target) {
                continue;
            }
            mask = mask | (1<<i);
            bool matches = numEqualSubSets(target, newCurrent + nums[i], nums, mask, numMatches, k, i+1, memo);
            if (matches) return true;
            mask = mask ^ (1<<i);

            //if you are starting fresh with a next subset match and utilizing the number at first [i]
            //reaching k subsets was not possible then with the set of bits open, it isn't possible to reach k subsets
            //hence break immediately rather than wasting more iterations
            if (newCurrent==0) break;

            //because the last iteration using newCurrent + nums[i] failed and nums[i+1] is same as nums[i]
            //it isn't possible to reach target with the number at nums[i]. hence skip to next number that is different
            while (i < nums.size() -1 && nums[i+1]==nums[i]) {
                i++;
            }
        }
        memo.insert(mask);
        return false;
    }

    static bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k !=0) return false;
        sort(nums.begin(), nums.end(), greater<>());
        unordered_set<int> memo;
        return numEqualSubSets(sum/k, 0, nums, 0, 0, k, 0, memo);
    }

    static bool canPartitionKSubsetsDP(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k !=0) return false;
        int maxNo = 1 << nums.size();
        int dp [maxNo];
        int target = sum/k;
        memset(dp, -1, sizeof(dp));
        dp[0]=0;
        //mask contains combination of bits for each of the indices in nums vector
        for (int mask =0; mask < maxNo; mask++) {
            if (dp[mask]==-1) continue;
            for(int i =0; i < nums.size(); i++) {
                int iOffset = 1<<i;
                //if bit at index i is already used , skip
                if ((mask & (iOffset)) != 0) continue;
                int newMask = mask | iOffset;
                //dp[mask] + nums[i] , reflects value after adding value at the ith bit
                if (dp[mask] + nums[i] <= target) {
                    //mod with target to reset the value to 0.
                    //this is to indicate that one partition has been reached using the bits in the mask
                    //and hence next partition needs to start from 0
                    dp[newMask]  = (dp[mask] + nums[i]) % target;
                }
            }
            if (dp[maxNo -1] ==0) {
                return true;
            }
        }
        return dp[maxNo -1] ==0;
    }

    static void testMe() {
        vector<int> nums = {2,2,2,2};
        //vector<int> nums = {4,3,1};
        //vector<int> nums = {2,2,2,2,3,4,5};
        int k = 2;
        bool res = canPartitionKSubsets(nums, k);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_PARTITIONTOKEQUALSUMSUBSETS_H
