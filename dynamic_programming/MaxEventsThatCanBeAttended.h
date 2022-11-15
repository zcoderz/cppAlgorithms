//
// Created by usman on 11/14/22.
//

#ifndef CPPALGORITHMS_MAXEVENTSTHATCANBEATTENDED_H
#define CPPALGORITHMS_MAXEVENTSTHATCANBEATTENDED_H

#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

class MaxEventsPossible{
public:

    static int maxValueDp(vector<vector<int>>& events, int k) {
        int n = events.size();
        auto comp = [] (vector<int> & a, vector<int> & b) -> bool {return a[1] < b[1];};
        sort(events.begin(), events.end(), comp);
        map<int, int> dp1 =  {{0, 0}};
        for (int i = 0; i < k; i++) {
            map<int, int> dp2 =  {{0, 0}};
            for (int j = 0; j < n; j++) {
                //cur is the value which is previously in the map (already processed in prior iteration of k)
                int cur = prev(dp1.lower_bound(events[j][0]))->second;
                if(cur + events[j][2] > dp2.rbegin()->second) {
                    //only add if the aggregated value in current map
                    dp2[events[j][1]] =  cur + events[j][2];
                }
            }
            swap(dp1, dp2);
        }
        return dp1.rbegin()->second;
    }

    static int maxValueRecuse(vector<vector<int>>& events, int currentK, int currIndex, int lastIndex, vector<vector<int>> & dp) {
        if (currentK == 0 || currIndex == lastIndex) {
            return 0;
        }
        if (dp[currIndex][currentK] != -1) return dp[currIndex][currentK];
        int currEnd = events[currIndex][1];
        int nextIndex = currIndex+1;
        for (; nextIndex < lastIndex; nextIndex++) {
            //find index of next start event after the current event finishes
            if (events[nextIndex][0] > currEnd) {
                break;
            }
        }
        return dp[currIndex][currentK]   = max(events[currIndex][2] + maxValueRecuse(events, currentK-1,  nextIndex, lastIndex, dp),
                                             maxValueRecuse(events, currentK,  currIndex+1, lastIndex, dp));
    }

    static int maxValue(vector<vector<int>>& events, int k) {
        //sort first by start times, if start times of two events are same sort by end time
        auto comp = [] (vector<int> & a, vector<int> & b) -> bool {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            } else {
                return a[0] < b[0];
            }
        };
        sort(events.begin(), events.end(), comp);
        vector<vector<int>> dp(events.size()+1, vector<int> (k+1, -1));
        return maxValueRecuse(events, k,  0, events.size(), dp);
    }

    static void testMe() {
        vector<vector<int>> events = {{1,5,6}, {0,4,5}, {5,7,2}, {7,9,7}};
        int result = maxValue(events, 2);
        cout << result << endl;
    }
};

#endif //CPPALGORITHMS_MAXEVENTSTHATCANBEATTENDED_H
