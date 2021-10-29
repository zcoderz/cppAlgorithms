//
// Created by usman on 10/28/21.
//

#ifndef CPPALGORITHMS_SOLVESUDOKU_H
#define CPPALGORITHMS_SOLVESUDOKU_H

#include <vector>
using namespace std;
class SolveSudoku {
public:

    vector<vector<int>> rowVals;
    vector<vector<int>> colVals;
    vector<vector<int>> cellVals;
    vector<vector<int>> board;
    int id = 0;
    vector<vector<int>> solve_sudoku_puzzle(vector<vector<int>> board) {
        this->board = board;
        std::vector<int> array{0,0, 0, 0, 0, 0, 0, 0, 0};
        for (int j =0; j < 9; j++) {
            rowVals.push_back(array);
            colVals.push_back(array);
            cellVals.push_back(array);
        }
        for (int j =0; j < 9; j++) {
            vector<int> & unitVals = this->board[j];
            for (int i = 0; i < 9; i++) {
                int val = unitVals[i];
                if (val !=0) {
                    colVals[i][val]=1;
                    rowVals[j][val]=1;
                    int cellId = (j/3)*3 + i/3;
                    cellVals[cellId][val]=1;
                }
            }
        }

        // Write your code here.
        runThroughBoard(0);
        return board;
    }

    bool runThroughBoard(int id) {
        if (id == 81) {
            return true;
        }
        int row = id / 9;
        int col = id % 9;
        int cellId = (row/3)*3 + col/3;
        for (int i =1; i <= 9; i++) {
            if (board[row][col] !=0) {
                return runThroughBoard(id+1);
            } else if (isValid(row, col, cellId, i)) {
                board[row][col] = i;
                rowVals[row][i]=1;
                colVals[col][i]=1;
                cellVals[cellId][i]=1;
                bool boardRet = runThroughBoard(id+1);
                if (boardRet) {
                    return true;
                }
                board[row][col] = 0;
                rowVals[row][i]=0;
                colVals[col][i]=0;
                cellVals[cellId][i]=0;
            }
        }
        return false;
    }

    bool isValid(int row, int col, int cellId, int val) {
        return (board[row][col] == 0 && rowVals[row][val]==0 && colVals[col][val]==0 && cellVals[cellId][val]==0);
    }
};
#endif //CPPALGORITHMS_SOLVESUDOKU_H
