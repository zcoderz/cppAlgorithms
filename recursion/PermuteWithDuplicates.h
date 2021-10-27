//
// Created by usman on 10/26/21.
//

#ifndef CPPALGORITHMS_PERMUTEWITHDUPLICATES_H
#define CPPALGORITHMS_PERMUTEWITHDUPLICATES_H

#endif //CPPALGORITHMS_PERMUTEWITHDUPLICATES_H

#include<vector>
#include <algorithm>
#include <set>
using namespace std;

class PermuteWithDuplicates {
public:

    void reverse(vector<int> & currVec, int index) {
        int right = currVec.size()-1;
        while (right > index) {
            swap(currVec[index++], currVec[right--]);
        }
    }

    bool nextPermutation(vector<int> & currVec) {
        //find first increasing sequence from right
        int index = currVec.size()-2;
        while (index >=0 && currVec[index+1] <= currVec[index]) {
            index--;
        }
        //if increasing sequence is found
        if (index >= 0) {
            int j = currVec.size()-1;

            //find first number from right thats smaller than the index
            while (currVec[index] >= currVec[j]) {
                j--;
            }
            //swap the index with the smaller value
            swap(currVec[index], currVec[j]);
            //reverse items on right of the index
            reverse(currVec, index+1);
            return true;
        }
        return false;
    }
    /**
     * iterative logic for permutation is :
     *  1. Sort
     *  2. Right to left, find first increasing sequence
     *  3. From right, find first item  greater than current index
     *  4. Swap current index with one greater than the current
     *  5. Reverse items on right of current
     * @param currVec
     * @param res
     */
    vector<vector<int>> permuteIterative(vector<int> & currVec) {
        vector<vector<int>> res;
        sort(currVec.begin(), currVec.end());
        do {
            res.push_back(currVec);
        } while (nextPermutation(currVec));
        return res;
    }


    set<vector<int>> processedPrefixes;
    void permute(int index, int size, vector<int> & currVec, vector<vector<int>> & res) {
        if (index == size) {
            res.push_back(currVec);
            return;
        }

        for (int i =index; i < size; i++) {
            if (i == index || currVec[i] != currVec[i-1]) {
                swap(currVec[i], currVec[index]);
                if (processedPrefixes.find(currVec) == processedPrefixes.end()) {
                    permute(index + 1, size, currVec, res);
                    processedPrefixes.insert(currVec);
                }
                swap(currVec[i], currVec[index]);
            }
        }
    }

    vector<vector<int> > get_permutations(vector<int> arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        permuteWithoutSet(0, arr.size(), arr, res);
        return res;
    }

    /**
     * extremely smart method because of its simplicity
     * @param index
     * @param size
     * @param currVec
     * @param res
     */
    void permuteWithoutSet(int index, int size, vector<int> & currVec, vector<vector<int>> & res) {
        if (index == size) {
            res.push_back(currVec);
            return;
        }

        for (int i =index; i < size; i++) {
            if (i == index || currVec[i] != currVec[index]) {
                swap(currVec[i], currVec[index]);
                permute(index + 1, size, currVec, res);
            }
        }
    }

};