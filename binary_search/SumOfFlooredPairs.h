//
// Created by usman on 1/22/23.
//

#ifndef CPPALGORITHMS_SUMOFFLOOREDPAIRS_H
#define CPPALGORITHMS_SUMOFFLOOREDPAIRS_H

#include <vector>
#include <climits>
#include <iostream>
#include <unordered_map>
using namespace std;

/**
 * https://leetcode.com/problems/sum-of-floored-pairs/solutions/1210073/c-short-easy-frequency-prefix-sum-solution-w-explanation/
 */
class SumOfFlooredPairs{
public:
    static int sumOfFlooredPairs(vector<int>& nums) {
        //need 2x the max element. i.e if max num is 1e5..less than 2x will be until 2*1e5-1
        int maxNums = 2*1e5;
        int MOD = 1e9+7;
        int maxNum = INT_MIN;
        vector<int> freq(maxNums);
        //update frequency for nums
        for (int num : nums) {
            freq[num]++;
            maxNum = max(maxNum, num);
        }
        //create a prefix sum of frequency so frequency of each number includes frequency of numbers before it
        for (int i =1; i < maxNums; i++) {
            freq[i] += freq[i-1];
        }
        int totalSum=0;
        //use a hash map to avoid repeated calculations
        unordered_map<int,int> numSum;
        for (int num : nums) {
            auto iter = numSum.find(num);
            if (iter != numSum.end()) {
                totalSum = (totalSum + iter->second) % MOD;
                continue;
            }

            int multiple =1;
            //left is the number one before where the given multiple range starts
            //this is needed so that we can exclude frequencies of numbers before this range
            int l = num*(multiple)-1;
            int sum =0;
            while (l <= maxNum) {
                //right is where the range ends
                int r = num*(multiple+1)-1;
                sum = (sum + (multiple)*(freq[r]-freq[l])) % MOD;
                multiple++;
                l = r;
            }
            numSum[num] = sum;
            totalSum = (totalSum + sum) % MOD;
        }
        return totalSum;
    }

    static void testMe() {
        vector<int> vals = {2,5,9};
        int res = sumOfFlooredPairs(vals);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_SUMOFFLOOREDPAIRS_H
