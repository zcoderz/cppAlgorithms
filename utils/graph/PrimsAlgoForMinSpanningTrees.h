//
// Created by usman on 11/9/21.
//

#ifndef CPPALGORITHMS_PRIMSALGOFORMINSPANNINGTREES_H
#define CPPALGORITHMS_PRIMSALGOFORMINSPANNINGTREES_H

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include "Vertex.h"
#include "Edge.h"
using namespace std;

class Prim {
    /**
     * the algo works only for undirected graphs. its better to use union find based algo instead as that is much easier
     * to write and explain and has the same complexity as this algo
     *
     * @param vertices
     * @param edges
     * @return
     */
    static int calculateMinSpanningTreeCost(vector<VertexP> &vertices, vector<EdgeP> &edges) {
        unordered_map<int, vector<EdgeP>> edgeMap;
        //assumes each bi-directional instance of the edge is specified in the edge vector
        //if a bi-directional edge is specified only once then we will need to add it twice
        //into the vector of edges, one with source pointing to destination and vice versa
        for (EdgeP & edge : edges) {
            vector<EdgeP> & vec = edgeMap[edge->getSrc()];
            vec.push_back(edge);
        }
        auto iterFirst = edgeMap.begin();

        //this set indicates vertices which have been seen
        unordered_set<int> seenVertices;
        seenVertices.insert(iterFirst->first);

        //this PQ is sorted smallest to largest
        auto comp = [] (pair<int, int> &a, pair<int, int> &b) -> bool { return a.second > b.second; };
        priority_queue<pair<int, int> , vector<pair<int,int>> , decltype(comp)> pQ (comp);

        //insert in PQ destination vertices from the first vertex along with their cost
        for (EdgeP & edge : iterFirst->second) {
            pQ.emplace(edge->getDest(), edge->getCost());
        }
        int totalCost = 0;
        while (!pQ.empty()) {
            //find the vertex on top of PQ (i.e. with the lowest cost)
            auto & thePair = pQ.top(); pQ.pop();
            if (seenVertices.find(thePair.first) == seenVertices.end()) {
                seenVertices.insert(thePair.first); //add the vertex to seen vertexes so that we don't visit it again
                totalCost += thePair.second;
                vector<EdgeP> & vertexEdges = edgeMap[thePair.first];
                for (EdgeP & edge : vertexEdges) {
                    //for each instance of an edge we are inserting in PQ. PQ memory space will grow very large
                    //alternative, we could leverage a data structure that contains cost of each vertex currently in PQ
                    //and ignore adding to PQ if this cost is larger than that already in PQ.
                    //when cost is lower, we could write a custom function in PQ which updates inplace the PQ
                    //node cost value and adjusts the PQ (bumps up the node) to its appropriate place in heap
                    //but the above is too much work for an interview and hence adding a new vertex cost in PQ is
                    //a good choice for interview.
                    pQ.emplace(edge->getDest(), edge->getCost());
                }
            }
        }
        return totalCost;
    }
};

#endif //CPPALGORITHMS_PRIMSALGOFORMINSPANNINGTREES_H
