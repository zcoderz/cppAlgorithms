//
// Created by usman on 11/22/22.
//

#ifndef CPPALGORITHMS_COMBINATIONSUMTWO_H
#define CPPALGORITHMS_COMBINATIONSUMTWO_H

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class CombinationSumTwo {
public:

    void processRecur(int sumSoFar, int index, int target, vector<vector<int>> & res, vector<int> & vals, vector<int>& candidates) {
        if (sumSoFar==target) {
            res.push_back(vals);
            return;
        }
        if (sumSoFar > target) return;
        for (int i =index; i < candidates.size(); i++) {
            //if first iteration on the call , process the number even if same as prior to handle cases such as 116 and target 8. include 1+1+6.
            //however for 116 and target 7, to avoid 1,6 to be included repeatedly,
            //in subsequent iteration if number is same as prior skip it. so once you have already processed 1 at index 0, skip the 1 at index 1 inside same loop
            if (i > index && candidates[i] == candidates[i-1]) continue;
            vals.push_back(candidates[i]);
            processRecur(candidates[i], i+1, target, res, vals, candidates);
            vals.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> vals;
        processRecur(0, 0, target, res, vals, candidates);
        return res;
    }
};

#endif //CPPALGORITHMS_COMBINATIONSUMTWO_H
