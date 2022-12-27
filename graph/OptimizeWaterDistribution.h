//
// Created by usman on 12/26/22.
//

#ifndef CPPALGORITHMS_OPTIMIZEWATERDISTRIBUTION_H
#define CPPALGORITHMS_OPTIMIZEWATERDISTRIBUTION_H

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class OptimizeWaterDistribution {
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

    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        for (int i =0; i < wells.size(); i++) {
            pipes.push_back({n+1, i+1, wells[i]});
        }
        auto comp = [] (vector<int> & left, vector<int> & right) -> bool {return left[2] < right[2];};
        sort(pipes.begin(), pipes.end(), comp);
        initialize(n+2);
        int cost = 0;
        for (int i=0; i < pipes.size(); i++) {
            if (runUnion(pipes[i][0], pipes[i][1])) {
                cost += pipes[i][2];
            }
        }
        return cost;
    }

    static void testMe() {
        vector<vector<int>> pipes = {{1,2,1},{2,3,1}};
        vector<int> wells = {1,2,2};
        OptimizeWaterDistribution opt;
        int res = opt.minCostToSupplyWater(3, wells, pipes);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_OPTIMIZEWATERDISTRIBUTION_H
