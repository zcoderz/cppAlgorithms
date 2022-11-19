//
// Created by usman on 11/18/22.
//

#ifndef CPPALGORITHMS_MINWINDOWSUBSEQUENCE_H
#define CPPALGORITHMS_MINWINDOWSUBSEQUENCE_H

#include <string>
#include <vector>
#include <climits>
using namespace std;

class MinWindowSubsequence {
public:
    static string minWindow(string s1, string s2) {
        int sz1 = s1.length();
        int sz2 = s2.length();
        vector<vector<int>> dp(sz1+1, vector<int> (sz2+2, INT_MAX));
        int minSz = INT_MAX;
        pair<int, int> coordinate;
        for (int i =1; i <= sz1; i++) {
            for (int j=1; j <= sz2; j++) {
                if (s1[i-1]==s2[j-1] && (j==1 || dp[i-1][j-1] != INT_MAX)) {
                    if (j==1) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] =   dp[i-1][j-1] + 1;
                    }

                    if (j==sz2 && minSz > dp[i][j]) {
                        minSz = dp[i][j];
                        coordinate = {i,j};
                    }
                } else if (i>0 && dp[i-1][j] != INT_MAX) {
                    dp[i][j] =  dp[i-1][j] + 1;
                }
            }
        }
        if (minSz < INT_MAX) {
            int i = coordinate.first;
            int j = coordinate.second;
            int sz = dp[i][j];
            int start=i-sz;
            return s1.substr(start, sz);
        }
        return "";
    }

    static void testMe() {
        string s1 = "hpsrhgogezyfrwfrejytjkzvgpjnqil";
        string s2 = "ggj";
        string res = minWindow(s1, s2);
        cout << res << endl;
    }

};

#endif //CPPALGORITHMS_MINWINDOWSUBSEQUENCE_H
