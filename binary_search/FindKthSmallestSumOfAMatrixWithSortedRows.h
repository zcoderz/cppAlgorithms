//
// Created by usman on 1/21/23.
//

#ifndef CPPALGORITHMS_FINDKTHSMALLESTSUMOFAMATRIXWITHSORTEDROWS_H
#define CPPALGORITHMS_FINDKTHSMALLESTSUMOFAMATRIXWITHSORTEDROWS_H

#include <vector>
#include <queue>
using namespace std;

class KthSmallestSumOfAMatrixWithSortedRows {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        //larger values , keep on top of queue
        //default PQ implementation also is less<>
        priority_queue<int, vector<int>, less<>> pQ; pQ.push(0);
        for (auto & row: mat) {
            priority_queue<int, vector<int>, less<>> newQ;
            while (!pQ.empty()) {
                int pQVal = pQ.top(); pQ.pop();
                for (int val : row) {
                    int nVal = pQVal + val;
                    if (newQ.size() >= k && nVal > newQ.top()) continue;
                    newQ.push(nVal);
                    if (newQ.size() > k) newQ.pop();
                }
            }
            swap(newQ, pQ);
        }
        return pQ.top();
    }
};

#endif //CPPALGORITHMS_FINDKTHSMALLESTSUMOFAMATRIXWITHSORTEDROWS_H
