//
// Created by usman on 11/4/21.
//

#ifndef CPPALGORITHMS_SUMEQUALTOTARGET_H
#define CPPALGORITHMS_SUMEQUALTOTARGET_H

#include <unordered_set>
#include <numeric>

using namespace std;
class SumEqualToTarget {
public:

    bool check_if_sum_possible(vector<long long int> & arr, bool isEmpty, int index, long long int sum) {
        if (!isEmpty && sum==0) {
            return true;
        }
        if (index == arr.size()) return false;
        return check_if_sum_possible(arr, isEmpty, index+1, sum) ||
                check_if_sum_possible(arr, false , index+1, sum-arr[index]);
    }


    bool check_if_sum_possible(vector <long long int> arr, long long int k) {
        return check_if_sum_possible(arr, true, 0, k);
    }
};

#endif //CPPALGORITHMS_SUMEQUALTOTARGET_H
