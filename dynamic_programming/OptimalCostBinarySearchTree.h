//
// Created by usman on 11/6/22.
//

#ifndef CPPALGORITHMS_OPTIMALCOSTBINARYSEARCHTREE_H
#define CPPALGORITHMS_OPTIMALCOSTBINARYSEARCHTREE_H

#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>

using namespace std;
class OptimalCostBinarySearchTree {
public:
    int minCost(vector<int> & keys, vector<int> & freq){
        int sz = keys.size();

        //dp[i][j] represents the min cost of constructing a tree serving keys from index i to j
        vector<vector<int>> dp(sz, vector<int> (sz));
        for (int i =0; i < sz; i++) {
            //diagonal in the matrix represents the cost with index at the root of the tree
            dp[i][i] = freq[i];
        }

        //start from processing length of 2 and moving on
        for (int len =2; len < sz; len++) {
            //loop from first size-len (if size is 4 and len is 2, last starting index is 2)
            for (int i=0; i <= sz - len; i++) {
                int j = i + len -1; //end index is len-1 ahead
                int sum = accumulate(freq.begin()+i, freq.begin()+j, 0);
                int cost = INT_MAX;
                //k is the index in middle and ranges from i.....j
                for (int k =i; k < j; k++) {
                    int left = k==0? 0: dp[i][k-1];
                    int right = k==sz-1? 0: dp[k+1][j];
                    cost = min(cost, sum + left + right);
                }
            }
        }
        return dp[0][sz-1];
    }

    int minCostRec (vector<int> & freq, int left, int right, int level) {
        if (left > right) return 0;

        int cost = INT_MAX;
        for (int i=left; i <= right; i++) {
            cost = min(cost, freq[i]*level + minCostRec(freq, left, i-1, level+1) + minCostRec(freq, i+1, right, level+1));
        }
        return cost;
    }

    int minCostRec (vector<int> & freq) {
        return minCostRec(freq, 0, freq.size()-1, 1);
    }
};

#endif //CPPALGORITHMS_OPTIMALCOSTBINARYSEARCHTREE_H
