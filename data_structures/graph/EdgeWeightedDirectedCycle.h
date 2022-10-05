//
// Created by usman on 10/4/22.
//

#ifndef CPPALGORITHMS_EDGEWEIGHTEDDIRECTEDCYCLE_H
#define CPPALGORITHMS_EDGEWEIGHTEDDIRECTEDCYCLE_H

#include <vector>
#include <limits>
#include "EdgeWeightedDigraph.h"
using namespace std;


class EdgeWeightedDirectedCycle {
private:
    vector<bool> isVisited;
    vector<bool> onStack;

    EdgeWeightedDigraph & edgeWeightedDigraph;
    vector<EdgeWeightedDigraph::WeightedEdge> cyclePath;
    vector<EdgeWeightedDigraph::WeightedEdge> traversePath;

public:

    EdgeWeightedDirectedCycle(EdgeWeightedDigraph &edgeWeightedDigraph) : edgeWeightedDigraph(edgeWeightedDigraph) {
        isVisited.resize(edgeWeightedDigraph.getNoOfVertexes());
        onStack.resize(edgeWeightedDigraph.getNoOfVertexes());
    }

    void processCycleDetection() {
        for (int i =0; i < edgeWeightedDigraph.getNoOfVertexes(); i++) {
            if (!isVisited[i]) {
                runDfs(i);
            }
        }
    }


    void runDfs(int v) {
        isVisited[v] = true;
        onStack[v] = true;
        list<EdgeWeightedDigraph::WeightedEdge> edges = edgeWeightedDigraph.getEdges(v);
        for (EdgeWeightedDigraph::WeightedEdge & edge : edges) {
            if (onStack[get<1>(edge)]) {
                EdgeWeightedDigraph::WeightedEdge path = edge;
                while (get<0>(path) != get<1>(edge)) {
                    cyclePath.push_back(path);
                    path = traversePath[get<0>(path)];
                }
                cyclePath.push_back(path);
            } else if (!isVisited[get<1>(edge)]) {
                traversePath[get<1>(edge)] = edge;
                runDfs(get<1>(edge));
            }
        }
        onStack[v] = false;
    }

    bool hasCycles() {
        return !cyclePath.empty();
    }

    vector<EdgeWeightedDigraph::WeightedEdge> getCyclePath() {
        return cyclePath;
    }
};

#endif //CPPALGORITHMS_EDGEWEIGHTEDDIRECTEDCYCLE_H
