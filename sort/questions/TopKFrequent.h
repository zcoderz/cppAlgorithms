//
// Created by usman on 10/19/21.
//

#ifndef KICK_START_TOPKFREQUENT_H
#define KICK_START_TOPKFREQUENT_H

#endif //KICK_START_TOPKFREQUENT_H

#include <unordered_map>
#include <vector>

using namespace std;

/**
 * Quick Select problem.
 */

class TopKFrequent {

    /**
     * in two way quick select, you are moving vals smaller vals on left
     * you are comparing against an item that you move to right
     * at end you swap right with current left index
     * @param vecFrequencies
     * @param left
     * @param right
     * @return
     */
    int partition(vector<pair<int, int>> & vecFrequencies , int left, int right) {
        int mid = left + (right-left) / 2;
        //put item on right
        swap(vecFrequencies[right], vecFrequencies[mid]);
        int freqComp = vecFrequencies[right].second;
        for (int j = left; j <= right; j++) {
            if (vecFrequencies[j].second < freqComp) {
                //move smaller items to left
                swap(vecFrequencies[j], vecFrequencies[left++]);
            }
        }
        //swap right with left , left is current index
        swap(vecFrequencies[right], vecFrequencies[left]);
        return left;
    }

    void quickSelect(vector<pair<int, int>> & vecFrequencies, int left, int right, int k) {
        if (left >= right) {
            return;
        }
        int partitionIndex = partition(vecFrequencies , left, right);
        if (partitionIndex == k) {
            return;
        } else if (partitionIndex > k) {
            quickSelect(vecFrequencies, left, partitionIndex-1, k);
        } else {
            quickSelect(vecFrequencies, partitionIndex+1, right, k);
        }
    }

    /**
     * 3 way partition. handles duplicates.
     * @param vecFrequencies
     * @param left
     * @param right
     * @param targetIndex
     */
    void partition(vector<pair<int, int>> & vecFrequencies , int left, int right, int targetIndex) {
        if (left >= right) {
            return ;
        }
        int origLeft = left;
        int origRight = right;
        int partitionIndex = left + (right-left) /2;
        swap(vecFrequencies[left],vecFrequencies[partitionIndex]);
        int pivotVal = vecFrequencies[left].second;
        int i = left + 1;
        while (i <= right) {
            if (vecFrequencies[i].second < pivotVal) {
                //if item is smaller, swap with left and move current and left forward
                swap(vecFrequencies[i++], vecFrequencies[left++]);
            } else if (vecFrequencies[i].second > pivotVal) {
                //move right left but keep index i at current location if item is greater
                swap(vecFrequencies[i], vecFrequencies[right--]);
            } else {
                //if same move current index forward
                i++;
            }
        }
        //look at right or left partitions if item is greater or smaller.
        //if index is in mid (not left, not right) return
        if (targetIndex < left) {
            partition(vecFrequencies, origLeft, left-1, targetIndex);
        } else if (targetIndex > right) {
            partition(vecFrequencies, right+1, origRight, targetIndex);
        }
    }

public:
    vector<int> find_top_k_frequent_elements(vector<int> arr, int k) {
        unordered_map<int, int> map;
        for (int i=0; i < arr.size(); i++) {
            auto iter = map.find(arr[i]);
            if (iter == map.end()) {
                map.insert(make_pair(arr[i], 1));
            } else {
                iter->second++;
            }
        }
        vector<pair<int, int>> vecFrequencies;
        copy(map.begin(), map.end(), back_inserter(vecFrequencies));
        int topIndex = vecFrequencies.size()-k;
        //quickSelect(vecFrequencies, 0, vecFrequencies.size()-1, topIndex);
        partition(vecFrequencies, 0, vecFrequencies.size()-1, topIndex);
        vector<int> theVec;
        theVec.reserve(k);

        for (int i=vecFrequencies.size()-1; i >= topIndex; i--) {
            theVec.push_back(vecFrequencies[i].first);
        }
        return theVec;
    }

};