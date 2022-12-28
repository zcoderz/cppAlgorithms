//
// Created by usman on 12/28/22.
//

#ifndef CPPALGORITHMS_NETWORKDELAYTIME_H
#define CPPALGORITHMS_NETWORKDELAYTIME_H

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class NetworkDelayTwo{
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graphEdges(n+1);
        for (auto & vec: times) {
            graphEdges[vec[0]].emplace_back(vec[1], vec[2]);
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pQ;
        pQ.emplace(0, k);
        vector<bool> seen(n+1);
        int countSeen = 0;
        while (!pQ.empty()) {
            auto [cost, vertex] = pQ.top(); pQ.pop();
            if (seen[vertex]) continue;
            seen[vertex]=true;
            countSeen++;
            if (countSeen==n) return cost;
            for (auto & p: graphEdges[vertex]) {
                if (seen[p.first]) continue;
                pQ.emplace(p.second+cost, p.first);
            }
        }
        return -1;
    }
};

#endif //CPPALGORITHMS_NETWORKDELAYTIME_H
