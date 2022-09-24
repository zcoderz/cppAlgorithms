//
// Created by USMAN QADIR on 9/24/22.
//

#ifndef CPPALGORITHMS_LONGESTREPEATEDSUBSTRING_H
#define CPPALGORITHMS_LONGESTREPEATEDSUBSTRING_H

#include <string>
using namespace std;

class LongestRepeatedSubstring {
public:

    static string get_longest_repeated_substring(string s) {
        int n = s.length();
        vector<vector<int>> lcp(n, vector<int>(n, 0));;
        // lcp[i][j] = k means length of longest common prefix between suffix starting at i and suffix
        // starting at j is k

        for (int i = 0; i < n; i++) {
            lcp[i][n - 1] = (s[i] == s[n - 1] ? 1 : 0);
        }

        for (int i = 0; i < n; i++) {
            lcp[n - 1][i] = (s[n-1] == s[i] ? 1 : 0);
        }

        int lrsLen = 0, lrsIndex = -1;
        for (int i = n - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                if (s[i] == s[j]) {
                    lcp[i][j] = 1 + lcp[i + 1][j + 1];
                } else {
                    lcp[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (lcp[i][j] > lrsLen) {
                    lrsIndex = i;
                    lrsLen = lcp[i][j];
                }
            }
        }

        string lrs = "";
        if (lrsIndex > -1) {
            lrs = s.substr(lrsIndex, lrsLen);
        }

        return lrs;
    }
};

#endif //CPPALGORITHMS_LONGESTREPEATEDSUBSTRING_H
