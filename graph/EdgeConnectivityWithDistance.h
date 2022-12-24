//
// Created by usman on 12/23/22.
//

#ifndef CPPALGORITHMS_EDGECONNECTIVITYWITHDISTANCE_H
#define CPPALGORITHMS_EDGECONNECTIVITYWITHDISTANCE_H

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <iterator>
#include <sstream>
using namespace std;

/**
 * A very elegant approach!
 */
class EdgeConnectivityWithDistance {
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

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        initialize(n);
        for (int i =0; i < queries.size(); i++)
            queries[i].push_back(i);
        auto comp = []  (vector<int> & a, vector<int> &b) -> bool {return a[2] < b[2];};
        sort(edgeList.begin(), edgeList.end(), comp);
        sort(queries.begin(), queries.end(), comp);
        int index=0;
        vector<bool> res(queries.size());
        for (int i =0; i < queries.size(); i++) {
            while (index < edgeList.size() && edgeList[index][2] < queries[i][2]) {
                runUnion(edgeList[index][0], edgeList[index][1]);
                index++;
            }
            int r1 = find(queries[i][0]);
            int r2 = find(queries[i][1]);
            res[queries[i].back()] = (r1==r2);
        }
        return res;
    }

    static void testMe() {
        EdgeConnectivityWithDistance edge;
        vector<vector<int>> edges = {{0,1,2},{1,2,4},{2,0,8},{1,0,16}};
        vector<vector<int>> queries = {{0,1,2},{0,2,5}};
        vector<bool> res = edge.distanceLimitedPathsExist(3, edges, queries);
        std::ostringstream oss;
        std::copy(res.begin(), res.end() , std::ostream_iterator<bool> (oss, ", "));
        cout << oss.str();
    }
};
#endif //CPPALGORITHMS_EDGECONNECTIVITYWITHDISTANCE_H
