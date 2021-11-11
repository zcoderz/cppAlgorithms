//
// Created by USMAN QADIR on 11/11/21.
//

#ifndef CPPALGORITHMS_COURSEDEPENDENCIESTOPOSORT_H
#define CPPALGORITHMS_COURSEDEPENDENCIESTOPOSORT_H

#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;
class CourseDependenciesTopoSort {
public:
    //unordered_map<int, unordered_set<int>> courseDependencies;
    //unordered_map<int, unordered_set<int>> inverseDependencies;
    vector<int> leftDependencies;
    vector<vector<int>> courseDependencies;

    bool can_be_completed(int n, vector<int> a, vector<int> b) {
        leftDependencies.resize(n); std::fill(leftDependencies.begin(), leftDependencies.end(), 0);
        courseDependencies.resize(n);
        for (int i =0; i < a.size(); i++) {
            leftDependencies[b[i]]++;
            courseDependencies[a[i]].push_back(b[i]);
        }
        int num=n;
        queue<int> courseQueue;
        for (int i =0; i < n; i++) {
            if(leftDependencies[i] ==0) courseQueue.push(i);
        }
        while (!courseQueue.empty()) {
            num--;
            int course = courseQueue.front();
            courseQueue.pop();
            vector<int> & vec = courseDependencies[course];
            for (int cDep: vec) {
                leftDependencies[cDep]--;
                if (leftDependencies[cDep] ==0) courseQueue.push(cDep);
            }
        }
        return num==0;
    }
};
#endif //CPPALGORITHMS_COURSEDEPENDENCIESTOPOSORT_H
