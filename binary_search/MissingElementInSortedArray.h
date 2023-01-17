//
// Created by usman on 1/16/23.
//

#ifndef CPPALGORITHMS_MISSINGELEMENTINSORTEDARRAY_H
#define CPPALGORITHMS_MISSINGELEMENTINSORTEDARRAY_H

#include <vector>
#include <iostream>
using namespace std;

class MissingElementInSortedArray {
public:
    int missingElement(vector<int>& nums, int k) {
        if (nums.size() == 1) {
            return nums[0] + k;
        }
        int left = 0;
        int right = nums.size() - 1;
        int origMissing = nums[right] - (nums[left] + (right-left));
        if (k > origMissing) {
            return nums[right] + (k - origMissing);
        }
        //break when right and left are adjacent to each other
        while (right > left + 1) {
            int mid = left + (right - left) / 2;
            int numMissing = nums[mid] - (nums[left] + (mid - left));
            if (numMissing < k) {
                left = mid;
                k -= numMissing;
            } else {
                right = mid;
            }
        }
        return nums[left] + k;
    }
    
    static void testMe() {
        vector<int> data = {1,2,4};
        MissingElementInSortedArray missing;
        int v = missing.missingElement(data, 3);
        cout << v << endl;
    }
};

#endif //CPPALGORITHMS_MISSINGELEMENTINSORTEDARRAY_H
