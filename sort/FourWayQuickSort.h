//
// Created by usman on 10/17/21.
//

#ifndef KICK_START_FOURWAYQUICKSORT_H
#define KICK_START_FOURWAYQUICKSORT_H

#endif //KICK_START_FOURWAYQUICKSORT_H

#include <algorithm>
using namespace std;

class FourWayQuickSort {

    void quicksort(int a[], int l, int r) {
        int i, j, k, p, q;
        int v;
        if (r <= l) return;
        v = a[r];
        i = l - 1;
        j = r;
        p = l - 1;
        q = r;
        for (;;) {
            while (a[++i] < v);
            while (v < a[--j]) if (j == l) break;
            if (i >= j) break;
            swap(a[i], a[j]);
            if (a[i] == v) {
                p++;
                swap(a[p], a[i]);
            }
            if (v == a[j]) {
                q--;
                swap(a[q], a[j]);
            }
        }
        swap(a[i], a[r]);
        j = i - 1;
        i = i + 1;
        for (k = l; k < p; k++, j--) swap(a[k], a[j]);
        for (k = r - 1; k > q; k--, i++) swap(a[k], a[i]);
        quicksort(a, l, j);
        quicksort(a, i, r);
    }

public:
    void runQuickSort(int arr[], int sz) {
        quicksort(arr, 0, sz - 1);
    }
};