//
// Created by usman on 12/5/22.
//

#ifndef CPPALGORITHMS_MAXVACATIONDAYS_H
#define CPPALGORITHMS_MAXVACATIONDAYS_H

#include <vector>
#include <unordered_map>
#include <list>
#include <iostream>
using namespace std;

class MaxVacationDays {
public:

    static int processMaxVacations(int cityId, int weekId, unordered_map<int, list<int>> & connections, vector<vector<int>>& days,
                                   int numWeeks, vector<vector<int>> & memo) {
        if (weekId == numWeeks) return 0;
        if (memo[cityId][weekId] != -1) return memo[cityId][weekId];
        int vacNo = 0;
        for (int connection : connections[cityId]) {
            vacNo = max(vacNo,
                        days[connection][weekId] + processMaxVacations(connection, weekId+1, connections, days, numWeeks, memo));
        }

        memo[cityId][weekId] = vacNo;
        return vacNo;
    }

    static int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        unordered_map<int, list<int>> connections;
        for (int i =0; i < flights.size(); i++) {
            connections[i].push_back(i);
            vector<int> & cons = flights[i];
            for (int j= 0; j < cons.size(); j++) {
                if (cons[j]==1) {
                    connections[i].push_back(j);
                }
            }
        }
        if (days.empty()) return 0;
        int weeks = days[0].size();
        int cities = flights.size();
        vector<vector<int>> memo(cities, vector<int> (weeks, -1));
        return processMaxVacations(0, 0, connections, days,  weeks, memo);
    }

    static void testMe() {
        vector<vector<int>> flights = {{0,1,0,0,0},{0,0,1,0,0},{0,0,0,1,0},{0,1,1,0,0},{1,1,0,1,0}};
        vector<vector<int>> days = {{5,4,3,0,4},{0,6,4,3,6},{4,2,0,2,6},{4,6,1,4,3},{5,0,4,0,5}};
        int res = maxVacationDays(flights, days);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_MAXVACATIONDAYS_H
