//
// Created by usman on 10/9/22.
//

#ifndef CPPALGORITHMS_WATERANDJUGPROBLEM_H
#define CPPALGORITHMS_WATERANDJUGPROBLEM_H
#include <unordered_set>
#include <queue>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;
class WaterAndJugProblem {
public:

    static bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        int total = jug1Capacity + jug2Capacity;
        vector<int> visited (total+1, 0);
        queue<int> theQueue;
        theQueue.push(0); visited[0] = 1;
        vector<int> moves = {jug1Capacity, -jug1Capacity, jug2Capacity, -jug2Capacity};
        while (!theQueue.empty()) {
            int val = theQueue.front(); theQueue.pop();
            cout << "processing " << val << endl;
            if (val == targetCapacity) return true;

            for (int i =0; i < 4; i++) {
                int newVal = val + moves[i];
                if (newVal < 0 || newVal > total || visited[newVal] == 1) continue;
                visited[newVal] = true;
                theQueue.push(newVal);
            }
        }
        return false;
    }

    static void moveFromJugOneToTwo(int &jugOne, int &jugTwo, int jugTwoCapacity) {
        int jugOneOrig = jugOne;
        jugOne -= min(jugOne, jugTwoCapacity-jugTwo);
        jugTwo +=  jugOneOrig -jugOne;
    }

    static string makestring(int a, int b) {
        ostringstream  stream;
        stream << a << "," << b;
        return stream.str();
    }

    static bool canMeasureWaterSlow(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        unordered_set<string> visited;
        queue<pair<int,int>> theQueue;
        theQueue.emplace(0,0); visited.insert("0,0");

        while (!theQueue.empty()) {
            auto [jug1, jug2] = theQueue.front(); theQueue.pop();
            //cout << "got jug1 " << jug1 << " , jug2 " << jug2 << endl;
            if (jug1+jug2 == targetCapacity) {
                return true;
            }

            int newJug1 = jug1, newJug2 = jug2;
            moveFromJugOneToTwo(newJug1, newJug2, jug2Capacity);
            auto val = makestring(newJug1, newJug2);
            if (visited.find(val) == visited.end()) {
                visited.insert(val);
                theQueue.emplace(newJug1, newJug2);
            }
            newJug1 = jug1, newJug2 = jug2;
            moveFromJugOneToTwo(newJug2, newJug1, jug1Capacity);
            val = makestring(newJug1, newJug2);
            if (visited.find(val) == visited.end()) {
                visited.insert(val);
                theQueue.emplace(newJug1, newJug2);
            }
            newJug1 = jug1, newJug2 = jug2Capacity;
            val = makestring(newJug1, newJug2);
            if (visited.find(val) == visited.end()) {
                visited.insert(val);
                theQueue.emplace(newJug1, newJug2);
            }
            newJug1 = jug1Capacity, newJug2 = jug2;
            val = makestring(newJug1, newJug2);
            if (visited.find(val) == visited.end()) {
                visited.insert(val);
                theQueue.emplace(newJug1, newJug2);
            }
            newJug1 = 0, newJug2 = jug2;
            val = makestring(newJug1, newJug2);
            if (visited.find(val) == visited.end()) {
                visited.insert(val);
                theQueue.emplace(newJug1, newJug2);
            }
            newJug1 = jug1, newJug2 = 0;
            val = makestring(newJug1, newJug2);
            if (visited.find(val) == visited.end()) {
                visited.insert(val);
                theQueue.emplace(newJug1, newJug2);
            }
        }

        return false;
    }

    static void testMe() {
        bool res =  canMeasureWater(3, 5, 4);
        cout << res << endl;

    }
};
#endif //CPPALGORITHMS_WATERANDJUGPROBLEM_H
