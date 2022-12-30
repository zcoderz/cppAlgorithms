//
// Created by usman on 12/29/22.
//

#ifndef CPPALGORITHMS_SHORTESTDISTANCEFROMALLBUILDINGS_H
#define CPPALGORITHMS_SHORTESTDISTANCEFROMALLBUILDINGS_H

#include <vector>
#include <queue>
#include <climits>
#include <tuple>
using namespace std;
/**
 * https://leetcode.com/problems/shortest-distance-from-all-buildings/
 * The below solution is taken from leetcode.
 * Very elegant in how it prunes the data and reuses the grid and distance vectors for each bfs iteration
 */
class BuildingsShortestDistance {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> moves = {{1,0}, {-1,0}, {0,1} , {0,-1}};
        vector<vector<int>> distance (rows, vector<int> (cols, 0));
        int minDist = INT_MAX;
        int targetValue = 0; //denotes open cells
        for (int i =0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] != 1) continue; //start work from buildings (buildings are denoted by 1)
                queue<tuple<int,int,int>> theQ;
                theQ.emplace(i,j,1); //start from the building. start step as 1, so it can be used as is on distance.
                minDist = INT_MAX;
                while (!theQ.empty()) {
                    auto [cRow, cCol, step] = theQ.front(); theQ.pop();
                    for (auto &move: moves) {
                        int nR = cRow + move[0];
                        int nC = cCol + move[1];
                        if (nR < 0 | nR == rows || nC < 0 || nC == cols || grid[nR][nC] != targetValue)
                            continue;
                        //decrement the grid value so that :
                        //1. it can be used to skip visiting this cell again in same iteration
                        //2. next iteration will only process cells that were reachable by previous iteration
                        //   non-reachable cells will get pruned, which will make the code faster.
                        grid[nR][nC] = targetValue-1;
                        //keep incrementing distance so that it amounts to total distance
                        //from all buildings as iterations complete
                        distance[nR][nC] += step;
                        //on each iteration minDist is reset (line 32)
                        //hence the last iteration will return the correct min distance as distances are aggregated
                        //if building is unreachable then minDist will stay as INT_MAX
                        minDist = min(minDist, distance[nR][nC]);
                        theQ.emplace(nR, nC, step+1);
                    }
                }
                //exit early if building is unreachable
                if (minDist == INT_MAX) return -1;
                targetValue--;
            }
        }
        return minDist;
    }
};
#endif //CPPALGORITHMS_SHORTESTDISTANCEFROMALLBUILDINGS_H
