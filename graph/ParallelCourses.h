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

    static int minimumSemesters(int n, vector<vector<int>>& relations) {
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

    static void testMe() {
        vector<vector<int>> dirs = {{1,2},{2,3},{3,1}};
        int res = minimumSemesters(3, dirs);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_PARALLELCOURSES_H
