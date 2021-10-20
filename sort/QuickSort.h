//
// Created by usman on 10/16/21.
//

#ifndef KICK_START_QUICKSORT_H
#define KICK_START_QUICKSORT_H
#endif //KICK_START_QUICKSORT_H
#include <random>
using namespace std;

class QuickSort {
private:

  void runQuickSort(int arr[], int left, int right) {
        if (left >= right) {
            return;
        }
        int partitionIndex = partition(arr, left, right);
        runQuickSort(arr, left, partitionIndex-1);
        runQuickSort(arr, partitionIndex+1, right);
    }

    int partition(int arr[], int left, int right) {
        //uniform_int_distribution<int> dist(left, right);
        //int partitionIndex = dist(*gen);
        int partitionIndex = left + (right-left)/2;
        swap(arr[left], arr[partitionIndex]);
        int origLeft = left;
        int partitionVal = arr[left++];
        while (true) {
            while (arr[right] > partitionVal) {
                right--;
            }
            while (arr[left] < partitionVal) {
                left++;
            }

            if (left >= right) break;
            swap(arr[left++], arr[right--]);
        }
        swap(arr[origLeft], arr[right]);
        return right;
    }
public:
    QuickSort() {
    }

    ~QuickSort() {
    }

    void runQuickSort(int arr[], int sz) {
        runQuickSort(arr, 0, sz-1);
    }
};