//
// Created by usman on 9/29/22.
//

#ifndef CPPALGORITHMS_CHEAPESTFLIGHTSWITHKSTOPS_H
#define CPPALGORITHMS_CHEAPESTFLIGHTSWITHKSTOPS_H

#include <vector>
#include <queue>
#include <limits>
#include <tuple>
#include <list>
#include <iostream>

using namespace std;

class CheapestFlightsWithinKStops {
public:
    static int findCheapestPriceDijkstra(int noOfVertices, vector<vector<int>>& flights, int src, int dst, int k) {
        list<pair<int, int>> adj[noOfVertices];
        for (auto & flight: flights) {
            adj[flight[0]].emplace_back(flight[1], flight[2]);
        }
        using ITuple = tuple<int,int, int>;
        priority_queue<ITuple, vector<ITuple>, greater<>> pq;

        // Create a vector for keys and initialize all
        // weights as infinite (INF)
        vector<int> vertexCurrentWeights(noOfVertices, std::numeric_limits<int>::max());

        // Insert source itself in priority queue and initialize
        // its vertexCurrentWeights as 0.
        pq.push(make_tuple(0, 0, src));
        vertexCurrentWeights[src] = 0;

        /* Looping till priority queue becomes empty */
        while (!pq.empty()) {
            auto [stops, flightWeight, city] =  pq.top();
            pq.pop();

            if (stops > k) {
                break;
            }
            for (auto & flightPair: adj[city]) {
                int dest = flightPair.first;
                int currWeight = flightPair.second;
                int pathVertexWeight = currWeight + flightWeight;
                //  If v is not in MST and flightWeight of (currentVertex,v) is smaller
                // than current vertexCurrentWeights of v
                if (vertexCurrentWeights[dest] > pathVertexWeight) {
                    // Updating vertexCurrentWeights of v
                    vertexCurrentWeights[dest] = pathVertexWeight;
                    pq.push(make_tuple(stops + 1, pathVertexWeight, dest));

                }
            }
        }
        return vertexCurrentWeights[dst] == numeric_limits<int>::max() ? -1 : vertexCurrentWeights[dst];
    }

    static int findCheapestPriceBellmanFordReducedMemory(int noOfVertices, vector<vector<int>>& flights, int src, int dst, int k) {
        list<pair<int, int>> adj[noOfVertices];
        int max = numeric_limits<int>::max();
        for (auto & flight: flights) {
            adj[flight[1]].emplace_back(flight[0], flight[2]);
        }
        vector<pair<int, int>> costVector (noOfVertices, make_pair(0, max));
        costVector[src] = make_pair(0, 0);
        for (int i =0; i <= k; i++) {
            for (int j =0; j < noOfVertices; j++) {
                for (auto &flightCost: adj[j]) {
                    //each of K is a flight. so K stops means that there can be K+1 flights
                    int currStops = costVector[flightCost.first].first;
                    if (currStops== k+1 || currStops ==i+1) continue;
                    int newCost = costVector[flightCost.first].second == max ? max : costVector[flightCost.first].second + flightCost.second;
                    int stops = costVector[flightCost.first].first + 1;
                    costVector[j] = make_pair(stops, newCost);
                }
            }
        }

        return costVector[dst].second == max ? -1 : costVector[dst].second;
    }

    static int findCheapestPriceBellmanFord(int noOfVertices, vector<vector<int>>& flights, int src, int dst, int k) {
        list<pair<int, int>> adj[noOfVertices];
        int max = numeric_limits<int>::max();
        for (auto & flight: flights) {
            adj[flight[1]].emplace_back(flight[0], flight[2]);
        }
        vector<vector<int>> costVector  (2, vector<int>(noOfVertices, max));
        costVector[0][src] = costVector[1][src] = 0;
        for (int i =0; i <= k; i++) {
            int currIndex = i%2;
            int otherIndex = (i+1)%2;
            costVector[currIndex] = costVector[otherIndex]; //copy previous to current
            for (int j =0; j < noOfVertices; j++) {
                for (auto &flightCost: adj[j]) {
                    int possibleCost = costVector[otherIndex][flightCost.first] == max ? max : costVector[otherIndex][flightCost.first] + flightCost.second;
                    costVector[currIndex][j] = min(costVector[currIndex][j], possibleCost);
                }
            }
        }
        int currIndex = k % 2;
        return costVector[currIndex][dst] == max ? -1 : costVector[currIndex][dst];
    }

    static void testFlights() {
        vector<vector<int>> flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
        int cost = findCheapestPriceDijkstra(4, flights, 0, 3, 1);
        cout << "DK" << cost << endl;

        cost = findCheapestPriceBellmanFord(4, flights, 0, 3, 1);
        cout << "BF" << cost << endl;

        flights = {{0,1,100},{1,2,100},{0,2,500}};
        cost = findCheapestPriceDijkstra(3, flights, 0, 2, 1);
        cout << "DK" << cost << endl;
        cost = findCheapestPriceBellmanFord(3, flights, 0, 2, 1);
        cout << "BF" << cost << endl;

        flights = {{0,1,1},{0,2,5},{1,2,1},{2,3,1}};
        cost = findCheapestPriceBellmanFordReducedMemory(4, flights, 0, 3, 1);
        cout << "BF" << cost << endl;
    }
};

#endif //CPPALGORITHMS_CHEAPESTFLIGHTSWITHKSTOPS_H
