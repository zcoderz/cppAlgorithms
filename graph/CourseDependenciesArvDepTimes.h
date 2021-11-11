//
// Created by usman on 11/11/21.
//

#ifndef CPPALGORITHMS_COURSEDEPENDENCIESARVDEPTIMES_H
#define CPPALGORITHMS_COURSEDEPENDENCIESARVDEPTIMES_H

class CourseDependenciesArvDepTimes {
public:
    vector<int> arrivalTime;
    vector<int> departureTime;
    vector<vector<int>> dependencies;
    vector<int> visited;

    int time=0;
    bool dfs(int nodeId) {
        visited[nodeId]=1;
        arrivalTime[nodeId] = ++time;
        vector<int> & deps = dependencies[nodeId];
        for (int dep : deps) {
            if (!visited[dep]) {
                bool  ret = dfs(dep);
                if (!ret) return ret;
            } else if (departureTime[dep]==0) {
                return false;
            }
        }
        departureTime[nodeId] = ++time;
        return true;
    }

    bool can_be_completed(int n, vector<int> & a, vector<int> & b) {
        arrivalTime.resize(n, 0);
        departureTime.resize(n, 0);
        visited.resize(n, 0);
        dependencies.resize(n);
        for (int i =0; i < a.size(); i++) {
            dependencies[b[i]].push_back(a[i]); //course b, depends on course a
        }
        for (int i=0; i < n; i++) {
            if (!visited[i]) {
                bool cycle = !dfs(i);
                if (cycle) return false;
            }
        }
        return true;
    }

};

#endif //CPPALGORITHMS_COURSEDEPENDENCIESARVDEPTIMES_H
