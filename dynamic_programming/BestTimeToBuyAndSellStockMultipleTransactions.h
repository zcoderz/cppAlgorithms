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
 *
 * DINOSAUR : lets do this again
 */
class BestTimeBuyAndSellStock {
public:
    static int maxProfit(int k, vector<int>& prices) {
        if (k==0) return 0;
        //allocate k+1, as next purchase (cost) depends on prior profits. cost[i+1] = min(.....price - profit[i]);
        //k states for profit and cost enable us to carry more state transitions, profits from prior state feeds to next
        vector<int> profit(k+1); //max on profit so initialize to 0
        vector<int> cost(k+1, INT_MAX); //min on cost taken so initialize to max
        for (int price: prices) {
            //need to apply price to all transactions so that we can record possible changes in cost and profit per transaction
            //it is confusing that in same loop , we calculate cost and use the same cost to calculate profit
            //but need to understand that a price will do one of below and not both :
            //1. decrease cost (if it is lower than prior price and profit before that stage)
            //2. increase profit if it is higher than price previously at that stage
            //3. do nothing
            for (int i=0; i < k;i++) {
                //costs is based on min, thus lower cost means higher future profits
                //cost is price - prior-profit. and thus higher profits from previous prices are carried forward inside cost
                //cost thus signify max profit while holding stock
                //lower cost from prior buy transaction moves forward (due to min) and can be later used when calculating profit from high price
                cost[i+1] = min(cost[i+1], price-profit[i]);


                //each transaction can be considered a phase
                //profit from a transaction feeds into cost for next
                //transaction which feeds into profit for that transaction
                //if profit is low, it just gets skipped
                //max profits from prior transactions are carried forward due to "max"
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
