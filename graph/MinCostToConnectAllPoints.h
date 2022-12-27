//
// Created by usman on 12/26/22.
//

#ifndef CPPALGORITHMS_MINCOSTTOCONNECTALLPOINTS_H
#define CPPALGORITHMS_MINCOSTTOCONNECTALLPOINTS_H

#include <vector>
#include <cstdlib>
#include <algorithm>
#include <climits>

using namespace std;

class MinCostToConnectAllPoints {
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

    void initialize(int n) {
        vertices.reserve(n);
        for (int i =0; i < n; i++) {
            vertices[i] = {i, 0};
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> edgeCosts;
        int numPoints = points.size();
        for (int i =0; i < points.size(); i++) {
            for (int j = i +1; j < points.size(); j++) {
                int weight = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                edgeCosts.push_back({weight, i , j});
            }
        }
        initialize(numPoints);
        sort(edgeCosts.begin(), edgeCosts.end());
        int cost=0;
        for (int i =0; i < edgeCosts.size(); i++) {
            if (runUnion(edgeCosts[i][1], edgeCosts[i][2])) {
                cost += edgeCosts[i][0];
            }
        }
        return cost;
    }

    int minCostConnectPointsFast(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> inMST(n, 0), minMST(n, INT_MAX);
        int cnt_node = 0, res = 0;
        minMST[0] = 0;
        while (cnt_node < n) {
            int curr_node = -1;
            int min_dist = INT_MAX;
            for (int i = 0; i < n; i++) {
                if (!inMST[i] && minMST[i] < min_dist) {
                    curr_node = i;
                    min_dist = minMST[i];
                }
            }
            res += min_dist;
            cnt_node++;
            inMST[curr_node] = 1;
            for (int i = 0; i < n; i++) {
                if (!inMST[i]) {
                    minMST[i] = min(minMST[i], dist(points[curr_node], points[i]));
                }
            }
        }
        return res;
    }

    int dist(vector<int>& p1, vector<int>& p2) {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }
};
#endif //CPPALGORITHMS_MINCOSTTOCONNECTALLPOINTS_H
