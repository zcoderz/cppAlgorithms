//
// Created by usman on 10/24/22.
//

#ifndef CPPALGORITHMS_MAXPRODUCTSUBARRAY_H
#define CPPALGORITHMS_MAXPRODUCTSUBARRAY_H

#include <vector>
#include <climits>
using namespace std;

class MaxProductSubArray {
public:
    int maxProduct(vector<int>& nums) {
        int maxV=nums[0];
        int minProduct = nums[0];
        int maxProduct = nums[0];
        for (int i =1 ; i < nums.size(); i++) {
            int tmp = maxProduct;
            maxProduct = max(nums[i] , max(maxProduct * nums[i], minProduct * nums[i]));
            maxV = max(maxV, maxProduct);
            minProduct = min(nums[i],  min(minProduct* nums[i], tmp * nums[i]));
        }
        return maxV;
    }
};

#endif //CPPALGORITHMS_MAXPRODUCTSUBARRAY_H
