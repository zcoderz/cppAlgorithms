//
// Created by usman on 10/27/21.
//

#ifndef CPPALGORITHMS_COMBINATIONSUM_H
#define CPPALGORITHMS_COMBINATIONSUM_H

#include <vector>
using namespace std;

/**
 * This is the question : https://leetcode.com/problems/combination-sum-iii/
 * 216. Combination Sum III
 */
class CombinationSum {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> currentComb;
        calculateCombinations(1, 0, 0, k, n, currentComb, res);
        return res;
    }

    void calculateCombinations(int startNum, int numbersUsedSoFar, int sumSoFar, int maxNumsAllowed, int target, vector<int> & currentComb, vector<vector<int>>  & res) {
        if (numbersUsedSoFar > maxNumsAllowed || sumSoFar > target) return;
        if (numbersUsedSoFar == maxNumsAllowed && sumSoFar == target) {
            res.push_back(currentComb);
            return;
        }

        for (int i=startNum ; i <=9; i++) {
            currentComb.push_back(i);
            calculateCombinations(i+1, numbersUsedSoFar+1, sumSoFar + i, maxNumsAllowed, target, currentComb, res);
            currentComb.pop_back();
        }
    }
};

#endif //CPPALGORITHMS_COMBINATIONSUM_H