//
// Created by usman on 10/28/21.
//

#ifndef CPPALGORITHMS_NQUEENS_H
#define CPPALGORITHMS_NQUEENS_H

#include <vector>

using namespace std;

class NQueens {
public:
    vector <vector<string> > find_all_arrangements(int n) {
        vector<vector<int>> res;
        vector<int> currVec;
        process(0, res, currVec, n);
        vector<vector<string>> strRes;
        for (vector<int> & vec : res) {
            vector<string> sVec;
            for (int v: vec) {
                sVec.push_back(converttostr(v, n));
            }
            strRes.push_back(sVec);
        }
        return strRes;
    }

    void process(int row, vector<vector<int>> & res, vector<int> & currVec, int n) {
        if (currVec.size() > 1 && isConflict(currVec)) return;
        if (row == n) {
            res.push_back(currVec);
            return;
        }
        for (int i =0; i <n; i++) {
            currVec.push_back(i);
            process(row+1, res, currVec, n);
            currVec.pop_back();
        }
    }

    string converttostr(int index, int totalcols) {
        string strVal;
        for (int i =0; i < totalcols; i++) {
            if (i==index) {
                strVal.push_back('q');
            } else {
                strVal.push_back('-');
            }
        }
        return strVal;
    }

    bool isConflict(vector<int> & currVec) {
        int lastVal = currVec[currVec.size() - 1];
        for (int i = 0; i < currVec.size()-1; i++) {
            if (currVec[i] == lastVal) return true;
        }
        int lastRow = currVec.size()-1;
        for (int i =0; i < currVec.size()-1; i++) {
            int val = currVec[i];
            if (abs(val-lastVal) == abs(lastRow-i)) return true;
        }
        return false;
    }
};

#endif //CPPALGORITHMS_NQUEENS_H
