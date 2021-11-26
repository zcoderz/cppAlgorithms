//
// Created by usman on 11/17/21.
//

#ifndef CPPALGORITHMS_PARTITIONEQUALSUBSET_H
#define CPPALGORITHMS_PARTITIONEQUALSUBSET_H

#include <vector>
#include <numeric>
#include <algorithm>
#include <optional>

using namespace std;

class PartitionEqualSubset{
public:


    /**
     * Here is a very elegant approach to this problem.
     * you are counting possible sums via a combination of numbers. if you reach desires sum you return true
     * for each number in array, you calculate possible sums reachable by adding the number to the previous sum
     *
     * you can work with a single array via iterating from right to left on sums, this is so that the current number
     * doesnt affect possibilities that existed before the number is processed
     *
     * @param nums
     * @return
     */
    bool canPartition(vector<int> &nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total %2 != 0) return false;
        int desiredSum = total / 2;
        vector<bool> sumsPossible(desiredSum+1, false);
        sumsPossible[0] = true;
        for (int i =1; i < nums.size(); i++) {
            int currNum = nums[i];
            //you have to walk in reverse rather than forward to prevent double counting
            //imagine having 1 as a number. that one can only be used once but if you start from left
            //it will get used to fill 1, then 2, then 3 and so on.
            for (int j=desiredSum; (j-currNum) >= 0; j--) {
                sumsPossible[j] = sumsPossible[j] | sumsPossible[j-currNum];
            }
            if (sumsPossible[desiredSum]) return true;
        }
        return false;
    }

    /**
     * memorization based approach. you calculate whether a certain sum is possible or not at a given index in nums
     * and reuse the previously calculated value.
     * other than memorization , this is a simple call  include/exclude current number from target subset
     * @param nums
     * @param possibles
     * @param index
     * @param targetSum
     * @return
     */
    bool canPartitionRecursive(vector<int> &nums, vector<vector<optional<bool>>> & possibles, int index, int targetSum) {
        if (targetSum == 0) {
            return true;
        }
        if (index == 0 || targetSum < 0) {
            return false;
        }
        if (possibles[targetSum][index] != nullopt) {
            return possibles[targetSum][index].value();
        }
        possibles[targetSum][index] = canPartitionRecursive(nums, possibles, index-1, targetSum-nums[index]) |
                canPartitionRecursive(nums, possibles, index-1, targetSum);

        return possibles[targetSum][index].value();
    }

    bool canPartitionRecursive(vector<int> &nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total %2 != 0) return false;
        int desiredSum = total / 2;
        vector<vector<optional<bool>>> possibles(desiredSum+1, vector<optional<bool>> (nums.size()));
        return canPartitionRecursive(nums, possibles, nums.size()-1, desiredSum);
    }

    bool canPartitionLeet(vector<int> &nums) {
        int totalSum = 0;
        // find sum of all array elements
        for (int num : nums) {
            totalSum += num;
        }
        // if totalSum is odd, it cannot be partitioned into equal sum subset
        if (totalSum % 2 != 0) return false;
        int subSetSum = totalSum / 2;
        int n = nums.size();
        vector<vector<bool>> dp (n+1, vector<bool>(subSetSum+1, false)) ;
        //bool dp[n + 1][subSetSum + 1];
        //memset(dp, 0, (n + 1) * (subSetSum + 1) * sizeof(bool));
        dp[0][0] = true;
        for (int i = 1; i <= n; i++) {
            int curr = nums[i - 1];
            for (int j = 0; j <= subSetSum; j++) {
                if (j < curr)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j] || (dp[i - 1][j - curr]);
            }
        }
        return dp[n][subSetSum];
    }
};

#endif //CPPALGORITHMS_PARTITIONEQUALSUBSET_H
