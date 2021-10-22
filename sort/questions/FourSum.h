//
// Created by usman on 10/22/21.
//

#ifndef CPPALGORITHMS_FOURSUM_H
#define CPPALGORITHMS_FOURSUM_H

#endif //CPPALGORITHMS_FOURSUM_H

#include <vector>
#include <unordered_set>

using namespace std;

class FourSum{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target, int k) {
        sort(nums.begin(), nums.end());
        return processKSum(nums, 0, nums.size()-1, target, 4);
    }

    vector<vector<int>> processKSum(vector<int>& nums, int left, int right, int target, int k) {
        vector<vector<int>> res;
        if ((right-left+1) < k) {
            //if K is so out of bounds exit early.
            return res;
        }
        long max = (long) nums[right];
        if ((k * max) < target) {
            return res;
        }

        long min = (long) nums[left];
        if ((k * min) > target) {
            return res;
        }

        if (k == 2) {
            return  processTwoSum(nums, left, right, target);
        }

        for (int i =left; i < right; i++) {
            if (i ==left || nums[i-1] != nums[i]) {
                for (vector<int> &vecReturned: processKSum(nums, i + 1, right, target - nums[i], k - 1)) {
                    //if (vecReturned.empty()) continue;
                    vecReturned.push_back(nums[i]);
                    res.push_back(vecReturned);
                }
            }
        }
        return res;
    }

    vector<vector<int>> processTwoSum(vector<int>& nums, int left, int right, int target) {
        unordered_set<int> set;
        vector<vector<int>> res;
        for (int i = left; i <= right; i++) {
            int val = target - nums[i];
            //res.back()[1] simplifies duplicate processing a whole lot!
            if (res.empty() || res.back()[1] != nums[i]) {
                if (set.find(val) != set.end()) {
                    res.push_back({val, nums[i]});
                }
            }
            set.insert(nums[i]);
        }
        return res;
    }
};