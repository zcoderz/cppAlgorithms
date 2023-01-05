//
// Created by usman on 12/26/22.
//

#ifndef CPPALGORITHMS_MINSPANNINGCRITICALCONNECTIONS_H
#define CPPALGORITHMS_MINSPANNINGCRITICALCONNECTIONS_H

#include <vector>
#include <algorithm>
#include <climits>
#include <iterator>
#include <iostream>
using namespace std;

class MinSpanningCriticalConnections {
public:
    class MinSpanning {
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

    public:
        int processCost(int n, vector<vector<int>>& edges, int edgeToExclude, int edgeToInclude) {
             initialize(n);
            int cost=0;
            int numConnections=n;
            if (edgeToInclude != -1) {
                runUnion(edges[edgeToInclude][0], edges[edgeToInclude][1]);
                numConnections--;
                cost += edges[edgeToInclude][2];
            }

            for (int i =0; i < edges.size(); i++) {
                if (i==edgeToExclude) continue;
                if (runUnion(edges[i][0], edges[i][1])) {
                    cost += edges[i][2];
                    numConnections--;
                }
            }
            if (numConnections == 1) return cost;
            return INT_MAX;
        }
    };

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for (int i =0; i < edges.size(); i++) {
            edges[i].push_back(i);
        }
        auto comp = []  (vector<int> & a, vector<int> &b) -> bool {return a[2] < b[2];};
        sort(edges.begin(), edges.end(), comp);
        MinSpanning minSpanning;
        int minCost = minSpanning.processCost(n, edges, -1, -1);
        vector<int> criticalEdges;
        vector<int> pseudoCriticalEdges;
        for (int i=0; i < edges.size(); i++) {
            MinSpanning minSpanning2;
            int minCostWithRemove = minSpanning2.processCost(n, edges, i, -1);
            if (minCostWithRemove > minCost) {
                criticalEdges.push_back(edges[i][3]);
            } else {
                MinSpanning minSpanning3;
                int minCostWithForceAdd = minSpanning3.processCost(n, edges, -1, i);
                if (minCost == minCostWithForceAdd)
                    pseudoCriticalEdges.push_back(edges[i][3]);
            }
        }
        return {criticalEdges, pseudoCriticalEdges};
    }

    static void testMe() {
        vector<vector<int>> edges = {{0,1,1},{1,2,1},{0,2,1},{2,3,4},{3,4,2},{3,5,2},{4,5,2}};
        MinSpanningCriticalConnections minTest;
        vector<vector<int>>  res = minTest.findCriticalAndPseudoCriticalEdges(6, edges);
        std::copy(res[0].begin(), res[0].end() , std::ostream_iterator<int>(cout, ", ")); cout << endl;
        std::copy(res[1].begin(), res[1].end() , std::ostream_iterator<int>(cout, ", "));
    }
};

#endif //CPPALGORITHMS_MINSPANNINGCRITICALCONNECTIONS_H
