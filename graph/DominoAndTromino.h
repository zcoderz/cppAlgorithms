//
// Created by usman on 10/15/22.
//

#ifndef CPPALGORITHMS_DOMINOANDTROMINO_H
#define CPPALGORITHMS_DOMINOANDTROMINO_H

#include <vector>
using namespace std;
class DominoTromino {
    /**
     * Excellent explanation on this at leetcode. They also explain solving this via matrix multiplication.
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
        int fPrior=1; //only 1 way to cover the first index with a vertical bar
        int fCurrent=2; //only 2 ways to completely cover first two indices (two vertical or two horizontal)
        int pCurrent=1; //only 1 way to add an L in first index


        for (int i =3; i <=n; i++) {
            int tmp = fCurrent;
            //can get to current F by adding 1 to priorF, adding two horizontal or two vertical to the prior prior F.
            //however, adding two vertical will double count the scenario already covered by adding one vertical to
            //the priorF
            //pCurrent is treated singularly for both partial up and down. hence can get to current fully covered by either of
            //adding an upper l or lower l to priorF
            fCurrent = (fPrior + fCurrent + 2 * pCurrent) % MOD;
            pCurrent = (fPrior + pCurrent) % MOD; // can add L to prior prior F , or add horizontal to prior p
            fPrior = tmp;
        }

        return fCurrent;
    }

};

#endif //CPPALGORITHMS_DOMINOANDTROMINO_H
