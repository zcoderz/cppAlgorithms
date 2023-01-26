//
// Created by usman on 1/25/23.
//

#ifndef CPPALGORITHMS_MAKEARRAYSTRICTLYINCREASING_H
#define CPPALGORITHMS_MAKEARRAYSTRICTLYINCREASING_H

#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>
using namespace std;

class MakeArrayStrictlyIncreasing{
public:

    static int process(vector<int>& arr1, vector<int>& arr2, vector<unordered_map<int, int>> & dp, int i, int j, int priorNum) {
        if (i==arr1.size()) {
            return 0;
        }
        auto & map = dp[i];
        auto iter = map.find(priorNum);
        if (iter != map.end()) return iter->second;
        int res1 = INT_MAX/2;
        int res2 = INT_MAX/2;
        auto jIter = upper_bound(arr2.begin()+j, arr2.end(), priorNum);
        if (jIter != arr2.end()) {
            res2 = process(arr1, arr2, dp, i + 1, jIter - arr2.begin() + 1, *jIter) + 1;
        }
        if (arr1[i] > priorNum) {
            res1 = process(arr1, arr2, dp, i + 1, j, arr1[i]);
        }
        int res = min(res1, res2);
        dp[i][priorNum] = res;
        return res;
    }

    static int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        vector<unordered_map<int, int>> dp(arr1.size() , unordered_map<int, int> ());
        int res = process(arr1, arr2, dp, 0, 0, INT_MIN);
        return res >= INT_MAX/2 ? -1: res;
    }

    static void testMe() {
        vector<int> a = {31,18,1,12,23,14,25,4,17,18,29,28,35,34,19,8,25,6,35};
        vector<int> b = {13,10,25,18,3,8,37,20,23,12,9,36,17,22,29,6,1,12,37,6,3,14,37,2};
        int res = makeArrayIncreasing(a,b);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_MAKEARRAYSTRICTLYINCREASING_H
