//
// Created by usman on 11/6/22.
//

#ifndef CPPALGORITHMS_REGULAREXPRESSIONDP_H
#define CPPALGORITHMS_REGULAREXPRESSIONDP_H
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class RegularExpressionDP {
public:
    static bool isMatch(string s, string p) {
        int strLength = s.size();
        int patternLength = p.size();

        vector<vector<bool>> dp(strLength+1, vector<bool>(patternLength+1));
        dp[0][0]=true;

        for (int i =0; i <= strLength; i++) {
            for (int j =1; j <=patternLength; j++) {
                if ((i >= 1) && (p[j-1] == '.' ||  (p[j-1] == s[i-1]))) {
                    dp[i][j] = dp[i-1][j-1];
                }
                if (p[j-1] == '*' ) {
                    if ((j > 1 && i >=1) && (p[j-2] == '.' || p[j-2] == s[i-1])) {
                        dp[i][j] = dp[i-1][j]; //to consider match until the last char in string and pattern
                    }
                    if (j > 1) {
                        dp[i][j] = dp[i][j-2] | dp[i][j]; //to consider for a match of 0 length (a* and pattern string being empty)
                    }
                }
            }
        }

        return dp[strLength][patternLength];
    }

    static void testMe() {
        string pattern = "ab*a*c*a";
        string strTest = "aaa";
        bool res = isMatch(strTest, pattern);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_REGULAREXPRESSIONDP_H
