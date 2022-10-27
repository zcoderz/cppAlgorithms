//
// Created by usman on 10/26/22.
//

#ifndef CPPALGORITHMS_LONGESTDIVISIBLESUBSET_H
#define CPPALGORITHMS_LONGESTDIVISIBLESUBSET_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

class LongestDivisibleSubset {
public:
    static vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        //use a pair so one index represents size and the other index represents prior
        vector<pair<int, int>> dp(nums.size());
        dp[0]= make_pair(1,0);
        int maxLenIndex =0;
        int maxLenCnt = 0;
        for (int i =1; i < nums.size(); i++) {
            dp[i]= make_pair(1,i);
            for (int j=0; j < i; j++) {
                if (((nums[i] % nums[j])==0) && (dp[i].first < dp[j].first +1)) {
                    //update max size and link to the prior index
                    dp[i].first = dp[j].first +1;
                    dp[i].second = j;
                }
            }
            if (dp[i].first > maxLenCnt) {
                //update max index and count
                maxLenCnt = dp[i].first;
                maxLenIndex = i;
            }
        }
        vector<int> res; bool circle=false;
        while (!circle) {
            res.push_back(nums[maxLenIndex]);
            int tmp  = dp[maxLenIndex].second;
            //the last index loops back to self, which is used to determine the end of loop
            if (tmp == maxLenIndex) circle = true;
            maxLenIndex = tmp;
        }
        return res;
    }

    static void testMe() {
        vector<int> vals = {1,2,3};
        vector<int> res = largestDivisibleSubset(vals);
        std::copy(res.begin(), res.end() , std::ostream_iterator<int>(cout, ", "));
    }
};

#endif //CPPALGORITHMS_LONGESTDIVISIBLESUBSET_H
