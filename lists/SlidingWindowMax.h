//
// Created by usman on 9/18/22.
//

#ifndef CPPALGORITHMS_SLIDINGWINDOWMAX_H
#define CPPALGORITHMS_SLIDINGWINDOWMAX_H

#include <vector>
#include <limits>
#include <set>
#include <deque>
using namespace std;

class SlidingWindowMax {
public:

    static vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> res(len-k+1);
        deque<int> indexes;
        for (int i =0; i < len; i++) {
            //the clever idea here is that every time when you iterate on a new number
            //you ensure that the deque has only numbers greater than current number in it.
            while (!indexes.empty() && nums[indexes.back()] < nums[i]) {
                indexes.pop_back();
            }
            //add current number to dequeue
            indexes.push_back(i);
            if (i >= k-1) {
                if (indexes.front() <= i-k) {
                    //due to sliding window, remove head of deque if needed
                    indexes.pop_front();
                }
                //push the highest number on to the result
                res[i-k+1] = nums[indexes.front()];
            }
        }
        return res;
    }

    static vector<int> maxSlidingWindowSet(vector<int>& nums, int k) {
        vector<int> res;
        multiset<int, std::greater<>> data; //for descending order
        int i =0;
        for ( ; i < k; i++) {
            data.insert(nums[i]);
        }
        res.push_back(*data.begin());
        for (; i < nums.size(); i++) {
            int prior = nums[i-k];
            data.erase(data.find(prior));
            data.insert(nums[i]);
            res.push_back(*data.begin());
        }
        return res;
    }
};

#endif //CPPALGORITHMS_SLIDINGWINDOWMAX_H
