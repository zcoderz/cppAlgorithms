//
// Created by usman on 10/20/21.
//

#ifndef CPPALGORITHMS_OPERATORCHECKS_H
#define CPPALGORITHMS_OPERATORCHECKS_H

#include <algorithm>
#include <set>
#include <vector>
#include <queue>
using namespace std;
class OperatorChecks {
public:

    void testOperators() {
        //smaller to larger ! use <
        auto comp = [](int &a, int &b) -> bool { return a < b; };
        vector<int> vec = {22,1,2,5,0,8989,71,3};
        sort(vec.begin(), vec.end(), comp);
        for (int i : vec ) {
            cout << i << endl;
        }

        //for set less operator means smallest to largest, greater is largest to smallest
        multiset<int, less<>> set;
        vector<int> first = {1,2,3,4,5,6};
        for (int val : first) {
            set.insert(val);
        }
        while (!set.empty()) {
            cout << *set.begin() << endl;
            set.erase(set.begin());
        }

        //PQ is different than regular sort operator
        //greater in PQ orders it smallest to largest. greater here is using the comparison operator '>'
        //if you want to sort via largest to smallest use operator '<'
        priority_queue<int , vector<int> , greater<int>> pQ;
        for (int val : first) {
            pQ.push(val);
        }
        while (!pQ.empty()) {
            cout << pQ.top() << endl;
            pQ.pop();
        }
    }
};

#endif //CPPALGORITHMS_OPERATORCHECKS_H