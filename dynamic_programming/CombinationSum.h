//
// Created by usman on 11/1/22.
//

#ifndef CPPALGORITHMS_COMBINATIONSUM_H
#define CPPALGORITHMS_COMBINATIONSUM_H

#include <vector>
#include <algorithm>
using namespace std;
class CombinationSum {
public:

    void recurse(vector<vector<int>> & res, vector<int>& candidates, vector<int> & currValues, int currSum, int target, int startIndex) {
        if (currSum == target) {
            res.push_back(currValues);
            return;
        }
        for (int i =startIndex; i < candidates.size(); i++) {
            if ((currSum + candidates[i]) > target) break;
            currValues.push_back(candidates[i]);
            recurse(res, candidates, currValues, currSum + candidates[i], target, i);
            currValues.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> currValues;
        recurse(res, candidates, currValues, 0, target, 0);
        return res;
    }

    static void testMe() {

    }
};

#endif //CPPALGORITHMS_COMBINATIONSUM_H
