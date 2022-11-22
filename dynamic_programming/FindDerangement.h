//
// Created by usman on 11/21/22.
//

#ifndef CPPALGORITHMS_FINDDERANGEMENT_H
#define CPPALGORITHMS_FINDDERANGEMENT_H

#include <vector>
using namespace std;
class FindDerangement {
public:
    int findDerangement(int n) {
        if (n==1) return 0;
        if (n==2) return 1;
        //for numbers 1---N, we can place 1 in to any of N-1 places, say its placed in i.
        //then if i is placed back in to 1's spot there are N-2 problems left
        //if we don't place i back into 1s spot, there are N-1 problems left
        //since there are N-1 options where 1 can go the dp equation is : dp[i] = (i-1) * (dp[i-1] + dp[i-2])
        int a=1;
        int b=0;
        int res;
        for (int i =3; i <=n; i++) {
            res=((( i - 1L )*( a + b ))%1000000007);
            b = a;
            a = res;
        }
        return a;
    }

};

#endif //CPPALGORITHMS_FINDDERANGEMENT_H
