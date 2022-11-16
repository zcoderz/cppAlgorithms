//
// Created by usman on 11/15/22.
//

#ifndef CPPALGORITHMS_ALLOCATEMAILBOXES_H
#define CPPALGORITHMS_ALLOCATEMAILBOXES_H

#include <vector>
#include <climits>
#include <iostream>
using namespace std;

/**
 * DINOSAUR: do this again
 */
class AllocateMailboxes {
public:
    static int recurseTotalCost(vector<int>& houses, int mailBoxes, int index, vector<vector<int>> & cost,
                                 vector<vector<int>> & dp) {
        static int MAX = 1000000;
        if (mailBoxes==0 && index==houses.size()) {
            return 0;
        }
        if (mailBoxes==0 || index==houses.size()) {
            return MAX;
        }
        if (dp[index][mailBoxes] != -1) {
        //    return dp[index][mailBoxes];
        }
        int res = MAX;
        for (int j = index; j < houses.size(); j++) {
            res = min (res, cost[index][j] + recurseTotalCost(houses, mailBoxes-1, j+1, cost, dp));
        }

        cout << "returning cost at index " << index << " as " << res << " with mailboxes " << mailBoxes << endl;
        dp[index][mailBoxes] = res;
        return res;
    }

    static int minDistance(vector<int>& houses, int k) {
        sort(houses.begin(), houses.end());
        vector<vector<int>> cost (houses.size(), vector<int> (houses.size()));
        for (int i =0; i < houses.size(); i++) {
            for (int j=0; j <=i; j++) {
                int median = j + (i-j)/2;
                int costV = 0;
                for (int l =j; l <=i; l++) {
                    costV += abs(houses[l]-houses[median]);
                }
                cost[j][i] = costV;
            }
        }
        vector<vector<int>> dp(houses.size()+1, vector<int> (k+1, -1));
        return recurseTotalCost(houses, k, 0, cost, dp);
    }

    static void testMe() {
        vector<int> houses = {2,3,5,12,18};
        int v = minDistance(houses, 2);
        cout << v << endl;
    }
};

#endif //CPPALGORITHMS_ALLOCATEMAILBOXES_H
