//
// Created by usman on 12/29/22.
//

#ifndef CPPALGORITHMS_THEMAZE_H
#define CPPALGORITHMS_THEMAZE_H

#include <vector>
#include <queue>
using namespace std;

class TheMaze {
public:

    int calculateNewIndex(vector<int> move, int row, int col, vector<vector<int>>& maze, vector<bool> &seen,
                          int rows, int cols) {
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
        }
    }

    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        vector<vector<int>> moves = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        queue<int> queue;
        int rows = maze.size();
        int cols = maze[0].size();
        int startIndex = start[0]*cols+start[1];
        int destIndex = destination[0]*cols+destination[1];
        queue.emplace(startIndex);
        vector<bool> seen (rows*cols);
        while (!queue.empty()) {
            auto index =  queue.front(); queue.pop();
            if (index == destIndex) return true;
            if (seen[index]) continue;
            seen[index] = true;
            int theRow = index/cols;
            int theCol = index%cols;
            for (auto & move: moves) {
                int newIndex = calculateNewIndex(move, theRow, theCol, maze, seen, rows, cols);
                if (newIndex==-1) continue;
                queue.emplace(newIndex);
            }
        }
        return false;
    }
};

#endif //CPPALGORITHMS_THEMAZE_H
