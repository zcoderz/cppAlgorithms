//
// Created by usman on 11/1/22.
//

#ifndef CPPALGORITHMS_TARGETSUM_H
#define CPPALGORITHMS_TARGETSUM_H
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>

using namespace std;

/**
 *
 */
class TargetSum {
public:
    static int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (target > sum || target < -sum) return false;
        vector<int> dp(2*sum+1);
        //set starting point to 1
        dp[sum]=1;

        //an offset of +sum is added to target to ensure indices stay positive
        //lowest value for target is -sum, which makes modTarget 0
        int modTarget = sum + target;

        for (int i=0; i < nums.size(); i++) {
            //you want to allocate a new array per iteration so that
            //you only use values in prior iteration to set current values
            vector<int> dpTmp(2*sum+1);
            //you can reach from +Sum to -Sum based on + or - nums
            //so that you can capture the whole range of reachable values , need to iterate from sum to -sum
            for (int j=sum; j >=-sum; j--) {
                //you can only update current data points if source point dp[sum+j] is not 0.
                if (dp[sum+j] ==0) continue;
                dpTmp[sum+j+nums[i]] += dp[sum+j];
                dpTmp[sum+j-nums[i]] += dp[sum+j];
            }
            swap(dpTmp, dp);
        }
        return dp[modTarget];
    }

    static void testMe() {
        vector<int> vals = {1,1,1,1,1};
        int res = findTargetSumWays(vals, 3);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_TARGETSUM_H
