//
// Created by usman on 10/4/22.
//

#ifndef CPPALGORITHMS_EDGEWEIGHTEDDIGRAPH_H
#define CPPALGORITHMS_EDGEWEIGHTEDDIGRAPH_H

#include <vector>
#include <list>
#include <tuple>

using namespace std;

class EdgeWeightedDigraph {
    //from, to, weight
public:
    typedef tuple<int, int, int> WeightedEdge;
private:
    int noVertexes;
    int noEdges;
    vector<int> indegree;
    vector<list<WeightedEdge>> adjacencyList;

public:

    EdgeWeightedDigraph(int vertexes) : noVertexes(vertexes) {
        indegree.resize(vertexes);
        adjacencyList.resize(vertexes);
    }

    ~EdgeWeightedDigraph() {
    }

    void addEdge(int from, int to, int weight) {
        adjacencyList[from].emplace_back(from, to, weight);
        indegree[to]++;
        noEdges++;
    }

    int getIndegree(int vertex) {
        return indegree[vertex];
    }

    int outDegree(int vertex) {
        return adjacencyList[vertex].size();
    }

    list<WeightedEdge> getEdges(int vertex) {
        return adjacencyList[vertex];
    }

    vector<list<WeightedEdge>> getAllEdges(int vertex) {
        return adjacencyList;
    }

    [[nodiscard]] int getNoOfVertexes() const {
        return noVertexes;
    }


};
#endif //CPPALGORITHMS_EDGEWEIGHTEDDIGRAPH_H
