//
// Created by usman on 10/31/22.
//

#ifndef CPPALGORITHMS_UNIQUEBINARYSEARCHTREES_H
#define CPPALGORITHMS_UNIQUEBINARYSEARCHTREES_H

#include <vector>

using namespace std;

class UniqueBinarySearchTree {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        if (n==1) return 1;
        dp[0]=1;
        dp[1]=1;
        for (int i=2; i <= n; i++) {
            int cnt =0;
            for (int j=i-1; j>=0; j--) {
                cnt += (dp[j] * dp[i-j-1]);
            }
            dp[i] = cnt;
        }
        return dp[n];
    }
};

#endif //CPPALGORITHMS_UNIQUEBINARYSEARCHTREES_H
