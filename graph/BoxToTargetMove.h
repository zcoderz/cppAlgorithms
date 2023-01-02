//
// Created by usman on 1/1/23.
//

#ifndef CPPALGORITHMS_BOXTOTARGETMOVE_H
#define CPPALGORITHMS_BOXTOTARGETMOVE_H

#include <vector>
#include <queue>
#include <unordered_set>
#include <tuple>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
using namespace std;

class BoxToTargetMove {
public:



    struct hashFunction
    {
        template <class T>
        inline void hash_combine(std::size_t& seed, const T& v) const
        {
            seed ^= std::hash<T>()(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }

        size_t operator()(const tuple<int, int,int,int> & x) const
        {
            std::size_t hash = 0;
            hash_combine(hash, get<0>(x));
            hash_combine(hash, get<1>(x));
            hash_combine(hash, get<2>(x));
            hash_combine(hash, get<3>(x));
            return hash;
        }
    };


    int minPushBox(vector<vector<char>>& grid) {
        pair<int,int> targetLoc;
        pair<int,int> startingBox;
        pair<int,int> startingPerson;
        int rows = grid.size();
        int cols = grid[0].size();
        for (int i =0; i < rows; i++) {
            for (int j =0; j < cols; j++) {
                if (grid[i][j]=='S') {
                    startingPerson = {i,j};
                } else if (grid[i][j]=='B') {
                    startingBox = {i,j};
                } else if (grid[i][j]=='T') {
                    targetLoc = {i,j};
                }
            }
        }
        unordered_set<tuple<int,int,int,int>, hashFunction> seen;
        //unordered_set<string> seen;
        vector<vector<int>> moves = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        priority_queue<tuple<int, int,int,int,int,int>, vector<tuple<int, int,int,int,int,int>>, greater<>> pQ;
        pQ.emplace(abs(startingBox.first-targetLoc.first) + abs(startingBox.second-targetLoc.second), 0,
                   startingBox.first, startingBox.second, startingPerson.first, startingPerson.second);
        while (!pQ.empty()) {
            auto [distance, steps, boxRow, boxCol, personRow, personCol] = pQ.top(); pQ.pop();
            if (boxRow==targetLoc.first && boxCol==targetLoc.second) return steps;
            tuple<int,int,int,int> index = make_tuple (boxRow, boxCol, personRow, personCol);
            //string strLoc =  to_string(boxRow) + ":" + to_string(boxCol) + "|" + to_string(personRow) + ":" + to_string(personCol);
            //if (seen.find(strLoc) != seen.end()) continue;
            //seen.insert(strLoc);
            if (seen.count(index) > 0) continue;
            seen.insert(index);
            for (auto & move: moves) {
                int nRow = personRow + move[0];
                int nCol = personCol + move[1];
                if (nRow <0 || nRow ==rows|| nCol < 0|| nCol == cols || grid[nRow][nCol]=='#') continue;
                index = make_tuple (boxRow, boxCol, nRow, nCol);
                //strLoc =  to_string(boxRow) + ":" + to_string(boxCol) + "|" + to_string(nRow) + ":" + to_string(nCol);
                //if (seen.find(strLoc) != seen.end()) continue;
                if (seen.count(index) > 0) continue;
                if (nRow == boxRow && nCol == boxCol) {
                    int nbRow = boxRow + move[0];
                    int nbCol = boxCol + move[1];
                    if (nbRow <0 || nbRow ==rows|| nbCol < 0|| nbCol == cols) continue;
                    pQ.emplace(abs(nbRow-targetLoc.first) + abs(nbCol-targetLoc.second)+steps+1,steps+1,
                               nbRow, nbCol, nRow, nCol);
                } else {
                    pQ.emplace(distance,steps, boxRow, boxCol, nRow, nCol);
                }
            }
        }
        return -1;
    }

    static void testMe() {
        int res = 20^2;
        cout << res << endl;
    }
};
#endif //CPPALGORITHMS_BOXTOTARGETMOVE_H
