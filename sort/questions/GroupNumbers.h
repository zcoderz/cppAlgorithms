//
// Created by usman on 10/18/21.
//

#ifndef KICK_START_GROUPNUMBERS_H
#define KICK_START_GROUPNUMBERS_H

#include <vector>
using namespace std;

class GroupNumbers {
public:
    vector <int> solve(vector <int> arr) {
        int left = 0;
        int right = arr.size()-1;
        while (left < right) {
            while (arr[left] % 2 ==0) {
                left++;
            }
            while(arr[right] %2 ==1) {
                right--;
            }
            if (left > right) break;
            swap(arr[left++], arr[right--]);
        }
        return arr;
    }
};

#endif //KICK_START_GROUPNUMBERS_H