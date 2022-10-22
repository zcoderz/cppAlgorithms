//
// Created by usman on 10/17/22.
//

#ifndef CPPALGORITHMS_HOUSEROBBER_H
#define CPPALGORITHMS_HOUSEROBBER_H

#include <vector>
#include <iostream>
using namespace std;

class HouseRobber {
public:

    static int houseRobber(vector<int>& nums, int start, int end) {
        int prior=0, current =0;
        for (int i =start; i <=end; i++) {
            int tmp = max(prior + nums[i], current);
            prior=current;
            current = tmp;
        }
        return current;
    }

    static int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> dp(nums.size()); dp[0] = nums[0];
        for (int i =1; i < nums.size(); i++) {
            dp[i] = max(dp[i-1], i >=2 ? nums[i] + dp[i-2] : nums[i]);
        }
        return dp[nums.size()-1];
    }

    static void testMe() {
        vector<int> data = {1,2,3,1};
        int res = rob(data);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_HOUSEROBBER_H
