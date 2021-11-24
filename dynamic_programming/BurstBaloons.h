//
// Created by usman on 11/18/21.
//

#include <vector>
using namespace std;

/**
 * This logic is similar to the matrix chain multiplication order
 */
#ifndef CPPALGORITHMS_BURSTBALOONS_H
#define CPPALGORITHMS_BURSTBALOONS_H
class BurstBaloons {
public:

    int maxCoins(vector<int>& nums, int left, int right, vector<vector<optional<int>>> & costs) {
        if (left == 0 || right == nums.size()-1 || left > right) {
            return 0;
        }
        if (costs[left][right] != nullopt) {
            return costs[left][right].value();
        }
        int costT = 0;
        for (int i = left; i <= right; i++) {
            int cost = nums[left-1] * nums[i] * nums[right+1];
            cost += maxCoins(nums, left, i-1, costs);
            cost += maxCoins(nums, i+1, right, costs);
            costT = max(cost, costT);
        }
        costs[left][right] = costT;
        return costT;
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.emplace_back(1);
        vector<vector<optional<int>>> costs(nums.size(), vector<optional<int>> (nums.size()));
        return maxCoins(nums, 1, nums.size()-2, costs);
    }

    int maxCoinsDP(vector<int>& nums) {
        // add 1 before and after nums
        nums.insert(nums.begin(), 1);
        nums.emplace_back(1);
        // dp[i][j] represents
        // maximum if we burst all nums[left]...nums[right], inclusive
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        //do not include the first one and the last one
        //since they are both fake balloons added by ourselves and we can not burst them
        //each matrix coordinate dp[left][right] denotes how much money you could make with that partition.
        //thus previously calculated partition values are utilized in calculating larger partitions to avoid
        //duplicate work. to ensure the dependency order in partition is correct
        //below code starts from last row and right end, it moves one row up per iteration,
        //while extending the partition bounds one further to left
        for (int left = nums.size() - 2; left >= 1; left--) {
            for (int right = left; right <= nums.size() - 2; right++) {
                // find the last burst one in nums[left]...nums[right]
                for (int i = left; i <= right; i++) {
                    // nums[i] is the last burst one
                    int gain = nums[left - 1] * nums[i] * nums[right + 1];
                    // recursively call left side and right side
                    int remaining = dp[left][i - 1] + dp[i + 1][right];
                    // update
                    dp[left][right] = max(remaining + gain, dp[left][right]);
                }
            }
        }
        // burst newNums[1]...newNums[n-2], excluding the first one and the last one
        return dp[1][nums.size() - 2];
    }
};
#endif //CPPALGORITHMS_BURSTBALOONS_H