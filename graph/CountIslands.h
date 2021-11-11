//
// Created by usman on 11/10/21.
//

#ifndef CPPALGORITHMS_COUNTISLANDS_H
#define CPPALGORITHMS_COUNTISLANDS_H

class CountIslands {
public:
    vector<vector<int>> moves = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    vector<vector<int>> * matrix;
    unordered_set<int> seen;
    int totalRows;
    int totalCols;
    int count_islands(vector<vector<int>> & matrix) {
        this->matrix = &matrix;
        totalRows = matrix.size();
        totalCols = matrix[0].size();
        int numIslands = 0;
        for (int i =0; i < totalRows; i++) {
            for (int j =0; j < totalCols; j++) {
                int index = i*totalCols + j;
                if (((matrix)[i][j]==1) && seen.find(index) == seen.end()) {
                    numIslands++;
                    process(i, j);
                }
            }
        }
        return numIslands;
    }

    void process(int row, int col) {
        int index = row*totalCols + col;
        seen.insert(index);
        for (vector<int> & move : moves) {
            int nRow = row + move[0];
            int nCol = col + move[1];
            int nindex = nRow*totalCols + nCol;
            if (isValid(nRow, nCol) && ((*matrix)[nRow][nCol]==1) && (seen.find(nindex) == seen.end())) {
                process(nRow, nCol);
            }
        }
    }

    bool isValid(int row, int col) {
        if (row < 0 || row >= totalRows || col < 0 || col >= (totalCols)) return false;
        return true;
    }
};

#endif //CPPALGORITHMS_COUNTISLANDS_H
