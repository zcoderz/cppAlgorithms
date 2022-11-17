//
// Created by usman on 11/16/22.
//

#ifndef CPPALGORITHMS_NONOVERLAPPINGINTERVALS_H
#define CPPALGORITHMS_NONOVERLAPPINGINTERVALS_H

#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

/**
 * This is an extremely simple question once you understand that all
 * sort the intervals so you can compare their end times
 * and you need to ensure that if an interval overlaps a prior interval you skip it
 * this is done because you want to minimize the furthest ending distance as you iterate over the intervals
 */
class NonOverlappingIntervals {
public:
    static int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        auto comp = []  (vector<int> & a, vector<int> &b) -> bool {return a[1] < b[1];};
        sort(intervals.begin(), intervals.end(), comp);
        int skipped = 0;
        int lastInterval = INT_MIN;
        for (vector<int> & interval : intervals) {
            if (interval[0] < lastInterval) {
                skipped++;
            } else {
                lastInterval = interval[1];
            }
        }
        return skipped;
    }

    static int eraseOverlapIntervalsDP(vector<vector<int>>& intervals) {
        auto comp = []  (vector<int> & a, vector<int> &b) -> bool {return a[1] < b[1];};
        sort(intervals.begin(), intervals.end(), comp);
        vector<int> dp(intervals.size());

        for (int i =0 ; i < intervals.size(); i++) {
            int j = i-1;
            while (j >= 0 && intervals[j][1] > intervals[i][0]) {
                j--; //go back to the first interval before current interval that doesnt overlap
            }
            dp[i] = max( (i > 0 ? dp[i-1] : 0), (j >=0 ? dp[j] : 0)+1);
        }
        return intervals.size() - dp[intervals.size()-1] ;
    }

    static void testMe() {
        vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};
        int res = eraseOverlapIntervalsDP(intervals);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_NONOVERLAPPINGINTERVALS_H
