//
// Created by usman on 11/7/22.
//

#ifndef CPPALGORITHMS_MAXSUMOFRECTANGLENOLARGERTHANK_H
#define CPPALGORITHMS_MAXSUMOFRECTANGLENOLARGERTHANK_H
#include <set>
#include <vector>
#include <iostream>
#include <climits>
using namespace std;

/**
 * https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/description/
 * DINOSAUR : This is a very tricky one......need to do again.
 */
class MaxSumRectangleLessThanK {
public:
    int result = INT_MIN;

    int kadaneSum(vector<int>& nums) {
        int maxSum = nums[0];
        int sum=nums[0];
        for(int i=1; i < nums.size(); i++) {
            sum = max(nums[i], sum+ nums[i]);
            maxSum = max (sum, maxSum);
        }
        return maxSum;
    }

    void updateResult(vector<int>& nums, int k) {
        int kSum = kadaneSum(nums);
        if (kSum <= k) {
            result = max(result, kSum);
            return;
        }
        //handle cases where submatrix sum is always less than k (insert 0)
        set<int> sortedData; sortedData.insert(0);
        int sum =0;
        for (int val : nums) {
            sum += val;
            //finding the largest possible matrix which when subtracted from sum will produce a result of k or less
            int target = sum-k;
            auto iter = sortedData.lower_bound(target);
            if (iter != sortedData.end())
                result = max (result, sum-*iter);

            sortedData.insert(sum);
        }
    }

    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        for (int i =0; i < rows; i++) {
            vector<int> rowData(cols);
            for (int j=i ; j < rows; j++) {
                for (int l=0; l < cols; l++) {
                    rowData[l] += matrix[j][l];
                }
                updateResult(rowData, k);
                if (result==k) return k;
            }
        }
        return result;
    }

    static void testMe() {
        vector<vector<int>> matrix = {{2,2,-1}};
        MaxSumRectangleLessThanK maxSum ;

        int res = maxSum.maxSumSubmatrix(matrix, 0);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_MAXSUMOFRECTANGLENOLARGERTHANK_H
