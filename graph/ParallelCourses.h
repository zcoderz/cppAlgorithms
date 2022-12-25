//
// Created by usman on 12/24/22.
//

#ifndef CPPALGORITHMS_PARALLELCOURSES_H
#define CPPALGORITHMS_PARALLELCOURSES_H


#include <vector>
#include <unordered_set>
using namespace std;

class ParallelCourses {
public:

    int process(int course, vector<vector<int>>& dependencies, vector<int> & visiting) {
        if (visiting[course] != 0) return visiting[course];
        visiting[course] = -1;
        int depth = 1;

        for (int dep : dependencies[course]) {
            int cDepth = process(dep, dependencies, visiting);
            if (cDepth==-1) return -1;
            depth = max(depth, cDepth+1);
        }

        visiting[course] = depth;
        return depth;
    }

    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>> deps (n+1, vector<int> ());

        for (auto & vec: relations) {
            deps[vec[0]].push_back(vec[1]);
        }

        vector<int> visiting (n+1);
        int res = 0;
        for (int i=1; i <= n; i++) {
            int val = process(i, deps, visiting);
            if (val == -1) return -1;
            res = max(res, val);
        }
        return res;
    }

    int minimumSemestersTopo(int n, vector<vector<int>>& relations) {
        vector<unordered_set<int>> deps (n+1, unordered_set<int> ());
        vector<vector<int>> invertedDep (n+1, vector<int> ());

        for (auto & vec: relations) {
            deps[vec[0]].insert(vec[1]);
            invertedDep[vec[1]].push_back(vec[0]);
        }
        vector<int> leaves;
        for (int i =1; i <= n; i++) {
            if (deps[i].empty()) leaves.push_back(i);
        }
        int coursesTaken = 0;
        int minTime =0;
        while (!leaves.empty()) {
            vector<int> newLeaves;
            for (int leaf : leaves) {
                for (int parent : invertedDep[leaf]) {
                    deps[parent].erase(leaf);
                    if (deps[parent].empty())
                        newLeaves.push_back(parent);
                }
                coursesTaken++;

            }
            minTime++;
            swap(leaves, newLeaves);
        }
        return coursesTaken == n? minTime : -1;
    }
};

#endif //CPPALGORITHMS_PARALLELCOURSES_H
