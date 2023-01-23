//
// Created by usman on 1/22/23.
//

#ifndef CPPALGORITHMS_MAXSUMOFRECTANGLENOLARGERTHANK_H
#define CPPALGORITHMS_MAXSUMOFRECTANGLENOLARGERTHANK_H

#include <vector>
#include <climits>
#include <set>
using namespace std;


class MaxSumOfRectangleNoLargerThanK {
public :

    int kadenceSum(vector<int> & data) {
        int maxS=INT_MIN;
        int sum=0;
        for (int i =0; i < data.size(); i++) {
            sum = max(sum+data[i], data[i]);
            maxS = max(sum, maxS);
        }
        return maxS;
    }

    /**
     * This is a useful algo. You keep running sum in a set. And search for a value in the set, which is "sum - target",
     * that can be subtracted to get to target.
     * @param data
     * @param k
     * @return
     */
    int calcSum(vector<int> & data, int k) {
        int res = kadenceSum(data);
        if (res <=k) return res;
        set<int> sums; sums.insert(0);
        int sum=0;
        int maxV=INT_MIN;
        //below code doesnt handle case of sum < k as its handled by the kadence sum algo above
        for (int val : data) {
            sum += val;
            //look for the minimum value by which sum is over the desired k.
            //in case sum is less than or equal to k, this will be negative or 0 and iter would point to the 0th element
            //that we just added above
            int target = sum-k;
            auto iter = sums.lower_bound(target);
            if (iter != sums.end()) {
                maxV = max (maxV, sum-*iter);
                if (maxV==k) return maxV;
            }
            //sums is the running sum of the data
            sums.insert(sum);
        }
        return maxV;
    }

    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int cols = matrix[0].size();
        int maxS=INT_MIN;
        for (int i =0; i < matrix.size(); i++) {
            vector<int> rowsAggregate(cols);
            for (int j =i; j < matrix.size(); j++) {
                for (int l =0; l < cols; l++) {
                    rowsAggregate[l] += matrix[j][l];
                }
                maxS = max(maxS, calcSum(rowsAggregate, k));
                if (maxS==k) return maxS;
            }
        }
        return maxS;
    }
};

#endif //CPPALGORITHMS_MAXSUMOFRECTANGLENOLARGERTHANK_H
