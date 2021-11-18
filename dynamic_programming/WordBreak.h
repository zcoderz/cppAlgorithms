//
// Created by usman on 11/17/21.
//

#ifndef CPPALGORITHMS_WORDBREAK_H
#define CPPALGORITHMS_WORDBREAK_H

#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Word Break problem running in O(N*K) where N is number of chars in string and K is the size of largest word in dictionary
 */
class WordBreak {
public:
    bool wordBreak(string & s, vector<string>& wordDict) {
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
};

#endif //CPPALGORITHMS_WORDBREAK_H
