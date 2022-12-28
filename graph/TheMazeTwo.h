//
// Created by usman on 12/28/22.
//

#ifndef CPPALGORITHMS_THEMAZETWO_H
#define CPPALGORITHMS_THEMAZETWO_H

#include <vector>
#include <queue>
using namespace std;

class TheMazeTwo {
public:

    int calculateNewIndex(vector<int> move, int row, int col, vector<vector<int>>& maze, vector<bool> &seen,
                          int rows, int cols, int &newCost) {
        int i =1;
        while (true) {
            int nRow = row + move[0]*i;
            int nCol = col + move[1]*i;
            if (nRow < 0 || nRow == rows || nCol < 0|| nCol==cols || maze[nRow][nCol] ==1) {
                nRow = row + move[0]* (i-1);
                nCol = col + move[1]* (i-1);
                int newIndex = nRow*cols+ nCol;
                if (seen[newIndex]) return -1;
                return newIndex;
            }
            i++;
            newCost++;
        }
    }

    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        vector<vector<int>> moves = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pQ;
        int rows = maze.size();
        int cols = maze[0].size();
        int startIndex = start[0]*cols+start[1];
        int destIndex = destination[0]*cols+destination[1];
        pQ.emplace(0, startIndex);
        vector<bool> seen (rows*cols);
        while (!pQ.empty()) {
            auto [cost, index] = pQ.top(); pQ.pop();
            if (index == destIndex) return cost;
            if (seen[index]) continue;
            seen[index] = true;
            int theRow = index/cols;
            int theCol = index%cols;
            for (auto & move: moves) {
                int newCost=0;
                int newIndex = calculateNewIndex(move, theRow, theCol, maze, seen, rows, cols, newCost);
                if (newIndex==-1) continue;
                pQ.emplace(cost+newCost, newIndex);
            }
        }
        return -1;
    }

    static void testMe() {
        vector<vector<int>> maze = {{0,0,1,0,0},{0,0,0,0,0},{0,0,0,1,0},{1,1,0,1,1},{0,0,0,0,0}};
        vector<int> start = {0,4};
        vector<int> dest = {4,4};
        TheMazeTwo mazeC;
        int res = mazeC.shortestDistance(maze,start, dest);
        cout << res << endl;
    }

};

#endif //CPPALGORITHMS_THEMAZETWO_H
