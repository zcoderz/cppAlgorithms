//
// Created by usman on 12/21/22.
//

#ifndef CPPALGORITHMS_EARLIESTFRIENDS_H
#define CPPALGORITHMS_EARLIESTFRIENDS_H

#include <vector>
#include <algorithm>
using namespace std;

class EarliestFriends {
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

    int earliestAcq(vector<vector<int>>& logs, int n) {
        if (logs.size() < n-1) return -1;
        sort(logs.begin(), logs.end());
        vertices.reserve(n);
        for (int i = 0; i < n; i++) {
            vertices.emplace_back(i, 0);
        }
        int groups = n;
        for (auto & vec: logs) {
            if (runUnion(vec[1], vec[2])) {
                groups--;
            }
            if (groups==1) return vec[0];
        }
        return -1;
    }
};

#endif //CPPALGORITHMS_EARLIESTFRIENDS_H
