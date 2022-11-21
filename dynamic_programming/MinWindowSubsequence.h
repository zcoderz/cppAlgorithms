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
        //dp[i][j] stores length of s1 string matched so far.
        //if unmtached , value is set as INT_MAX
        vector<vector<int>> dp(sz1+1, vector<int> (sz2+2, INT_MAX));
        int minSz = INT_MAX;
        pair<int, int> coordinate;
        //sarting from 1 instead of 0 makes handling of 0th index simple
        for (int i =1; i <= sz1; i++) {
            for (int j=1; j <= sz2; j++) {
                //on process a match if the characters match and whether one of below satisfies
                //1. we are at the first character of s2
                //2. we are on a subsequent character of s2 and
                //dp array value of [i-1][j-1] has been calculated. this is important to avoid
                //matches of a suffix without having matched prefix
                if (s1[i-1]==s2[j-1] && (j==1 || dp[i-1][j-1] != INT_MAX)) {
                    if (j==1) {
                        dp[i][j] = 1; //start the match at 1
                    } else {
                        dp[i][j] =   dp[i-1][j-1] + 1; //increment the match by 1 on each subsequent match
                    }
                    //if you have reached the end of s2 and length of s1 is smaller than the prior match size
                    //update the match coordinates and size
                    if (j==sz2 && minSz > dp[i][j]) {
                        minSz = dp[i][j];
                        coordinate = {i,j};
                    }
                } else if (i>0 && dp[i-1][j] != INT_MAX) {
                    //in case of mismatch increase the size when the prior call
                    //dp[i-1][j] has a match (!= INT_MAX)
                    dp[i][j] =  dp[i-1][j] + 1;
                }
            }
        }
        if (minSz < INT_MAX) {
            int i = coordinate.first;
            int j = coordinate.second;
            //dp[i][j] contains length of the s1 string that was matched
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
