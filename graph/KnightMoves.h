//
// Created by usman on 11/11/21.
//

#ifndef CPPALGORITHMS_KNIGHTMOVES_H
#define CPPALGORITHMS_KNIGHTMOVES_H

#include <limits>
#include <queue>
#include <unordered_set>


using namespace std;

#include <iostream>

/**
 * this questions needs to be solved via BFS. DFS can cause a very large stack explosion when working with large matrix
 * also code with bfs is simpler for this solution
 */
class KnightMoves {
public:

    static bool isValid(pair<int, int> & location) {
        if (location.first < 0 || location.first > 600 || location.second < 0 || location.second > 600) {
            return false;
        }
        return true;
    }

    static int minKnightMoves(int x, int y) {
        x = x + 300; y = y + 300;
        vector<vector<int>> moves = {{2,  1},
                                     {2,  -1},
                                     {1,  2},
                                     {1,  -2},
                                     {-2, 1},
                                     {-2, -1},
                                     {-1, 2},
                                     {-1, -2}};
        int numMoves = 0;
        queue<pair<int, int>> queueA;
        queue<pair<int, int>> queueB;
        vector<vector<bool>> seenA (601, vector<bool> (601));
        vector<vector<bool>> seenB(601, vector<bool> (601));
        bool turnA = true;
        queueA.emplace(300, 300); seenA[300][300] = true;
        queueB.emplace(x, y); seenB[x][y] = true;

        while (!queueA.empty() && !queueB.empty()) {
            pair<int, int> currIndex;
            int iSize = turnA ? queueA.size() : queueB.size();
            if (iSize ==0) continue;
            numMoves++;
            for (int i =0; i < iSize; i++) {
                if (turnA) {
                    currIndex = queueA.front();
                    queueA.pop();
                } else {
                    currIndex = queueB.front();
                    queueB.pop();
                }
                for (auto &move: moves) {
                    pair<int, int> newIndex(currIndex.first + move[0], currIndex.second + move[1]);
                    if (!isValid(newIndex)) continue;
                    if (turnA && seenA[newIndex.first][newIndex.second]) continue;
                    if (!turnA && seenB[newIndex.first][newIndex.second]) continue;
                    cout << "move " << numMoves << " at turn index " << newIndex.first-300 << " , " << newIndex.second-300 << endl;
                    if (turnA && seenB[newIndex.first][newIndex.second]) return numMoves;
                    if (!turnA && seenA[newIndex.first][newIndex.second]) return numMoves;

                    if (turnA) {
                        seenA[newIndex.first][newIndex.second] = true;
                        queueA.push(newIndex);
                    } else {
                        seenB[newIndex.first][newIndex.second] = true;
                        queueB.push(newIndex);
                    }
                }
            }
            turnA = !turnA;
        }

        return -1;
    }

    static void testMe() {
        cout << minKnightMoves(4, 3) << endl;
    }
};

#endif //CPPALGORITHMS_KNIGHTMOVES_H
