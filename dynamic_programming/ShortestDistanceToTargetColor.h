//
// Created by usman on 10/28/22.
//

#ifndef CPPALGORITHMS_SHORTESTDISTANCETOTARGETCOLOR_H
#define CPPALGORITHMS_SHORTESTDISTANCETOTARGETCOLOR_H

#include <vector>

using namespace std;

class ShortestDistanceToTargetColor {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        vector<int> leftColorIndex(3,-1); //initialize to first index
        vector<vector<int>> distance(colors.size(), vector<int> (3, INT_MAX));
        for (int i =0; i < colors.size(); i++) {
            int color = colors[i] - 1; //-1 to turn the index 0 based (array)
            for (int j = leftColorIndex[color]+1; j < i; j++) {
                distance[j][color] = i-j;
            }
            leftColorIndex[color]=i;
            distance[i][color] = 0;
        }
        vector<int> rightColorIndex(3, colors.size()); //initialize to last index
        for (int i =colors.size()-1; i >= 0; i--) {
            int color = colors[i] - 1; //-1 to turn the index 0 based (array)
            for (int j = rightColorIndex[color]-1; i<j; j--) {
                distance[j][color] = min (distance[j][color] , j-i);
            }
            rightColorIndex[color]=i;
            distance[i][color] = 0;
        }

        vector<int> res;
        for (vector<int> & query: queries) {
            int val = distance[query[0]][query[1]-1];
            val = val == INT_MAX? -1 : val;
            res.push_back(val);
        }
        return res;
    }
};

#endif //CPPALGORITHMS_SHORTESTDISTANCETOTARGETCOLOR_H
