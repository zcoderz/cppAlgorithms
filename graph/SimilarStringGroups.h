//
// Created by usman on 12/22/22.
//

#ifndef CPPALGORITHMS_SIMILARSTRINGGROUPS_H
#define CPPALGORITHMS_SIMILARSTRINGGROUPS_H

#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class SimilarStringGroups {
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

    bool checkSimilar(string & first, string & second) {
        int diff = 0;
        for (int i =0; i < first.size(); i++) {
            if (first[i] != second[i]) diff++;
            if (diff > 2) return false;
        }
        return true;
    }

    int numSimilarGroups(vector<string>& strs) {
        for (int i =0; i < strs.size(); i++) {
            vertices.emplace_back(i, 0);
        }
        int sz = strs.size();
        for (int i =0; i < strs.size(); i++) {
            for (int j =0; j < strs.size(); j++) {
                if (checkSimilar(strs[i], strs[j])) {
                    if (runUnion(i, j))
                        sz--;
                }
            }
        }
        return sz;
//        unordered_set<int> parents;
//        for (auto & vertex: vertices) {
//            parents.insert(find(vertex.first));
//        }
//        return parents.size();
    }
};

#endif //CPPALGORITHMS_SIMILARSTRINGGROUPS_H
