//
// Created by usman on 1/16/23.
//

#ifndef CPPALGORITHMS_CAPACITYTOSHIPPACKAGESWITHINDDAYS_H
#define CPPALGORITHMS_CAPACITYTOSHIPPACKAGESWITHINDDAYS_H

#include <vector>
#include <numeric>
using namespace std;

class CapacityToShitPackagesWithinDDays {
public:
    bool isPossible(vector<int>& weights, int days, int capacity) {
        int currWeight = 0;
        int currDays = 1;
        for (int i =0; i < weights.size(); i++) {
            if (weights[i] > capacity ){
                return false;
            } else if ((currWeight + weights[i]) > capacity) {
                currWeight = weights[i];
                currDays++;
            } else  {
                currWeight += weights[i];
            }
        }
        return currDays <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int total = accumulate(weights.begin(), weights.end(), 0);
        int leastCapacity = total/days;
        int maxCapacity = total;
        while (maxCapacity > leastCapacity) {
            int midCapacity = leastCapacity + (maxCapacity-leastCapacity)/2;
            bool  possible = isPossible(weights, days, midCapacity);
            if (possible) {
                maxCapacity = midCapacity;
            } else {
                leastCapacity=midCapacity+1;
            }
        }
        return leastCapacity;
    }
};

#endif //CPPALGORITHMS_CAPACITYTOSHIPPACKAGESWITHINDDAYS_H
