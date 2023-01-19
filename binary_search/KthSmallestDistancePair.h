//
// Created by usman on 1/18/23.
//

#ifndef CPPALGORITHMS_KTHSMALLESTDISTANCEPAIR_H
#define CPPALGORITHMS_KTHSMALLESTDISTANCEPAIR_H

#include <vector>
#include <algorithm>

using namespace std;

class KthSmallestDistancePair {
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int lo=0; //smallest diff is 0
        int hi= nums[nums.size()-1] - nums[0]; //largest diff is btw largest and smallest

        //do a binary search for diffs in range of lo--hi
        //and for each diff find how many pairs satisfy it.
        //converge lo and hi on k cnt
        while (hi > lo) {
            int left = 0;
            int mid = lo + (hi-lo)/2;
            int cnt = 0;
            for (int right =0; right < nums.size(); right++) {
                while (nums[right]-nums[left] > mid) left++;
                cnt += right - left; //right-left is the number of pairs that are less than mid
            }
            if (cnt >= k) {
                hi=mid;
            } else {
                lo=mid+1;
            }
        }
        return lo;
    }
};

#endif //CPPALGORITHMS_KTHSMALLESTDISTANCEPAIR_H
