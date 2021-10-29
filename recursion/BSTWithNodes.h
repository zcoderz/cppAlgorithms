//
// Created by usman on 10/28/21.
//

#ifndef CPPALGORITHMS_BSTWITHNODES_H
#define CPPALGORITHMS_BSTWITHNODES_H

#include <unordered_map>

class BSTWithNodes {
public:
    unordered_map<int, int> bstPossibilities;
    long long int how_many_BSTs(int n) {
        return process(n);
    }

    long long int process(int num) {
        long long int * bst = new long long int[num+1];
        fill(bst, bst+num+1, 0);
        bst[0] = 1;
        for (int numNodes = 1 ; numNodes <= num; numNodes++) {
            for (int rightNodes =0; rightNodes < numNodes; rightNodes++) {
                int leftNodes = numNodes-1-rightNodes;
                bst[numNodes] += bst[leftNodes] * bst[rightNodes];
            }
        }
        long long int val = bst[num];
        delete [] bst;
        return val;
    }

    int processRecursive(int num) {
        if (num == 0) {
            return 1;
        }
        auto iter = bstPossibilities.find(num);
        if (iter != bstPossibilities.end()) {
            return iter->second;
        }

        int numP = 0;

        for (int rightNum =0; rightNum < num; rightNum++) {
            int leftNum = num-1-rightNum;
            numP += process(leftNum) * process(rightNum);
        }
        bstPossibilities[num] = numP;
        return numP;
    }
};

#endif //CPPALGORITHMS_BSTWITHNODES_H