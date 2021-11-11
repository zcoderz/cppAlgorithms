//
// Created by usman on 11/11/21.
//

#ifndef CPPALGORITHMS_NUMBEROFCONNECTEDCOMPONENTS_H
#define CPPALGORITHMS_NUMBEROFCONNECTEDCOMPONENTS_H
#include "../utils/graph/UnionFind.h"
class NumberOfConnectedComponents {
public:
   vector<pair<int, int>> vertices;

    int find(int vertexId) {
        if (vertices[vertexId].first != vertexId) {
            int parent = find(vertices[vertexId].first);
            vertices[vertexId].first = parent;
        }
        return vertices[vertexId].first;
    }

    void runUnion(int vertexId1, int vertexId2) {
        vertexId1 = find(vertexId1);
        vertexId2 = find(vertexId2);

        if (vertices[vertexId1].second == vertices[vertexId2].second) {
            vertices[vertexId1].second++;
            vertices[vertexId2].first = vertexId1;
        } else if (vertices[vertexId1].second > vertices[vertexId2].second) {
            vertices[vertexId2].first = vertexId1;
        } else {
            vertices[vertexId1].first = vertexId2;
        }
    }

    int number_of_connected_components(int n, vector<vector<int>> & edgesP) {
        vertices.resize(n);
        for (int i =0; i < n; i++) {
            vertices[i] = make_pair(i, 0);
        }
        int numConnectedComponents = n;
        for (vector<int> & edge : edgesP) {
            int p1 = find(edge[0]);
            int p2 = find(edge[1]);
            if (p1 != p2) {
                runUnion(edge[0], edge[1]);
                numConnectedComponents--;
            }
        }
        return numConnectedComponents;
    }


    int number_of_connected_components_using_lib(int n, vector<vector<int>> & edgesP) {
        vector<VertexP> vertices = UnionFind::constructVertices(n);
        vector<EdgeP> edges = UnionFind::constructEdges(edgesP);
        UnionFind::connectVertices(vertices, edges);
        return UnionFind::numConnectedVertices(vertices);
    }
};

#endif //CPPALGORITHMS_NUMBEROFCONNECTEDCOMPONENTS_H
