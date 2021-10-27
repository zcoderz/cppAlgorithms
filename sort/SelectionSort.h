//
// Created by usman on 10/13/21.
//

#ifndef KICK_START_SELECTIONSORT_H
#define KICK_START_SELECTIONSORT_H


#include <algorithm>
class SelectionSort {

public:
    void runSelectionSort(int arr[], int sz) {

        for (int i =0; i < sz; i++) {
            int minIndex = i;
            for (int j=i+1; j < sz; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            std::swap(arr[i], arr[minIndex]);
        }
    }
};
#endif //KICK_START_SELECTIONSORT_H