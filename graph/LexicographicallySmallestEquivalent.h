//
// Created by usman on 12/21/22.
//

#ifndef CPPALGORITHMS_LEXICOGRAPHICALLYSMALLESTEQUIVALENT_H
#define CPPALGORITHMS_LEXICOGRAPHICALLYSMALLESTEQUIVALENT_H

#include <string>
#include <vector>
using namespace std;

class LexicographicallySmallestEquiv {
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

        if (vertexId1 < vertexId2) {
            vertices[vertexId2].first = vertexId1;
        } else {
            vertices[vertexId1].first = vertexId2;
        }

        return true;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vertices.reserve(26);
        for (int i =0; i < 26; i++) {
            vertices.emplace_back(i, 0);
        }
        for (int i =0; i < s1.size(); i++) {
            runUnion(s1[i]-'a', s2[i]-'a');
        }
        string mappedStr;
        for (char ch : baseStr) {
            char mappedCh = 'a' + find(ch-'a') ;
            mappedStr += mappedCh;
        }
        return mappedStr;
    }
};

#endif //CPPALGORITHMS_LEXICOGRAPHICALLYSMALLESTEQUIVALENT_H
