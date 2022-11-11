//
// Created by usman on 11/10/22.
//

#ifndef CPPALGORITHMS_INTERLEAVINGSTRING_H
#define CPPALGORITHMS_INTERLEAVINGSTRING_H

#include <string>
#include <iostream>
using namespace std;

/**
 * DINOSAUR: do the dp solution again
 */
class InterleavingString {
public:
    static bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) return false;
        vector<bool> dp(s2.length()+1);
        int s1Sz = s1.length();
        int s2Sz = s2.length();
        for (int i =0; i <= s1Sz; i++) {
            for (int j =0; j <= s2Sz; j++) {
                if (i==0 && j ==0) {
                    dp[j] = true;
                } else if (i==0) {
                    dp[j] = dp[j-1] && s2[j-1] == s3[i+j-1];
                } else if (j==0) {
                    dp[j] = dp[j] && s1[i-1] == s3[i+j-1];
                } else {
                    dp[j] = (dp[j] && s1[i-1] == s3[i+j-1]) || (dp[j-1] && s2[j-1] == s3[i+j-1]);
                }
            }
        }
        return dp[s2Sz];
    }

    static bool processRecursive(string & s1, string &s2, int iS1, int iS2, string &s3, vector<vector<int>> & memo) {

        int s3Index = iS1 + iS2;
        if ((s3Index ) == s3.length() && iS1==s1.length() && iS2== s2.length()) {
            return true;
        }
        if (iS1 < s1.length() && iS2 < s2.length() && memo[iS1][iS2] != -1) {
            return memo[iS1][iS2];
        }
        if (iS1 < s1.length() && s1[iS1] == s3[s3Index]) {
            bool res = processRecursive(s1, s2, iS1+1, iS2, s3, memo);
            if (iS1 < s1.length() && iS2 < s2.length())
                memo[iS1][iS2] = res;
            if (res) return true;
        }

        if (iS2 < s2.length() && s2[iS2] == s3[s3Index]) {
            bool res = processRecursive(s1, s2, iS1, iS2+1, s3, memo);
            if (iS1 < s1.length() && iS2 < s2.length())
                memo[iS1][iS2] = res;
            if (res) return true;
        }
        if (iS1 < s1.length() && iS2 < s2.length())
            memo[iS1][iS2] = 0;
        return false;
    }

    static bool isInterleaveRec(string s1, string s2, string s3) {
        vector<vector<int>> memo(s1.size(), vector<int> (s2.size(), -1));
        return processRecursive(s1, s2, 0, 0, s3, memo);
    }



    static void testMe() {
        string str1 = "abc";
        string str2 = "fg";
        string str3 = "abcfg";
        bool res = isInterleave(str1, str2, str3);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_INTERLEAVINGSTRING_H
