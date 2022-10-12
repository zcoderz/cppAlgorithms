//
// Created by usman on 10/10/22.
//

#ifndef CPPALGORITHMS_UNIQUEPATHS_H
#define CPPALGORITHMS_UNIQUEPATHS_H
#include <vector>
using namespace std;
class UniquePaths {
public:
    static int uniquePaths(int m, int n) {
        vector<int> vals (m*n, 0);
        vals[0]=1;
        int end = m*n;
        for (int i =1; i < end; i++) {
            if (i%n != 0) {
                vals[i] += vals[i-1];
            }
            if (i >= n) {
                vals[i] += vals[i-n];
            }
        }
        return vals[end-1];
    }


};

#endif //CPPALGORITHMS_UNIQUEPATHS_H
