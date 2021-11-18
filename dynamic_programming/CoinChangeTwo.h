//
// Created by usman on 11/17/21.
//

#ifndef CPPALGORITHMS_COINCHANGETWO_H
#define CPPALGORITHMS_COINCHANGETWO_H
#include <vector>
using namespace std;

class CoinChangeTwo {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> combinations(amount+1, 0);
        combinations[0] = 1;
        for (int coin : coins) {
            for (int i =1; i <=amount; i++) {
                if ((i-coin) < 0) continue;
                combinations[i] += combinations[i-coin];
            }
        }
        return combinations[amount];
    }
};

#endif //CPPALGORITHMS_COINCHANGETWO_H
