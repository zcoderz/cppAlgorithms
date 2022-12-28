//
// Created by usman on 12/28/22.
//

#ifndef CPPALGORITHMS_THEMAZETHREE_H
#define CPPALGORITHMS_THEMAZETHREE_H

#include <vector>
#include <queue>
#include <string>
#include <tuple>
#include <climits>
#include <algorithm>
#include <iostream>
using namespace std;

class TheMazeThree {
public:

    int calculateNewIndex(vector<int> move, int row, int col, vector<vector<int>>& maze, vector<bool> &seen,
                          int rows, int cols, int &newCost, int destination) {
        int i =1;
        while (true) {
            int nRow = row + move[0]*i;
            int nCol = col + move[1]*i;
            if (nRow >= 0 && nRow < rows && nCol >= 0 && nCol < cols) {
                int newIndex = nRow*cols+ nCol;
                if (newIndex==destination) return newIndex;
            }
            if (nRow < 0 || nRow == rows || nCol < 0|| nCol==cols || maze[nRow][nCol] ==1) {
                nRow = row + move[0]* (i-1);
                nCol = col + move[1]* (i-1);
                int newIndex = nRow*cols+ nCol;
                if (seen[newIndex]) return -1;
                return newIndex;
            }
            i++;
            newCost++;
        }
    }

    string findShortestWay(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        vector<vector<int>> moves = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        vector<char> paths = {'r', 'l','d','u'};
        priority_queue<tuple<int,int,string>, vector<tuple<int,int,string>>, greater<>> pQ;
        int rows = maze.size();
        int cols = maze[0].size();
        int startIndex = start[0]*cols+start[1];
        int destIndex = destination[0]*cols+destination[1];
        pQ.emplace(0, startIndex,"");
        vector<bool> seen (rows*cols);
        vector<string> possiblePaths;
        int minCost = INT_MAX;
        while (!pQ.empty()) {
            auto [cost, index, path] = pQ.top(); pQ.pop();
            if (index == destIndex && cost <= minCost) {
                possiblePaths.push_back(path);
                minCost = cost;
                continue;
            } else if (cost > minCost) {
                break;
            }
            if (seen[index]) continue;
            seen[index] = true;
            int theRow = index/cols;
            int theCol = index%cols;
            for (int i =0; i < moves.size(); i++) {
                auto & move =  moves[i];
                char dir = paths[i];
                int newCost=0;
                int newIndex = calculateNewIndex(move, theRow, theCol, maze, seen, rows, cols, newCost, destIndex);
                if (newIndex==-1) continue;
                pQ.emplace(cost+newCost, newIndex, path+dir);
            }
        }
        sort(possiblePaths.begin(), possiblePaths.end());
        return possiblePaths.empty() ? "impossible" : possiblePaths[0];
    }

    static void testMe() {
        vector<vector<int>> maze = {{0,0,0,0,0},{1,1,0,0,1},{0,0,0,0,0},{0,1,0,0,1},{0,1,0,0,0}};
        vector<int> start = {4,3};
        vector<int> dest = {0,1};
        TheMazeThree mazeC;
        string res = mazeC.findShortestWay(maze,start, dest);
        cout << res << endl;
    }

};
#endif //CPPALGORITHMS_THEMAZETHREE_H
