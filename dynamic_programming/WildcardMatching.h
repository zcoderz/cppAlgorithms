//
// Created by USMAN QADIR on 11/4/22.
//

#ifndef CPPALGORITHMS_WILDCARDMATCHING_H
#define CPPALGORITHMS_WILDCARDMATCHING_H
#include <string>
#include <vector>
#include <iostream>

using namespace std;

/**
 * DINOSAUR : This one has tricky edge cases. Need to do again.
 */
class WildCardMatching {
public:
    static bool isMatch(string s, string p) {
        string modPattern; bool firstStar = true;
        for (int i =0; i < p.length(); i++) {
            if (p[i] == '*') {
                if (firstStar) {
                    modPattern +=  p[i];
                    firstStar = false;
                }
            } else {
                firstStar = true;
                modPattern +=  p[i];
            }
        }

        //add size + 1 to make traversal of matrix for prior indices easier
        //string is going across rows and pattern is going across columns
        vector<vector<bool>> dp(s.length()+1, vector<bool> (modPattern.length()+1));
        dp[0][0]= true; //empty string match with empty pattern is true
        if (modPattern[0]=='*')
            dp[0][1] = true; //need to set so that first column (entire string first pattern char) gets match



        for (int i =1; i <= s.length(); i++) {
            for (int j =1; j <= modPattern.length(); j++) {
                if (modPattern[j-1]=='*') {
                    dp[i][j] = (dp[i][j-1] || dp[i-1][j]);
                } else if ((modPattern[j-1]=='?') || (modPattern[j-1] == s[i-1])) {
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }

        return dp[s.length()][modPattern.length()];
    }

    static void testMe() {
        string str = "aa";
        string p = "*";
        bool res = isMatch(str, p);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_WILDCARDMATCHING_H
