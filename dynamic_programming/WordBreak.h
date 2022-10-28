//
// Created by usman on 11/17/21.
//

#ifndef CPPALGORITHMS_WORDBREAK_H
#define CPPALGORITHMS_WORDBREAK_H

#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

/**
 * Word Break problem running in O(N*K) where N is number of chars in string and K is the size of largest word in dictionary
 */


class WordBreak {
public:
    static bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set wordSet (wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size()+1); dp[0]=true;
        for (int i=1; i <= s.size(); i++) {
            for (int j=i-1; j >=0; j--) {
                if (dp[j] && wordSet.find(s.substr(j, i-j)) != wordSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }

    static bool wordBreakTwo(string & s, vector<string>& wordDict) {
        unordered_set<string> theSet (wordDict.begin(), wordDict.end());
        int maxStringLen = 0;
        for (string & str: wordDict) {
            maxStringLen = max((int)str.size(), maxStringLen);
        }

        int strSz = s.size();
        int maxLenSeen = 0;
        int i=0;
        vector<bool> seen(strSz, false);
        seen[0] = true;
        while (i <= maxLenSeen) {
            if(!seen[i]) {++i; continue;}
            int boundary = min(strSz-i, maxStringLen);
            for (int j =1; j <= boundary; ++j) {
                string temp = s.substr(i, j);
                if (theSet.find(temp) != theSet.end()) {
                    seen[i+j] = true;
                    maxLenSeen = max(maxLenSeen, i+j);
                }
            }
            if (maxLenSeen==strSz) return true;
            ++i;
        }
        return false;
    }

    static void testMe() {
        string str = "leetcode";
        vector<string> dict = {"leet", "code"};
        bool res = wordBreak(str, dict);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_WORDBREAK_H
