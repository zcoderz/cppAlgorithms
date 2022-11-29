//
// Created by usman on 11/28/22.
//

#ifndef CPPALGORITHMS_STONEGAMETHREE_H
#define CPPALGORITHMS_STONEGAMETHREE_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class StoneGameThree {
public:
    static int recurseResult(int index, vector<int>& stoneValue, bool turn, vector<int> & dp) {
        if (index >= stoneValue.size()) return 0;
        if (dp[index] != INT_MIN) return dp[index];
        int maxV = INT_MIN;
        int tmp = 0;
        for (int i=index; i < index+3 && i < stoneValue.size(); i++) {
            tmp += stoneValue[i];
            int rec = recurseResult(i+1, stoneValue, !turn, dp);
            maxV = max(maxV, tmp- rec);
        }
        dp[index] = maxV;
        return maxV;
    }

    static string stoneGameIII(vector<int>& stoneValue) {
        vector<int> dp(stoneValue.size(), INT_MIN);
        int res = recurseResult(0, stoneValue, true, dp);
        if (res >0) return "Alice";
        else if(res < 0) return "Bob";
        else return "Tie";
    }

    static string stoneGameIIIDP(vector<int>& stoneValue) {
        vector<int> dp(stoneValue.size(), INT_MIN);

        for (int i = stoneValue.size()-1; i >=0; i--) {
            for(int tmpAmt=0, offset=0; offset < 3 && i+offset < stoneValue.size(); offset++) {
                tmpAmt += stoneValue[i+offset];
                int nextIndex = i+offset+1;
                int nextPlayerV = nextIndex < stoneValue.size() ? dp[nextIndex] : 0;
                dp[i] = max (dp[i], tmpAmt-nextPlayerV);
            }
        }
        int res = dp[0];
        if (res >0) return "Alice";
        else if(res < 0) return "Bob";
        else return "Tie";
    }

    static void testMe() {
        vector<int> vals = {1,2,3,7};
        string res = stoneGameIIIDP(vals);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_STONEGAMETHREE_H
