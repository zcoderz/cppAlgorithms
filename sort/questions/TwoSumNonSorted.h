//
// Created by usman on 10/18/21.
//

#ifndef KICK_START_TWOSUMNONSORTED_H
#define KICK_START_TWOSUMNONSORTED_H

#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class TwoSumNonSorted {

    //single pass two sum
    vector<int> two_sum(vector<int> numbers, int target) {
        unordered_map<int, int> data;
        for (int i =0; i < numbers.size(); i++) {
                int complement = target - numbers[i];
                auto  iter = data.find(complement);
                if (data.find(complement) != data.end()) {
                    return {i, iter->second};
                }
                data.insert(make_pair(numbers[i], i));
        }
        return {};
    }

    vector<int> two_sum_two_pass(vector<int> numbers, int target) {
        unordered_map<int, int> valIndex;

        for (int j = numbers.size()-1; j >=0; j--) {
            if (valIndex.find(numbers[j]) == valIndex.end()) {
                valIndex[numbers[j]] = j;
            }
        }
        int otherIndex = -1;
        int i =0;
        for (; i < numbers.size(); i++) {
            int diff = target - numbers[i];
            unordered_map<int, int>::iterator  iter = valIndex.find(diff);
            if (iter != valIndex.end() && iter->second != i) {
                otherIndex = iter->second;
                break;
            }
        }
        if (otherIndex != -1) {
            return {i,  otherIndex};
        } else {
            return {-1,-1};
        }
    }
};

#endif //KICK_START_TWOSUMNONSORTED_H