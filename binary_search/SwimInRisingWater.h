//
// Created by usman on 1/24/23.
//

#ifndef CPPALGORITHMS_SWIMINRISINGWATER_H
#define CPPALGORITHMS_SWIMINRISINGWATER_H

#include <vector>
#include <stack>
#include <climits>

using namespace std;

class SwimInRisingWater {
public:
    
    bool possible(vector<vector<int>>& grid, int target) {
        int n= grid.size();
        vector<bool> seen(n*n);
        static vector<vector<int>> moves = {{0,1},{0,-1},{1,0},{-1,0}};
        stack<int> theStack; theStack.push(0); seen[0] = true;
        int desiredCell = n*n-1;
        while (!theStack.empty()) {
            int val = theStack.top(); theStack.pop();
            if (val==desiredCell) return true;
            int row = val/n;
            int col = val % n;
            for (auto  & move: moves) {
                int nRow = row+move[0]; int nCol = col+move[1];
                if (nRow ==n || nCol ==n || nRow < 0 || nCol < 0) continue;
                int targetCell = nRow *n + nCol;
                if (grid[nRow][nCol] > target || seen[targetCell]) continue;
                seen[targetCell] = true;
                theStack.push(targetCell);
            }
        }
        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int low = grid[0][0];
        int high = INT_MIN;
        int sz = grid.size();
        for (int i =0; i < sz; i++) {
            for (int j =0; j < sz; j++) {
                high= max(high , grid[i][j]);
            }
        }

        while (high>low) {
            int mid = low + (high-low)/2;
            if (possible(grid, mid)) {
                high = mid;
            } else {
                low = mid+1;
            }
        }
        return low;
    }
};
#endif //CPPALGORITHMS_SWIMINRISINGWATER_H
