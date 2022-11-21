//
// Created by usman on 11/19/22.
//

#ifndef CPPALGORITHMS_CHERRYPICK_H
#define CPPALGORITHMS_CHERRYPICK_H

#include <vector>
#include <climits>
#include <iostream>
using namespace std;

class CherryPick {
public:
    static int cherryPickup(vector<vector<int>>& grid) {
        int gridSz = grid.size();
        vector<vector<vector<int>>> dp(gridSz, vector<vector<int>> (gridSz, vector<int> (gridSz, -1)));
        return max(0, cherryCount(0,0,0, grid, dp, gridSz));
    }

    static int cherryCount(int p1R, int p1C, int p2R, vector<vector<int>>& grid, vector<vector<vector<int>>> & dp, int gridSz) {
        int p2C = (p1C + p1R - p2R);
        if (p1R == gridSz  || p2R == gridSz || p2C == gridSz || p1C == gridSz || grid[p1R][p1C] == -1 || grid[p2R][p2C] == -1)
            return INT_MIN;
        if (dp[p1R][p1C][p2R] != -1)
            return dp[p1R][p1C][p2R];

        int pCherries = grid[p1R][p1C];
        if (p1R != p2R)
            pCherries += grid[p2R][p2C]; //different cells add (same cells don't add, to avoid double count)

        //terminate recursion at last row, col
        if (p1R == gridSz-1 && p1C == gridSz-1)
            return grid[p1R][p1C];
        //P1Down, P2Right
        //P1Down, P2Down
        //P1Right, P2Down
        //P1Right, P2Right
        pCherries += max(cherryCount(p1R+1, p1C, p2R, grid, dp, gridSz),
                                max(cherryCount(p1R+1, p1C, p2R+1, grid, dp, gridSz),
                                    max(cherryCount(p1R, p1C+1, p2R+1, grid, dp, gridSz),
                                        cherryCount(p1R, p1C+1, p2R, grid, dp, gridSz))));
        dp[p1R][p1C][p2R] = pCherries;
        //cout << "returning cherries as " << pCherries << " for " << p1R << " , " << p1C << ", " << p2C << endl;
        return pCherries;
    }

    static void testMe() {
        vector<vector<int>> grid = {{0,1,-1},{1,0,-1},{1,1,1}};
        int res = cherryPickup(grid);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_CHERRYPICK_H
