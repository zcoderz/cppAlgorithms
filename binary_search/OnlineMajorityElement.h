//
// Created by usman on 1/26/23.
//

#ifndef CPPALGORITHMS_ONLINEMAJORITYELEMENT_H
#define CPPALGORITHMS_ONLINEMAJORITYELEMENT_H

#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <algorithm>
using namespace std;

class OnlineMajorityElement {
    unordered_map<int, vector<int>> valMap;
    vector<int>& _arr;
    OnlineMajorityElement(vector<int>& arr) : _arr(arr) {
        for (int i =0; i < arr.size(); i++) {
            valMap[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int threshold) {
        //add 1 to right - left , if left is 0, and right is 1.
        //you need to cover both 0 and first indexes. and hence mod by 2
        int distance = right-left+1;
        //for a majority element there is a 50% chance that the number will be returned at the given index.
        //given the complete array size is 10000 then we need to choose x, such that 2^x > 10000.
        //20 is larger than the desired and hence choosing it.
        for (int i=0; i < 20; i++) {
            int index = left + (rand() % distance);
            auto & arr = valMap[_arr[index]];
            auto lIter = lower_bound(arr.begin(), arr.end(), left);
            auto rIter = upper_bound(arr.begin(), arr.end(), right);
            //check the frequency of the number between the range.
            //if it's greater than threshold then we are good to return
            if ((rIter - lIter) >= threshold) {
                return _arr[index];
            }
        }
        return -1;
    }
};

#endif //CPPALGORITHMS_ONLINEMAJORITYELEMENT_H
