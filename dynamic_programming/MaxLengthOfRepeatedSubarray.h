//
// Created by usman on 1/25/23.
//

#ifndef CPPALGORITHMS_MAXLENGTHOFREPEATEDSUBARRAY_H
#define CPPALGORITHMS_MAXLENGTHOFREPEATEDSUBARRAY_H

#include <vector>
#include <climits>
#include <iostream>

using namespace std;

class MaxLengthOfRepeatedSubArray {
public:


    static int findLength(vector<int> &nums1, vector<int> &nums2) {
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), 0));
        int maxMatch = 0;
        for (int i = 0; i <nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i]==nums2[j]) {
                    if ( i >0 && j >0) {
                        dp[i][j] = dp[i-1][j-1] + 1;
                    } else
                        dp[i][j] =1;
                }
                maxMatch = max(maxMatch, dp[i][j]);
            }
        }
        return maxMatch;
    }

    static void testMe() {
        vector<int> v1 = {1,2,3,2,1};
        vector<int> v2 = {3,2,1,4,7};
        int res = findLength(v1, v2);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_MAXLENGTHOFREPEATEDSUBARRAY_H
