//
// Created by usman on 1/21/23.
//

#ifndef CPPALGORITHMS_MINIMUMOPERATIONSTOMAKEASUBSEQUENCE_H
#define CPPALGORITHMS_MINIMUMOPERATIONSTOMAKEASUBSEQUENCE_H

#include <vector>
#include <unordered_map>
#include <map>
#include <climits>

using namespace std;

/**
 * Neat way to transform problem into largest increasing sequence and solve it
 */
class MinOperationsToMakeASubsequence {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> indexes;
        for (int i =0; i < target.size(); i++) {
            indexes[target[i]] = i;
        }
        //use a stack to track increasing index sequences.
        //the stack will contain the largest increasing sequence in it.
        vector<int> matchStack;
        for (int v: arr) {
            auto iterTargetIndex = indexes.find(v);
            if (iterTargetIndex == indexes.end()) continue;
            //iterTargetIndex->second is the index of the value v in target array
            auto iter = lower_bound(matchStack.begin(), matchStack.end(), iterTargetIndex->second);
            if (iter == matchStack.end()) {
                //add if it increases the sequence size
                matchStack.push_back(iterTargetIndex->second);
            } else {
                //in stack update value at lower_bound (same or greater) index to be current value
                *iter = iterTargetIndex->second;
            }
        }
        return target.size()-matchStack.size();
    }
};

#endif //CPPALGORITHMS_MINIMUMOPERATIONSTOMAKEASUBSEQUENCE_H
