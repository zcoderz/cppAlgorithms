//
// Created by usman on 1/23/23.
//

#ifndef CPPALGORITHMS_MAXIMUMAVERAGESUBARRAYII_H
#define CPPALGORITHMS_MAXIMUMAVERAGESUBARRAYII_H

#include <vector>
#include <climits>
#include <cstdlib>
#include <iostream>

using namespace std;

class MaximumAverageSubarrayII{
public:

    /**
     * target is the desired median of a subarray of length k
     * algo checks whether the target median can be reached or not
     * @param nums
     * @param target
     * @param k
     * @return
     */
    static bool possible(vector<int>& nums, double target, int k) {
        double currSum=0;
        int j=0;
        //get the running some until first k integers with target subtracted.
        for (; j < k; j++) {
            currSum += (nums[j]-target);
        }
        //if currSum is positive then it means that target is achievable
        if (currSum >= 0) return true;
        double priorSum = 0;
        double minPrior = 0;
        for (; j < nums.size(); j++) {
            //keep updating current sum
            currSum += (nums[j]-target);
            priorSum += (nums[j-k]-target);
            //track the smallest sub array towards left of the array
            minPrior = min(minPrior, priorSum);
            //currSum is total , its just saying currSum - minPrior >= 0
            if (currSum >= minPrior) return true;
        }
        return false;
    }

    static double findMaxAverage(vector<int>& nums, int k) {
        int minV = INT_MAX;
        int maxV = INT_MIN;
        for (int num: nums) {
            minV = min(minV, num);
            maxV = max(maxV, num);
        }
        double l = minV, r = maxV;
        double epsilon = 1e-5;
        double priorMid = INT_MAX;
        double mid = l + (r-l)/2.0;
        //converge towards the highest possible mid
        while (abs(mid-priorMid) > epsilon) {
            if (possible(nums, mid, k)) {
                l = mid;
            } else {
                r = mid;
            }
            priorMid = mid;
            mid = l + (r-l)/2.0;
        }
        return mid;
    }

    static void testMe() {
        vector<int> data = {1,12,-5,-6,50,3};
        double res = findMaxAverage(data, 4);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_MAXIMUMAVERAGESUBARRAYII_H
