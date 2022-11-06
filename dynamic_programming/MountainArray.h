//
// Created by usman on 11/4/22.
//

#ifndef CPPALGORITHMS_MOUNTAINARRAY_H
#define CPPALGORITHMS_MOUNTAINARRAY_H

#include <vector>
#include <iostream>

using namespace std;
class MountainArray {
public:
    static int minimumMountainRemovals(vector<int>& nums) {
        vector<int> dpUp(nums.size(),1);
        for (int i =0; i < nums.size(); i++) {
            for (int j=0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dpUp[i] = max(dpUp[i], dpUp[j]+1);
                }
            }
        }

        vector<int> dpDown(nums.size(),1);
        for (int i = nums.size()-1; i >=0; i--) {
            for (int j=nums.size()-1; j > i; j--) {
                if (nums[i] > nums[j]) {
                    dpDown[i] = max(dpDown[i], dpDown[j]+1);
                }
            }
        }


        int maxMountainLen = 0;
        for (int i =0; i < nums.size(); i++) {
            maxMountainLen= max(maxMountainLen, dpDown[i] + dpUp[i]-1);
        }

        return nums.size() - maxMountainLen;
    }

    static void testMe() {
        vector<int> vals = {9,8,1,7,6,5,4,3,2,1};
        int res = minimumMountainRemovals(vals);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_MOUNTAINARRAY_H
