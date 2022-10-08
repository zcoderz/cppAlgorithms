//
// Created by usman on 10/7/22.
//

#ifndef CPPALGORITHMS_NETWORKDELAYTIME_H
#define CPPALGORITHMS_NETWORKDELAYTIME_H
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <unordered_map>
using namespace std;

class NetworkDelayTime {
public:
    typedef pair<int,int> IPair;
    struct pairgreater  {
        bool
        operator()(const IPair & x, const IPair &y) const { return x.second > y.second ;}
    };

    static int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        int MAX = numeric_limits<int>::max();
        unordered_map<int, vector<IPair>> adjacencyList;
        for (vector<int> & time: times) {
            adjacencyList[time[0]].emplace_back(time[1], time[2]);
        }
        //auto comp = [] (pair<int, int> &a, pair<int, int> &b) -> bool { return a.second > b.second; };
        priority_queue<IPair, vector<IPair>, pairgreater> pq;
        pq.emplace(k, 0);
        vector<bool> seen(n, false);
        vector<int> weights(n, MAX);
        int cntSeen = 0;
        int maxWt = 0;
        while (!pq.empty()) {
            auto [vertex, wt] = pq.top(); pq.pop();
            if (seen[vertex]) continue;
            cntSeen++;
            seen[vertex] = true;
            maxWt = max (maxWt, wt);
            if (cntSeen == n) return maxWt;
            for (IPair & edge: adjacencyList[vertex]) {
                if (wt + edge.second > weights[edge.first-1]) continue; //don't add to PQ if new edge is larger than prior edge that's already on queue
                weights[edge.first-1] = wt + edge.second;
                pq.emplace(edge.first,  wt + edge.second);
            }
        }
        return -1;
    }

    static void testMe() {
        vector<vector<int>> paths = {{2,1,1},{2,3,1},{3,4,1}};
        int val = networkDelayTime(paths, 4, 2);
        cout << val << endl;
    }
};

#endif //CPPALGORITHMS_NETWORKDELAYTIME_H
