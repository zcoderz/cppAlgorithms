//
// Created by usman on 11/17/22.
//

#ifndef CPPALGORITHMS_LONGESTPALINDROMICSUBSEQUENCETWO_H
#define CPPALGORITHMS_LONGESTPALINDROMICSUBSEQUENCETWO_H

#include <string>
#include <iostream>

using namespace std;

/**
 * DINOSAUR : Do this again!
 */
class LongestPalindromicSubsequenceTwo {
public:
    static int longestPalindromeSubseq(string s, int left, int right, int priorC, vector<vector<vector<int>>> & dp) {
        if (left >= right) {
            return 0;
        }
        if (dp[left][right][priorC] != -1) {
            return dp[left][right][priorC];
        }
        if (s[left]-'a' == priorC) {
            dp[left][right][priorC] =  longestPalindromeSubseq(s, left+1, right, priorC, dp);
            return dp[left][right][priorC];
        }
        if (s[right]-'a' == priorC) {
            dp[left][right][priorC] = longestPalindromeSubseq(s, left, right-1, priorC, dp);
            return dp[left][right][priorC];
        }
        if (s[left] == s[right]) {
            dp[left][right][priorC] =  longestPalindromeSubseq(s, left+1, right-1, s[left]-'a', dp) + 2;
            //cout << "m-at " << left << " , " << right << " val is " << dp[left][right][priorC] << endl;
            return dp[left][right][priorC];
        } else {
            dp[left][right][priorC] =  max(longestPalindromeSubseq(s, left+1, right, priorC, dp), longestPalindromeSubseq(s, left, right-1, priorC, dp));
            //cout << "at " << left << " , " << right << " val is " << dp[left][right][priorC] << endl;
            return dp[left][right][priorC];
        }
    }

    static int longestPalindromeSubseqDP(string s) {
        vector<vector<vector<int>>> dp(s.size()+1, vector<vector<int>> (s.size()+1, vector<int> (27, 0)));
        for (int i =s.length()-1; i>=0; i--) {
            for (int j =i+1; j < s.size(); j++) {
                for (int prev=26; prev >=0; prev--) {
                    if (s[i]-'a' == prev) {
                        dp[i][j][prev] = dp[i + 1][j][prev];
                    }
                    else if (s[j]-'a' == prev) {
                        dp[i][j][prev] = dp[i][j - 1][prev];
                    }
                    else if (s[i] == s[j]) {
                        dp[i][j][prev] = dp[i+1][j-1][s[i]-'a']+2;
                    } else {
                        dp[i][j][prev] = max (dp[i][j-1][prev], dp[i+1][j][prev]);
                    }
                }
            }
        }
        return dp[0][s.length()-1][26];
    }

    static int longestPalindromeSubseqDPFast(string s) {
        typedef pair<int,char> IntChar;
        vector<vector<IntChar>> dp(s.length()+1, vector<IntChar> (s.length()+1, {0, ' '}));
        for (int gap=1; gap < s.length(); gap++) {
            for (int i=0, j=i+gap; j < s.length(); i++, j++) {
                if(s[i] == s[j] && (gap ==1 || dp[i+1][j-1].second != s[i])){
                    if(gap == 1)
                        dp[i][j] = {2, s[i]};
                    else
                        dp[i][j] = {dp[i+1][j-1].first + 2, s[i]};
                } else {
                    if (dp[i+1][j].first > dp[i][j-1].first) {
                        dp[i][j] = dp[i+1][j];
                    } else {
                        dp[i][j] = dp[i][j-1];
                    }
                }
            }
        }
        return dp[0][s.length()-1].first;
    }

    static int longestPalindromeSubseq(string s) {
        vector<vector<vector<int>>> dp(s.size(), vector<vector<int>> (s.size(), vector<int> (27, -1)));
        return longestPalindromeSubseq(s, 0, s.size()-1, 26, dp);
    }

    static void testMe() {
        string str = "bbabab";
        int res = longestPalindromeSubseqDPFast(str);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_LONGESTPALINDROMICSUBSEQUENCETWO_H
