//
// Created by usman on 10/27/22.
//

#ifndef CPPALGORITHMS_PALINDROMICSUBSTRING_H
#define CPPALGORITHMS_PALINDROMICSUBSTRING_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class PalindromicSubstring {
public:
    static int countSubstrings(string s) {
        int cnt =0;
        for(int i=0; i < s.length(); i++) {
            cnt += countPalindromes(s, i, i); //for odd
            cnt += countPalindromes(s, i, i+1); //for even
        }
        return cnt;
    }

    static int countPalindromes(string &s, int low, int hi) {
        int num = 0;
        while (low >=0 && hi < s.length()) {
            if (s[low] != s[hi]) {
                break;
            }
            low--;hi++;
            num++;
        }
        return num;
    }

    static void testMe() {
        int v = countSubstrings("aaa");
        cout << v << endl;
    }
};

#endif //CPPALGORITHMS_PALINDROMICSUBSTRING_H
