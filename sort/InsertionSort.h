//
// Created by usman on 10/16/21.
//

#ifndef KICK_START_INSERTIONSORT_H
#define KICK_START_INSERTIONSORT_H

#include <algorithm>
using namespace std;

class InsertionSort {
public:
    void runInsertionSort(int arr[], int sz) {
        for (int i = 0; i < sz-1; i++) {
            for (int j = i+1 ; j > 0; j--) {
                if (arr[j] < arr[j-1]) {
                    swap(arr[j], arr[j-1]);
                } else {
                    break;
                }
            }
        }
    }
};
#endif //KICK_START_INSERTIONSORT_H