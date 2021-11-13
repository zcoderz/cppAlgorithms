//
// Created by usman on 11/13/21.
//

#ifndef CPPALGORITHMS_COURSESCHEDULE_H
#define CPPALGORITHMS_COURSESCHEDULE_H
#include <unordered_set>

using namespace std;
class CourseSchedule {
public:

    /**
     * very simple but extremely elegant approach
     * @param n
     * @param prerequisites
     * @return
     */
    vector<int> course_schedule(int n, vector<vector<int>> & prerequisites) {
        vector<int> order;
        //dependencies indicate a list of courses that the given course is dependent on
        vector<vector<int>> dependencies(n);
        //indicates number of courses dependent on a given course
        vector<int> numDependencies(n, 0);

        for (vector<int> & preReq: prerequisites) {
            int needsCompletedAfter = preReq[0];
            int dependingCourse = preReq[1];
            //when the given dependingCourse completes , you can decrease dependency on the needsCompletedAfter
            //hence add the needsCompletedAfter as dep on this dependingCourse
            //(you need to notify the needsCompletedAfter that its dependencies have decreased).
            dependencies[dependingCourse].push_back(needsCompletedAfter);
            //increase number of dependencies of the needsCompletedAfter, since you just found a needsCompletedAfter that this needsCompletedAfter depends on
            numDependencies[needsCompletedAfter]++;
        }

        //start with courses that have no dependency
        for (int i =0; i < numDependencies.size(); i++) {
            if (numDependencies[i]==0) order.push_back(i);
        }

        //loop through courses that can be completed, while decreasing dependency number of each dependent course
        //if dependency number of a dependent course reaches 0, it means that course can be done next
        //since the new course is added to end of the vector (push_back) you can keep iterating on the vector
        for (int i=0 ; i < order.size(); i++) {
            for (int canBeDoneAfter : dependencies[order[i]]) {
                if(--numDependencies[canBeDoneAfter]==0) {
                    order.push_back(canBeDoneAfter);
                }
            }
        }

        //if you cant complete all courses then return -1 to denote a cycle
        if (order.size() != n) {
            return {-1};
        }
        return order;
    }

    bool processCourse(int courseId, vector<int> & courseOrder , vector<vector<int>> & prerequisites, vector<int> & visitingOrder) {
        if (visitingOrder[courseId] == 1) {
            return false;
        }
        if (visitingOrder[courseId] == 2) {
            return true;
        }
        visitingOrder[courseId]=1;
        vector<int> & preReqs = prerequisites[courseId];
        for (int depCourse : preReqs) {
            bool ret = processCourse(depCourse, courseOrder, prerequisites, visitingOrder);
            if (!ret) return ret;
        }
        courseOrder.push_back(courseId);
        visitingOrder[courseId] = 2;
        return true;
    }

    vector<int> course_schedule_dfs(int n, vector<vector<int>> & prerequisites) {
        //unordered_set<int> seen;
        vector<int> courseOrder;
        vector<vector<int>> preReqDepOrder(n);
        vector<int> visitingOrder(n, 0);
        for (vector<int> &  preReqs : prerequisites) {
            int course = preReqs[1];
            int depCourse = preReqs[0];
            preReqDepOrder[course].push_back(depCourse);
        }

        for (int i =0; i < n; i++) {
            if (visitingOrder[i] == 0) {
                bool  ret = processCourse(i, courseOrder, preReqDepOrder, visitingOrder);
                if (!ret) {
                    return {-1};
                }
            }
        }

        reverse(courseOrder.begin(), courseOrder.end());
        return courseOrder;
    }
};

#endif //CPPALGORITHMS_COURSESCHEDULE_H
