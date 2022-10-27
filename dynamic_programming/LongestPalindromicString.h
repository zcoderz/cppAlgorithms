//
// Created by usman on 10/27/22.
//

#ifndef CPPALGORITHMS_LONGESTPALINDROMICSTRING_H
#define CPPALGORITHMS_LONGESTPALINDROMICSTRING_H

#include <string>
#include <iostream>
using namespace std;

class LongestPalindromicString {
public:
    static string longestPalindrome(string s) {
        int start=0, end=0;
        for (int i=0; i < s.length(); i++) {
            int len = calcMaxPalLength(s, i, i);
            if (len > end-start+1) {
                start = i - len/2;
                end = start + len-1;
            }
            len = calcMaxPalLength(s, i, i+1);
            if (len > end-start+1) {
                end = i + len/2;
                start = end - len + 1;
            }
        }
        return s.substr(start, end-start+1);
    }

    static int calcMaxPalLength(string &s, int low, int hi) {
        int l=low, high=low;
        while (low >=0 && hi < s.length() && s[low] == s[hi] ) {
            l=low, high=hi;
            low--; hi++;
        }
        return high-l+1;
    }

    static void testMe() {
        string str = "cbbd";
        string v = longestPalindrome(str);
        cout << v << endl;
    }
};

#endif //CPPALGORITHMS_LONGESTPALINDROMICSTRING_H
