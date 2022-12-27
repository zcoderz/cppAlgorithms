//
// Created by usman on 12/26/22.
//

#ifndef CPPALGORITHMS_SWIMINRISINGWATER_H
#define CPPALGORITHMS_SWIMINRISINGWATER_H

#include <vector>
#include <algorithm>
using namespace std;

/**
 * Min Spanning Tree is a very interesting approach for this problem!!!
 */
class SwimInRisingWater {
public:
    vector<pair<int, int>> vertices;

    int find(int vertexId) {
        if (vertices[vertexId].first != vertexId) {
            int parent = find(vertices[vertexId].first);
            vertices[vertexId].first = parent;
        }
        return vertices[vertexId].first;
    }

    bool runUnion(int vertexId1, int vertexId2) {
        vertexId1 = find(vertexId1);
        vertexId2 = find(vertexId2);
        if (vertexId1 == vertexId2) return false;
        if (vertices[vertexId1].second == vertices[vertexId2].second) {
            vertices[vertexId1].second++;
            vertices[vertexId2].first = vertexId1;
        } else if (vertices[vertexId1].second > vertices[vertexId2].second) {
            vertices[vertexId2].first = vertexId1;
        } else {
            vertices[vertexId1].first = vertexId2;
        }
        return true;
    }

    void initialize(int n) {
        vertices.reserve(n);
        for (int i =0; i < n; i++) {
            vertices[i] = {i, 0};
        }
    }

    int swimInWater(vector<vector<int>>& grid) {
        int rows = grid.size();
        int num = rows*rows;
        vector<int> theVec(num);
        for (int i =0; i < num; i++) theVec[i]=i;
        auto comp = [&grid, &rows] (int & l, int & r) -> bool {return grid[l/rows][l%rows] < grid[r/rows][r%rows];};
        sort(theVec.begin(), theVec.end(), comp);
        initialize(num);
        vector<bool> seen (num);
        vector<vector<int>> moves = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for (int i =0; i < num; i++) {
            seen[theVec[i]] = true;
            int theRow = theVec[i]/rows;
            int theCol = theVec[i]%rows;
            for (auto & vec: moves ) {
                int nR = theRow + vec[0];
                int nC = theCol + vec[1];
                if (nR < 0 || nR >=rows || nC < 0 || nC >=rows) continue;
                int nIndex = nR*rows+nC;
                if (seen[nIndex]) {
                    //union the given cell with surrounding cells that have been visited
                    runUnion(nIndex, theVec[i]);
                }
            }
            if (find(0) == find(num-1)) {
                return grid[theRow][theCol];
            }
        }
        return -1;
    }
};

#endif //CPPALGORITHMS_SWIMINRISINGWATER_H
