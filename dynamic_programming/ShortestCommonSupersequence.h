//
// Created by usman on 11/24/22.
//

#ifndef CPPALGORITHMS_SHORTESTCOMMONSUPERSEQUENCE_H
#define CPPALGORITHMS_SHORTESTCOMMONSUPERSEQUENCE_H

#include <string>
#include <vector>
using namespace std;

class ShortestCommonSuperSequence {

    static string shortestCommonSupersequence(string str1, string str2) {
        string sCommonS;
        string lcs = largestCommonSubsequence(str1, str2);
        int i =0, j =0, l=0;
        while (i < str1.length() || j < str2.length()) {
            char lc = l < lcs.length() ? lcs[l++] : 'A';
            while (i < str1.length() && str1[i] != lc) {
                sCommonS += str1[i++];
            }
            while (j < str2.length() && str2[j] != lc) {
                sCommonS += str2[j++];
            }
            if (lc >= 'a')
                sCommonS += lc;
            i++; j++;
        }

        return sCommonS;
    }


    static string largestCommonSubsequence(string &str1, string & str2) {
        vector<vector<string>> dp(str1.length()+1, vector<string> (str2.length()+1));
        for (int i =1; i <= str1.length(); i++) {
            for (int j =1; j <= str2.length(); j++) {
                if (str1[i-1]==str2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + str1[i-1];
                } else {
                    if (dp[i-1][j].size() > dp[i][j-1].size()) {
                        dp[i][j] = dp[i-1][j];
                    }  else {
                        dp[i][j] = dp[i][j-1];
                    }
                }
            }
        }
        return dp[str1.length()][str2.length()];
    }

};

#endif //CPPALGORITHMS_SHORTESTCOMMONSUPERSEQUENCE_H
