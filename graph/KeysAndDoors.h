//
// Created by usman on 11/14/21.
//

#ifndef CPPALGORITHMS_KEYSANDDOORS_H
#define CPPALGORITHMS_KEYSANDDOORS_H
#include <vector>
#include <set>
#include <queue>
using namespace std;

struct Point{

    void moveToLoc(int x, int y, uint16_t keyP) {
        path.push_back({x,y});
        key = keyP;
    }
    //contains set of coordinates the point has visited in path
    vector<vector<int>> path;
    //contains the current set of keys so far accumulated along the path
    uint16_t key;
};


class KeysAndDoors{
public:
    vector <vector<int>> find_shortest_path(vector<string> grid) {
        vector<vector<int>> moves = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        uint32_t rows = grid.size();
        uint32_t cols = grid[0].size();
        //for each cell in grid use a set to determine the set of keys that have visited the cell so far
        //this is done so that we can avoid revisiting the cell with same keys
        vector<vector<set<uint16_t>>> visitedKeys (rows, vector<set<uint16_t>>(cols));
        int row=0;
        int col=0;
        for (; row < rows; row++) {
            bool startPosFound = false;
            for (col=0; col < cols; col++) {
                if (grid[row][col]=='@') {
                    startPosFound = true;
                    break;
                }
            }
            if (startPosFound) break;
        }
        Point start;
        start.moveToLoc(row, col, 0);
        queue<Point> theQueue;
        theQueue.push(move(start));
        visitedKeys[row][col].insert(0);
        while (!theQueue.empty()) {
            Point thePoint = move(theQueue.front()); theQueue.pop();
            int xOrig = thePoint.path.back()[0];
            int yOrig = thePoint.path.back()[1];
            for (vector<int> & possibleMove: moves) {
                int newX = xOrig + possibleMove[0];
                int newY = yOrig + possibleMove[1];
                if (newX <0 || newX == rows || newY < 0 || newY == cols || grid[newX][newY] == '#') {
                    continue;
                }

                if (grid[newX][newY] == '+') {
                    thePoint.moveToLoc(newX, newY, 0);
                    return thePoint.path;
                }
                uint16_t newKey = thePoint.key;
                if (grid[newX][newY] >= 'a' && grid[newX][newY] <= 'j') {
                    //add key provided to the key bit mask
                    newKey |=  (1 << (grid[newX][newY]-'a'));
                }

                if (grid[newX][newY] >= 'A' && grid[newX][newY] <= 'J') {
                    //don't have key to enter cell
                    if ((newKey & (1 << (grid[newX][newY] - 'A'))) == 0) {
                        continue;
                    }
                }

                //check if cell was already visited, if so skip!
                bool insertMove = true;
                set<uint16_t> & cellKeys = visitedKeys[newX][newY];

                for (auto iter = begin(cellKeys) ; iter != end(cellKeys);) {
                    //means this key in the set is either a direct match or a super set of current newKey
                    uint16_t val = *iter & newKey;
                    if (val == newKey) {
                        //the move has already been processed
                        insertMove = false;
                        break;
                    }
                    ++iter;
                }

                if (insertMove) {
                    cellKeys.insert(newKey);
                    Point copy = thePoint;
                    copy.moveToLoc(newX, newY, newKey);
                    theQueue.emplace(move(copy));
                }
            }
        }

        return {};
    }
};

#endif //CPPALGORITHMS_KEYSANDDOORS_H
