//
// Created by usman on 10/18/21.
//

#ifndef KICK_START_MERGEVECTORS_H
#define KICK_START_MERGEVECTORS_H

#endif //KICK_START_MERGEVECTORS_H
#include <vector>
using namespace std;

class MergeVectors {
public:
    void merger_first_into_second(vector<int>& arr1, vector<int>& arr2) {
        auto reverseIter = arr2.end()-1;
        while (!arr2.empty() && *reverseIter == 0) {
            reverseIter = arr2.erase(reverseIter);
            reverseIter--;
        }

        auto  iterFirst = arr1.begin();
        auto  iterSecond = arr2.begin();
        while (iterFirst != arr1.end()) {
            if (iterSecond == arr2.end()) {
                iterSecond = arr2.insert(iterSecond, *iterFirst);
                iterFirst++; iterSecond++;
            } else {
                if (*iterSecond < *iterFirst) {
                    iterSecond++;
                } else {
                    iterSecond = arr2.insert(iterSecond, *iterFirst);
                    iterFirst++; iterSecond++;
                }
            }
        }
    }
};