//
// Created by usman on 10/24/22.
//

#ifndef CPPALGORITHMS_MAXCONSECUTIVEONES_H
#define CPPALGORITHMS_MAXCONSECUTIVEONES_H

#include <vector>

using namespace std;

class MaxConsecutiveOnes {
public:

    int findMaxConsecutiveOnesSliding(vector<int>& nums) {
        int left = 0;
        int numZeros = 0;
        int maxOnes = 0;
        for (int i=0; i < nums.size(); i++) {
            if (nums[i]==0) numZeros++;
            while (numZeros > 1) {
                if (nums[left]==0) numZeros--;
                left++;
            }
            maxOnes = max(maxOnes, i-left+1);
        }
        return maxOnes;
    }

    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<int> oneOrder;
        int priorOneCnt=0;
        for (int i=0; i < nums.size(); i++) {
            if (nums[i]==1) {
                priorOneCnt++;
            } else {
                if (priorOneCnt != 0) {
                    oneOrder.push_back(priorOneCnt);
                }
                priorOneCnt = 0;
                oneOrder.push_back(0);
            }
        }

        if (priorOneCnt !=0) oneOrder.push_back(priorOneCnt);;
        int maxOnes =0;
        for(int i =0; i < oneOrder.size(); i++) {
            int numberOfOnes = oneOrder[i];
            if (numberOfOnes > 0 && i >= 2 && oneOrder[i - 2] > 0) {
                numberOfOnes += oneOrder[i - 2] + 1;
            } else if (numberOfOnes > 0 && i >= 1 && oneOrder[i - 1] == 0) {
                numberOfOnes +=  1;
            } else if (numberOfOnes == 0 && i>=1 && oneOrder[i-1]>0) {
                numberOfOnes=1 + oneOrder[i-1];
            } else if (numberOfOnes == 0) {
                numberOfOnes=1;
            }
            maxOnes = max(maxOnes, numberOfOnes);
        }
        return maxOnes;
    }
};

#endif //CPPALGORITHMS_MAXCONSECUTIVEONES_H
