//
// Created by usman on 1/19/23.
//

#ifndef CPPALGORITHMS_MAXIMUMSCOREOFAGOODSUBARRAY_H
#define CPPALGORITHMS_MAXIMUMSCOREOFAGOODSUBARRAY_H

#include <vector>
#include <climits>

using namespace std;

class MaximumScoreOfAGoodSubarray {
public:
    int maximumScore(vector<int>& nums, int k) {
        int sz = nums.size();
        int res = nums[k];
        int i=k, j =k;
        int minNum = nums[k];
        while (true) {
            if (i > 0 && j < sz-1) {
                if (nums[i-1] > nums[j+1]) {
                    i--;
                } else {
                    j++;
                }
            } else if (j== sz-1 && i > 0) {
                i--;
            } else if (i==0 && j < sz-1) {
                j++;
            }
            minNum = min(minNum, min(nums[i], nums[j]));
            res = max(res, minNum * (j-i+1));
            if (i==0 && j==sz-1) break;
        }
        return res;
    }
};

#endif //CPPALGORITHMS_MAXIMUMSCOREOFAGOODSUBARRAY_H
