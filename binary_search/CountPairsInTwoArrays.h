//
// Created by usman on 1/17/23.
//

#ifndef CPPALGORITHMS_COUNTPAIRSINTWOARRAYS_H
#define CPPALGORITHMS_COUNTPAIRSINTWOARRAYS_H

#include <vector>
#include <algorithm>

using namespace std;

/**
 * This is a very clever problem!
 *
 * Given two integer arrays nums1 and nums2 of length n, count the pairs of indices (i, j)
 * such that i < j and nums1[i] + nums1[j] > nums2[i] + nums2[j].
 * Return the number of pairs satisfying the condition.
 *
 * The above equation can be rewritten as : nums1[i] - nums2[i] + nums1[j] - nums2[j] > 0.
 * return number of pairs that are true for the above equation
 *
 * 1. Diffs array can be created and nums1-nums2 be stored in it
 * 2. The diffs array is then sorted
 * 3. Start from right and left ends.
 *    i.e. -5/0, -4/1, -3/2, 3/3, 4/4, 6/5
 *    1. right at index 5 is 6 and left at index 0 is -5 , 6 + -5 = 1 which is greater than 0.
 *       and all numbers at indexes between 0 and 5 hold for the above.
 *    2. now right is at index 4, 4 + (-5) is -1, you move left forward, 4-4 is 0, wont work, move forward
 *       works at 4-3, and we get 4-2 combinations. now we move right further left and so on until right > left
*/
class CountPairInTwoArrays {
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        vector<int> diffs(nums1.size());
        for (int i =0; i < nums1.size(); i++) {
            diffs[i] = nums1[i] - nums2[i];
        }
        sort(diffs.begin(), diffs.end());
        int ans=0;
        int left =0;
        int right = diffs.size()-1;
        while (left < right) {
            if (diffs[right]+diffs[left] > 0) {
                ans += (right-left); right--;
            } else {
                left++;
            }
        }
        return ans;
    }
};

#endif //CPPALGORITHMS_COUNTPAIRSINTWOARRAYS_H
