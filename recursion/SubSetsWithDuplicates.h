//
// Created by usman on 10/27/21.
//

#ifndef CPPALGORITHMS_SUBSETSWITHDUPLICATES_H
#define CPPALGORITHMS_SUBSETSWITHDUPLICATES_H

#endif //CPPALGORITHMS_SUBSETSWITHDUPLICATES_H

#include <vector>
#include <algorithm>
using namespace std;

class SubSetsWithDuplicates {
public:
    vector<string> get_distinct_subsets(string str) {
        vector<string> subSets;
        sort(str.begin(), str.end());
        string strEmpty;
        processSubsets(strEmpty, 0, str, subSets);
        return subSets;
    }

    void processSubsets(string &strSoFar, int index, string & origString, vector<string> & subSets) {
        subSets.push_back(strSoFar);
        if (index == origString.size()) {
            return;
        }
        for (int i = index; i < origString.size(); i++) {
            if (i != index && origString[i] == origString[i-1]) continue;
            strSoFar.push_back(origString[i]);
            processSubsets(strSoFar, i+1, origString, subSets);
            strSoFar.pop_back();
        }
    }
};