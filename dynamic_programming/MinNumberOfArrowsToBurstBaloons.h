//
// Created by usman on 11/16/22.
//

#ifndef CPPALGORITHMS_MINNUMBEROFARROWSTOBURSTBALOONS_H
#define CPPALGORITHMS_MINNUMBEROFARROWSTOBURSTBALOONS_H

#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class MinArrowsToBurstBaloons {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        //sort ascending by xend
        auto comp = [] (vector<int> &a, vector<int> & b) -> bool  {return a[1] < b[1];};
        sort(points.begin(), points.end(), comp);
        int arrows = 0;
        int prior = INT_MIN;
        for (vector<int> & point: points) {
            if (point[0] > prior) {
                arrows++;
                prior = point[1];
            }
        }
    }
};

#endif //CPPALGORITHMS_MINNUMBEROFARROWSTOBURSTBALOONS_H
