//
// Created by usman on 11/13/21.
//

#ifndef CPPALGORITHMS_CRITICALCONNECTIONS_H
#define CPPALGORITHMS_CRITICALCONNECTIONS_H

#include <vector>
using namespace std;

class CriticalConnections {
public:
    vector<int> nodeParents;
    vector<int> arrivalTimes;
    vector<int> departureTimes;
    vector<int> lowestTimes;
    vector<bool> visited;
    vector<vector<int>> criticalEdges;
    int time=0;

    void criticalDfs(int node, int parent, vector<vector<int>> & edges ) {
        arrivalTimes[node]= lowestTimes[node]=time++;
        visited[node] = true;
        for (int child : edges[node]) {
            if (child != parent) {
                if (!visited[child]) {
                    criticalDfs(child, node, edges);
                }
                //for each child that's not _parent
                //use its lowest time to update the current node's lowest time
                lowestTimes[node] = min(lowestTimes[node], lowestTimes[child]);
            }
        }

        if (parent != -1 && arrivalTimes[node]==lowestTimes[node]) {
            //this is a critical edge since the child nodes dont have a back pointer to _parent nodes
            criticalEdges.push_back({parent, node});
        }
        departureTimes[node]= time++;
    }

    vector<vector<int>> find_critical_connections(int num, vector<vector<int>> connections) {
        //for standard reuse of this pattern keep the below variables around
        nodeParents.resize(num, -1);
        arrivalTimes.resize(num, 0);
        departureTimes.resize(num, 0);
        lowestTimes.resize(num, 0);
        visited.resize(num, false);
        vector<vector<int>> adjacencyList(num);
        for (vector<int> & vec: connections) {
            adjacencyList[vec[0]].push_back(vec[1]);
            adjacencyList[vec[1]].push_back(vec[0]);
        }
        criticalDfs(0, -1, adjacencyList);
        return criticalEdges;
    }
};

#endif //CPPALGORITHMS_CRITICALCONNECTIONS_H
