//
// Created by usman on 1/16/23.
//

#ifndef CPPALGORITHMS_SEARCHINSORTEDARRAYOFUNKNOWNSIZE_H
#define CPPALGORITHMS_SEARCHINSORTEDARRAYOFUNKNOWNSIZE_H

#include <cmath>
#include <climits>

class SortedSearchInArray {
    class ArrayReader {
           public:
             int get(int index) const;
    };

    int search(const ArrayReader & reader, int target) {
        int left = 0; int right = 1;
        while (right > left) {
            int mid = left + (right-left) / 2;
            int val = reader.get(mid);
            if (val > target) {
                right=mid;
            } else if (val < target) {
                left = mid+1;
            } else {
                return mid;
            }
        }
        return reader.get(left) == target ? left : -1;
    }
};

#endif //CPPALGORITHMS_SEARCHINSORTEDARRAYOFUNKNOWNSIZE_H
