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

    /**
     * The recursive function with memorization is more tricky than it seems!
     * @param n1
     * @param n2
     * @param i
     * @param j
     * @param ans
     * @param dp
     * @return
     */
    int lcs(vector<int>& n1, vector<int>& n2, int i, int j, int &ans, vector<vector<int>>&dp){
        if (i >= n1.size() || j >= n2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int cur = 0;
        if (n1[i] == n2[j]){
            //if match add one to the largest possible answer so far
            cur = lcs(n1, n2, i + 1, j + 1, ans, dp)+1;
        }
        //recurse forward independently in each array
        lcs(n1, n2, i, j + 1, ans, dp);
        lcs(n1, n2, i + 1, j, ans, dp);
        //update ans to cur
        ans = max(ans, cur);
        return dp[i][j] = cur;
    }

    int findLengthRec(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int ans = 0;
        lcs(nums1, nums2, 0, 0, ans, dp);
        return ans;
    }

    static void testMe() {
        vector<int> v1 = {0,1,1,1,1};
        vector<int> v2 = {1,0,1,0,1};
        int res = findLength(v1, v2);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_MAXLENGTHOFREPEATEDSUBARRAY_H
