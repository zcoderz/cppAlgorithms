//
// Created by usman on 12/27/22.
//

#ifndef CPPALGORITHMS_DESTINATIONMINCOST_H
#define CPPALGORITHMS_DESTINATIONMINCOST_H

#include <vector>
#include <queue>
#include <tuple>

using namespace std;

class DestinationMinCost {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int numCities = passingFees.size();
        vector<vector<pair<int, int>>> graphEdges(numCities);
        for (auto & vec: edges) {
            graphEdges[vec[0]].emplace_back(vec[1], vec[2]);
            graphEdges[vec[1]].emplace_back(vec[0], vec[2]);
        }
        vector<int> timeTaken(numCities);
        typedef tuple<int,int,int> CostVertexTime;
        //standard PQ is ordered less, need to do greater.
        priority_queue<CostVertexTime, vector<CostVertexTime>, greater<>> pQ;
        pQ.emplace(passingFees[0], 0, 0);
        while (!pQ.empty()) {
            auto [currCost, currVertex, currTime]  = pQ.top(); pQ.pop();
            //if you reach the same node again, only process if new time is less than prior time
            //this is the ONLY difference between this problem and standard shortest paths
            //that's because you can get into a scenario where you reached an intermediate vertex with less cost
            //but later crossed the max time and hence couldn't reach destination
            //another path may cross the same vertex with higher cost but in less time and thus still create more possibilities
            if (timeTaken[currVertex] != 0 && currTime >= timeTaken[currVertex]) continue;
            timeTaken[currVertex] = currTime;
            if (currVertex == numCities-1) return currCost;
            for (auto & p: graphEdges[currVertex]) {
                if (timeTaken[p.first] != 0 && currTime + p.second >= timeTaken[p.first]) continue;
                if ((p.second + currTime) > maxTime) continue;
                pQ.emplace(passingFees[p.first] + currCost, p.first, currTime + p.second);
            }
        }
        return -1;
    }
};

#endif //CPPALGORITHMS_DESTINATIONMINCOST_H
