//
// Created by usman on 11/21/22.
//

#ifndef CPPALGORITHMS_WAYSTODISTRIBUTECANDIES_H
#define CPPALGORITHMS_WAYSTODISTRIBUTECANDIES_H


#include <vector>
#include <iostream>
using namespace std;

class CountWaysToDistributeCandies {
public:
    static int waysToDistribute(int n, int k) {
        typedef long long ll;
        vector<vector<ll>> dp (n+1, vector<ll> (k+1));
        for (int i =1; i <=k; i++) {
            dp[i][i] = 1;
        }

        for(int j =1; j <=k; j++) {
            for (int i=2; i <=n; i++) {
                //if you have put i-1 candies already into j bags then the ith candy can go into any of the j bags
                //hence possibilities are j * dp[i-1][j]
                //other option is you put i-1 candies into the j-1 bags and put the ith candy into the new jth bag
                dp[i][j] = (j * dp[i-1][j] + dp [i-1][j-1]) % 1000000007;
            }
        }
        return dp[n][k];
    }

    static void testMe() {
        int res = waysToDistribute(3, 2);
        cout << res << endl;
    }
};
#endif //CPPALGORITHMS_WAYSTODISTRIBUTECANDIES_H
