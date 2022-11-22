//
// Created by usman on 11/21/22.
//

#ifndef CPPALGORITHMS_FOURKEYSKEYBOARD_H
#define CPPALGORITHMS_FOURKEYSKEYBOARD_H

#include <iostream>
using namespace std;
class FourKeysKeyboard {
public:
    static int maxA(int n) {
        vector<int> dp(n+1);
        for (int i =1; i <=n; i++) {
            if (i <=5) {
                dp[i] = i;
            } else {
                dp[i] = max(
                        dp[i-1]+1, //prior number plus 1
                        max(dp[i-3]*2, //ctla,c,v (3 strokes to copy and paste prior). count after paste is prior*2
                            max(dp[i-4]*3, //ctl,a,c+paste+paste
                                dp[i-5]*4))); //ctl,a,c+paste+paste+paste
                                //no point going beyond 3 pastes as we can in 3 strokes select copy paste a longer list
            }
        }
        return dp[n];
    }

    static void testMe() {
        int res = maxA(9);
        cout << res << endl;
    }

};

#endif //CPPALGORITHMS_FOURKEYSKEYBOARD_H
