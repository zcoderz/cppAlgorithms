//
// Created by usman on 10/26/21.
//

#ifndef CPPALGORITHMS_NCHOOSEK_H
#define CPPALGORITHMS_NCHOOSEK_H

#endif //CPPALGORITHMS_NCHOOSEK_H

#include <vector>

class NChooseK{
public:

    void process(int index, int startNum, int possibleNums, int chooseNums, vector<int> & currVec, vector<vector<int>> & res) {
        if (index == chooseNums) {
            res.push_back(currVec);
            return;
        }
        for (int i = startNum ; i <= possibleNums; i++) {
            currVec.push_back(i);
            process(index+1, i+1, possibleNums, chooseNums, currVec, res);
            currVec.pop_back();
        }
    }

    vector<vector<int>> find_combinations(int n, int k) {
        vector<vector<int>> res;
        vector<int> vec;
        process(0, 1, n, k, vec, res);
        return res;
    }
};