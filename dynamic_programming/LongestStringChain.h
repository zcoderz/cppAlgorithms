//
// Created by usman on 10/26/22.
//

#ifndef CPPALGORITHMS_LONGESTSTRINGCHAIN_H
#define CPPALGORITHMS_LONGESTSTRINGCHAIN_H

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class LongestStringChain {
public:
    bool wordExtension(string &left, string & right) {
        if (right.size() != left.size() +1 ) return false;
        int diffCnt =0;
        for (int i =0; i < right.size(); i++) {
            if (left[i-diffCnt] != right[i]) {
                diffCnt++;
                if (diffCnt > 1) return false;
            }
        }
        return true;
    }

    int longestStrChain(vector<string> & words) {
        //smaller sized string first
        sort(words.begin(), words.end(), [] (string &a, string &b) {return a.length() < b.length();});
        int longestChain=1;
        vector<int> dp(words.size()); dp[0]=1;

        for (int i =1; i < words.size(); i++) {
            dp[i] = 1;
            for (int j=0; j < i; j++) {
                if (wordExtension(words[j], words[i])) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            longestChain = max (longestChain, dp[i]);
        }
        return longestChain;
    }
};

#endif //CPPALGORITHMS_LONGESTSTRINGCHAIN_H
