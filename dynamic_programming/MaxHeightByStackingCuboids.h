//
// Created by usman on 11/9/22.
//

#ifndef CPPALGORITHMS_MAXHEIGHTBYSTACKINGCUBOIDS_H
#define CPPALGORITHMS_MAXHEIGHTBYSTACKINGCUBOIDS_H

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class MaxHeightByStackingCuboids {
public:

    static int maxHeight(vector<vector<int>>& cuboids) {
        for (vector<int> & cuboid : cuboids) {
            sort(cuboid.begin(), cuboid.end()); //sort such that width is first , length second and height last (largest)
        }
        auto comp = [] (vector<int> & a, vector<int> & b) -> bool {
            if (a[0]==b[0]) {
                if (a[1]==b[1]) {
                    return a[2] > b[2];
                } else {
                    return a[1] > b[1];
                }
            } else {
                return a[0] > b[0];
            }
        };
        sort(cuboids.begin(), cuboids.end(), comp);
        int sz = cuboids.size();
        vector<int> heights (sz);
        int maxHeight = 0;
        for (int i =0; i < sz; i++) {
            heights[i] = cuboids[i][2];
            for (int j =0; j < i; j++) {
                if (cuboids[j][0] >= cuboids[i][0] && cuboids[j][1] >= cuboids[i][1] && cuboids[j][2] >= cuboids[i][2]) {
                    heights[i] = max(heights[i], cuboids[i][2] + heights[j]);
                }
            }
            maxHeight = max(maxHeight, heights[i]);
        }
        return maxHeight;
    }

    static void testMe() {
        vector<vector<int>> cubes = {{50,45,20}, {95,37,53},{45,23,12}};
        int res = maxHeight(cubes);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_MAXHEIGHTBYSTACKINGCUBOIDS_H
