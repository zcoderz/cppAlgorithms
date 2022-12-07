//
// Created by usman on 10/16/22.
//

#ifndef CPPALGORITHMS_DUNGEONGAME_H
#define CPPALGORITHMS_DUNGEONGAME_H

#include <vector>
#include <queue>
#include <iostream>
using namespace std;

/**
 * This is a deceptively tricky problem!
 *
 */
class DungeonGame {
public:
    static int calculateMinimumHPPQ(vector<vector<int>>& dungeon) {
        //lowest sum so far, current sum, x coordinate, y coordinate
        typedef tuple<int,int, int, int> KnightData;
        priority_queue<KnightData, vector<KnightData> , less<>> pQ;
        int targetX = dungeon.size()-1;
        int targetY = dungeon[0].size()-1;
        if (targetY < 0 || targetX < 0) return 0;
        pQ.emplace(dungeon[0][0],dungeon[0][0],0,0);
        vector<vector<int>> dp(targetX+1, vector<int> (targetY+1, INT_MIN));
        vector<vector<int>> moves = {{1,0}, {0,1}};
        while (!pQ.empty()) {
            auto [lowestH, currentH, xCord, yCord] = pQ.top(); pQ.pop();
            if (xCord==targetX && yCord == targetY) {
                if (lowestH > 0) return 0;
                //if lowest health  is -5, then we need at least +6 initially to keep health at 1 or higher
                return 1-lowestH;
            }
            //if you already visited the cell with a current health higher than what this iteration brings,
            //then no need to process this iteration
            if (dp[xCord][yCord] > currentH) continue;
            dp[xCord][yCord] = currentH;
            for (auto & move: moves) {
                int nextX = xCord + move[0];
                int nextY = yCord + move[1];
                if (nextX > targetX || nextY > targetY) continue;
                int nextCurrentH = currentH+dungeon[nextX][nextY];
                int nextlowestH = min(lowestH, nextCurrentH);
                pQ.emplace(nextlowestH,nextCurrentH,nextX,nextY);
            }
        }
        return 0;
    }

    static int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int xCols = dungeon.size()-1;
        int yCols = dungeon[0].size()-1;
        if (yCols < 0 || xCols < 0) return 0;
        vector<vector<int>> dp(xCols+1, vector<int> (yCols+1, INT_MAX));
        for (int x=xCols; x >=0; x--) {
            for (int y=yCols; y>=0; y--) {
                if (x==xCols && y==yCols) {
                    //need at least one health to enter a cell
                    //hence need to do a max with limit on 1
                    dp[x][y] = max(1-dungeon[x][y], 1);
                }  else {
                    int rightV = INT_MAX;
                    int downV = INT_MAX;
                    if (y < yCols) {
                        //you are going to a target cell from current cell
                        //target cell contains what's the minimum health it requires.
                        //hence the health you need is : what-is-required - what-you-got
                        //the minimum health you need is 1. hence, limit max on 1
                        rightV = max(1, dp[x][y+1]-dungeon[x][y]);
                    }
                    if (x < xCols) {
                        downV = max(1, dp[x+1][y]-dungeon[x][y]);
                    }
                    dp[x][y] = min(rightV, downV);
                }
            }
        }
        return dp[0][0];
    }

    static void testMe() {
        vector<vector<int>> data = {{1},{-2},{1}} ; //{{-2,-3,3},{-5,-10,1},{10,30,-5}};
        int res = calculateMinimumHP(data);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_DUNGEONGAME_H
