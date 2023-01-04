//
// Created by usman on 1/3/23.
//

#ifndef CPPALGORITHMS_SHORTESTPATHTOGETALLKEYS_H
#define CPPALGORITHMS_SHORTESTPATHTOGETALLKEYS_H

#include <vector>
#include <bitset>
#include <string>
#include <queue>
#include <tuple>
#include <iostream>
#include <unordered_set>
using namespace std;

class ShortestPathToGetAllKeys {
public:
    static int shortestPathAllKeys(vector<string>& grid) {
        pair<int,int> startingCoordinate;
        int numKeys = 0;
        int rows = grid.size();
        int cols = grid[0].length();
        for (int i =0; i < rows; i++) {
            for (int j=0; j < cols; j++) {
                if (grid[i][j] == '@')
                    startingCoordinate = {i,j};
                if (grid[i][j] >= 'a' && grid[i][j] <= 'z')
                    numKeys++;
            }
        }
        vector<vector<int>> moves = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        vector<vector<unordered_set<ulong>>> visited(rows, vector<unordered_set<ulong>> (cols));
        //moves, keys, coordinate
        queue<tuple<int,bitset<27>,int>> theQ;
        bitset<27> emptyBits; emptyBits.set(0);

        theQ.emplace(0, emptyBits, startingCoordinate.first*cols + startingCoordinate.second);
        while (!theQ.empty()) {
            auto [numMoves, keyset, coordinate] = theQ.front(); theQ.pop();
            int cRow = coordinate/cols;
            int cCol = coordinate % cols;
            char ch = grid[cRow][cCol];
            if (ch >= 'a' && ch <= 'z') {
                int key= ch-'a'+1;
                keyset.set(key);
                if (keyset.count() == numKeys+1)
                    return numMoves;
            }
            for (auto & move: moves) {
                int nRow = cRow + move[0];
                int nCol = cCol + move[1];
                if (nRow <0 || nRow == rows || nCol < 0 || nCol == cols || grid[nRow][nCol] == '#') continue;
                char gChar = grid[nRow][nCol];
                //check can visit (have key)
                if (gChar >= 'A' && gChar <= 'Z') {
                    int theIndex = gChar-'A'+1;
                    if (!keyset.test(theIndex)) continue; //don't have key
                }
                //check already visited
                unordered_set<ulong> & cellVisit = visited[nRow][nCol];
                ulong ulCurrentKey = keyset.to_ulong();
                bool cVisited = false;
                for ( auto & vKey : cellVisit) {
                    if ((ulCurrentKey & vKey) == ulCurrentKey) {
                        cVisited = true;
                        break;
                    }
                }
                if (cVisited) continue;
                //need to check that the group of keys has been visited.
                //independently same keys might have toughed the cell but that doesn't matter
                cellVisit.insert(ulCurrentKey);
                theQ.emplace(numMoves+1, keyset, nRow*cols + nCol);
            }
        }
        return -1;
    }

    static void testMe() {
        vector<string> vec = {".#.b.","A.#aB","#d...","@.cC.","D...#"};
        int res = shortestPathAllKeys(vec);
        cout << res;
    }
};

#endif //CPPALGORITHMS_SHORTESTPATHTOGETALLKEYS_H
