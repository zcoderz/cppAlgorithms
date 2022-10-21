//
// Created by usman on 10/21/22.
//

#ifndef CPPALGORITHMS_KNIGHTDIALER_H
#define CPPALGORITHMS_KNIGHTDIALER_H

#include <vector>
#include <numeric>
using namespace std;

class KnightDialer {
public:
    int knightDialer(int n) {
        vector<vector<int>> moves {{4,6},{8,6},{7,9},{4,8}, {0,9,3},{},{7,1,0}, {2,6}, {1,3}, {2,4}};
        vector<vector<long>> dp(2, vector<long> (10, 0));
        int index =0;
        for (int i =0; i < 10; i++) dp[index][i]=1;
        index++;
        int MOD = 1000000007;
        int priorIndex;
        for (int i=1; i < n; i++) {
            priorIndex = (index+1) % 2;
            for (int j=0; j < 10; j++) {
                dp[index][j] = 0;
                for (int k : moves[j]) {
                    dp[index][j] = (dp[index][j] + (dp[priorIndex][k])) % (MOD) ;
                }
            }
            index = priorIndex;
        }
        priorIndex = (index+1) % 2;
        long sum=0;
        for (long v: dp[priorIndex]) {
            sum = (sum + v) % MOD;
        }
        return (int) sum;
    }
};

#endif //CPPALGORITHMS_KNIGHTDIALER_H
