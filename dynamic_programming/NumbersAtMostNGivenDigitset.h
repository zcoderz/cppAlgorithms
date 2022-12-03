//
// Created by usman on 12/2/22.
//

#ifndef CPPALGORITHMS_NUMBERSATMOSTNGIVENDIGITSET_H
#define CPPALGORITHMS_NUMBERSATMOSTNGIVENDIGITSET_H

#include <stdio.h>
#include <vector>
#include <string>
#include <queue>
#include <cstdlib>
#include <iostream>
using namespace std;

/**
 * This is a very tricky problem to solve via DP.
 * Dinosaur : Write notes....
 */
class NumbersAtMostNGivenDigitSet {
public:

    static int atMostNGivenDigitSetQueue(vector<string>& digits, int n) {
        queue<int> theQueue;
        vector<int> iDigits;
        for (string & dig: digits) {
            int val = atoi(dig.c_str());
            iDigits.push_back(val);
            if (val <= n) theQueue.push(val);
        }
        int res = 0;
        int MAX_INT_10 = INT_MAX/10;
        while (!theQueue.empty()) {
            res++;
            int val = theQueue.front();
            cout << val << endl;
            theQueue.pop();
            if (val > MAX_INT_10) continue;
            val *= 10;
            for (int i =0; i < iDigits.size(); i++) {
                if (val > INT_MAX-iDigits[i]) continue;
                int nVal = val + iDigits[i];
                if (nVal <= n) {
                    theQueue.push(nVal);
                }
            }
        }
        return res;
    }

    /**
     * this is tricky!!!
     * @param digits
     * @param n
     * @return
     */
    static int atMostNGivenDigitSet(vector<string>& digits, int n) {
        std::string s = std::to_string(n);
        int sz = s.length();
        int  dp [sz+1];
        memset(dp, 0, sizeof(dp));
        dp[sz]=1;
        for (int i =sz-1; i >=0; --i) {
            int si = s[i] - '0';
            for (string d: digits) {
                int v = atoi(d.c_str());
                if (v < si) {
                    /**
                     * if value is less then the given number at the n digit
                     * say n = 200
                     * say digits are 1,7,6
                     * you compared 1 against 2 and that returned less. the comparison was made at the 0th digit
                     * size of n=3, there are 2 digits to the right of 2 . number of digits is 3 (1,7,6).
                     * you can generate 3^2 combinations.
                     * hence pow(digits.size , # of digits to the right of the index)
                     */
                    dp[i] += pow(digits.size(), sz-i-1);
                } else if (v==si) {
                    /**
                     * if the value is same you can only use number of combinations that existed with one higher digit
                     * say n = 270
                     * digits are [2,8,6]
                     * say you compared 2 against 2 which is same.
                     * hence you can form a number that starts with 2 at that index
                     * so you take number of combinations that are possible one index higher and include them
                     */
                    dp[i] += dp[i+1];
                }
            }
        }
        /**
            if we have a number n = 700, and if we have digits 89
            at index 1, we can generate numbers 8 & 9. that's 2^1
            at digit 2 , we can generate 88, 99, 89 & 98. that's 2^2
            hence irrespective of the digits we can generate digitCount^i...for i from 1 to (sz-1)
         */
        for (int i =1; i < sz; i++) {
            dp[0] += pow(digits.size(), i);
        }
        return dp[0];
    }
    
    static void testMe() {
        vector<string> vals = {"2","8", "6"};
        int res = atMostNGivenDigitSet(vals, 270);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_NUMBERSATMOSTNGIVENDIGITSET_H
