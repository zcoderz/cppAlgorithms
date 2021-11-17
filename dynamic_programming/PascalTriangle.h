//
// Created by usman on 11/17/21.
//

#ifndef CPPALGORITHMS_PASCALTRIANGLE_H
#define CPPALGORITHMS_PASCALTRIANGLE_H

#include <vector>
using namespace std;

class PascalTriangle {
public:

    /**
     *
     * Idea here is based on that for any row we dont need to process beyond the target column.
     * Hence, we stop processing the row once we reached the target column or earlier if the row boundary is reached.
     * In addition, we dont need to store all the as we move down the pyramid. Hence, we utilize a working row
     * and the prior row only.
     *
     * row indexes are starting from 0. col indexes are also starting from 0
     * @param targetRow
     * @param targetCol
     * @return
     */
    int getPascalTriangleValue(int targetRow, int targetCol) {
        if (targetRow == 0 || targetRow == 1) {
            return 1;
        }
        vector<int> prior = {1,1};
        for (int currRow = 2; currRow <= targetRow; ++currRow) {
            vector<int> curr;
            curr.push_back(1);
            for (int i = 1; i <= targetCol; i++) {
                if (i > currRow) break;
                else if (i == currRow) {
                    curr.push_back(1);
                } else {
                    curr.push_back(prior[i-1] + prior[i]);
                }
            }
            prior = move(curr);
        }
        return prior[targetCol];
    }
};

#endif //CPPALGORITHMS_PASCALTRIANGLE_H
