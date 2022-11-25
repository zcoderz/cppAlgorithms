//
// Created by usman on 11/22/22.
//

#ifndef CPPALGORITHMS_PALINDROMEREMOVAL_H
#define CPPALGORITHMS_PALINDROMEREMOVAL_H

#include <vector>
#include <iostream>
#include <climits>
using namespace std;

class PalindromeRemoval {
public:
    static int minimumMoves(vector<int>& arr) {
        int sz = arr.size();
        vector<vector<int>> dp(sz, vector<int> (sz, sz));
        for (int i =0; i < sz; i++) {
            dp[i][i] =1;
        }
        for (int i =0; i < sz-1; i++) {
            if (arr[i] == arr[i+1])
                dp[i][i+1] =1;
            else
                dp[i][i+1] =2;
        }
        for (int gap = 3; gap <= sz; gap++) {
            for (int left =0, right = left+gap-1; right < sz; left++, right++) {
                if (arr[left]==arr[right]) {
                    dp[left][right] = dp[left+1][right-1];
                }
                for (int mid=left; mid<right; mid++) {
                    dp[left][right] = min(dp[left][right], dp[left][mid] + dp[mid+1][right]);
                }
            }
        }
        return dp[0][sz-1];
    }

    static void testMe() {
        vector<int> vals = {1,3,4,1,5};
        int res = minimumMoves(vals);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_PALINDROMEREMOVAL_H
