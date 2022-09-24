//
// Created by usman on 9/19/22.
//

#ifndef CPPALGORITHMS_VALIDATEEXPRESSION_H
#define CPPALGORITHMS_VALIDATEEXPRESSION_H
#include <string>
#include <stack>
#include <vector>
#include <unordered_map>
//#include <ranges>
#include <string_view>
#include <iostream>
#include <iomanip>
#include <list>
using namespace std;

class ValidateExpression {


public:

    static bool is_valid(string expression) {

        auto isOperator = [](char ops){
            if(ops == '+' || ops == '-' || ops == '*') { return true; }
            return false;
        };

        auto isOpenBracket = [](char ob){
            if(ob == '(' || ob == '{' || ob == '[') { return true; }
            return false;
        };

        auto isCloseBracket = [](char cb){
            if(cb == ')' || cb == '}' || cb == ']') { return true; }
            return false;
        };

        auto isBracketMatch = [](char ob, char cb){
            if(ob == '(' && cb == ')') { return true; }
            if(ob == '{' && cb == '}') { return true; }
            if(ob == '[' && cb == ']') { return true; }
            return false;
        };

        //keeping 2 stacks really simplifies the problem!
        stack<int>digits;
        stack<char>opsAndBrackets;
        bool isNumber = false; //used to check whether 2 numbers are not added without an operator
        for(int i = 0; i < expression.size(); ++i) {
            if(isOperator(expression[i]))  {
                opsAndBrackets.push(expression[i]);
                isNumber = false;
            }
            else if (isdigit(expression[i])) {
                digits.push(expression[i] - '0');
                if(isNumber) {
                    return (false); //error 2 numbers without an operator
                }
                isNumber = true;
            } else if (isOpenBracket(expression[i])) {
                opsAndBrackets.push(expression[i]);
            }
            else if (isCloseBracket(expression[i])) {
                bool matching = false;
                while (!matching && (!opsAndBrackets.empty()) ) {
                    char topchar = opsAndBrackets.top();
                    opsAndBrackets.pop();
                    if(isBracketMatch(topchar, expression[i])) {
                        matching = true;
                    } else if(isOperator(topchar)) {
                        if(digits.size() < 2)
                            return false;
                        digits.pop();
                    } else {
                        return false;
                    }
                }
            } else {
                return false; //unknown character
            }
        }

        while (!opsAndBrackets.empty()) {
            char topchar = opsAndBrackets.top();
            opsAndBrackets.pop();
            if (!isOperator(topchar)) {
                return false;
            }
            if (digits.size() < 2) {
                return false;
            } else {
                digits.pop();
            }
        }
        if (digits.size() > 1 || !opsAndBrackets.empty()) {
            return false;
        }
        return true;
    }

    static char getOpenMapping(char ch) {
        if (ch == ')') {
            return '(';
        } else if (ch == ']') {
            return '[';
        } else if (ch == '}') {
            return '{';
        }
    }

    static bool isOpen(char  ch) {
        return ch == '(' || ch == '[' || ch == '{';
    }

    static bool isClose(char  ch) {
        return ch == ')' || ch == ']' || ch == '}';
    }

    static bool isOperator(char ch) {
        return ch == '-' || ch == '+' || ch == '*';
    }


    static vector<string> split(string &expression, string   delims) {
        vector<string> res;
        size_t beg, pos = 0;
        while ((beg = expression.find_first_not_of(delims, pos)) != std::string::npos) {
            pos = expression.find_first_of(delims, beg + 1);
            res.push_back(expression.substr(beg, pos - beg)) ;
        }
        return res;
    }

    static bool validateOperators(string & expression) {
        bool leftNumFound = false,  operatorFound =false;
        for (int i=0; i < expression.size(); i++) {
            if (isOperator(expression[i]) && !leftNumFound) {
                return false;
            } else if (isOperator(expression[i])) {
                leftNumFound = false;
                operatorFound = true;
            }
            if (isdigit(expression[i]) && !operatorFound) {
                leftNumFound = true;
            } else if (isdigit(expression[i]) && operatorFound) {
                operatorFound = false;
            }
        }
        return (!leftNumFound && !operatorFound);
    }

    static bool is_validComplex(string &expression) {
        if (!validateOperators(expression)) {
            return false;
        }
        vector<string> splitString = split(expression, "*+-" );
        vector<int> arr (128, 0);
        for (const auto& str: splitString) {
            if (str.empty()) return false;
            bool digitFound = false;
            for (char ch : str) {
                if (isdigit(ch)) {
                    if (digitFound) {
                        return false;
                    }
                    digitFound = true;
                }
                if (isOpen(ch)) {
                    arr[ch]++;
                } else if (isClose(ch)) {
                    char open = getOpenMapping(ch);
                    if (arr[open] == 0) {
                        return false;
                    }
                    arr[open]--;
                }
            }
            if (!digitFound && splitString.size() > 1) return false;
        }

        for (int i =0; i < 128; i++) {
            if (arr[i] > 0) {
                return false;
            }
        }

        return true;
    }
//    static bool is_valid(string &expression) {
//        stack<char> expressionStack;
//        // Write your code here.
//        for (char ch: expression) {
//            if (isdigit(ch)) {
//                if (!expressionStack.empty() && isdigit(expressionStack.top())) {
//                    return false;
//                }
//                if (!expressionStack.empty() && isOperator(expressionStack.top())) {
//                    expressionStack.pop();
//                    expressionStack.pop(); //remove operator and the number before it
//                }
//                expressionStack.push(ch);
//            }  else if (isClose(ch)) {
//                char open = getOpenMapping(ch);
//                bool  isOp = false;
//                bool digitFound = false;
//                while (expressionStack.top() != open) {
//                    if (isOpen(expressionStack.top()) || (isOp && !isOperator(expressionStack.top()))) {
//                        //if stack contains a different open bracket or not an operator when an operator is expected, return false
//                        return false;
//                    } else {
//                        isOp = true;
//                    }
//                    if (isdigit(expressionStack.top())) {
//                        digitFound = true;
//                    }
//                    expressionStack.pop();
//                }
//                if (expressionStack.empty()) {
//                    return false;
//                }
//                expressionStack.pop();
//                if (digitFound) {
//                    expressionStack.push('1');
//                }
//            } else if (isOpen(ch))  {
//                expressionStack.push(ch);
//            } else {
//                //must be an operator
//                if (!isdigit(expressionStack.top())) {
//                    return false;
//                }
//                expressionStack.push(ch);
//            }
//        }
//        if (expressionStack.size() == 1 && isdigit(expressionStack.top())) return true;
//        else return false;
//    }
};
#endif //CPPALGORITHMS_VALIDATEEXPRESSION_H
