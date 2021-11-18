//
// Created by usman on 11/17/21.
//

#ifndef CPPALGORITHMS_TRIANGLE_H
#define CPPALGORITHMS_TRIANGLE_H
#include <vector>

using namespace std;

class Triangle {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() ==1) {
            return triangle[0][0];
        }
        vector<int> & prior = triangle[0];
        vector<int> curr;
        for (int i =1; i < triangle.size(); i++) {
            curr.clear();
            for (int j =0; j <= i; ++j) {
                if (j==0|| j==i) {
                    if (j==0) {
                        curr.push_back(triangle[i][j] + prior[j]);
                    } else {
                        curr.push_back(triangle[i][j] + prior[j-1]);
                    }
                } else {
                    curr.push_back(min(triangle[i][j] + prior[j], triangle[i][j] + prior[j-1]));
                }
            }
            prior = move(curr);
        }
        return *min_element(prior.begin(), prior.end());
    }
};

#endif //CPPALGORITHMS_TRIANGLE_H
