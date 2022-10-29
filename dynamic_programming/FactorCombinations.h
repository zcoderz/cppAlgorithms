//
// Created by USMAN QADIR on 10/28/22.
//

#ifndef CPPALGORITHMS_FACTORCOMBINATIONS_H
#define CPPALGORITHMS_FACTORCOMBINATIONS_H

#include <vector>
#include <iostream>

using namespace std;

class FactorCombination {
public:

    static void getFactorRec(vector<vector<int>> &res, vector<int> & vec, int iStart, int rem, int orig) {
        if (rem ==1) {
            res.push_back(vec);
            return;
        }
        for (int j = iStart; j <= rem; j++) {
            if (rem%j==0 && j != orig) {
                vec.push_back(j);
                getFactorRec(res, vec, j, rem/j, orig);
                vec.pop_back();
            }
        }
    }

    static vector<vector<int>> getFactors(int n) {
        if (n==1) return {};
        vector<vector<int>> res;
        vector<int> comb;
        getFactorRec(res, comb, 2, n, n);
        return res;
    }

    static void testMe() {
        vector<vector<int>> results = getFactors(12);
        for (auto res: results) {
            std::copy(res.begin(), res.end() , std::ostream_iterator<int>(cout, ", ")); cout << endl;
        }
    }
};

#endif //CPPALGORITHMS_FACTORCOMBINATIONS_H
