//
// Created by usman on 10/16/21.
//

#ifndef KICK_START_MERGESORT_H
#define KICK_START_MERGESORT_H



class MergeSort {
public:
    void runMergeSort(int arr[], int sz) {
        int * aux = new int [sz];
        copy(arr, arr+sz, aux);
        processMergeSort(arr, aux, 0, sz-1);
        delete [] aux;
    }

private:
    void processMergeSort(int dest[], int aux[], int left, int right) {
        if (left >= right) {
            return;
        }
        int mid = left + (right-left) / 2;
        processMergeSort(aux, dest, left, mid);
        processMergeSort(aux, dest, mid+1, right);
        merge(dest, aux, left, mid+1, right);
    }

    void merge(int dest[], int aux[], int left, int mid, int right) {
        int iFirst = left;
        int iSecond = mid;
        int currIndex = left;
        while (iFirst < mid || iSecond <= right) {
            if (iFirst < mid && iSecond <= right) {
                if (aux[iFirst] < aux[iSecond]) {
                    dest[currIndex++] = aux[iFirst++];
                } else {
                    dest[currIndex++] = aux[iSecond++];
                }
            } else if (iFirst < mid) {
                dest[currIndex++] = aux[iFirst++];
            } else {
                dest[currIndex++] = aux[iSecond++];
            }
        }
    }

    vector<int> merge_sort(vector<int> arr) {
        // Write your code here.
        vector<int> aux (arr);
        copy(arr.begin(), arr.end(), aux.begin());
        //processMergeSort(arr, aux, 0, arr.size()-1);
        return arr;
    }

};

#endif //KICK_START_MERGESORT_H