//
// Created by usman on 10/8/22.
//

#ifndef CPPALGORITHMS_SLIDINGPUZZLE_H
#define CPPALGORITHMS_SLIDINGPUZZLE_H

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <queue>
using namespace std;

class SlidingPuzzle {
public:
    static int slidingPuzzle(vector<vector<int>>& board) {
        int numMoves =0;
        int rows = board.size();
        int cols = board[0].size();
        string currState;
        int index=0;
        for (int i =0 ; i < rows; i++) {
            for (int j =0; j < cols; j++) {
                currState +=  '0' + board[i][j];
                if(board[i][j] ==0) {
                    index = i*cols + j;
                }
            }
        }
        string targetState = "123450";
        queue<pair<int,string>> stateQueue; stateQueue.emplace(index, currState);
        set<string> visited; visited.insert(currState);
        vector<vector<int>> moves = {{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        while (!stateQueue.empty()) {
            cout << "----------------------------"  << endl;
            int size = stateQueue.size();
            numMoves++;
            for (int i =0; i < size; i++) {
                auto [ zeroIndex, newStateOrig] = stateQueue.front(); stateQueue.pop();
                cout << "processing " << newStateOrig << endl;
                if (newStateOrig == targetState) return numMoves;
                for (int possibleSwap : moves[zeroIndex]) {
                    string newState = newStateOrig;
                    swap(newState[zeroIndex], newState[possibleSwap]);
                    if (visited.find(newState) != visited.end()) continue;
                    visited.insert(newState);
                    stateQueue.emplace(possibleSwap, newState);
                }
            }
        }
        return -1;
    }

    static void testMe() {
        vector<vector<int>> setup = {{4,1,2},{5,0,3}};
        int res  = slidingPuzzle(setup);
        cout << res << endl;
    }
};
#endif //CPPALGORITHMS_SLIDINGPUZZLE_H
