//
// Created by usman on 12/20/22.
//

#ifndef CPPALGORITHMS_REDUNDANTDIRECTEDCONNECTION_H
#define CPPALGORITHMS_REDUNDANTDIRECTEDCONNECTION_H

#include <vector>
#include <unordered_map>
using namespace std;

/**
 * Very tricky question: https://leetcode.com/problems/redundant-connection-ii
 * here is a good explanation :
 * https://leetcode.com/problems/redundant-connection-ii/solutions/254733/python-union-find-clear-logic/
 *
 */
class RedundantDirectedConnection {
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

    /**
     * Here is the reason why cand2 is ignored in the union find process. When it is ignored, if a cycle is
     * detected in the union find process, we know the cycle has nothing to do with cand2.
     * Therefore, the answer must be cand1 if cand1 exists, or the edge incuring the cycle if cand1 does not exist.
     * If no cycle is detected, then either cand1 or cand2 is the bad edge.
     * But since cand2 appears later than cand1 in the list, we should return cand2.
     *
     * @param edges
     * @return
     */
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        unordered_map<int, int> parentMap;
        vector<int> cand1, cand2;
        int sz = edges.size();
        vertices.reserve(sz+1);
        for (int i=0; i <= sz; i++) {
            vertices.emplace_back(i, 0);
        }
        for (auto & vec: edges) {
            if (parentMap.find(vec[1]) != parentMap.end()) {
                //when a node has more than one parent, record the edges
                cand1 = {parentMap[vec[1]], vec[1]};
                cand2 = {vec[0], vec[1]};
                break;
            }
            parentMap[vec[1]] = vec[0];
        }
        for (auto & vec: edges) {
            //skip candidate 2 entirely
            if (!cand2.empty() && vec[0] == cand2[0] && vec[1] == cand2[1]) continue;
            if (!runUnion(vec[0], vec[1])) {
                //if cand1 doesnt exist, return the edge that caused the cycle
                if (cand1.empty()) return vec;
                //if a cycle is found and cand1 exists, return it since it must have caused the cycle
                return cand1;
            }
        }
        //if a cycle isnt found, return cand2 since it occurs later
        return cand2;
    }
};

#endif //CPPALGORITHMS_REDUNDANTDIRECTEDCONNECTION_H
