//
// Created by USMAN QADIR on 10/22/22.
//

#ifndef CPPALGORITHMS_STOCKBUYANDSELLWITHTRANSACTIONFEE_H
#define CPPALGORITHMS_STOCKBUYANDSELLWITHTRANSACTIONFEE_H

#include <vector>

using namespace std;

class StockBuyAndSell {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int totalProfit=0;
        int currProfit = 0;
        int currMin = prices[0];
        for(int i =1; i < prices.size(); i++) {
            if (prices[i] < currMin) {
                currMin = prices[i];
                totalProfit += currProfit;
                currProfit=0;
            } else {
                int tmpProfit = prices[i] - currMin - fee;
                currProfit = max(currProfit, tmpProfit);
            }

        }
        return totalProfit+currProfit;
    }
};

#endif //CPPALGORITHMS_STOCKBUYANDSELLWITHTRANSACTIONFEE_H
