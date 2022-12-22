//
// Created by usman on 12/22/22.
//

#ifndef CPPALGORITHMS_NUMBERISLANDSTWO_H
#define CPPALGORITHMS_NUMBERISLANDSTWO_H

#include <vector>

using namespace std;

class NumberIslandsTwo {
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

    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vertices.reserve(m*n);
        for (int i =0; i < m*n; i++) {
            vertices.emplace_back(-1, 0);
        }
        int cnt = 0;
        vector<int> counts;
        vector<vector<int>> moves = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for (auto & vec: positions) {
            int i = vec[0], j = vec[1];
            int index = i*n+j;
            if (vertices[index].first == -1) {
                vertices[index] = {index, 0}; cnt++; //increase count whenever a new island is created
            }
            for (auto & move : moves) {
                int nR = i + move[0];
                int nC = j + move[1];
                if (nR < 0 | nC < 0 | nR >= m || nC >= n) continue;
                int newIndex = nR*n+nC;
                if (vertices[newIndex].first != -1) {
                    if (runUnion(index, newIndex))
                        cnt--; //whenever two unconnected components are merged, the count decreases
                }
            }
            counts.push_back(cnt);
        }
        return counts;
    }
};

#endif //CPPALGORITHMS_NUMBERISLANDSTWO_H
