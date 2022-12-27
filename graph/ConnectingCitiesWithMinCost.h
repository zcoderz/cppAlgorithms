//
// Created by usman on 12/26/22.
//

#ifndef CPPALGORITHMS_CONNECTINGCITIESWITHMINCOST_H
#define CPPALGORITHMS_CONNECTINGCITIESWITHMINCOST_H

#include <vector>
#include <algorithm>

using namespace std;

class ConnectingCitiesWithMinCost {
public:
    vector<pair<int, int>> vertices;

    int find(int vertexId) {
        if (vertices[vertexId].first != vertexId) {
            int parent = find(vertices[vertexId].first);
            vertices[vertexId].first = parent;
        }
        return vertices[vertexId].first;
    }

    bool runUnion(int vertexId1, int vertexId2) {
        vertexId1 = find(vertexId1);
        vertexId2 = find(vertexId2);
        if (vertexId1 == vertexId2) return false;
        if (vertices[vertexId1].second == vertices[vertexId2].second) {
            vertices[vertexId1].second++;
            vertices[vertexId2].first = vertexId1;
        } else if (vertices[vertexId1].second > vertices[vertexId2].second) {
            vertices[vertexId2].first = vertexId1;
        } else {
            vertices[vertexId1].first = vertexId2;
        }
        return true;
    }

    void initialize(int n) {
        vertices.reserve(n);
        for (int i =0; i < n; i++) {
            vertices[i] = {i, 0};
        }
    }

    int minimumCost(int n, vector<vector<int>>& connections) {
        auto comp = []  (vector<int> & a, vector<int> &b) -> bool {return a[2] < b[2];};
        sort(connections.begin(), connections.end(), comp);
        initialize(n+1);
        int numConnections=0;
        int cost = 0;
        for (auto & vec: connections) {
            if (runUnion(vec[0], vec[1])) {
                numConnections++;
                cost += vec[2];
            }
        }
        //cout << numConnections << endl;
        if (numConnections == n-1) {
            return cost;
        }
        return -1;
    }
};

#endif //CPPALGORITHMS_CONNECTINGCITIESWITHMINCOST_H
