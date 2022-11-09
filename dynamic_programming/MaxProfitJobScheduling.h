//
// Created by USMAN QADIR on 11/8/22.
//

#ifndef CPPALGORITHMS_MAXPROFITJOBSCHEDULING_H
#define CPPALGORITHMS_MAXPROFITJOBSCHEDULING_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

class MaxProfitJobScheduling {
public:

    static int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs;
        for (int i = 0; i < n; ++i) {
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }
        //sort by ending times ascending
        sort(jobs.begin(), jobs.end());
        //add marker that profit at time ending in 0 is 0
        map<int, int> dp = {{0, 0}};
        for (auto& job : jobs) {
            //prev(dp.upper_bound(job[1])) <--- get cost until time at or before the start time of the job
            //upper bound returns higher time (greater)...prev will return window at or before start time
            int cur = prev(dp.upper_bound(job[1]))->second + job[2];
            if (cur > dp.rbegin()->second)
                dp[job[0]] = cur;
        }
        return dp.rbegin()->second;
    }

    static void testMe() {
        vector<int> startTimes = {1,2,3,3};
        vector<int> endTimes = {3,4,5,6};
        vector<int> profits = {50,10,40,70};
        int res = jobScheduling(startTimes, endTimes, profits);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_MAXPROFITJOBSCHEDULING_H
