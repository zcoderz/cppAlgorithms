//
// Created by usman on 1/21/23.
//

#ifndef CPPALGORITHMS_CLOSESTROOM_H
#define CPPALGORITHMS_CLOSESTROOM_H

#include <vector>
#include <algorithm>
#include <set>
#include <climits>

using namespace std;

class ClosestRoom {
public:
    static vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        for (int i =0; i < queries.size(); i++) {
            queries[i].push_back(i);
        }
        auto comp = [] (vector<int> &a, vector<int> & b) -> bool {return a[1] > b[1];};
        sort(rooms.begin(), rooms.end(), comp);
        sort(queries.begin(), queries.end(), comp);
        set<int> currentRooms;
        vector<int> result (queries.size());
        int roomIndex=0;
        for (auto & query : queries) {
            int roomSz = query[1];
            while (roomIndex < rooms.size() && rooms[roomIndex][1] >= roomSz) {
                currentRooms.insert(rooms[roomIndex++][0]);
            }

            auto next = currentRooms.lower_bound(query[0]);
            int nextDt = next == currentRooms.end() ? INT_MAX : abs(query[0]-*next);
            int priorDt =  next == currentRooms.begin() ? INT_MAX : abs(query[0]- *prev(next));

            if (nextDt < priorDt) {
                result[query[2]] = *next;
            } else if (nextDt >= priorDt && priorDt != INT_MAX){
                result[query[2]] = *prev(next);
            } else {
                result[query[2]] = -1;
            }
        }
        return result;
    }

    static void testMe() {
        vector<vector<int>> rooms = {{1,4},{2,3},{3,5},{4,1},{5,2}};
        vector<vector<int>> queries = {{2,3},{2,4},{2,5}};
        auto res = closestRoom(rooms, queries);
        int j = 1;
    }
};

#endif //CPPALGORITHMS_CLOSESTROOM_H
