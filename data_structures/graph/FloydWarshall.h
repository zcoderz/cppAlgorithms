//
// Created by usman on 12/28/22.
//

#ifndef CPPALGORITHMS_FLOYDWARSHALL_H
#define CPPALGORITHMS_FLOYDWARSHALL_H

#include <vector>
#include <climits>

using namespace std;

class FloydWarshall {
    void calculateAllPairShortestPaths(int n, vector<vector<int>> & edges, int distanceThreshold) {
        //Floyd Warshall Algo
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX)); //initial weights are infinity
        //1. set self connection weights to 0
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }
        //2. set direct edge weights
        for (int i = 0; i < edges.size(); i++) {
            dist[edges[i][0]][edges[i][1]] = dist[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        //k is the intermediate node that can be used as an intermediate hop while going between i and j
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
};

#endif //CPPALGORITHMS_FLOYDWARSHALL_H
