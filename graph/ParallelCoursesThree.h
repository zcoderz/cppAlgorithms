//
// Created by usman on 10/12/22.
//

#ifndef CPPALGORITHMS_PARALLELCOURSESTHREE_H
#define CPPALGORITHMS_PARALLELCOURSESTHREE_H

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class ParallelCoursesThree {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> courseDependencies (n+1);
        vector<int> indegree(n+1);
        for (vector<int> & relation: relations) {
            courseDependencies[relation[0]].push_back(relation[1]);
            indegree[relation[1]]++;
        }
        queue<int> courseQueue;
        vector<int> totalTimePerCourse (n+1);
        for (int i =1; i <= n; i++) {
            if (indegree[i] ==0) {
                courseQueue.push(i);
                totalTimePerCourse[i] = time[i-1];
            }
        }

        while (!courseQueue.empty()) {
            int course = courseQueue.front(); courseQueue.pop();
            for (int depCourse : courseDependencies[course]) {
                totalTimePerCourse[depCourse] = max(totalTimePerCourse[depCourse], time[depCourse-1] + totalTimePerCourse[course]);
                if (--indegree[depCourse]==0) courseQueue.push(depCourse);
            }
        }
        return *max_element(totalTimePerCourse.begin(), totalTimePerCourse.end());
    }
};

#endif //CPPALGORITHMS_PARALLELCOURSESTHREE_H
