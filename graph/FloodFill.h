//
// Created by usman on 11/11/21.
//

#ifndef CPPALGORITHMS_FLOODFILL_H
#define CPPALGORITHMS_FLOODFILL_H
class FloodFill {
    vector<vector<int>> moves = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int totalRows;
    int totalColumns;

    bool isValid(int row, int col) {
        if (row <0 || row >= totalRows || col < 0 || col >= totalColumns) {
            return false;
        }
        return true;
    }

    void process(int row, int col, int new_color, vector<vector<int>> & image) {
        int currColor = image[row][col];
        image[row][col] = new_color;

        for (vector<int> & move: moves ) {
            int nRow = row + move[0];
            int nCol = col + move[1];
            if (isValid(nRow, nCol) && image[nRow][nCol] == currColor ) {
                process(nRow, nCol, new_color, image);
            }
        }
    }


    vector<vector<int>> flood_fill(int pixel_row, int pixel_column, int new_color, vector<vector<int>> & image) {
        totalRows = image.size();
        totalColumns = image[0].size();
        if (image[pixel_row][pixel_column] != new_color) {
            process(pixel_row, pixel_column, new_color, image);
        }
        return image;
    }

};
#endif //CPPALGORITHMS_FLOODFILL_H
