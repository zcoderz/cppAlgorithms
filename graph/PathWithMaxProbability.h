//
// Created by usman on 10/7/22.
//

#ifndef CPPALGORITHMS_PATHWITHMAXPROBABILITY_H
#define CPPALGORITHMS_PATHWITHMAXPROBABILITY_H

#include <iostream>

#include <vector>
#include <queue>
#include <limits>

using namespace std;
class PathWithMaxProbability {
public:


//    struct PairComp {
//        bool operator() (const Pair &a, const Pair & b) {return a.second < b.second;}
//    };


    static double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        typedef pair<double, int> Pair;
        vector<vector<Pair>> vecEdges (n);
        for (int i =0; i < edges.size(); i++) {
            vecEdges[edges[i][0]].emplace_back(succProb[i], edges[i][1]);
            vecEdges[edges[i][1]].emplace_back(succProb[i], edges[i][0]);
        }
        double MIN = numeric_limits<double>::min();
        priority_queue<Pair> pQ;
        pQ.emplace(1.0, start);
        vector<bool> seen (n);
        vector<double> weights (n, MIN);
        while (!pQ.empty()) {
            auto [wt, vertex] = pQ.top(); pQ.pop();
            if (seen[vertex]) continue;
            if (vertex == end) return wt;
            seen[vertex] = true;
            for (Pair & pair: vecEdges[vertex]) {
                double newWt = wt * pair.first;
                if (newWt < weights[pair.second]) continue;
                weights[pair.second] = newWt;
                pQ.emplace(newWt, pair.second);
            }
        }
        return 0;
    }

    static void testMe() {
        vector<vector<int>> edges = {{1,4},{2,4},{0,4},{0,3},{0,2},{2,3}};
        vector<double> successProbs = {0.37,0.17,0.93,0.23,0.39,0.04};
        double val = maxProbability(5, edges, successProbs, 3, 4);
        cout << val << endl;
    }

};
#endif //CPPALGORITHMS_PATHWITHMAXPROBABILITY_H
