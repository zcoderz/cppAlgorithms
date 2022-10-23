//
// Created by usman on 10/22/22.
//

#ifndef CPPALGORITHMS_STOCKBUYANDSELLWITHCOOLDOWN_H
#define CPPALGORITHMS_STOCKBUYANDSELLWITHCOOLDOWN_H
#include <vector>
#include <iostream>
using namespace std;
class StockBuyAndSellWithCoolDown {
public:
    int maxProfitDPFast(vector<int>& prices) {
        int held=-prices[0];
        int sold=0;
        int reset=0;
        for (int i =1; i <prices.size(); i++) {
            int preSold = sold;
            sold = prices[i] + held;
            held = max(held, reset-prices[i]);
            reset = max(reset, preSold);
        }
        return max(sold, reset);
    }

    static int maxProfitDP(vector<int>& prices) {
        vector<int> profitsDP(prices.size()+2);
        for(int i=prices.size()-1; i >=0; i--) {
            int maxP = 0;
            for (int j = i+1;  j< prices.size(); j++) {
                maxP = max(maxP, prices[j]-prices[i] + profitsDP[j+2]);
            }
            profitsDP[i] = max(maxP, profitsDP[i+1]); //profitsDP[i+1] in case you purchased at next price
        }
        return profitsDP[0];
    }

    static void testMe() {
        vector<int> prices = {1,2,3,0,2};
        int v = maxProfitDP(prices);
        cout << v << endl;
    }
};
#endif //CPPALGORITHMS_STOCKBUYANDSELLWITHCOOLDOWN_H
