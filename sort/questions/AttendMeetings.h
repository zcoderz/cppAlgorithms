//
// Created by usman on 10/19/21.
//

#ifndef KICK_START_ATTENDMEETINGS_H
#define KICK_START_ATTENDMEETINGS_H

#endif //KICK_START_ATTENDMEETINGS_H


#include <algorithm>
#include <vector>
using namespace std;

class Comparator {
public:
    bool operator() (const vector<int> & left, const vector<int> & right ) {
        return left[0] < right[0];
    }
};

class AttendMeetings {
public:
    int can_attend_all_meetings(vector<vector<int>> intervals) {
        Comparator comp;
        std::sort(intervals.begin(), intervals.end(), comp);
        int priorEnd = -1;
        for (int i=0; i < intervals.size(); i++) {
            if (intervals[i][0] < priorEnd) {
                return false;
            }
            priorEnd = intervals[i][1];
        }
        return true;
    }

};