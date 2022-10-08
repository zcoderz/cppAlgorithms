//
// Created by usman on 10/6/22.
//

#ifndef CPPALGORITHMS_OPENLOCKS_H
#define CPPALGORITHMS_OPENLOCKS_H
#include <iostream>

#include <vector>
#include <queue>
#include <string>
#include <unordered_set>
using namespace std;

class OpenLocks {
public:
    inline static string moveLockForward(string &strStartVal, int index, bool fwdMove) {
        char digit = strStartVal[index];
        int iDigit =  digit - '0';
        iDigit = fwdMove ?  (iDigit+1) % 10 : (iDigit-1) % 10;
        iDigit = iDigit == -1 ? 9: iDigit;
        char aChar = '0' + iDigit;
        return strStartVal.substr(0, index) + aChar + strStartVal.substr(index+1);
    }

    static int openLock(vector<string>& deadends, string target) {
        unordered_set<string> setDeadends(deadends.begin(), deadends.end());
        if (setDeadends.find("0000") != setDeadends.end()) return -1;
        if (target == "0000") return 0;
        queue<string> queueA; queueA.push("0000");
        queue<string> queueB; queueB.push(target);
        unordered_set<string> visitedA; visitedA.insert("0000");
        unordered_set<string> visitedB; visitedB.insert(target);
        bool turnA = true;
        int numTurns = 0;
        while (!queueA.empty() && !queueB.empty()) {
            int iSize = turnA ? queueA.size() : queueB.size();
            if (iSize ==0) continue;
            numTurns++;
            for (int i =0; i < iSize; i++) {
                string strVal = turnA ? queueA.front() : queueB.front();
                turnA ? queueA.pop() : queueB.pop();
                for (int j =0; j < 4; j++) {
                    bool  fwdMove = true;
                    for (int k =0; k < 2; k++) {
                        string strNewVal = moveLockForward(strVal, j, fwdMove);
                        fwdMove = !fwdMove;
                        //already processed
                        if (turnA && visitedA.find(strNewVal) != visitedA.end() ||
                            !turnA && visitedB.find(strNewVal) != visitedB.end())
                            continue;
                        //ignore deadends
                        if (setDeadends.find(strNewVal) != setDeadends.end()) continue;
                        //found on other side --> we are done.
                        if ((turnA && visitedB.find(strNewVal) != visitedB.end() ||
                             !turnA && visitedA.find(strNewVal) != visitedA.end()))
                            return numTurns;
                        //add next lock on queue
                        turnA ? queueA.push(strNewVal) : queueB.push(strNewVal);
                        turnA ? visitedA.insert(strNewVal) : visitedB.insert(strNewVal);
                    }
                }
            }
            turnA = !turnA;
        }
        return -1;
    }

    static void testMe() {
        vector<string> deadends = {"8888"};
        string target = "0009";
        int turns = openLock(deadends, target);
        cout << turns << endl;
    }
};


#endif //CPPALGORITHMS_OPENLOCKS_H
