//
// Created by usman on 10/18/22.
//

#ifndef CPPALGORITHMS_MINCOSTTICKETS_H
#define CPPALGORITHMS_MINCOSTTICKETS_H
#include <vector>
#include <limits>
using namespace std;

class MinCostTickets {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int lastDay = days[days.size()-1];
        vector<int> accumulatedCost(lastDay+1, 0);
        int daysIndex = 0;
        for (int i =1; i <= lastDay; i++) {
            if (days[daysIndex] == i) {
                accumulatedCost[i] =  min(accumulatedCost[i-1] + costs[0], min ((i >=7 ? accumulatedCost[i-7] + costs[1] : costs[1]), (i >=30 ? accumulatedCost[i-30] + costs[2] : costs[2])));
                daysIndex++;
            } else {
                accumulatedCost[i] = accumulatedCost[i-1];
            }
        }
        return accumulatedCost[lastDay];
    }
};

#endif //CPPALGORITHMS_MINCOSTTICKETS_H
