//
// Created by usman on 11/17/22.
//

#ifndef CPPALGORITHMS_LONGESTREPEATEDSUBSTRING_DP_H
#define CPPALGORITHMS_LONGESTREPEATEDSUBSTRING_DP_H

#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
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

    static bool substrFound(string &s, int mid) {
        unordered_set<string> hashSet;
        int sz = s.size();
        for (int i=0; i <= sz-mid; i++) {
            string tmp = s.substr(i, mid);
            if (hashSet.contains(tmp)) return true;
            hashSet.insert(tmp);
        }
        return false;
    }

    static int longestRepeatedSubstringBinarySearch(string s) {
        int sz = s.length();
        int left = 1;
        int right = sz;
        int mid;
        while (left <= right) {
            mid = (left + (right-left)/2);
            if (substrFound(s, mid))
                left = mid+1;
            else
                right = mid-1;
        }
        return left-1;
    }
    static void testMe() {
        string str = "aabcaab";
        int res = longestRepeatedSubstringBinarySearch(str);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_LONGESTREPEATEDSUBSTRING_DP_H
