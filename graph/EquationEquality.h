//
// Created by usman on 12/21/22.
//

#ifndef CPPALGORITHMS_EQUATIONEQUALITY_H
#define CPPALGORITHMS_EQUATIONEQUALITY_H

#include <vector>
#include <string>
using namespace std;

class EquationEquality {
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

    bool equationsPossible(vector<string>& equations) {
        vertices.reserve(26);
        for (int i =0; i < 26; i++) {
            vertices.emplace_back(i, 0);
        }
        for (string & eq : equations) {
            if (eq[1] == '=') {
                runUnion(eq[0]-'a', eq[3]-'a');
            }
        }
        for (string & eq : equations) {
            if (eq[1] == '!') {
                int v1 = find(eq[0]-'a');
                int v2 = find(eq[3]-'a');
                if (v1==v2) return false;
            }
        }
        return true;
    }
};

#endif //CPPALGORITHMS_EQUATIONEQUALITY_H
