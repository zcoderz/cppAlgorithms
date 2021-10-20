//
// Created by usman on 10/19/21.
//

#ifndef KICK_START_KTHLARGESTINANARRAY_H
#define KICK_START_KTHLARGESTINANARRAY_H

#endif //KICK_START_KTHLARGESTINANARRAY_H
#include <vector>
#include <algorithm>

using namespace std;

class KthLargestInAnArray {

    /**
     * three way partition - quick select
     * @param numbers
     * @param left
     * @param right
     * @param kth
     */
    void partition(vector<int> & numbers, int left, int right, int kth) {
        if (left >= right) return;
        int origLeft = left;
        int origRight = right;
        int mid = left + (right-left) / 2;
        swap(numbers[mid], numbers[left]);
        int compVal = numbers[left];
        int currIndex = left+1;
        while (currIndex <= right) {
            //swap smaller items to left of array
            if (numbers[currIndex] < compVal) {
                swap(numbers[currIndex++], numbers[left++]);
            } else if (numbers[currIndex] > compVal) {
                swap(numbers[currIndex], numbers[right--]);
            } else {
                currIndex++;
            }
        }
        if (kth < left) {
            partition(numbers, origLeft, left-1, kth);
        } else if (kth > right) {
            partition(numbers, right+1, origRight, kth);
        }
    }

    /**
     * two way partition quick select
     * @param numbers
     * @param left
     * @param right
     * @return
     */
    int partition(vector<int> & numbers, int left, int right) {
        int mid = left + (right-left) / 2;
        swap(numbers[mid], numbers[right]);
        int compVal = numbers[right];
        int currIndex = left;
        while (currIndex <= right) {
            //swap smaller items to left of array
            if (numbers[currIndex] < compVal) {
                swap(numbers[currIndex++], numbers[left++]);
            } else {
                currIndex++;
            }
        }
        swap(numbers[left], numbers[right]);
        return left;
    }

    void quickSelect(vector<int> & numbers, int left, int right, int k) {
        if (left >= right) return;
        int partitionIndex = partition(numbers, left, right);
        if (partitionIndex == k) {
            return;
        } else if (partitionIndex > k) {
            quickSelect(numbers, left, partitionIndex-1, k);
        } else {
            quickSelect(numbers, partitionIndex+1, right, k);
        }
    }

    int kth_largest_in_an_array(vector<int> numbers, int k) {
        int index = numbers.size() -k;
        partition(numbers, 0, numbers.size()-1, index);
        return numbers[index];
    }

    int kth_largest_in_an_array_twoway(vector<int> numbers, int k) {
        int index = numbers.size() -k;
        quickSelect(numbers, 0, numbers.size()-1, index);
        return numbers[index];
    }
};