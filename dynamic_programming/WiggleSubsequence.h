//
// Created by usman on 10/24/22.
//

#ifndef CPPALGORITHMS_WIGGLESUBSEQUENCE_H
#define CPPALGORITHMS_WIGGLESUBSEQUENCE_H

#include <vector>

using namespace std;

/**
 *
 * https://leetcode.com/problems/wiggle-subsequence/
 */
class WiggleSubSequence {

public:
    /**
     * This solution is extremely simple and beautiful!
     * @param nums
     * @return
     */
    int wiggleMaxLength(vector<int>& nums) {
        int noUps=1;
        int noDowns=1;
        //carry the prior down or up forward into the next opposite one while incrementing
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1]) {
                noUps = noDowns+1;
            } else if (nums[i] < nums[i-1]) {
                noDowns = noUps + 1;
            }
        }
        return max(noUps, noDowns);
    }

    int wiggleMaxLengthWithConnections(vector<int>& nums) {
        pair<int,int> negative = make_pair(0, 1);
        pair<int,int> positive = make_pair(0, 1);

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[negative.first] && (
                    (negative.second+1 > positive.second) ||
                    ((negative.second+1 == positive.second) && nums[i] > nums[positive.first]))) {
                positive = make_pair(i, negative.second+1);
            } else if (nums[i] < nums[positive.first] && (
                    (positive.second+1 > negative.second) ||
                    ((positive.second+1 == negative.second) && nums[i] < nums[negative.first]))) {
                negative = make_pair(i, positive.second+1);
            }
        }
        return max(negative.second, positive.second);
    }
};

#endif //CPPALGORITHMS_WIGGLESUBSEQUENCE_H
