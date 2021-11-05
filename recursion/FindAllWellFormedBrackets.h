//
// Created by usman on 11/4/21.
//

#ifndef CPPALGORITHMS_FINDALLWELLFORMEDBRACKETS_H
#define CPPALGORITHMS_FINDALLWELLFORMEDBRACKETS_H

#include <vector>

using namespace std;

class FindAllWellFormedBrackets {
public:
    char openC = '(';
    char closeC = ')';


    void processWellFormedBrackets(string & currStr, vector<string> & res, int open, int close) {
        if (open == 0 &&  close ==0) {
            res.push_back(currStr);
            return;
        }
        if (open > 0) {
            currStr.push_back(openC);
            processWellFormedBrackets(currStr, res, open - 1, close);
            currStr.pop_back();
        }
        if (close > open) {
            currStr.push_back(closeC);
            processWellFormedBrackets( currStr, res, open, close-1);
            currStr.pop_back();
        }
    }

    vector<string> find_all_well_formed_brackets(int n) {
        string currStr;
        vector<string> res;
        processWellFormedBrackets(currStr, res, n, n);
        return res;
    }
};

#endif //CPPALGORITHMS_FINDALLWELLFORMEDBRACKETS_H
