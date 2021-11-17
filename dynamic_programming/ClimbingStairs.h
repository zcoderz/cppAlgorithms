//
// Created by usman on 11/17/21.
//

#ifndef CPPALGORITHMS_CLIMBINGSTAIRS_H
#define CPPALGORITHMS_CLIMBINGSTAIRS_H

/**
 * IMP: Set base case as 1.
 * Start from stair 2. You have already set your begin value as stair 2.
 */
class ClimbingStairs {
public:

    int climbStairs(int n) {
        if (n ==1) {
            return n;
        }
        int twoPrior = 1;
        int onePrior = 1;
        for (int i = 2; i <= n; i++) {
            int curr = twoPrior + onePrior;
            twoPrior = onePrior;
            onePrior = curr;
        }
        return onePrior;
    }

};

#endif //CPPALGORITHMS_CLIMBINGSTAIRS_H
