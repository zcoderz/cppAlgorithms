//
// Created by usman on 10/27/21.
//

#ifndef CPPALGORITHMS_PARENTHESIS_H
#define CPPALGORITHMS_PARENTHESIS_H

#include <vector>

using namespace std;

class Parenthesis {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> parenthesis;
        string workString;
        generateParenthesis(n, n, workString, parenthesis);
        return parenthesis;
    }

    void generateParenthesis(int open, int close, string & workString, vector<string>  & parenthesis) {
        if (open == 0 && close ==0) {
            parenthesis.push_back(workString);
        }
        if (open > 0) {
            workString.push_back('(');
            generateParenthesis(open -1, close, workString, parenthesis);
            workString.pop_back();
        }
        if (close > open) {
            workString.push_back(')');
            generateParenthesis(open , close-1, workString, parenthesis);
            workString.pop_back();
        }
    }
};

#endif //CPPALGORITHMS_PARENTHESIS_H