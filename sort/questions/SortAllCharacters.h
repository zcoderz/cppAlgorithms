//
// Created by usman on 10/22/21.
//

#ifndef CPPALGORITHMS_SORTALLCHARACTERS_H
#define CPPALGORITHMS_SORTALLCHARACTERS_H

class SortAllCharacters {
public:
    int partition(vector<char> arr, int left, int right) {
        int origLeft = left;
        int origRight = right;
        int mid = left + (right-left) /2 ;
        swap(arr[left], arr[mid]);
        int pivotVal = arr[left++];

        while (right >= left) {
            while (left < origRight &&  arr[left] < pivotVal) left++;
            while (origLeft < right && arr[right] > pivotVal) right--;
            if (left >= right) break;
            swap(arr[left++], arr[right--]);
        }
        swap(arr[origLeft], arr[right]);
        return right;
    }

    void sort(vector<char> arr, int left, int right) {
        if (left >= right) return;
        int pivot = partition(arr, left, right);
        sort(arr, left, pivot-1);
        sort(arr, pivot+1, right);
    }


    vector<char> sort_array(vector<char> arr) {
        sort(arr, 0, arr.size()-1);
        return arr;
    }



};
#endif //CPPALGORITHMS_SORTALLCHARACTERS_H