//
// Created by usman on 9/26/22.
//

#ifndef CPPALGORITHMS_MINWINDOWSUBSTRING_H
#define CPPALGORITHMS_MINWINDOWSUBSTRING_H

#include <string>
#include <vector>
#include <limits>
using namespace std;
class MinWindowSubstring {
public:

    static string minimum_window(string s, string t) {
        vector<int> targetFreq(128, 0);
        vector<int> newFreq(128, 0);
        for (int i =0; i < t.length(); i++) {
            targetFreq[t[i]]++;
        }
        int left =0, right = 0;
        int minLen = numeric_limits<int>::max();
        int iStart = 0;
        int countSearchChars = 0;
        string res;
        for (; right < s.length(); right++) {
            newFreq[s[right]]++;

            if (newFreq[s[right]] <= targetFreq[s[right]]) {
                countSearchChars++;
            }
            while (left < s.length() && newFreq[s[left]] > targetFreq[s[left]]) {
                newFreq[s[left]]--; left++;
            }
            if (countSearchChars == t.size()) {
                int len = right-left+1;
                if (len < minLen) {
                    iStart = left;
                    minLen = len;
                }
            }
        }
        if (minLen != numeric_limits<int>::max()) {
            res = s.substr(iStart, minLen);
        }
        return res.empty() ? "-1" : res;
    }
};

#endif //CPPALGORITHMS_MINWINDOWSUBSTRING_H
