//
// Created by usman on 10/26/21.
//

#ifndef CPPALGORITHMS_RUNPERMUTATIONS_H
#define CPPALGORITHMS_RUNPERMUTATIONS_H

#include <vector>

using namespace std;

class RunPermutations {
public:
    vector<vector<int> > get_permutations(vector<int> arr) {
        vector<vector<int>> allPerms;
        runPermutations(arr, 0, allPerms, arr.size());
        return allPerms;
    }

    void runPermutations(vector<int> & arr, int processIndex, vector<vector<int>> & allPerms, int size) {
        if (processIndex == size-1) {
            allPerms.push_back(arr);
            return;
        }
        for (int j =processIndex; j <= size-1; j++) {
            swap(arr[processIndex], arr[j]);
            runPermutations(arr, processIndex+1, allPerms,size);
            swap(arr[processIndex], arr[j]);
        }
    }

};
#endif //CPPALGORITHMS_RUNPERMUTATIONS_H