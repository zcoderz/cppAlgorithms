//
// Created by usman on 1/17/23.
//

#ifndef CPPALGORITHMS_CUTTINGRIBBONS_H
#define CPPALGORITHMS_CUTTINGRIBBONS_H

#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class CuttingRibbons {
public:
    int maxLength(vector<int>& ribbons, int k) {
        //large value ulonglong needed so that we don't overflow the total
        unsigned long long v = 0;
        unsigned long long total = accumulate(ribbons.begin(), ribbons.end(), v);
        if (k > total) return 0;
        int maxV = total/k;
        int minV = 1;
        while (minV < maxV) {
            long long numRibbons = 0;
            int mid = minV + (maxV-minV+1)/2;
            for (int ribbon : ribbons) {
                numRibbons = numRibbons + ribbon/mid;
                if (numRibbons >= k) break;
            }
            if (numRibbons >= k) {
                minV = mid;
            } else {
                maxV = mid-1;
            }
        }
        return minV;
    }
};

#endif //CPPALGORITHMS_CUTTINGRIBBONS_H
