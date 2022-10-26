//
// Created by usman on 10/25/22.
//

#ifndef CPPALGORITHMS_TOSSSTRANGECOINS_H
#define CPPALGORITHMS_TOSSSTRANGECOINS_H

#include <vector>

using namespace std;

class TossStrangeCoins {
public:

     double probabilityOfHeads(vector<double>& probs, int target) {
         //create two dp arrays to hold probabilities of heads.
         //each index denotes probability of head for that number of iterations
         //can also utilize code to work with one dp array and update the indices from highest to lowest order
         vector<double> dp(target+1); dp[0]=1;
         vector<double> dpTmp(target+1);
         for (double prob: probs) {
             for (int i=0; i <= target; i++) {
                 if (i==0) {
                     //probability of no heads is the probability of no heads in prior iteration * (1- current-probability)
                     dpTmp[i] = dp[i] * (1 - prob);
                 } else {
                     //probability of one less head * probability of current head +
                     //probability of same number of heads in prior iteration * probability of tail in current iteration
                     dpTmp[i] = dp[i-1] * (prob) +  dp[i] * (1-prob) ;
                 }
             }
             //do the current work on a tmp array. swap it with main dp, so next iteration can use dp
             swap(dpTmp, dp);
         }
         return dp[target];
     }
};

#endif //CPPALGORITHMS_TOSSSTRANGECOINS_H
