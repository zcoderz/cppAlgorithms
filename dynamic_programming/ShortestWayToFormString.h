//
// Created by usman on 10/27/22.
//

#ifndef CPPALGORITHMS_SHORTESTWAYTOFORMSTRING_H
#define CPPALGORITHMS_SHORTESTWAYTOFORMSTRING_H

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

class ShortestWayToFormString {
public:
    static int shortestWay(string source, string target) {
        unordered_map<char,vector<int>> charMap;
        for (int i =0; i < source.length(); i++) {
            charMap[source[i]].push_back(i);
        }
        int rounds = 1;
        int sourceIndex = -1;
        for (int i =0; i < target.length(); i++) {
            char ch = target[i];
            auto iter = charMap.find(ch);
            if (iter == charMap.end()) return -1;
            auto &vec = iter->second;
            auto iterVec = upper_bound(vec.begin(), vec.end(), sourceIndex);
            if (iterVec == vec.end()) {
                sourceIndex = -1;
                rounds++;
                i--; //didnt find it, next iteration will move forward. move i back
            } else {
                sourceIndex = *iterVec;
                if (sourceIndex==source.length()-1) {
                    sourceIndex=-1;
                    if (i < target.length()-1) rounds++; //reached end of source string but target has more
                }
            }
        }
        return rounds;
    }

    static void testMe() {
        int res = shortestWay("adbsc", "addddddddddddsbc");
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_SHORTESTWAYTOFORMSTRING_H
