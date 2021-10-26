//
// Created by usman on 10/22/21.
//

#ifndef CPPALGORITHMS_SORTCOLORS_H
#define CPPALGORITHMS_SORTCOLORS_H

#endif //CPPALGORITHMS_SORTCOLORS_H

#include <vector>

using namespace std;

class SortColors {
public:
    void sortColors(vector<int>& nums) {
        int left =0;
        int right = nums.size() - 1;
        int curr = left;
        int leftColor = 0;
        int midColor = 1;


        while (curr <= right) {
            if (nums[curr] == midColor) {
                curr++;
            } else if (nums[curr] == leftColor) {
                swap(nums[curr++], nums[left++]);
            } else {
                swap(nums[curr], nums[right--]);
            }
        }
    }
};