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
            int tmp = arr[i];
            int j;
            for (j = i ; j > 0; j--) {
                if (arr[j-1] > tmp) {
                    //right shift the larger elements
                    arr[j] = arr[j-1];
                } else {
                    break;
                }
            }
            arr[j] = tmp;
        }
    }
};
#endif //KICK_START_INSERTIONSORT_H