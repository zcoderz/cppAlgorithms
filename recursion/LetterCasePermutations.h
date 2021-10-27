//
// Created by usman on 10/26/21.
//

#ifndef CPPALGORITHMS_LETTERCASEPERMUTATIONS_H
#define CPPALGORITHMS_LETTERCASEPERMUTATIONS_H

#include <vector>
#include <string>

using namespace std;

class LetterCasePermutations {
public:
    vector<string> letter_case_permutations(string str) {
        vector<string> res;
        processPermutations(str, 0, res, res.size());
        return res;
    }

    void processPermutations(string str, int index, vector<string> & res, int size) {
        if (index == size) {
            res.push_back(str);
            return;
        }

        if (isdigit(str[index])) {
            processPermutations(str, index+1, res, size);
        } else {
            char orig = str[index];
            char upper = toupper(orig);
            str[index] = upper;
            processPermutations(str, index+1, res, size);
            char lower = tolower(orig);
            str[index] = lower;
            processPermutations(str, index+1, res, size);
            str[index] = orig;
        }
    }
};

#endif //CPPALGORITHMS_LETTERCASEPERMUTATIONS_H