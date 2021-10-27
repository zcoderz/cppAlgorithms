//
// Created by usman on 10/18/21.
//

#ifndef KICK_START_TWOSUM_H
#define KICK_START_TWOSUM_H

#include <vector>
using namespace std;

class TwoSum {
public:
    vector<int> pair_sum_sorted_array(vector<int> numbers, int target) {
        int left = 0; int right = numbers.size() -1 ;
        bool found = false;
        while (left < right) {
            int theSum = numbers[left] + numbers[right];
            if (theSum == target) {
                found = true; break;
            } else if (theSum > target) {
                right--;
            } else {
                left++;
            }
        }
        if (!found) return {-1, -1};
        else return {left, right};
    }
};

#endif //KICK_START_TWOSUM_H