//
// Created by usman on 10/23/22.
//

#ifndef CPPALGORITHMS_BESTTIMETOBUYANDSELLSTOCKTHREE_H
#define CPPALGORITHMS_BESTTIMETOBUYANDSELLSTOCKTHREE_H

#include <vector>
#include <climits>

using namespace std;

class BestTimeStockThree {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        vector<int> dpRight(size+1); dpRight[size-1]=0;
        vector<int> dpLeft(size+1); dpLeft[0]=0;
        int leftMin= prices[0];
        int rightMax=prices[size-1];
        for (int i =1; i < size; i++) {
            dpLeft[i] = max(dpLeft[i-1], prices[i]-leftMin);
            leftMin = min(leftMin, prices[i]);
            dpRight[size-i-1] = max(dpRight[size-i], rightMax-prices[size-i-1]);
            rightMax = max(rightMax, prices[size-i-1]);
        }
        int maxTotalP = 0;
        for (int i =0; i < size; i++) {
            maxTotalP = max(maxTotalP, dpLeft[i] + dpRight[i+1]);
        }
        return maxTotalP;
    }

    /**
     * See the data as a series of events.
     * We need to capture two profits , profit 1 and profit 2
     * profit1 = T1price - T1cost
     * cost2 = T2price_buy - profit1
     * profit2 = t2price_sell - cost2 = t2price_sell - t2price_buy + profit1
     * @param prices
     * @return
     */
    int maxProfitFast(vector<int>& prices) {
        int t1Cost=INT_MAX;
        int t1Profit=0;
        int t2Cost=INT_MAX;
        int t2Profit=0;

        for (int i=0; i < prices.size(); i++) {
            //these equation are very clever but tricky to come up with
            //need to draw sequence of transactions on white board and use them to come up with these equations
            t1Cost = min(t1Cost, prices[i]);
            t1Profit = max(t1Profit, prices[i]-t1Cost);

            t2Cost = min(t2Cost, prices[i]-t1Profit);
            t2Profit=max(t2Profit,  prices[i]-t2Cost);

        }
        return t2Profit;
    }
};
#endif //CPPALGORITHMS_BESTTIMETOBUYANDSELLSTOCKTHREE_H
