//
// Created by usman on 10/14/21.
//

#ifndef KICK_START_BUBBLESORT_H
#define KICK_START_BUBBLESORT_H

#include <algorithm>
using namespace std;
class BubbleSort {
public:
    void runBubbleSort(int arr [], int size) {
        for (int i =0; i < size; i++) {
            for (int j = size-1; j > i; j--) {
                if (arr[j] < arr[j-1]) {
                    swap(arr[j], arr[j-1]);
                }
            }
        }
    }
};
#endif //KICK_START_BUBBLESORT_H