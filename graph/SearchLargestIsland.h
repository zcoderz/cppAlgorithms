//
// Created by usman on 11/11/21.
//

#ifndef CPPALGORITHMS_SEARCHLARGESTISLAND_H
#define CPPALGORITHMS_SEARCHLARGESTISLAND_H
class LargestIsland {
public:
    vector <vector<int>> moves = {{1,  0},
                                  {-1, 0},
                                  {0,  1},
                                  {0,  -1}};
    vector <vector<int>> *matrix;
    unordered_set<int> seen;
    int totalRows;
    int totalCols;
    int maxSz = 0;

    bool isValid(int row, int col) {
        if (row < 0 || row >= totalRows || col < 0 || col >= (totalCols)) return false;
        return true;
    }

    int process(int row, int col) {
        int index = row * totalCols + col;

        seen.insert(index);
        int sz = 1;
        for (vector<int> &move: moves) {
            int nRow = row + move[0];
            int nCol = col + move[1];
            int nindex = nRow * totalCols + nCol;
            if (isValid(nRow, nCol) && ((*matrix)[nRow][nCol] == 1) && (seen.find(nindex) == seen.end())) {
                sz += process(nRow, nCol);
            }
        }
        return sz;
    }


    int max_island_size(vector <vector<int>> &matrix) {
        this->matrix = &matrix;
        totalRows = matrix.size();
        totalCols = matrix[0].size();

        for (int i = 0; i < totalRows; i++) {
            for (int j = 0; j < totalCols; j++) {
                int index = i * totalCols + j;
                if (((matrix)[i][j] == 1) && seen.find(index) == seen.end()) {
                    maxSz = max (maxSz, process(i, j));
                }
            }
        }
        return maxSz;
    }

};
#endif //CPPALGORITHMS_SEARCHLARGESTISLAND_H
