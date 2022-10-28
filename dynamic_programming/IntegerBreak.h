//
// Created by usman on 10/21/22.
//

#ifndef CPPALGORITHMS_INTEGERBREAK_H
#define CPPALGORITHMS_INTEGERBREAK_H
#include <vector>
#include <iostream>
using namespace std;
class IntegerBreak {
public:
    static int integerBreak(int n) {
        if (n==2) return 1;
        vector<int> table(n+1); //table(0) has no meaning
        table[1] = 1;
        table[2] = 2;
        for (int i=3; i <=n; i++) {
            int best;
            if (i==n) best = i-1; //special case: the overall rod must be split at least once. hence can do 1*n-1
            else best = i; //the rod doesn't need to be split
            for (int j=1; j < i; j++) {
                best = max(best, table[j] * table[i-j]);
            }
            table[i] = best;
        }
        return table[n];
    }

    int integerBreakSimples(int n) {
        if (n==2) return 1;
        vector<int> dp(n+1);
        for (int i =1; i <=n; i++) {
            int l=1, k=i-1;
            dp[i] = i==n ? i-1 : i; //the number needs to be broken into atleast two pieces
            while (k>=l) {
                dp[i] = max(dp[i], dp[l++]*dp[k--]);
            }
        }
        return dp[n];
    }

    static void testMe() {
        int v = integerBreak(5);
        cout << v << endl;
    }
};
#endif //CPPALGORITHMS_INTEGERBREAK_H
