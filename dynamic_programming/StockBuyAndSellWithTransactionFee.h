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
        int profit=0; //this is the max profit you can get from buying and selling stocks
        int stockBuyOrHold = -prices[0]; //this represents value if you hold prior stock or buy a new one

        for (int i =1; i < prices.size(); i++) {
            profit = max(profit, prices[i] + stockBuyOrHold - fee);
            //if prices continue to rise this will represent value of the cheapest stock
            //otherwise if you bought a new stock, this will represent cash value after buying stock
            //thus when stock is next sold price[i] + stockBuyOrHold will represent the buy-sell transaction profit
            stockBuyOrHold = max(stockBuyOrHold, profit-prices[i]);
        }

        return profit;
    }
};

#endif //CPPALGORITHMS_STOCKBUYANDSELLWITHTRANSACTIONFEE_H
