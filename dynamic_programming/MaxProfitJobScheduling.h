//
// Created by USMAN QADIR on 11/8/22.
//

#ifndef CPPALGORITHMS_MAXPROFITJOBSCHEDULING_H
#define CPPALGORITHMS_MAXPROFITJOBSCHEDULING_H

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class MaxProfitJobScheduling {
public:
    static int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        typedef tuple<int, int, int> JobInfo;
        vector<JobInfo> jobVector;
        for (int i =0; i < startTime.size(); i++) {
            jobVector.emplace_back(profit[i], startTime[i], endTime[i]);
        }
        auto comp = [] (JobInfo &a, JobInfo &b) -> bool {
            // a < b, so that smaller end times are at beginning
            return get<2> (a) < get<2> (b);
        };
        sort(jobVector.begin(), jobVector.end(), comp);
        int maxProfit = 0;
        int lastEnd = get<2> (jobVector[jobVector.size()-1]);
        vector<int> dp(lastEnd+1,-1); dp[0]=0;
        for (int i =0; i < jobVector.size(); i++) {
            JobInfo  & jobInfo = jobVector[i];
            int startIndex = get<1> (jobInfo);
            int origStartIndex = startIndex;
            while (dp[startIndex]==-1) {
                startIndex--;
            }
            int startProfit = dp[startIndex];
            while (startIndex <= origStartIndex) {
                dp[startIndex++] = startProfit;
            }
            dp[get<2> (jobInfo)]= max(maxProfit, startProfit + get<0> (jobInfo));
            maxProfit = max(maxProfit, dp[get<2> (jobInfo)]);
        }
        return maxProfit;
    }

    static void testMe() {
        vector<int> startTimes = {1,2,3,4,6};
        vector<int> endTimes = {3,5,10,6,9};
        vector<int> profits = {20,20,100,70,60};
        int res = jobScheduling(startTimes, endTimes, profits);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_MAXPROFITJOBSCHEDULING_H
