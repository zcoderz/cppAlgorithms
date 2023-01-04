//
// Created by usman on 1/3/23.
//

#ifndef CPPALGORITHMS_NUMBEROFDISTINCTISLANDS_H
#define CPPALGORITHMS_NUMBEROFDISTINCTISLANDS_H

#include <set>
#include <vector>
using namespace std;

class NumberOfDistinctIslands {
public:


    static void dfs(int rows, int cols, int startRow, int startCol, int currRow, int currCol, vector<vector<int>>& grid,
             vector<vector<bool>> & seen, set<pair<int,int>> & islandSet) {
        if (seen[currRow][currCol]) return;
        seen[currRow][currCol] = true;
        islandSet.emplace(currRow-startRow, currCol-startCol);
        static vector<vector<int>> moves = {{1,0},{-1,0}, {0,1},{0,-1}};
        for (auto & move: moves) {
            int nRow = currRow + move[0];
            int nCol = currCol + move[1];
            if (nRow < 0 || nRow == rows || nCol < 0 || nCol == cols || seen[nRow][nCol] || grid[nRow][nCol] != 1) continue;
            dfs(rows, cols, startRow, startCol, nRow, nCol, grid, seen, islandSet);
        }
    }

    static int numDistinctIslands(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> seen(rows, vector<bool> (cols));
        set<set<pair<int,int>>> distinctIslands;
        for (int i =0; i < rows; i++) {
            for (int j =0; j < cols; j++) {
                if (!seen[i][j] && grid[i][j] == 1) {
                    set<pair<int,int>> islandSet;
                    dfs(rows, cols, i, j, i, j, grid, seen, islandSet);
                    distinctIslands.emplace(islandSet);
                }
            }
        }
        return distinctIslands.size();
    }

    static void testMe() {
        NumberOfDistinctIslands distIslands;
        vector<vector<int>> grid = {{1,1,0,1,1},{1,0,0,0,0},{0,0,0,0,1},{1,1,0,1,1}};
        int res = numDistinctIslands(grid);
        cout << res ;
    }
};

#endif //CPPALGORITHMS_NUMBEROFDISTINCTISLANDS_H
