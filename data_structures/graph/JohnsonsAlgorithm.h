//
// Created by usman on 10/14/22.
//

#ifndef CPPALGORITHMS_JOHNSONSALGORITHM_H
#define CPPALGORITHMS_JOHNSONSALGORITHM_H
#include <vector>
#include <list>
#include <limits>
#include "DijkstrasShortestPath.h"

using namespace std;

/**
 * See Johnson.md for more details!
 */
class JohnsonsAlgorithm {

    static vector<int> findEdgeWeightsByBellmanFord(int noOfVertices, vector<vector<int>>& edges) {
        noOfVertices++;
        list<pair<int, int>> adj[noOfVertices];
        int max = numeric_limits<int>::max();
        for (auto & edge: edges) {
            adj[edge[1]].emplace_back(edge[0], edge[2]);
        }
        int newVertex = noOfVertices-1;
        for (int i =0; i < newVertex; i++) {
            adj[newVertex].emplace_back(i, 0);
        }
        vector<int> costVector (noOfVertices,  max);
        for (int i =0; i <= noOfVertices; i++) {
            for (int j =0; j < noOfVertices; j++) {
                for (auto &flightCost: adj[j]) {
                    costVector[j] = costVector[flightCost.first] == max ? max : costVector[flightCost.first] + flightCost.second;
                }
            }
        }
        return vector<int> (costVector.begin(), costVector.end()-1);
    }

    static void runJohnsonsAlgo(int noOfVertices, vector<vector<int>>& edges) {
        vector<int> weightAdjustments = findEdgeWeightsByBellmanFord(noOfVertices, edges);
        //adjust weights to make them non-negative
        for (int i =0; i < edges.size(); i++) {
            edges[i][2] += weightAdjustments[edges[i][0]] - weightAdjustments[edges[i][1]];
        }
        //run dijkstra to find all pair shortest path
        DijkstraShortestPath shortestPathCalc(noOfVertices, edges);
        vector<vector<int>> shortestPaths = shortestPathCalc.calculateAllPairShortestPath();
        //+dB -dA
        for (int i=0; i < noOfVertices; i++) {
            for (int j=0; i < noOfVertices; i++) {
                if (i == j) continue;
                shortestPaths[i][j] += weightAdjustments[j] - weightAdjustments[i];
                cout << "Shortest path between vertices " << i << " and vertices " << j << " is " << shortestPaths[i][j] << endl;
            }
        }
    }
};
#endif //CPPALGORITHMS_JOHNSONSALGORITHM_H
