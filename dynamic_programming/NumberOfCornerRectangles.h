//
// Created by usman on 11/20/22.
//

#ifndef CPPALGORITHMS_NUMBEROFCORNERRECTANGLES_H
#define CPPALGORITHMS_NUMBEROFCORNERRECTANGLES_H

#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;
class NumberOfCornerRectangles {
public:
    static int countCornerRectangles(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<unordered_set<int>> rowOnes(rows, unordered_set<int>());
        for (int i = 0; i < rows; i++)  {
            vector<int> & row = grid[i];
            unordered_set<int> & set = rowOnes[i];
            for (int j =0; j < cols; j++) {
                if(grid[i][j] == 1) {
                    set.insert(j);
                }
            }
        }

        int res = 0;
        for (int i = 0; i < rows; i++)  {
            unordered_set<int> & origRowOnes = rowOnes[i];
            for (int j =i+1; j < rows; j++) {
                unordered_set<int> & nextRowOnes = rowOnes[j];
                int matchCnt = 0;
                for (int val : nextRowOnes) {
                    if (origRowOnes.find(val) != origRowOnes.end()) matchCnt++;
                }
                res += ((matchCnt * (matchCnt-1))/2);
            }
        }
        return res;
    }

    static void testMe() {
        vector<vector<int>> grid = {{1, 0, 0, 1, 0}, {0, 0, 1, 0, 1}, {0, 0, 0, 1, 0}, {1, 0, 1, 0, 1}};
        int res = countCornerRectangles(grid);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_NUMBEROFCORNERRECTANGLES_H
