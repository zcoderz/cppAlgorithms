//
// Created by usman on 10/19/21.
//

#ifndef KICK_START_ONLINEMEDIAN_H
#define KICK_START_ONLINEMEDIAN_H

#include <algorithm>

using namespace std;

class OnlineMedian {

public:
    vector<int> online_median(vector<int> stream) {
        priority_queue<int , vector<int> , greater<int>> minHeap; //smallest item on top
        priority_queue<int> maxHeap; //largest element on top
        vector<int> result;
        result.reserve(stream.size());

        for (int val : stream) {
            //always add to max Heap because it will sort the data in increasing order
            maxHeap.push(val);
            //pick maximum value from max heap and put in min heap
            minHeap.push(maxHeap.top());
            maxHeap.pop();


            //mentally think of it as LEFT ORDERED BLOCK (max heap increasing order) & RIGHT ORDERED BLOCK (min heap decreasing order)
            //when size differ need to move balance in favor of max heap
            if (minHeap.size() > maxHeap.size()) {
                //this is important. it's possible that previously a large value went into minheap
                //which is now on top and needs to be moved back into max heap
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }

            if (maxHeap.size() > minHeap.size()) {
                result.push_back(maxHeap.top());
            }  else {
                int median = (minHeap.top() + maxHeap.top()) / 2;
                result.push_back(median);
            }
        }

        return result;
    }

    vector<int> online_median_sort(vector<int> stream) {
        vector<int> data;
        data.reserve(stream.size());
        vector<int> result;
        result.reserve(stream.size());
        for (int val : stream) {
            //lower_bound on vector runs a binary search!
            auto iter = lower_bound(data.begin(), data.end(), val);
            data.insert(iter, val);
            int sz = data.size();
            int mid = sz / 2;
            int median;
            if (sz % 2 == 0) {
                median = (data[mid] + data[mid-1]) / 2;
            } else {
                median = data[mid];
            }
            result.push_back(median);
        }
        return result;
    }
};

#endif //KICK_START_ONLINEMEDIAN_H