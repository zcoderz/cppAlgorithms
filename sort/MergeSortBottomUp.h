//
// Created by usman on 10/17/21.
//

#ifndef KICK_START_MERGESORTBOTTOMUP_H
#define KICK_START_MERGESORTBOTTOMUP_H

#endif //KICK_START_MERGESORTBOTTOMUP_H
#include <algorithm>
using namespace std;

class MergeSortBottomUp {
public:
    void runMergeSort(int ** arr, int sz) {
        processMergeSort(arr, sz-1);
    }
private:

    void processMergeSort(int ** arr, int right) {
        int * aux = new int [right+1];
        copy(*arr, *arr+right+1, aux);
        int mergeOffset = 1;
        while (mergeOffset <= right) {
            int i =0;
            while (i + mergeOffset <= right) {
                merge(*arr, aux, i, i+mergeOffset, min(i+2*mergeOffset-1, right));
                i += 2*mergeOffset;
            }
            int *temp = aux;
            aux = *arr;
            *arr = temp;
            mergeOffset *= 2;
        }
        int *temp = aux;
        aux = *arr;
        *arr = temp;
        delete [] aux;
    }

    void merge (int dest [], const int aux [], int left, int j, int right) {
        int origMid = j;
        int currIndex = left;
        while (currIndex <= right) {
            if ((left < origMid) && (j <= right)) {
                if (aux[left] <= aux[j]) {
                    dest[currIndex++] = aux[left++];
                } else {
                    dest[currIndex++] = aux[j++];
                }
            } else if (left < origMid) {
                dest[currIndex++] = aux[left++];
            } else {
                dest[currIndex++] = aux[j++];
            }
        }
    }
};