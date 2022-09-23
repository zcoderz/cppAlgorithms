//
// Created by usman on 9/22/22.
//

#ifndef CPPALGORITHMS_SHORTESTPALINDROME_H
#define CPPALGORITHMS_SHORTESTPALINDROME_H

#include <string>
#include <algorithm>
using namespace std;

class ShortestPalindrome {
public:
    static string shortestPalindromeKPM(string s) {
        int n = s.size();
        string rev(s);
        reverse(rev.begin(), rev.end());
        //add a delimiter between old and new to differentiate between the two
        string s_new = s + "#" + rev;
        int n_new = s_new.size();
        vector<int> f(n_new, 0);
        //start from beginning
        for (int i = 1; i < n_new; i++) {
            int j = f[i - 1];
            while (j > 0 && s_new[i] != s_new[j]) {
                //work backwards to find the longest suffix which is also a prefix
                //this enables us to use the prior information to skip some unnecessary matches
                //i.e.     abcabcaby
                //         abcaby--> when y doesn't match you check in the table to see that the longest prefix is 2,
                //         so you try to match from the second character which in-fact matches
                j = f[j - 1];
            }
            if (s_new[i] == s_new[j]) {
                ++j; //when strings match increment j
            }
            f[i] = j; //j indicates the length of the suffix and prefix which have so far matched
        }
        return rev.substr(0, n - f[n_new - 1]) + s;
    }

    static string shortestPalindrome(string s) {
        int n = s.size();
        int i = 0;
        //how many characters match in the string
        for (int j = n - 1; j >= 0; j--) {
            if (s[i] == s[j])
                i++;
        }
        if (i == n) {
            return s;
        }
        string  remain_rev = s.substr(i, n);
        reverse(remain_rev.begin(), remain_rev.end());
        string val = shortestPalindrome(s.substr(0, i));
        cout << " remain_rev " << remain_rev << ", retShortest " << val << ", substr " << s.substr(i) << endl;

        return remain_rev + val + s.substr(i);
    }

};

#endif //CPPALGORITHMS_SHORTESTPALINDROME_H
