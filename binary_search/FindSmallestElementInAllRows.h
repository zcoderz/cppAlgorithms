//
// Created by usman on 1/18/23.
//

#ifndef CPPALGORITHMS_FINDSMALLESTELEMENTINALLROWS_H
#define CPPALGORITHMS_FINDSMALLESTELEMENTINALLROWS_H

#include <vector>
using namespace std;

class FindSmallestElementInAllRows {
public:

    bool checkValInMatrix(vector<vector<int>>& mat, vector<int> & indices, int val, int cols) {
        bool found = true;
        for (int i =1; i < mat.size(); i++) {
            if (indices[i] == cols) {
                found = false;
                break;
            }
            while (indices[i] < cols && mat[i][indices[i]] < val) {
                indices[i]++;
            }

            if (indices[i] == cols || mat[i][indices[i]] != val) {
                found = false;
            }
        }
        return found;
    }

    int smallestCommonElement(vector<vector<int>>& mat) {
        if (mat.size()==1) return mat[0][0];
        int cols = mat[0].size();
        vector<int> indices(mat.size());
        for (int val : mat[0]) {
            if(checkValInMatrix(mat, indices, val, cols)) {
                return val;
            }
        }
        return -1;
    }
};

#endif //CPPALGORITHMS_FINDSMALLESTELEMENTINALLROWS_H
