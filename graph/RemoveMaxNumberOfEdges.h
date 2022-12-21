//
// Created by usman on 12/21/22.
//

#ifndef CPPALGORITHMS_REMOVEMAXNUMBEROFEDGES_H
#define CPPALGORITHMS_REMOVEMAXNUMBEROFEDGES_H
#include <vector>
using namespace std;

class RemoveMaxNumberOfEdges {
    vector<pair<int, int>> verticesA;
    vector<pair<int, int>> verticesB;

    int find(int vertexId, vector<pair<int, int>> & vertices) {
        if (vertices[vertexId].first != vertexId) {
            int parent = find(vertices[vertexId].first, vertices);
            vertices[vertexId].first = parent;
        }
        return vertices[vertexId].first;
    }

    bool runUnion(int vertexId1, int vertexId2, vector<pair<int, int>> & vertices) {
        vertexId1 = find(vertexId1, vertices);
        vertexId2 = find(vertexId2, vertices);
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

    int numComponents (vector<pair<int, int>> & vertices) {
        int parents = 0; int priorParent=-1;
        for (int i =1; i < vertices.size(); i++) {
            int parent = find(i, vertices);
            if (parent != priorParent) {
                priorParent = vertices[i].first;
                parents++;
            }
        }
        return parents;
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        verticesA.reserve(n+1);
        for (int i =0; i <= n; i++ ) {
            verticesA.emplace_back(i, 0);
        }
        int removable = 0;
        for (auto & vec: edges) {
            if (vec[0] !=3) continue;
            if (!runUnion(vec[1], vec[2], verticesA)) {
                removable++;
            }
        }
        verticesB = verticesA;
        for (auto & vec: edges) {
            if ( vec[0] ==1  && !runUnion(vec[1], vec[2], verticesA)) {
                removable++;
            }
            if ( vec[0] ==2  && !runUnion(vec[1], vec[2], verticesB)) {
                removable++;
            }
        }
        if (numComponents(verticesA) > 1 || numComponents(verticesB) > 1) return -1;
        return removable;
    }
};

#endif //CPPALGORITHMS_REMOVEMAXNUMBEROFEDGES_H
