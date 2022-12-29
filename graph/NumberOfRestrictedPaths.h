//
// Created by usman on 12/29/22.
//

#ifndef CPPALGORITHMS_NUMBEROFRESTRICTEDPATHS_H
#define CPPALGORITHMS_NUMBEROFRESTRICTEDPATHS_H

#include <vector>
#include <climits>
#include <queue>
using namespace std;

class NumberOfRestrictedPaths {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        int MOD =  1000000007;
        vector<int> distances(n+1, INT_MAX);
        vector<vector<pair<int,int>>> vertexEdges(n+1);
        for (auto & vec: edges) {
            vertexEdges[vec[0]].emplace_back(vec[2], vec[1]); //distance, vertex
            vertexEdges[vec[1]].emplace_back(vec[2], vec[0]); //distance, vertex
        }

        calcDistance(n, distances, vertexEdges);

        vector<int> numPossibles(n+1, -1);
        vector<bool> seen(n+1);
        return calcPaths(1, n, distances, vertexEdges, numPossibles, seen, MOD);
    }

    int calcPaths(int vertex, int dest, vector<int> & distances, vector<vector<pair<int,int>>> & vertexEdges,
                  vector<int> & numPossibles, vector<bool> & seen, int MOD) {
        if (vertex==dest) return 1;
        if (numPossibles[vertex] != -1) return numPossibles[vertex];
        seen[vertex] = true;
        int numPaths = 0;
        for (auto & p : vertexEdges[vertex]) {
            if (seen[p.second]) continue;
            if (distances[vertex] <= distances[p.second]) continue;
            numPaths = (numPaths +  calcPaths(p.second, dest, distances, vertexEdges, numPossibles, seen, MOD)) % MOD;
        }
        seen[vertex]= false;
        numPossibles[vertex] = numPaths;
        return numPaths;
    }

    void calcDistance(int n, vector<int> & distances, vector<vector<pair<int,int>>> & vertexEdges) {
        vector<bool> seen(n+1);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pQ;
        pQ.emplace(0, n);
        while (!pQ.empty()) {
            auto [cost, vertex] = pQ.top(); pQ.pop();
            if (seen[vertex]) continue;
            seen[vertex] = true;
            distances[vertex] = cost;
            for (auto & p: vertexEdges[vertex]) {
                if (seen[p.second]) continue;
                pQ.emplace(cost + p.first, p.second);
            }
        }
    }
};

#endif //CPPALGORITHMS_NUMBEROFRESTRICTEDPATHS_H
