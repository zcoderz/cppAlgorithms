//
// Created by usman on 11/18/22.
//

#ifndef CPPALGORITHMS_VALIDPALINDROMETHREE_H
#define CPPALGORITHMS_VALIDPALINDROMETHREE_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class ValidPalindrome {
public:
    static bool isValidPalindrome(string s, int k) {
        int sz = s.length();
        vector<vector<int>> dp(sz, vector<int> (sz));
        for (int i =0; i < sz; i++)
            dp[i][i] = 1;
        for (int gap =1; gap < sz; gap++) {
            for (int i=0,j=i+gap; j < sz; i++, j++) {
                if (s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1]+2;
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return k >= (sz-dp[0][sz-1]);
    }

    static void testMe() {
        bool res = isValidPalindrome("abcdeca", 2);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_VALIDPALINDROMETHREE_H
