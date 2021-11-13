//
// Created by usman on 11/13/21.
//

#ifndef CPPALGORITHMS_CRITICALCONNECTIONS_H
#define CPPALGORITHMS_CRITICALCONNECTIONS_H

#include <vector>
using namespace std;

class CriticalConnections {
public:
    vector<vector<int>> find_critical_connections(int number_of_servers, vector<vector<int>> connections) {
        vector<vector<int>> vertexConnections(number_of_servers);
        for (vector<int> & vec : connections) {
            int src = vec[0];
            int dest = vec[1];
            vertexConnections[src].push_back(dest);
            vertexConnections[dest].push_back(src);
        }

        vector<vector<int>> res;
        for (int i =0; i < number_of_servers; i++) {
            vector<int> & vec = vertexConnections[i];
            if (vec.size() == 1) {
                res.push_back({i, vec[0]});
            }
        }

        if (res.empty()) {
            return {{-1,-1}};
        }
        return res;
    }
};

#endif //CPPALGORITHMS_CRITICALCONNECTIONS_H
