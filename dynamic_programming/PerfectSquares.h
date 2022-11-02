//
// Created by usman on 11/1/22.
//

#ifndef CPPALGORITHMS_PERFECTSQUARES_H
#define CPPALGORITHMS_PERFECTSQUARES_H
#include <math.h>
#include <climits>
#include <vector>
#include <iostream>
using namespace std;
class PerfectSquares {
public:
    static int numSquares(int n) {
        int maxSq = (int) sqrt (n);
        vector<int> sqVec (maxSq+1);
        for (int i = 1; i <= maxSq; i++) {
            sqVec[i] = i*i;
        }

        vector<int> dp(n+1 , INT_MAX); dp[0]=0;
        for (int i=1; i <=n; i++) {
            for (int j=1; j <=maxSq; j++) {
                if ((i- sqVec[j]) < 0) break;
                dp[i] = min(dp[i-sqVec[j]]+1, dp[i]);
            }
        }

        return dp[n];
    }

    static int numSquaresSimpler(int n) {
        vector<int> dp(n+1 , INT_MAX); dp[0]=0;
        for (int i=1; i <=n; i++) {
            for (int j=1; j*j <=i; j++) {
                dp[i] = min(dp[i-j*j]+1, dp[i]);
            }
        }
        return dp[n];
    }

    static void testMe() {
        int v = numSquares(13);
        cout << v << endl;
    }
};

#endif //CPPALGORITHMS_PERFECTSQUARES_H
