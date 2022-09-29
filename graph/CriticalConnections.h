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
    vector<int> visited;
    vector<vector<int>> criticalEdges;
    int time=0;

    int criticalDfs(int nodeId, vector<vector<int>> & adjacencyList) {
        lowestTimes[nodeId] = arrivalTimes[nodeId]= ++time;
        visited[nodeId]=1;
        for (int child: adjacencyList[nodeId]) {
            if (visited[child] == -1) {
                nodeParents[child] = nodeId;
                //update the lowest time based on the lowest time from the child
                lowestTimes[nodeId] = min(lowestTimes[nodeId], criticalDfs(child, adjacencyList));
            } else if (child != nodeParents[nodeId]) {
                //for each child that's not _parent and had already been visited,
                //use its lowest time to set the current node's lowest time
                lowestTimes[nodeId] = min(lowestTimes[nodeId], lowestTimes[child]);
            }
        }
        //root node can't be a critical connection since it doesn't have any _parent and hence excluding the _parent
        //"0" node.
        if (lowestTimes[nodeId] == arrivalTimes[nodeId] && nodeId !=0) {
            //this is a critical edge since the child nodes dont have a back pointer to _parent nodes
            criticalEdges.push_back({nodeParents[nodeId], nodeId});
        }
        departureTimes[nodeId]= ++time;
        //the function needs to send the lowest time for it and its children back to _parent (caller)
        return lowestTimes[nodeId];
    }

    vector<vector<int>> find_critical_connections(int num, vector<vector<int>> connections) {
        //for standard reuse of this pattern keep the below variables around
        nodeParents.resize(num, -1);
        arrivalTimes.resize(num, 0);
        departureTimes.resize(num, 0);
        lowestTimes.resize(num, 0);
        visited.resize(num, -1);
        vector<vector<int>> adjacencyList(num);
        for (vector<int> & vec: connections) {
            adjacencyList[vec[0]].push_back(vec[1]);
            adjacencyList[vec[1]].push_back(vec[0]);
        }
        criticalDfs(0, adjacencyList);
        return criticalEdges;
    }
};

#endif //CPPALGORITHMS_CRITICALCONNECTIONS_H
