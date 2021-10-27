//
// Created by usman on 10/27/21.
//

#ifndef CPPALGORITHMS_PASCALTRIANGLE_H
#define CPPALGORITHMS_PASCALTRIANGLE_H


#include <vector>
#include <map>
using namespace std;

class PascalTriangle {
public:
    map<pair<int, int> , int> mapRowCol;

    vector<int> getRow(int rowIndex) {
        vector<int> vals;
        for (int i =0; i <= rowIndex; i++) {
            vals.push_back(getVal(rowIndex, i));
        }
        return vals;
    }


    int getVal(int row, int col) {
        if (row == 1|| col == 0 || col == row) {
            return 1;
        } else  {
            pair<int, int> p(row, col);
            auto  iter = mapRowCol.find(p);
            if (iter != mapRowCol.end()) {
                return iter->second;
            }
        }
        int priorLeft = getVal(row-1, col-1);
        int priorRight = getVal(row-1, col);
        int sum = priorLeft+priorRight;
        mapRowCol.insert(make_pair(pair<int, int> (row,col), sum) );
        return sum;
    }
};

#endif //CPPALGORITHMS_PASCALTRIANGLE_H