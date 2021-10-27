//
// Created by usman on 10/19/21.
//

#ifndef KICK_START_KTHLARGESTINSTREAM_H
#define KICK_START_KTHLARGESTINSTREAM_H

#include <vector>
#include <queue>
#include <set>
using namespace std;


class KthLargestInStream {
public:
    // Complete the function below.
    vector<int> kth_largest(int k, vector<int> initial_stream, vector<int> append_stream) {
        priority_queue<int , vector<int> , greater<int>> pQ;
        for (int val : initial_stream) {
            pQ.push(val);
            if (pQ.size() > k) {
                pQ.pop();
            }
        }

        std::vector<int> res;
        for (int val : append_stream) {
            if (pQ.size() >=k) {
                //running the below check is only necessary if we already have K elements in PQ
                if (val > pQ.top()) {
                    pQ.push(val);
                }
            } else {
                pQ.push(val);
            }

            if (pQ.size() > k) {
                pQ.pop();
            }
            res.push_back(pQ.top());
        }
        return res;
    }


    vector<int> kth_largest_set(int k, vector<int> initial_stream, vector<int> append_stream) {
        //priority_queue<int , vector<int> , less<int>> pQ;
        multiset<int, greater<>> set;

        for (int val : initial_stream) {
            set.insert(val);
            if (set.size() > k) {
                set.erase(*set.rbegin());
            }
        }

        for (int i : set) {
            cerr << i << ",";
        }

        std::vector<int> res;

        for (int val : append_stream) {
            set.insert(val);
            if (set.size() > k) {
                set.erase(--set.end());
            }
            res.push_back(*set.rbegin());
        }

        return res;
    }

};
#endif //KICK_START_KTHLARGESTINSTREAM_H