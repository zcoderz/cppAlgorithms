//
// Created by usman on 11/19/22.
//

#ifndef CPPALGORITHMS_CHERRYPICKTWO_H
#define CPPALGORITHMS_CHERRYPICKTWO_H

#include <vector>
#include <climits>
#include <iostream>
using namespace std;

class CherryPickTwo {
public:
    static int cherryPickup(vector<vector<int>>& grid) {
        int rowSz = grid.size();
        int colSz = grid[0].size();
        vector<vector<vector<int>>> dp(rowSz, vector<vector<int>>( colSz, vector<int> (colSz, -1)));
        return recurseMaxCherries(0, 0, colSz-1, grid, dp, rowSz, colSz);
    }

    static int recurseMaxCherries(int row, int cP1, int cP2, vector<vector<int>>& grid,
                                  vector<vector<vector<int>>>& dp, int rowSz, int colSz) {
        if (cP1 == colSz || cP2 == colSz || cP1 <0 || cP2 < 0) return INT_MIN;
        int cherries = grid[row] [cP1];
        if (cP1 != cP2)
            cherries += grid[row] [cP2];
        if (row == rowSz-1) {
            return cherries;
        }
        if(dp[row][cP1][cP2] !=-1)
            return dp[row][cP1][cP2];
        int cherryAdd = INT_MIN;
        for (int i=-1; i <=1; i++) {
            for (int j=-1; j <= 1; j++) {
                cherryAdd = max(cherryAdd, recurseMaxCherries(row+1,cP1+i, cP2+j, grid, dp, rowSz, colSz));
            }
        }
        cherries += cherryAdd;
        dp[row][cP1][cP2] = cherries;
        cout << "returning " << cherries << " at " << row << " , " << cP1 << " , " << cP2 << endl;
        return cherries;
    }

    static void testMe() {
        vector<vector<int>> grid = {{3,1,1},{2,5,1},{1,5,5},{2,1,1}};
        int res = cherryPickup(grid);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_CHERRYPICKTWO_H
