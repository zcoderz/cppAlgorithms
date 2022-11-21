//
// Created by usman on 11/20/22.
//

#ifndef CPPALGORITHMS_ANDOIDUNLOCKPATTERNS_H
#define CPPALGORITHMS_ANDOIDUNLOCKPATTERNS_H
#include <vector>
using namespace std;

class AndroidUnlockPatterns {
    int numberOfPatterns(int m, int n) {
        vector<vector<int>> skipL(10, vector<int> (10));
        skipL[1][3] = skipL[3][1] = 2;
        skipL[1][7] = skipL[7][1] = 4;
        skipL[7][9] = skipL[9][7] = 8;
        skipL[9][3] = skipL[3][9] = 6;
        skipL[1][9] = skipL[9][1] = skipL[3][7] = skipL[7][3] = skipL[4][6] = skipL[6][4] = skipL[2][8] = skipL[8][2] = 5;
        vector<bool> visited (10);
        int numPatterns = 0;
        numPatterns += numberPatterns(1, m, n, visited, skipL, 1) * 4;
        numPatterns += numberPatterns(1, m, n, visited, skipL, 2) * 4;
        numPatterns += numberPatterns(1, m, n, visited, skipL, 5);
        return numPatterns;
    }

    int numberPatterns (int depth, int minDepth, int maxDepth, vector<bool> visited, vector<vector<int>> & skipL, int index) {
        if (depth > maxDepth) return 0;
        visited[index] = true;
        int numP = depth >= minDepth ? 1 : 0;
        for (int i =1; i < 10; i++) {
            if (!visited[i] && (skipL[index][i] ==0 || visited[skipL[index][i]])) {
                numP += numberPatterns(depth+1, minDepth, maxDepth, visited, skipL, i);
            }
        }
        visited[index] = false;
        return numP;
    }
};

#endif //CPPALGORITHMS_ANDOIDUNLOCKPATTERNS_H
