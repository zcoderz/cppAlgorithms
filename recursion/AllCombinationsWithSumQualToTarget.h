//
// Created by usman on 10/26/21.
//

#ifndef CPPALGORITHMS_ALLCOMBINATIONSWITHSUMQUALTOTARGET_H
#define CPPALGORITHMS_ALLCOMBINATIONSWITHSUMQUALTOTARGET_H

#endif //CPPALGORITHMS_ALLCOMBINATIONSWITHSUMQUALTOTARGET_H

#include <vector>
#include <set>
using namespace std;

class SumEqualToTarget {
public:
    vector<vector<int>> generate_all_combinations(vector<int> arr, int target) {
        vector<vector<int>> res;
        vector<int> currentCombination;
        sort(arr.begin(), arr.end());
        processSum(arr, target, 0, 0, res, currentCombination);
        return res;
    }

    /**
     * very elegant solution! if duplicate dont process in loop (recursion will correctly handle the inclusion once)
     * back track for index to handle case where index is excluded
     * @param arr
     * @param target
     * @param index
     * @param soFar
     * @param combVec
     * @param currentCombination
     */
    void processSum(vector<int> & arr, int target,  int index, int soFar, vector<vector<int>> & combVec, vector<int> & currentCombination) {
        if (soFar == target) {
            combVec.push_back(currentCombination);
            return;
        } else if (soFar > target || index ==  arr.size()) {
            return;
        }

        for (int i =index ; i < arr.size(); i++) {
            if (i > index && arr[i-1] == arr[i]) continue;
            currentCombination.push_back(arr[i]);
            processSum(arr, target, i+1, soFar+arr[i], combVec, currentCombination);
            currentCombination.pop_back();
        }
    }

    void processSumWithCt(vector<int> & arr, int target,  int index, int soFar, vector<vector<int>> & combVec, vector<int> & currentCombination) {
        if (soFar == target) {
            combVec.push_back(currentCombination);
            return;
        } else if (soFar > target || index == arr.size()) {
            return;
        }

        int currentVal = arr[index];
        int nextDiffIndex = 1;
        while (index + nextDiffIndex < arr.size() && arr[index+nextDiffIndex] == currentVal) {
            nextDiffIndex++;
        }

        int ct=0 ;
        while (ct < nextDiffIndex) {
            currentCombination.push_back(currentVal);
            processSum(arr, target, index+ nextDiffIndex, soFar + currentVal * (ct+1), combVec, currentCombination);
            ct++;
        }

        currentCombination.erase(currentCombination.end()-ct, currentCombination.end());
        processSum(arr, target, index+ct, soFar , combVec, currentCombination);
    }

    void processSumAvoidDupsViaSet(vector<int> & arr, int target,  int index, int soFar, set<vector<int>> & combSet, vector<int> & currentCombination) {
        if (soFar == target) {
            if (combSet.find(currentCombination) == combSet.end()) {
                combSet.insert(currentCombination);
            }
            return;
        } else if (soFar > target || index == arr.size()) {
            return;
        }

        processSumAvoidDupsViaSet(arr, target,   index+1, soFar, combSet, currentCombination);
        currentCombination.push_back(arr[index]);
        processSumAvoidDupsViaSet(arr, target,   index+1, soFar+arr[index], combSet, currentCombination);
        currentCombination.pop_back();
    }

};