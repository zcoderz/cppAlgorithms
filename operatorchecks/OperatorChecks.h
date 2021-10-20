//
// Created by usman on 10/20/21.
//

#ifndef CPPALGORITHMS_OPERATORCHECKS_H
#define CPPALGORITHMS_OPERATORCHECKS_H

#endif //CPPALGORITHMS_OPERATORCHECKS_H

#include <algorithm>
#include <set>
#include <vector>
#include <queue>
using namespace std;
class OperatorChecks {
public:

    void testOperators() {
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

        //greater in PQ orders it smallest to largest. greater here is using the comparison operator '>'
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
