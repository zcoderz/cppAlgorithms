//
// Created by usman on 10/4/22.
//

#ifndef CPPALGORITHMS_KOSARAJUSTRONGLYCONNECTED_H
#define CPPALGORITHMS_KOSARAJUSTRONGLYCONNECTED_H

#include <vector>
#include <list>

using namespace std;

class KosarajuStronglyConnected {

    vector<list<int>> adjacencyList;
    vector<list<int>> reverseAdjacencyList;

    list<int> departureTimes; //higher first
    vector<int> visited;

    void process(vector<pair<int, int>> & edges, int noVertices) {
        adjacencyList.resize(noVertices);
        reverseAdjacencyList.resize(noVertices);
        departureTimes.resize(noVertices, -1);
        visited.resize(noVertices);

        for (auto & edge : edges) {
            adjacencyList[edge.first].push_back(edge.second);
            reverseAdjacencyList[edge.second].push_back(edge.first);
        }

        //run a dfs on the reversed edge graph. record departure times of nodes visited.
        for (int i =0; i < noVertices; i++) {
            if (!visited[i]) {
                runDfs(reverseAdjacencyList, i);
            }
        }
        fill(visited.begin(), visited.end(), false);
        int strongComponents =0;
        list<int> departureTimesCpy = departureTimes;
        //run dfs on nodes by departure time
        for (int i : departureTimesCpy) {
            if (visited[i]) continue;
            runDfs(adjacencyList, i);
            strongComponents++; //advance components visited in each traversal.
        }
    }

    void runDfs(vector<list<int>> & adjList, int i) {
        visited[i] = true;
        for (int edgeTo : adjList[i]) {
            if (!visited[edgeTo]) {
                runDfs(adjList, edgeTo);
            }
        }
        departureTimes.push_front(i);
    }
};

#endif //CPPALGORITHMS_KOSARAJUSTRONGLYCONNECTED_H
