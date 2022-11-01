//
// Created by usman on 10/31/22.
//

#ifndef CPPALGORITHMS_MINCOSTTREEFROMLEAFVALUES_H
#define CPPALGORITHMS_MINCOSTTREEFROMLEAFVALUES_H

#include <vector>
#include <stack>
#include <climits>
using namespace std;
/**
 * DINOSAUR : This should be practiced again!!!
 */
class MinCostTreeFromLeaf {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int sum=0;
        vector<int> theStack; theStack.push_back(INT_MAX);
        for (int val : arr) {
            while (val >= theStack.back()) {
                int stackMin = theStack.back(); theStack.pop_back();
                sum += (min(theStack.back(), val) * stackMin);
            }
            theStack.push_back(val);
        }
        for (int i = 2; i < theStack.size(); i++) {
            sum += (theStack[i] * theStack[i-1]);
        }
        return sum;
    }

};

#endif //CPPALGORITHMS_MINCOSTTREEFROMLEAFVALUES_H
