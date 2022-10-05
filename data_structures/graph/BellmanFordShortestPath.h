//
// Created by usman on 10/4/22.
//

#ifndef CPPALGORITHMS_BELLMANFORDSHORTESTPATH_H
#define CPPALGORITHMS_BELLMANFORDSHORTESTPATH_H

#include <queue>
#include <limits>
#include "EdgeWeightedDirectedCycle.h"

class BellmanFordShortestPath {
private :
    vector<int> distances;
    queue<int> vertexQueue;
    int relaxIterations;
    vector<int> vertexPriorEdge;
    vector<bool> onQueue;
    vector<EdgeWeightedDigraph::WeightedEdge> negativeCyclePath;
    EdgeWeightedDigraph  & edgeWeightedDigraph;

    void   checkForNegativeCycle() {
        int noVertices = 0;
        for (int i=0; i < vertexPriorEdge.size(); i++) {
            if (vertexPriorEdge[i] != -1) noVertices++;
        }
        EdgeWeightedDigraph digraph(noVertices);
        for(int i =0; i < vertexPriorEdge.size(); i++) {
            if (vertexPriorEdge[i] != -1) {
                digraph.addEdge(vertexPriorEdge[i], i, 0);
            }
        }
        EdgeWeightedDirectedCycle detectCycle(digraph);
        detectCycle.processCycleDetection();
        negativeCyclePath = detectCycle.getCyclePath();
    }

public:
    BellmanFordShortestPath(EdgeWeightedDigraph  & edgeWeightedDigraph_) : edgeWeightedDigraph(edgeWeightedDigraph_)  {
        distances.resize(edgeWeightedDigraph.getNoOfVertexes(), numeric_limits<int>::max());
        onQueue.resize(edgeWeightedDigraph.getNoOfVertexes());
        vertexPriorEdge.resize(edgeWeightedDigraph.getNoOfVertexes(), -1);
    }

    void processShortestPath(int sourceVertex) {
        vertexQueue.push(sourceVertex);
        while (!onQueue.empty() && negativeCyclePath.empty()) {
            int v = vertexQueue.front(); vertexQueue.pop();
            onQueue[v] = false;
            relax(v);
        }
    }

    void relax(int vertex) {
        list<EdgeWeightedDigraph::WeightedEdge> edges = edgeWeightedDigraph.getEdges(vertex);
        for (EdgeWeightedDigraph::WeightedEdge &edge : edges) {
            if (distances[get<1>(edge)] > (distances[get<0>(edge)] + get<2>(edge))) {
                if (!onQueue[get<1>(edge)]) {
                    vertexQueue.push(get<1>(edge));
                }
                distances[get<1>(edge)] = distances[get<0>(edge)] + get<2>(edge);
                vertexPriorEdge[get<1>(edge)] = get<0>(edge);
            }
            if (++relaxIterations % edgeWeightedDigraph.getNoOfVertexes() == 0) {
                //if there is a cycle it will have at max V edges.
                //hence, check every V relaxation for a cycle
                checkForNegativeCycle();
                if (!negativeCyclePath.empty()) return;
            }
        }
    }

    bool runSimplifiedBF(EdgeWeightedDigraph &digraph, int sourceVertex) {
        vector<int> distances (digraph.getNoOfVertexes(), numeric_limits<int>::max());
        distances[sourceVertex] = 0;
        for (int i =1; i < digraph.getNoOfVertexes(); i++) {
            //repeat for vertices -1 i.e. if 3 vertices shortest path will have 2 edges
            for (int j =0; j < digraph.getNoOfVertexes(); j++) {
                for (EdgeWeightedDigraph::WeightedEdge & edge :  digraph.getEdges(j)) {
                    if (distances[get<0>(edge)] != numeric_limits<int>::max() &&
                        distances[get<0>(edge)] + get<2>(edge) < distances[get<1> (edge)]) {
                        distances[get<1>(edge)]  =  get<2>(edge) + distances[get<0> (edge)];
                    }
                }
            }
        }
        bool hasNegativeCycle = false;
        int i =0;
        while (!hasNegativeCycle && i < digraph.getNoOfVertexes()) {
            for (EdgeWeightedDigraph::WeightedEdge & edge :  digraph.getEdges(i)) {
                int wt = distances[get<0>(edge)];
                wt += get<2>(edge);
                if (wt < distances[get<1>(edge)]) hasNegativeCycle = true;
            }
        }

        return !hasNegativeCycle;
    }

};
#endif //CPPALGORITHMS_BELLMANFORDSHORTESTPATH_H
