//
// Created by usman on 1/25/23.
//

#ifndef CPPALGORITHMS_MINIMIZEMAXDISTANCETOGASSTATION_H
#define CPPALGORITHMS_MINIMIZEMAXDISTANCETOGASSTATION_H

#include <vector>
#include <set>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>

using namespace std;

class MinimizeMaxDistanceToGasStation {
public:
    /**
     * this approach is so simple that its beautiful.
     * all you check is that the distance between two stations is less than delta.
     * if so, you skip adding a new station. else you add a new station
     * @param stations
     * @param k
     * @param delta
     * @return
     */
    static bool possible(vector<int>& stations, int k, double delta) {
        for (int i =0; i < stations.size()-1; i++) {
            k -= (int) ((stations[i+1]-stations[i]) /delta);
        }
        return k >=0;
    }

    static double minmaxGasDist(vector<int>& stations, int k) {
        double left = 0, right = *prev(stations.end());
        double epsilon = 1e-6;
        while ((right -left) > epsilon) {
            double mid = left + (right-left)/2.0;
            if (possible(stations, k, mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return left;
    }

    static void testMe() {
        vector<int> vals = {10,19,25,27,56,63,70,87,96,97};
        double res = minmaxGasDist(vals, 3);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_MINIMIZEMAXDISTANCETOGASSTATION_H
