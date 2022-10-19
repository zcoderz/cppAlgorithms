//
// Created by usman on 10/16/22.
//

#ifndef CPPALGORITHMS_DUNGEONGAME_H
#define CPPALGORITHMS_DUNGEONGAME_H

#include <vector>
#include <iostream>
using namespace std;

class DungeonGame {
public:
    static int calculateMinimumHP(vector<vector<int>>& dungeon) {
        return 0;
    }

    static void testMe() {
        vector<vector<int>> data = {{1,-3,3}, {0,-2,0}, {-3,-3,-3}};
        int res = calculateMinimumHP(data);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_DUNGEONGAME_H
