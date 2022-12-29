//
// Created by usman on 12/28/22.
//

#ifndef CPPALGORITHMS_COURSESCHEDULEFOUR_H
#define CPPALGORITHMS_COURSESCHEDULEFOUR_H

#include <vector>

using namespace std;

class CourseScheduleFour {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> dependencies(numCourses, vector<int> (numCourses));
        for (auto &vec: prerequisites) {
            dependencies[vec[1]][vec[0]]=1;
        }
        for (int k=0;k < numCourses; k++) {
            for (int i =0; i < numCourses; i++) {
                for (int j =0; j < numCourses; j++) {
                    dependencies[i][j]= dependencies[i][j] || (dependencies[i][k] && dependencies[k][j]);
                }
            }
        }
        vector<bool> res(queries.size());
        for (int i =0; i < queries.size(); i++) {
            res.push_back(dependencies[queries[i][1]][queries[i][0]]);
        }
        return res;
    }
};

#endif //CPPALGORITHMS_COURSESCHEDULEFOUR_H
