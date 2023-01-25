//
// Created by usman on 1/24/23.
//

#ifndef CPPALGORITHMS_RANDOMPICKWITHBLACKLIST_H
#define CPPALGORITHMS_RANDOMPICKWITHBLACKLIST_H

#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cstdlib>

using namespace std;

class RandomPickWithBlacklist {
public:

    int adjustedSz;
    unordered_map<int, int> map;

    RandomPickWithBlacklist(int n, vector<int>& blacklist) {
        unordered_set<int> blackSet;
        copy(blacklist.begin(), blacklist.end(), inserter(blackSet, blackSet.begin()));
        vector<int> otherPartition;
        adjustedSz = n - blacklist.size();
        for (int i = adjustedSz; i < n; i++) {
            if (blackSet.count(i)) continue;
            otherPartition.push_back(i);
        }
        int otherIndex=0;

        for (int item : blacklist) {
            if (item < adjustedSz)
                map[item] = otherPartition[otherIndex++];
        }
    }

    int pick() {
        int k = rand() % adjustedSz;
        return map.count(k) ? map[k] : k;
    }
};

#endif //CPPALGORITHMS_RANDOMPICKWITHBLACKLIST_H
