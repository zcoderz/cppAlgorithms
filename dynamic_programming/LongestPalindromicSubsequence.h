//
// Created by USMAN QADIR on 10/27/22.
//

#ifndef CPPALGORITHMS_LONGESTPALINDROMICSUBSTRING_H
#define CPPALGORITHMS_LONGESTPALINDROMICSUBSTRING_H
#include <iostream>
#include <vector>
using namespace std;


class LongestPalindromicSubstring{
public:

    static int longestPalindromeSubseq(string &s, int l, int r, vector<vector<int>> & memo) {
        if (l>r) return 0;
        if (l==r) return 1;
        if (memo[l][r] !=0) return memo[l][r];
        int sz=0;
        if (s[l]==s[r]) {
            sz = longestPalindromeSubseq(s, l+1, r-1, memo) + 2;
        } else {
            sz= max(longestPalindromeSubseq(s, l+1, r,memo) , longestPalindromeSubseq(s, l, r-1,memo));
        }
        memo[l][r] =sz;
        return sz;
    }
    // = "bbbab"; "cbbd";
    static int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.length(), vector<int> (s.length()));
        int sz = s.length();
        for (int i=sz-1; i >=0; i--) {
            dp[i][i]=1;
            for (int j=i+1; j <sz; j++) {
                if (s[i]==s[j]) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                } else {
                    dp[i][j] = max (dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][s.length()-1];
    }

    static int longestPalindromeSubseqRec(string s) {
        vector<vector<int>> memo(s.length(), vector<int> (s.length()));
        return longestPalindromeSubseq(s,0,s.length()-1, memo);
    }

    static void testMe() {
        string str = "bba";// "b bbab";
        int res = longestPalindromeSubseq(str);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_LONGESTPALINDROMICSUBSTRING_H
