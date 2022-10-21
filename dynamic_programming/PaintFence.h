//
// Created by usman on 10/21/22.
//

#ifndef CPPALGORITHMS_PAINTFENCE_H
#define CPPALGORITHMS_PAINTFENCE_H

#include <vector>
using namespace std;
class PaintFence {
public:
    int numWays(int n, int k) {
        vector<int> dpSame(n);
        vector<int> dpDiff(n);
        dpDiff[0] = k;
        for(int i =1; i < n; i++) {
            dpDiff[i] = (k-1) * (dpSame[i-1]+dpDiff[i-1]);
            dpSame[i] = dpDiff[k-1];
        }
        return dpDiff[n-1] + dpSame[n-1];
    }
};

#endif //CPPALGORITHMS_PAINTFENCE_H
