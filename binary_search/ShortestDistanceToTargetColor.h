//
// Created by usman on 1/19/23.
//

#ifndef CPPALGORITHMS_SHORTESTDISTANCETOTARGETCOLOR_H
#define CPPALGORITHMS_SHORTESTDISTANCETOTARGETCOLOR_H

#include <vector>
#include <unordered_map>
#include <cstdlib>

using namespace std;
/**
 * Binary search for this problem is an interesting approach and straight forward approach.
 * The other approach is DP , left and right diffs per index. DP is more elegant and faster.
 */
class ShortestDistanceToTargetColor {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> colorMap;
        for (int i =0 ; i < colors.size(); i++) {
            colorMap[colors[i]].push_back(i);
        }
        vector<int> results;
        int m = 0;
        for (auto & query : queries) {
            int color = query[1]; int index = query[0];
            auto res = colorMap.find(color);
            if (res == colorMap.end()) {
                results.push_back(-1);
            } else {
                //lower bound returns the given search value if found or next larger if not found
                auto tIndex = lower_bound(res->second.begin(), res->second.end(), index);
                if (tIndex == res->second.begin()) {
                    //you found the value at given index
                    results.push_back(abs(*tIndex-index));
                } else if (tIndex == res->second.end()) {
                    //the value didn't exist at or beyond the given index.
                    //it must exist on a prior index since the value does in fact exist and the prior value must be closest
                    results.push_back(abs(index- (*(prev(tIndex)))));
                } else {
                    //both prior and currNext exist, return the closer one
                    int prior = abs(index- (*(prev(tIndex))));
                    int currOrNext = abs(index- (*tIndex));
                    results.push_back(min(prior,currOrNext));
                }
            }
            m++;
        }
        return results;
    }

    static void testMe() {
        vector<int> vals = {3,2,2,1,3,1,1,1,3,1};
        vector<vector<int>> queries = {{4,1},{9,2},{4,2},{8,1},{0,3},{2,1},{2,3},{6,3},{4,1},{1,2}};
        auto res = shortestDistanceColor(vals, queries);

    }
};

#endif //CPPALGORITHMS_SHORTESTDISTANCETOTARGETCOLOR_H
