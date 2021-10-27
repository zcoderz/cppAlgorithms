//
// Created by usman on 10/21/21.
//

#ifndef CPPALGORITHMS_THREESUM_H
#define CPPALGORITHMS_THREESUM_H


#include <vector>
#include <unordered_set>

using namespace std;
class ThreeSum {
public:
    /**
     * sort based approach
     * @param nums
     * @return
     */
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i =0; i < nums.size(); i++) {
            if (i ==0 || nums[i-1] != nums[i]) {
                processSum(nums, i+1, -nums[i], res);
            }
        }
        return res;
    }

    void processSum(vector<int> & nums, int startIndex, int target, vector<vector<int>> & res) {
        int i = startIndex;
        int j = nums.size() - 1;
        while (j > i) {
            if ( (nums[i] + nums[j]) > target) {
                j--;
            } else if ((nums[i] + nums[j]) < target) {
                i++;
            } else {
                res.push_back({-target, nums[i++], nums[j--]});
                while (i < nums.size() && nums[i] == nums[i-1]) {
                    i++;
                }
                while (j > i  && nums[j] == nums[j+1]) {
                    j--;
                }
            }
        }
    }

    vector<vector<int>> threeSumHash(vector<int>& nums) {
        set<vector<int>> res;
        set<int> dups;
        unordered_map<int, int> valMap;
        for (int i =0; i < nums.size(); i++) {
            if (dups.find(nums[i]) == dups.end()) {
                int val = nums[i];
                for (int j = i+1; j < nums.size(); j++) {
                    int target = -val - nums[j];
                    auto  iter = valMap.find(target);
                    if (iter != valMap.end() && iter->second == i) {
                        vector<int> vec = {val, nums[j], target};
                        sort(vec.begin(), vec.end());
                        res.insert(vec);
                    }
                    valMap[nums[j]] = i;
                }
                dups.insert(nums[i]);
            }
        }
        vector<vector<int>> vRes(res.begin(), res.end());
        return vRes;
    }
};

#endif //CPPALGORITHMS_THREESUM_H