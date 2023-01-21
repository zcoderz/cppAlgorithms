//
// Created by usman on 1/20/23.
//

#ifndef CPPALGORITHMS_MEDIANOFTWOSORTEDARRAYS_H
#define CPPALGORITHMS_MEDIANOFTWOSORTEDARRAYS_H
#include <vector>
#include <climits>

using namespace std;

class MedianOfTwoSortedArrays {
public:
    /**
     * Idea is :
     * 1. Calculate the partition size of the two vectors combined
     * 2. Allocate a chunk of partition to one vector and the remaining to the other vector
     * 3. Do a binary search on the smaller vector, moving its partition left or right.
     * 4. For each partition in an array , have left and right sides of the partition.
     *    for even partitions left is towards the left of middle and right to the right
     *    for odd partitions left is the median
     * 5. Compare left and right intervals from the two partitions.
     *    left of each partition should be less than than right of the other partition.
     *    when this holds, we are at the correct partition indexes.
     * 6. For odd partitions so that left is at the median, make partition equal to (total length +1)/2
     *    -- for example for arrays [1,2] & [7,8,9] median is 7
     *    -- for left to be at 7, right has to be at index 8. which is the 3rd index.
     *    -- thus partition length = 3 = (5+1)/2
     * @param nums1
     * @param nums2
     * @return
     */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            //do binary search on the smaller array
            return findMedianSortedArrays(nums2, nums1);
        }
        int totalSz = nums1.size() + nums2.size();
        int partitionSz = (totalSz+1)/2;
        int lo=0, hi= nums1.size();
        while (lo <= hi) {
            int partition = lo + (hi-lo)/2;
            int otherPartition = partitionSz-partition;
            int aLeft = partition > 0 ? nums1[partition-1] : INT_MIN;
            int aRight = partition >= nums1.size() ? INT_MAX : nums1[partition];
            int bLeft = otherPartition > 0 ? nums2[otherPartition-1] : INT_MIN;
            int bRight = otherPartition >= nums2.size() ? INT_MAX : nums2[otherPartition];
            if (aLeft > bRight) {
                //move the first partition left
                hi = partition-1;
            } else if (bLeft > aRight) {
                //move first partition right
                lo = partition+1;
            }  else {
                //partitions are correct
                if (totalSz%2==0) {
                    return (max(aLeft, bLeft)+ min(aRight, bRight))/2.0;
                } else {
                    return max(aLeft, bLeft);
                }
            }
        }
        return 1.0;
    }
};

#endif //CPPALGORITHMS_MEDIANOFTWOSORTEDARRAYS_H
