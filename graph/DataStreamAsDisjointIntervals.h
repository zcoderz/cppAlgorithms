//
// Created by usman on 12/23/22.
//

#ifndef CPPALGORITHMS_DATASTREAMASDISJOINTINTERVALS_H
#define CPPALGORITHMS_DATASTREAMASDISJOINTINTERVALS_H

#include <vector>
#include <set>

using namespace std;

class SummaryRanges {
public:
    set<int> nums;
    SummaryRanges() {

    }

    void addNum(int value) {
        nums.insert(value);
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        int left=-1, right=-1;
        for (int val : nums) {
            if (left ==-1) {
                left = right = val;
            } else if (val == right+1) {
                right = val;
            }  else {
                res.push_back({left, right});
                left=right=val;
            }
        }
        res.push_back({left,right});
        return res;
    }
};

#endif //CPPALGORITHMS_DATASTREAMASDISJOINTINTERVALS_H
