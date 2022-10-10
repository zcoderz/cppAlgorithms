//
// Created by usman on 10/7/22.
//

#ifndef CPPALGORITHMS_PATHWITHMINEFFORT_H
#define CPPALGORITHMS_PATHWITHMINEFFORT_H

#include <iostream>

#include <vector>
#include <queue>
#include <limits>
#include <tuple>

using namespace std;

class PathWithMinEffort {
public:

    static int minimumEffortPath(vector<vector<int>>& heights) {
        typedef tuple<int,int,int> Tuple;
        if(heights.empty()) return 0;
        int rows = heights.size();
        int cols = heights[0].size();
        if (cols == 0) return 0;

        vector<bool> seen(rows*cols);
        //default pQ is with comp less and hence is a max heap. we need a min heap.
        priority_queue<Tuple, vector<Tuple>, greater<>> pQ ;
        int targetIndex = rows*cols-1;

        pQ.emplace(0,heights[0][0],0);
        vector<vector<int>> moves = {{0,1}, {1,0},{-1,0}, {0,-1}};
        while (!pQ.empty()) {
            auto [wt, priorHt, coordinate] = pQ.top(); pQ.pop();
            if (coordinate == targetIndex) {
                return wt;
            }
            if (seen[coordinate]) {
                continue;
            }
            seen[coordinate] = true;
            int row = rows == 1 ? 0: coordinate / cols;
            int col = coordinate % cols;
            for (vector<int> &move: moves) {
                int newRow = row + move[0], newCol = col + move[1];
                if (newRow == rows || newCol == cols || newRow < 0 || newCol < 0) continue; //invalid coordinate
                int newCoordinate = newRow*cols + newCol;
                if (seen[newCoordinate]) continue;
                int diff = max(abs(priorHt-heights[newRow][newCol]), wt);
                pQ.emplace(diff,heights[newRow][newCol],newCoordinate);
            }
        }
        return 0;
    }

    static void testMe() {
        vector<vector<int>> heights = {{4,3,4,10,5,5,9,2},{10,8,2,10,9,7,5,6},{5,8,10,10,10,7,4,2},{5,1,3,1,1,3,1,9},{6,4,10,6,10,9,4,6}};
        int val = minimumEffortPath(heights);
        cout << val << endl;
    }
};

#endif //CPPALGORITHMS_PATHWITHMINEFFORT_H
