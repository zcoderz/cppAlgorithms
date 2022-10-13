//
// Created by usman on 10/10/22.
//

#ifndef CPPALGORITHMS_PARALLELCOURSES_H
#define CPPALGORITHMS_PARALLELCOURSES_H
#include <vector>
#include <iostream>
using namespace std;

class ParallelCourses {
public:

    static int dfs(int course, vector<bool> & visited, vector<vector<int>> & courseDependencies, vector<int> & courseDepth) {
        if (courseDepth[course] != -1) {
            return courseDepth[course];
        }
        visited[course] = true;
        int maxD = 0;
        for (int depCourse: courseDependencies[course]) {
            if (visited[depCourse]) return -1;
            int val = dfs(depCourse, visited, courseDependencies, courseDepth);
            if (val ==-1) return -1;
            maxD = max(maxD, val);
        }
        maxD++;
        courseDepth[course] = maxD;
        visited[course] = false;
        return maxD;
    }

    static int minimumSemestersThree(int n, vector<vector<int>>& relations) {
        vector<vector<int>> courseDependencies (n+1);
        for (vector<int> & vec: relations) {
            courseDependencies[vec[0]].push_back(vec[1]);
        }
        int maxLevels =0;
        vector<int> courseDepth (n+1, -1);
        vector<bool> visited(n+1);
        for (int i =1; i <=n; i++) {
            int val = dfs(i, visited, courseDependencies, courseDepth);
            if (val == -1) return -1;
            maxLevels = max(maxLevels, val);
        }
        return maxLevels;
    }

    static int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>> courseDependencies (n+1);
        vector<int> indegree(n+1);
        for (vector<int> & relation: relations) {
            courseDependencies[relation[0]].push_back(relation[1]);
            indegree[relation[1]]++;
        }
        queue<int> courseQueue;
        int cnt = 0;
        vector<int> totalTimePerCourse (n+1, -1);
        for (int i =1; i <= n; i++) {
            if (indegree[i] ==0) {
                courseQueue.push(i);
                totalTimePerCourse[i] = 1;
                cnt++;
            }
        }
        while (!courseQueue.empty()) {
            int course = courseQueue.front(); courseQueue.pop();
            for (int depCourse : courseDependencies[course]) {
                totalTimePerCourse[depCourse] = max(totalTimePerCourse[depCourse], 1 + totalTimePerCourse[course]);
                if (--indegree[depCourse]==0) {courseQueue.push(depCourse); cnt++;}
            }
        }
        if (cnt != n) return -1;
        return *max_element(totalTimePerCourse.begin(), totalTimePerCourse.end());
    }

    int minimumSemestersTwo(int n, vector<vector<int>>& relations) {
        vector<vector<int>> courseDependencies (n+1);

        vector<int> indegree(n+1);
        for (vector<int> & relation: relations) {
            courseDependencies[relation[0]].push_back(relation[1]);
            indegree[relation[1]]++;
        }
        queue<int> courseQueue;
        vector<int> totalTimePerCourse (n+1, -1);
        for (int i =1; i <= n; i++) {
            if (indegree[i] ==0) {
                courseQueue.push(i);
                totalTimePerCourse[i] = 1;
            }
        }
        vector<bool> visited (n+1);
        while (!courseQueue.empty()) {
            int course = courseQueue.front(); courseQueue.pop();
            visited[course] = true;
            for (int depCourse : courseDependencies[course]) {
                totalTimePerCourse[depCourse] = max(totalTimePerCourse[depCourse], 1 + totalTimePerCourse[course]);
                if (--indegree[depCourse]==0) courseQueue.push(depCourse);
            }
        }
        int vCount = count(visited.begin(), visited.end(), true);
        if (vCount != n) return -1;
        return *max_element(totalTimePerCourse.begin(), totalTimePerCourse.end());
    }

    static void testMe() {
        vector<vector<int>> dirs = {{1,2},{2,3},{3,1}};
        int res = minimumSemesters(3, dirs);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_PARALLELCOURSES_H
