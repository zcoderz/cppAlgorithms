//
// Created by usman on 11/9/22.
//

#ifndef CPPALGORITHMS_BOXSTACKINGLENGTHWIDTHREUSE_H
#define CPPALGORITHMS_BOXSTACKINGLENGTHWIDTHREUSE_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>
using namespace std;

/**
 * https://www.youtube.com/watch?v=9mod_xRB-O0&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr&index=31
 * https://github.com/mission-peace/interview/blob/master/src/com/interview/dynamic/BoxStacking.java
 * https://www.geeksforgeeks.org/box-stacking-problem-dp-22/
 *
 */
class BoxStackingLengthWidthReuse {

public:

    static void generatePermutations(vector<int> & cube, vector<vector<int>> & permutations, int index) {
        if (index == cube.size()) {
            if (cube[0] >= cube[1]) //assuming 0th index is for length , ensure length is greater than width
                permutations.push_back(cube);
            return;
        }
        for (int i =index; i < cube.size(); i++) {
            swap(cube[i], cube[index]);
            generatePermutations(cube, permutations, index+1);
            swap(cube[i], cube[index]);
        }
    }

    static vector<vector<int>> rotateCubes(vector<vector<int>>& cuboids) {
        vector<vector<int>> res;
        for (vector<int> & cube: cuboids) {
            vector<vector<int>> permutations;
            generatePermutations(cube, permutations, 0);
            res.insert(res.end(), permutations.begin(), permutations.end());
        }
        return res;
    }

    static int maxHeight(vector<vector<int>>& cuboids) {
        vector<vector<int>> rotatedCubes = rotateCubes(cuboids);
        //sort based on areas, larger areas first
        auto comp = [] (vector<int> & a, vector<int> & b) -> bool { return a[0] * a[1] > b[0] * b[1] ;};
        sort(rotatedCubes.begin(), rotatedCubes.end(), comp);
        int maxHeight = 0;
        int size = rotatedCubes.size();
        vector<int> heightVec(size);
        vector<int> priorVec(size, -1);
        for (int i=0; i < size; i++) {
            heightVec[i] = rotatedCubes[i][2];
            for (int j=0; j < i; j++) {
                if ((rotatedCubes[j][0] > rotatedCubes[i][0]) && (rotatedCubes[j][1] > rotatedCubes[i][1])) {
                    heightVec[i] = max (heightVec[i], rotatedCubes[i][2] + heightVec[j]);
                    priorVec[i] =j;
                }
            }
            if (heightVec[i] > maxHeight) {
                maxHeight = heightVec[i];
            }
        }
        return maxHeight;
    }

    static void testMe() {
        vector<vector<int>> cubes = {{36,46,41},{15,100,100},{75,91,59},{13,82,64}};
        int res = maxHeight(cubes);
        cout << res << endl;
    }
};
#endif //CPPALGORITHMS_BOXSTACKINGLENGTHWIDTHREUSE_H
