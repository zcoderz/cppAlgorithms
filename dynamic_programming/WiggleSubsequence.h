//
// Created by usman on 10/24/22.
//

#ifndef CPPALGORITHMS_WIGGLESUBSEQUENCE_H
#define CPPALGORITHMS_WIGGLESUBSEQUENCE_H

#include <vector>

using namespace std;

/**
 * DINOSAUR : Do this again without seeing code.......:)
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
};

#endif //CPPALGORITHMS_WIGGLESUBSEQUENCE_H
