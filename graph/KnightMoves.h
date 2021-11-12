//
// Created by usman on 11/11/21.
//

#ifndef CPPALGORITHMS_KNIGHTMOVES_H
#define CPPALGORITHMS_KNIGHTMOVES_H

#include <limits>
#include <queue>
#include <unordered_set>


using namespace std;

#include <iostream>

/**
 * this questions needs to be solved via BFS. DFS can cause a very large stack explosion when working with large matrix
 * also code with bfs is simpler for this solution
 */
class KnightMoves {
public:
    vector<vector<int>> moves = {{2,  1},
                                 {2,  -1},
                                 {1,  2},
                                 {1,  -2},
                                 {-2, 1},
                                 {-2, -1},
                                 {-1, 2},
                                 {-1, -2}};
    int totalRows;
    int totalCols;
    int destRow;
    int destCol;

    bool isValid(int row, int col) {
        if (row < 0 || row >= totalRows || col < 0 || col >= totalCols) {
            return false;
        }
        return true;
    }

    int processMove(int row, int col) {
        int numMoves = 0;
        queue<pair<int, int>> queue;
        unordered_set<int> seen;
        queue.push(make_pair(row, col));
        while (!queue.empty()) {
            int sz = queue.size();
            numMoves++;
            for (int i = 0; i < sz; i++) {
                auto rowCol = queue.front();
                queue.pop();
                for (vector<int> &move: moves) {
                    int newRow = rowCol.first + move[0];
                    int newCol = rowCol.second + move[1];
                    if (newRow == destRow && newCol == destCol) return numMoves;
                    int index = newRow * totalCols + newCol;
                    if (isValid(newRow, newCol) && seen.find(index) == seen.end()) {
                        seen.insert(index);
                        queue.push(make_pair(newRow, newCol));
                    }
                }
            }
        }
        return -1;
    }

    int find_minimum_number_of_moves(int rows, int cols, int start_row, int start_col, int end_row, int end_col) {
        if (start_col == end_col && start_row == end_row) {
            return 0;
        }
        // Write your code here.
        totalRows = rows;
        totalCols = cols;
        destRow = end_row;
        destCol = end_col;
        return processMove(start_row, start_col);
    }
};

#endif //CPPALGORITHMS_KNIGHTMOVES_H
