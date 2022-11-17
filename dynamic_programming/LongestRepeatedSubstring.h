//
// Created by usman on 11/17/22.
//

#ifndef CPPALGORITHMS_LONGESTREPEATEDSUBSTRING_DP_H
#define CPPALGORITHMS_LONGESTREPEATEDSUBSTRING_DP_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class LongestRepeatedSubstringDP {
public:

    static int longestRepeatingSubstring(string s) {
        int maxV = 0;
        int sz = s.size();
        vector<vector<int>> dp (sz+1, vector<int> (sz+1));
        for (int i =1; i <= sz; i++) {
            for (int j=i+1; j <=sz; j++) {
                if (s[i-1] == s[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    maxV = max(maxV, dp[i][j]);
                }
            }
        }
        return maxV;
    }

    static void testMe() {
        string str = "aabcaabdaab";
        int res = longestRepeatingSubstring(str);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_LONGESTREPEATEDSUBSTRING_DP_H
