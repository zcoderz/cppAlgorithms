//
// Created by usman on 1/23/23.
//

#ifndef CPPALGORITHMS_MINIMUMSPACEWASTEDFROMPACKAGING_H
#define CPPALGORITHMS_MINIMUMSPACEWASTEDFROMPACKAGING_H

#include <vector>
#include <numeric>
#include <algorithm>
#include <climits>
using namespace std;

class MinimumSpaceWastedFromPackaging {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        sort(packages.begin(), packages.end());
        long totalPackageSpace = accumulate(packages.begin(), packages.end(), 0l);
        long res = LONG_MAX;
        int MOD = 1e9+7;
        for (auto & sBoxes : boxes) {
            sort(sBoxes.begin(), sBoxes.end());
            if (*prev(packages.end()) > *prev(sBoxes.end())) continue;
            vector<int>::iterator i,j = packages.begin() ;
            long curr = 0;
            for (int box : sBoxes) {
                i = upper_bound(j, packages.end(), box);
                curr = (curr + ((i-j) * box ));
                j = i;
                if (i==packages.end()) break;
            }
            res = min (res, curr);
        }
        return res == LONG_MAX ? -1 : (res-totalPackageSpace) % MOD;
    }
};
#endif //CPPALGORITHMS_MINIMUMSPACEWASTEDFROMPACKAGING_H
