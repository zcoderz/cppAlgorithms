//
// Created by usman on 12/20/22.
//

#ifndef CPPALGORITHMS_REDUNDANTCONNECTION_H
#define CPPALGORITHMS_REDUNDANTCONNECTION_H

#include <vector>

using namespace std;

/**
 * 684. Redundant Connection
 */
class RedundantConnection {
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

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //the edges are labeled 1 to n. there is one extra edge. hence number of edges equals number of vertices
        //add 1 to sz compensate for the 0th vertex, since in examples the vertices begin from 1.
        int sz = edges.size();
        vertices.reserve(sz+1);
        for (int i=0; i <= sz; i++) {
            vertices.emplace_back(i, 0);
        }
        for (auto & vec: edges) {
            if (!runUnion(vec[0], vec[1]))
                return vec;
        }
        return {0,0};
    }
};

#endif //CPPALGORITHMS_REDUNDANTCONNECTION_H
