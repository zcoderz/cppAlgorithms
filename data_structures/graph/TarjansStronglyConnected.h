//
// Created by usman on 10/5/22.
//

#ifndef CPPALGORITHMS_TARJANSSTRONGLYCONNECTED_H
#define CPPALGORITHMS_TARJANSSTRONGLYCONNECTED_H
#include <vector>
#include <list>
#include <stack>

using namespace std;
class StronglyConnected {

    vector<list<int>> adjacencyList;
    vector<int> arrivalTimes;
    vector<int> lowestArrivalTime;
    stack<int>  vertexStack;
    vector<bool> vertexOnStack;
    vector<int> vertexComponentIds;
    int numberOfStronglyConnectedComponents;
    int time = 0;

    void runDfs(int vertexId) {
        arrivalTimes[vertexId] = lowestArrivalTime[vertexId] = time++;
        vertexStack.push(vertexId);
        vertexOnStack[vertexId] = true;

        for (int edgeTo : adjacencyList[vertexId]) {
            if (arrivalTimes[edgeTo] == -1) {
                //vertex is not yet visited
                runDfs(edgeTo);
                //it is possible that the edgeTo vertex is in same strongly connected component
                //i.e. has a back edge to an ancestor vertex in same strongly connected component
                // --> then lowest arrival time of the edge will be less than current node's lowest arrival time
                //also possible that the edge belongs to a different strongly connected component.
                // --> then lowest arrival time of the node will be higher than current node's lowest arrival time
                lowestArrivalTime[vertexId] = min(lowestArrivalTime[edgeTo], lowestArrivalTime[vertexId]);
            } else if (vertexOnStack[edgeTo]) {
                //vertex is currently being visited in same call stack
                //the current edge must be a back edge
                lowestArrivalTime[vertexId] = arrivalTimes[edgeTo];
            } //else this edge must be to a vertex in a different strongly connected component
        }

        if (lowestArrivalTime[vertexId] == arrivalTimes[vertexId]) {
            //this vertex must be the root of a new strongly connected component
            while (vertexStack.top() != vertexId) {
                vertexComponentIds[vertexStack.top()] = numberOfStronglyConnectedComponents;
                vertexOnStack[vertexId] = false;
                vertexStack.pop();
            }
            vertexComponentIds[vertexId] = numberOfStronglyConnectedComponents;
            numberOfStronglyConnectedComponents++;
        }
        vertexStack.pop();
        vertexOnStack[vertexId] = false;
    }

    void process(vector<pair<int, int>> & edges, int noVertices) {
        adjacencyList.resize(noVertices);
        lowestArrivalTime.resize(noVertices, -1);
        arrivalTimes.resize(noVertices, -1);
        vertexOnStack.resize(noVertices);

        for (auto &edge: edges) {
            adjacencyList[edge.first].push_back(edge.second);
        }

        for (int i =0; i < noVertices; i++) {
            if (arrivalTimes[i] == -1) runDfs(i);
        }
    }
};

#endif //CPPALGORITHMS_TARJANSSTRONGLYCONNECTED_H
