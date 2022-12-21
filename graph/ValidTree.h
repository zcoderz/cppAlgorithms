//
// Created by usman on 12/20/22.
//

#ifndef CPPALGORITHMS_VALIDTREE_H
#define CPPALGORITHMS_VALIDTREE_H

#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class ValidTree {

    bool processDfs(int vertex, unordered_set<int> & visited, unordered_map<int, vector<int>> & theMap, int parent) {
        if (visited.find(vertex) != visited.end()) return false; //cycle
        visited.insert(vertex);
        for (int newV: theMap[vertex]) {
            //we want to avoid repeating the already covered edge to the parent
            if (newV == parent) continue;
            bool  res = processDfs(newV, visited, theMap, vertex);
            if (!res) return false;
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        //if number of edges is not equal to number of nodes -1 then the tree is either not connected or has cycles
        if (edges.size() != n-1) return false;
        unordered_map<int, vector<int>> theMap;
        for (auto & vec: edges) {
            //need to add both sides of edge to map
            //because we are dealing with an undirected graph
            theMap[vec[0]].push_back(vec[1]);
            theMap[vec[1]].push_back(vec[0]);
        }
        unordered_set<int> visited;
        return processDfs(0, visited, theMap, -1) &&
                    visited.size() == n; //all vertexes should have been visited
    }

};

#endif //CPPALGORITHMS_VALIDTREE_H
