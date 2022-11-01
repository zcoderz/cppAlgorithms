//
// Created by usman on 10/31/22.
//

#ifndef CPPALGORITHMS_TWOKEYSKEYBOARD_H
#define CPPALGORITHMS_TWOKEYSKEYBOARD_H

#include <math.h>
#include <iostream>


class TwoKeys {

public:
    static int minStepsNo;
    static void minStepsRec(int target, int curr, int copy) {
        if (target == curr) return ;
        if (curr > copy &&  (target % curr) == 0) {
            //if target can be reached via copy and pasting current and current is greater than copy
            //then increasing the length of copy is more efficient.
            //i.e. for N=8.
            //copy on 1 (copy), 1 Paste = 2.
            //now copy and paste 2, and increase curr to 4
            //now copy and paste curr and increase curr to 8
            copy = curr; minStepsNo++;
        }
        minStepsNo++;
        minStepsRec(target , curr + copy, copy);
    }

    static int minSteps(int n) {
        minStepsNo=0;
        minStepsRec(n, 1, 0);
        return minStepsNo;
    }



    static void testMe() {
        int v = minSteps(4);
        cout << v << endl;
    }
};
#endif //CPPALGORITHMS_TWOKEYSKEYBOARD_H
