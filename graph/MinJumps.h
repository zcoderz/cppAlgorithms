//
// Created by usman on 1/1/23.
//

#ifndef CPPALGORITHMS_MINJUMPS_H
#define CPPALGORITHMS_MINJUMPS_H

#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
using namespace std;
class MinJumps {
public:

    /**
     * bi directional search!!
     * @param arr
     * @return
     */
    static int minJumps(vector<int>& arr) {
        if (arr.size() <=1 ) return 0;
        vector<bool> seen(arr.size());
        unordered_map<int, vector<int>> valIndices;
        for (int i =0; i < arr.size(); i++) {
            valIndices[arr[i]].push_back(i);
        }
        unordered_set<int> currSet;
        currSet.insert(0);
        seen[0] = true;
        unordered_set<int> otherSet;
        otherSet.insert(arr.size()-1);
        seen[arr.size()-1] = true;
        int steps = 0;
        while (!currSet.empty()) {
            if (currSet.size() > otherSet.size())
                swap(currSet, otherSet);
            unordered_set<int> newSet;
            for (auto index: currSet) {
                if (otherSet.count(index-1)) return steps+1;
                if (otherSet.count(index+1)) return steps+1;

                if (index > 0 && !seen[index-1]) {
                    newSet.insert(index-1);
                    seen[index-1] = true;
                }
                if (index < arr.size()-1 && !seen[index+1]) {
                    newSet.insert(index+1);
                    seen[index+1] = true;
                }
                for (int mappedIndex : valIndices[arr[index]]) {
                    if (otherSet.count(mappedIndex)) return steps+1;
                    if (seen[mappedIndex]) continue;
                    newSet.insert(mappedIndex);
                    seen[mappedIndex] = true;
                }
                valIndices.erase(arr[index]); //prevent redundant searches
            }
            swap(currSet, newSet);
            steps++;
        }
        return -1;
    }

    static int minJumpsSingleDir(vector<int>& arr) {
        int len = arr.size()-1;
        vector<bool> seen(len+1);
        unordered_map<int, vector<int>> valIndices;
        for (int i =0; i < arr.size(); i++) {
            valIndices[arr[i]].push_back(i);
        }
        queue<int> theQ;
        theQ.push(0);
        seen[0] = true;
        int steps = 0;
        while (!theQ.empty()) {
            queue<int> newQueue;
            while (!theQ.empty()) {
                int index = theQ.front(); theQ.pop();
                if (index==len) return steps;
                if (index > 0 && !seen[index-1]) {
                    newQueue.push(index-1);
                    seen[index-1] = true;
                }
                if (index < len && !seen[index+1]) {
                    newQueue.push(index+1);
                    seen[index+1] = true;
                }
                for (int mappedIndex : valIndices[arr[index]]) {
                    if (seen[mappedIndex]) continue;
                    newQueue.push(mappedIndex);
                    seen[mappedIndex] = true;
                }
                valIndices.erase(arr[index]); //prevent redundant searches
            }
            swap(theQ, newQueue);
            steps++;
        }
        return -1;
    }

    static void testMe() {
        vector<int> vals = {404,-23,-23,404,100,23,23,23,3,404};
        int res = minJumps(vals);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_MINJUMPS_H
