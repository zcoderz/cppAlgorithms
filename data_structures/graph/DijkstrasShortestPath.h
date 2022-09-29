//
// Created by usman on 9/29/22.
//

#ifndef CPPALGORITHMS_DIJKSTRASSHORTESTPATH_H
#define CPPALGORITHMS_DIJKSTRASSHORTESTPATH_H
//
// Created by usman on 9/28/22.
//


#include <vector>
#include <list>
#include <queue>
#include <limits>
#include <iostream>

using namespace std;

typedef pair<int, int> IPair;

// This class represents a directed graph using
// adjacency list representation
class DijkstraShortestPath {
    int noOfVertices;    // No. of vertices

    // In a weighted graph, we need to store vertex
    // and weight pair for every edge
    list< pair<int, int> > *adj;


public:
    DijkstraShortestPath(int noOfVertices_) {
        noOfVertices = noOfVertices_;
        adj = new list<IPair> [noOfVertices_];
    }

    ~DijkstraShortestPath() {
        delete [] adj;
    }

    // function to add an edge to graph
    void addEdge(int u, int v, int w) {
        //if its a directed graph then the direction needs to be singular
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }


    // Print MST using Prim's algorithm
    // Prints shortest paths from src to all other vertices
    void shortestPath(int sourceVertex, int targetVertex) {
        auto comp = [] (pair<int, int> &a, pair<int, int> &b) -> bool { return a.second > b.second; };
        priority_queue<IPair, vector<IPair>, decltype(comp)> pq;

        // Create a vector for keys and initialize all
        // weights as infinite (INF)
        vector<int> vertexCurrentWeights(noOfVertices, std::numeric_limits<int>::max());

        // To store parent array which in turn store MST
        vector<int> parent(noOfVertices, -1);

        // To keep track of vertices searched so far
        vector<bool> searchedSoFar(noOfVertices, false);

        int src = sourceVertex;

        // Insert source itself in priority queue and initialize
        // its vertexCurrentWeights as 0.
        pq.push(make_pair(src, 0));
        vertexCurrentWeights[src] = 0;
        int pathWeight = -1;
        /* Looping till priority queue becomes empty */
        while (!pq.empty()) {
            // The first vertex in pair is the minimum vertexCurrentWeights
            // vertex, extract it from priority queue.
            // vertex label is stored in second of pair (it
            // has to be done this way to keep the vertices
            // sorted vertexCurrentWeights (vertexCurrentWeights must be first item
            // in pair)
            int currentVertex = pq.top().first;
            int currentVertexWeight = pq.top().second;
            if (currentVertex == targetVertex) {
                pathWeight = currentVertexWeight;
                break;
            }
            pq.pop();

            //Different vertexCurrentWeights values for same vertex may exist in the priority queue.
            //The one with the least vertexCurrentWeights value is always processed first.
            //Therefore, ignore the rest.
            if (searchedSoFar[currentVertex]) {
                continue;
            }

            searchedSoFar[currentVertex] = true;  // Include vertex in MST

            for (auto & vertexNeighborPair: adj[currentVertex]) {
                // Get vertex label and weight of current adjacent
                // of currentVertex.
                int vertex = vertexNeighborPair.first;
                int weight = vertexNeighborPair.second;

                int pathVertexWeight = weight + currentVertexWeight;

                //  If v is not in MST and weight of (currentVertex,v) is smaller
                // than current vertexCurrentWeights of v
                if (!searchedSoFar[vertex] && vertexCurrentWeights[vertex] > pathVertexWeight) {
                    // Updating vertexCurrentWeights of v
                    vertexCurrentWeights[vertex] = pathVertexWeight;
                    pq.push(make_pair(vertex, vertexCurrentWeights[vertex]));
                    parent[vertex] = currentVertex;
                }
            }
        }

        // Print edges of MST using parent array
        for (int i = targetVertex; i != sourceVertex ; ) {
            cout << "vertex " << i << " has parent " << parent[i] << endl;
            i = parent[i];
        }

        cout << "total path weight = " << pathWeight << endl;
    }

    static void testDijkstrasShortestPathAlgo() {
        // create the graph given in above figure
        int noOfVertices = 9;
        DijkstraShortestPath g(noOfVertices);
        //  making above shown graph
        g.addEdge(0, 1, 4);
        g.addEdge(0, 7, 8);
        g.addEdge(1, 2, 8);
        g.addEdge(1, 7, 11);
        g.addEdge(2, 3, 7);
        g.addEdge(2, 8, 2);
        g.addEdge(2, 5, 4);
        g.addEdge(3, 4, 9);
        g.addEdge(3, 5, 14);
        g.addEdge(4, 5, 10);
        g.addEdge(5, 6, 2);
        g.addEdge(6, 7, 1);
        g.addEdge(6, 8, 6);
        g.addEdge(7, 8, 7);
        g.shortestPath(1, 4);
    }

};

#endif //CPPALGORITHMS_DIJKSTRASSHORTESTPATH_H
