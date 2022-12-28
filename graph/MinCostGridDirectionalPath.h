//
// Created by usman on 12/27/22.
//

#ifndef CPPALGORITHMS_MINCOSTGRIDDIRECTIONALPATH_H
#define CPPALGORITHMS_MINCOSTGRIDDIRECTIONALPATH_H

#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class MinCostGridDirectionalPath {
public:
    int minCost(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int gridSz = rows*cols;
        vector<vector<pair<int,int>>> connectionCosts(gridSz);
        vector<vector<int>> moves = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        for (int i =0; i < rows; i++) {
            for (int j =0; j < cols; j++) {
                int dir = grid[i][j] - 1;
                int index = i*cols+j;
                for (int k=0; k < moves.size(); k++) {
                    int nRow = i+moves[k][0];
                    int nCol = j+moves[k][1];
                    if (nRow < 0|| nRow >= rows || nCol < 0 || nCol >= cols) continue;
                    int cost = k==dir ? 0: 1;
                    int nIndex = nRow*cols+nCol;
                    connectionCosts[index].emplace_back(nIndex, cost);
                }
            }
        }
        priority_queue<pair<int, int> , vector<pair<int, int>> , greater<>> pQ;
        pQ.emplace(0, 0);
        vector<bool> seen(gridSz);
        while (!pQ.empty()) {
            auto [cost, vertex] = pQ.top(); pQ.pop();
            if (vertex==gridSz-1) return cost;
            if (seen[vertex]) continue;
            seen[vertex] = true;
            for (auto & p: connectionCosts[vertex]) {
                if (seen[p.first]) continue;
                pQ.emplace(cost + p.second, p.first);
            }
        }
        return -1;
    }

    static void testMe() {
        MinCostGridDirectionalPath minCost;
        vector<vector<int>> grid = {{1,1,3},{3,2,2},{1,1,4}};
        int res = minCost.minCost(grid);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_MINCOSTGRIDDIRECTIONALPATH_H
