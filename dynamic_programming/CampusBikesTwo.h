//
// Created by usman on 12/1/22.
//

#ifndef CPPALGORITHMS_CAMPUSBIKESTWO_H
#define CPPALGORITHMS_CAMPUSBIKESTWO_H

#include <vector>
#include <valarray>
#include <cstring>
#include <climits>
#include <iostream>
using namespace std;

class CampusBikesTwo {
public:
    static int manhattanDist (int x1, int y1, int x2, int y2) {
        return abs(x1-x2) + abs(y2-y1);
    }

    static int calcDistRecur(int workersAssigned, vector<vector<int>>& workers, vector<vector<int>>& bikes, int mask, int dp[] ) {
        if (workersAssigned == workers.size()) {
            return 0;
        }
        if(dp[mask] != -1) {
            return dp[mask];
        }
        int minDist = INT_MAX;
        for (int i =0; i < bikes.size(); i++) {
            if ((mask & (1<<i)) != 0) continue;
            minDist = min(minDist, manhattanDist(workers[workersAssigned][0], workers[workersAssigned][1], bikes[i][0], bikes[i][1])
                               + calcDistRecur(workersAssigned+1, workers, bikes, mask | (1<<i), dp ));
        }
        return dp[mask] = minDist;
    }

    static int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int dp [1 << bikes.size()];
        memset(dp, -1, sizeof(dp));
        return calcDistRecur(0, workers, bikes, 0, dp);
    }

    static int countOnes(int mask) {
        int cnt = 0;
        while (mask !=0) {
            mask &= mask-1;
            cnt++;
        }
        return cnt;
    }

    static int assignBikesDP(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int minDist = INT_MAX;
        int dp [1 << bikes.size()];
        std::fill_n(dp, 1<<bikes.size(), INT_MAX);
        dp[0]=0;
        for (int mask =0; mask < (1 << bikes.size()); mask++) {
            int workersAssigned = countOnes(mask);
            if (workersAssigned >= workers.size()) {
                minDist = min(minDist, dp[mask]);
                continue;
            }
            for (int i =0; i < bikes.size(); i++) {
                if ((mask & (1<<i)) !=0) continue;
                int dist = manhattanDist(workers[workersAssigned][0], workers[workersAssigned][1], bikes[i][0], bikes[i][1]);
                dist += dp[mask];
                int newMask = mask | (1<<i);
                dp[newMask] = min (dp[newMask], dist);
            }
        }
        return minDist;
    }

    static int assignBikesPQ(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<>> pQ;
        pQ.push({0,0});
        int numWorkers = workers.size();
        unordered_set<int> processed;
        while (!pQ.empty()) {
            auto pair = pQ.top();
            pQ.pop();
            int mask = pair.second;
            int dist = pair.first;
            int worksAssigned = countOnes(mask);
            if (worksAssigned == numWorkers) {
                return dist;
            }
            if (processed.find(mask) != processed.end()) continue;
            processed.insert(mask);
            for (int i =0; i < bikes.size(); i++) {
                if ((mask & (1<<i)) != 0) continue;
                int newMask = mask | (1<<i);
                if (processed.find(newMask) != processed.end()) continue;
                int newDist = dist + manhattanDist(workers[worksAssigned][0], workers[worksAssigned][1], bikes[i][0], bikes[i][1]);
                pQ.push({newDist,newMask});
            }
        }
        return INT_MAX;
    }

    static void testMe() {
        vector<vector<int>> workers = {{0,0},{1,0},{2,0},{3,0},{4,0}};
        vector<vector<int>> bikes = {{0,999},{1,999},{2,999},{3,999},{4,999},{5,999},{6,999}};
        int res = assignBikesPQ(workers, bikes);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_CAMPUSBIKESTWO_H
