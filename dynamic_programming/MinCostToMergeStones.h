//
// Created by usman on 10/20/22.
//

#ifndef CPPALGORITHMS_MINCOSTTOMERGESTONES_H
#define CPPALGORITHMS_MINCOSTTOMERGESTONES_H

#include <vector>
#include <iostream>

using namespace std;

/**
 * Dinosaur : NEED TO DO AGAIN
 */
class MinCostToMergeStones {
public:

    int dp[31][31];
    int K;

    int mergeKstones(vector<int>& stones,int l, int r, vector<int>& sum)
    {
        if(r-l<=K-2) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        int ans = INT_MAX;
        //on every merge k piles are transformed into 1 pile, so it removes k piles and adds 1 which is k-1.
        //after m merges, we are left with 1 pile. so (k-1)*m + 1 (left with one) = size
        //hence (k-1)*m = size -1

        //on each call K-1 piles are merged.
        for(int t=l; t<r; t+=K-1) {
            ans = min(ans,mergeKstones(stones,l,t,sum)+mergeKstones(stones,t+1,r,sum));
        }

        if((r-l)%(K-1)==0) {
            ans += sum[r+1]- sum[l];
        }
        return dp[l][r] = ans;
    }

    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        K = k;

        if((n-1)%(k-1) != 0) return -1;

        vector<int> sum(n+1,0);

        for(int i=1;i<=n;i++)
        {
            sum[i] = sum[i-1]+stones[i-1];
        }

        memset(dp,-1,sizeof(dp));
        return mergeKstones(stones,0,n-1,sum);
    }

    static int minCostUQ(vector<int> & prefix, vector<vector<vector<int>>> & dp, int i, int j, int k, int noPiles) {
        static int MAX = 100000;
        if (i==j && noPiles ==1) return 0;
        if (i==j) return MAX;
        if (dp[i][j][noPiles] != -1) {
            return dp[i][j][noPiles];
        }
        if (noPiles == 1) {
            //cost of merging into 1 pile is same as cost of merging k piles into 1 + prefix [i->j]
            dp[i][j][noPiles] = minCostUQ (prefix, dp, i, j, k, k) + (i==0 ? prefix[j] : prefix[j] - prefix[i-1]);
            return dp[i][j][noPiles];
        }
        int minCostV = MAX;
        for (int m=i; m < j; m++) {
            //cost of merging into 1 pile is same as cost of merging k piles into 1 + prefix [i->j]
            minCostV = min(minCostV,  minCostUQ(prefix, dp, i, m, k, 1)  + minCostUQ (prefix, dp, m+1, j, k, noPiles-1));
        }
        dp[i][j][noPiles] = minCostV;
        return dp[i][j][noPiles];
    }

    static int mergeStonesUQ(vector<int>& stones, int k) {
        int size = stones.size();
        //on every merge k piles are transformed into 1 pile, so it removes k piles and adds 1 which is k-1.
        //after m merges, we are left with 1 pile. so (k-1)*m + 1 (left with one) = size
        //hence (k-1)*m = size -1
        if ( (size-1) % (k-1) !=0) return -1;
        vector<vector<vector<int>>> dp(size, vector<vector<int>> (size, vector<int> (k+1, -1)));
        vector<int> prefix (size);
        for (int i =0; i < size; i++) {
            prefix[i] = i == 0 ? stones[i] : prefix[i-1] + stones[i];
        }
        return minCostUQ (prefix, dp, 0, size-1, k, 1);
    }

    static void testMe() {
        vector<int> stones = {3,2,1,2,4};
        int k = 3;
        MinCostToMergeStones ms{};
        int res = ms.mergeStones(stones, k);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_MINCOSTTOMERGESTONES_H
