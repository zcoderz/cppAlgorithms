//
// Created by usman on 12/23/22.
//

#ifndef CPPALGORITHMS_COURSESCHEDULE2_H
#define CPPALGORITHMS_COURSESCHEDULE2_H

#include <vector>
#include <stack>
using namespace std;

class CourseSchedule2 {

    bool processRec(vector<vector<int>> & deps, int course, vector<bool> & doneCheck, vector<bool> & visiting, vector<int> & courseOrder) {
        if (visiting[course]) return false;
        visiting[course] = true;
        for (int dep : deps[course]) {
            if (doneCheck[dep]) continue;
            bool res = processRec(deps, dep, doneCheck, visiting, courseOrder);
            if (!res) return res;
        }
        doneCheck[course] = true;
        visiting[course] = false;
        courseOrder.push_back(course);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> dependencies (numCourses);
        for (auto & vec: prerequisites) {
            dependencies[vec[0]].push_back(vec[1]);
        }
        vector<bool> doneCheck (numCourses);
        vector<bool> visited (numCourses);
        vector<int> courseOrder;
        for (int i = 0; i < numCourses; i++) {
            if (doneCheck[i]) continue;
            if (!processRec(dependencies, i, doneCheck, visited, courseOrder))
                return {};
        }
        return courseOrder;
    }
};

#endif //CPPALGORITHMS_COURSESCHEDULE2_H
