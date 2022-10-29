//
// Created by usman on 10/29/22.
//

#ifndef CPPALGORITHMS_LONGESTINCREASINGPATHINMATRIX_H
#define CPPALGORITHMS_LONGESTINCREASINGPATHINMATRIX_H

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/**
 * DINOSAUR : do this again
 */
class LongestIncreasingPathInMatrix {
public:
    static int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        if (cols == 0) return 0;
        //reflects how many surrounding cells are less than the given cell
        //and thus from how many cells can you come into this cell
        vector<vector<int>> inDegreeVec (rows, vector<int> (cols));
        list<pair<int,int>> leaves;
        vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for (int i =0; i < rows; i++) {
            for (int j =0; j < cols; j++) {
                for (vector<int> & dir : dirs) {
                    int x = i + dir[0], y = j + dir[1];
                    if (x<0 || x >= rows || y < 0 || y >= cols) continue;
                    if (matrix[i][j] > matrix[x][y]) {
                        inDegreeVec[i][j]++;
                    }
                }
                if (inDegreeVec[i][j] == 0) {
                    leaves.emplace_back(i,j);
                }
            }
        }
        int maxPathSz=0;
        while (!leaves.empty()) {
            maxPathSz++;
            int sz = leaves.size();
            for (int i =0 ; i < sz; i++) {
                pair<int, int> cell = leaves.front(); leaves.pop_front();
                for (vector<int> & dir : dirs) {
                    int x = cell.first + dir[0], y = cell.second + dir[1];
                    if (x<0 || x >= rows || y < 0 || y >= cols) continue;
                    if (matrix[cell.first][cell.second] < matrix[x][y]) {
                        inDegreeVec[x][y]--;
                        if (inDegreeVec[x][y] == 0) {
                            leaves.emplace_back(x,y);
                        }
                    }
                }
            }
        }

        return maxPathSz;
    }

    static void testMe() {
        vector<vector<int>> mat = {{9,9,4},{6,6,8},{2,1,1}};
        int res = longestIncreasingPath(mat);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_LONGESTINCREASINGPATHINMATRIX_H
