//
// Created by usman on 11/29/22.
//

#ifndef CPPALGORITHMS_CANIWIN_H
#define CPPALGORITHMS_CANIWIN_H

#include <bitset>
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

class CanIWin {
public:

    static bool winPossible(bitset<21> & bits, vector<unordered_map<bitset<21>, bool>> & dp,  int maxChoosableInteger, int desiredTotal, int currTotal, bool turn, bool & crossed) {
        auto & theMap = dp[currTotal];
        auto iter = theMap.find(bits);
        if (iter != theMap.end()) {
            //cout << " current total " << currTotal << " bits used " << bits << " returning cached value " << " turn " << turn << ", res=" << iter->second << endl;
            return iter->second;
        }
        for (int i=1; i <= maxChoosableInteger; i++) {
            if (bits[i]) continue;
            if ((currTotal + i) >= desiredTotal) {
                crossed = true;
                //cout << " current total " << currTotal << " bits used " << bits << " returning true " << " turn " << turn << " on add " << i << endl;
                theMap[bits] = true;
                return true;
            }
            bits[i] = true;
            bool  nextWinPossible = winPossible(bits, dp, maxChoosableInteger, desiredTotal, currTotal+i, !turn, crossed);
            bits[i] = false;
            if (!nextWinPossible) {
                theMap[bits] = true;
                //cout << " current total " << currTotal << " bits used " << bits << " returning true " << " turn " << turn << endl;
                return true;
            }

        }
        theMap[bits] = false;
        //cout << " current total " << currTotal << " bits used " << bits << " returning false " << " turn " << turn << endl;
        return false;
    }

    static bool canIWinSlow(int maxChoosableInteger, int desiredTotal) {
        vector<unordered_map<bitset<21>, bool>> dp(desiredTotal+1);
        bitset<21> bits;
        bool crossed = false;
        return winPossible(bits, dp, maxChoosableInteger, desiredTotal, 0, true, crossed) && crossed;
    }

    static bool winPossible(int dp [] , int maxChoosableInteger, int remaining, int mask) {
        int & res = dp[mask];
        if (res != -1) return res;
        for (int i =1; i <= maxChoosableInteger; i++) {
            if ( (1 << (i-1) ) & mask) continue;
            int left =  remaining-i;
            if (left <=0) {
                res = 1;
                return true;
            }
            bool next = winPossible(dp, maxChoosableInteger, left, mask | (  1 << (i-1) ));
            if (!next) {
                res = 1;
                return true;
            }
        }
        res = 0;
        return false;
    }

    static bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger*(maxChoosableInteger+1)/2 < desiredTotal) return false;
        int dp [(1 << 20)] ;
        memset(dp, -1, sizeof(dp));
        return winPossible(dp, maxChoosableInteger, desiredTotal, 0);
    }

    static void testMe() {
        bool res = canIWin(5,50);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_CANIWIN_H
