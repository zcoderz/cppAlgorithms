//
// Created by usman on 11/15/22.
//

#ifndef CPPALGORITHMS_DISTINCTSUBSEQUENCES_H
#define CPPALGORITHMS_DISTINCTSUBSEQUENCES_H

#include <string>
#include <iostream>
using namespace std;

class DistinctSubsequences {
public:

    static int numDistinct(string s, string t, int tIndex, int sIndex, vector<vector<int>> &dp) {
        if (tIndex == t.size()) {
            return 1;
        }
        if (sIndex == s.size()) {
            return 0;
        }
        if (dp[sIndex][tIndex] != -1) {
            return dp[sIndex][tIndex];
        }
        int numMatch = 0;
        if(s[sIndex] == t[tIndex]) {
            numMatch = numDistinct(s,t,tIndex+1, sIndex+1, dp);
        }
        numMatch += numDistinct(s,t,tIndex, sIndex+1, dp);
        dp[sIndex][tIndex] = numMatch;
        return numMatch;
    }

    static int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size()+1, vector<int> (t.size()+1, -1));
        return numDistinct(s, t, 0, 0, dp);
    }

    static int numDistinctDP(string s, string t) {
        vector<vector<int>> dp(s.size()+1, vector<int> (t.size()+1, 0));
        int lastRow = s.size()-1;
        int lastCol = t.size();
        for (int i = s.size(); i >=0; i--) {
            dp[i][lastCol]=1;
        }
        for (int i = s.size()-1; i >=0; i--) {
            for (int j = t.size()-1; j>=0; j--) {
                dp[i][j] = dp[i+1][j];
                if (s[i] == t[j] ) {
                    dp[i][j] = ( dp[i][j] + dp[i+1][j+1]) % 1000000007;;
                }
            }
        }
        return dp[0][0];
    }

    static void testMe() {
        string a = "rabbbit";
        string b = "rabbit";
        int res = numDistinctDP(a,b);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_DISTINCTSUBSEQUENCES_H
