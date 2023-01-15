//
// Created by usman on 10/15/22.
//

#ifndef CPPALGORITHMS_DOMINOANDTROMINO_H
#define CPPALGORITHMS_DOMINOANDTROMINO_H

#include <vector>
using namespace std;
class DominoTromino {
    /**
     * Visualizing this one is very tricky!!!
     * https://leetcode.com/problems/domino-and-tromino-tiling/solutions/1570448/domino-and-tromino-tiling/
     * f(k): The number of ways to fully cover a board of width kkk.
     * p(k): The number of ways to partially cover a board of width kkk.
     * @param n
     * @return
     */
    int numTilings(int n) {
        if (n==1) return 1;
        if (n==2) return 2;

        int MOD = 1000000007;
        int fPriorPrior=1; //only 1 way to cover the first index with a vertical bar
        int fPrior=2; //only 2 ways to completely cover first two indices (two vertical or two horizontal)
        int pPrior=1; //only 1 way to add an L in first index

        for (int i =3; i <=n; i++) {
            int tmp = fPrior;

            //to fPriorPrior you can add two horizontal dominos
            //to fPrior you can add one vertical domino
            //to L you can add an inverted L
            //to a horizontal upper domino creating a partial in prior you can add an inverted L
            //hence 2*prior
            fPrior = (fPriorPrior + fPrior + 2 * pPrior) % MOD;

            //to a full at 2 prior you can add L
            //to a prior L , you can add an upper domino to create L- shape
            pPrior = (fPriorPrior + pPrior) % MOD;
            fPriorPrior = tmp;
        }

        return fPrior;
    }

};

#endif //CPPALGORITHMS_DOMINOANDTROMINO_H
