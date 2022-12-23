//
// Created by usman on 12/22/22.
//

#ifndef CPPALGORITHMS_GRAPHCONNECTIVITYWITHTHRESHOLD_H
#define CPPALGORITHMS_GRAPHCONNECTIVITYWITHTHRESHOLD_H

#include <vector>
using namespace std;

class GraphConnectivity {
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

    void initialize(int sz) {
        vertices.reserve(sz);
        for (int i =0; i < sz; i++) {
            vertices.emplace_back(i, 0);
        }
    }

    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        initialize(n+1);
        int divisor = threshold+1;
        for (int i =divisor; i <= n/2; i++) {
            int m = 2;
            while (i*m <=n) {
                runUnion(i, i*m);
                m++;
            }
        }
        vector<bool> res;
        for (auto & query : queries) {
            int r1 = find(query[0]);
            int r2 = find(query[1]);
            res.push_back(r1==r2);
        }
        return res;
    }

};

#endif //CPPALGORITHMS_GRAPHCONNECTIVITYWITHTHRESHOLD_H
