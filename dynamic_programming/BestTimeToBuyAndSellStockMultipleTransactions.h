//
// Created by usman on 10/23/22.
//

#ifndef CPPALGORITHMS_BESTTIMETOBUYANDSELLSTOCKMULTIPLETRANSACTIONS_H
#define CPPALGORITHMS_BESTTIMETOBUYANDSELLSTOCKMULTIPLETRANSACTIONS_H

#include <vector>
#include <climits>
#include <iostream>

using namespace std;

/**
 * This is a very simple and yet extremely clever algorithm.
 * an array of K profit and costs enables us to capture profits from 1...k transactions
 * min on cost carries prior profits per state (transaction) forward
 * max on profit carries higher profits per state forward
 */
class BestTimeBuyAndSellStock {
public:
    static int maxProfit(int k, vector<int>& prices) {
        if (k==0) return 0;
        //allocate k+1, as next purchase (cost) depends on prior profits. cost[i+1] = min(.....price - profit[i]);
        vector<int> profit(k+1); //max on profit so initialize to 0
        vector<int> cost(k+1, INT_MAX); //min on cost taken so initialize to max
        for (int price: prices) {
            for (int i=0; i < k;i++) {
                //costs is based on min, as lower cost means higher future profits
                //cost is price - prior-profit. and thus higher profits from previous prices are carried forward inside cost
                cost[i+1] = min(cost[i+1], price-profit[i]);
                //price is subtracted from cost to calculate profit, max profits from past are carried forward

                //each transaction can be considered a phase
                //profit from a transaction feeds into cost for next
                //transaction which feeds into profit for that transaction
                //if profit is low, it just gets skipped

                //lower cost from prior buy transaction moves forward (due to min) and can be later used when calculating profit from high price

                //k states for profit and cost enable us to carry more state transitions, profits from prior state feeds to next
                profit[i+1] = max(profit[i+1], price - cost[i+1]);
            }
        }
        return profit[k];
    }

    static void testMe() {
        vector<int> prices = {7,1,5,3,6,1,8};
        int profit = maxProfit(2, prices);
        cout << profit << endl;
    }
};

#endif //CPPALGORITHMS_BESTTIMETOBUYANDSELLSTOCKMULTIPLETRANSACTIONS_H
