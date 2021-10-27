//
// Created by usman on 10/16/21.
//

#ifndef KICK_START_THREEWAYQUICKSORT_H
#define KICK_START_THREEWAYQUICKSORT_H

#include <algorithm>

using namespace std;

class ThreeWayQuickSort {
private:

    void partition(int arr[] , int left, int right) {
        if (left >= right) {
            return ;
        }
        int origLeft = left;
        int origRight = right;
        int partitionIndex = left + (right-left) /2;
        swap(arr[left],arr[partitionIndex]);
        int pivotVal = arr[left];
        int i = left + 1;
        while (i <= right) {
            if (arr[i] < pivotVal) {
                swap(arr[i++], arr[left++]);
            } else if (arr[i] > pivotVal) {
                swap(arr[i], arr[right--]);
            } else {
                i++;
            }
        }
        partition(arr, origLeft, left-1);
        partition(arr, right+1, origRight);
    }
public:
    void runQuickSort(int arr[], int sz) {
        partition(arr, 0, sz-1);
    }
};

#endif //KICK_START_THREEWAYQUICKSORT_H