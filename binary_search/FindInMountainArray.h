//
// Created by usman on 1/19/23.
//

#ifndef CPPALGORITHMS_FINDINMOUNTAINARRAY_H
#define CPPALGORITHMS_FINDINMOUNTAINARRAY_H

#include <vector>
using namespace std;

class FindInMountainArray {
    class MountainArray {
    public:
        int get(int index);
        int length();
    };

public:
    static int binarySearch(int left, int right, int target, MountainArray &mountainArr, bool ascending) {
        while (right > left) {
            int mid;
            if (ascending)
                mid = left + (right-left+1)/2;
            else
                mid = left + (right-left)/2;

            int mVal = mountainArr.get(mid);

            if (ascending && mVal > target) {
                right=mid-1;
            } else if (!ascending && mVal > target) {
                left=mid+1;
            } else if (ascending) {
                left = mid;
            } else {
                right=mid;
            }
        }
        return mountainArr.get(left) == target ? left : -1;
    }

    static int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak =0;
        int left = 0;
        int sz = mountainArr.length()-1;
        int right = sz-1;
        while (right > left) {
            int mid = left + (right-left)/2;
            int mVal = mountainArr.get(mid);
            if (mountainArr.get(mid+1) > mVal) {
                left = mid+1;
            } else {
                right = mid;
            }
        }
        peak = left;
        int index = binarySearch(0, peak, target, &mountainArr);
        return (index != -1) ? index : binarySearch(peak+1, sz-1, target, &mountainArr);
    }

    static void testMe() {
        vector<int> vals = {}
    }

};

#endif //CPPALGORITHMS_FINDINMOUNTAINARRAY_H
