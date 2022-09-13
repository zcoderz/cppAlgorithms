//
// Created by usman on 9/13/22.
//

#ifndef CPPALGORITHMS_STRINGSFROMWILDCHAR_H
#define CPPALGORITHMS_STRINGSFROMWILDCHAR_H
#include <string>
#include <vector>

using namespace std;
class StringTest {
public:
    static vector<string> find_all_possibilities(string &s) {
        // Write your code here.
        vector<string> retVec;
        string startStr;
        find_all_possibilities(s, retVec, startStr);
        return retVec;
    }

    static void find_all_possibilities(string &parsingString, vector<string> & vec, string & currStr) {
        if (parsingString.empty()) {
            vec.push_back(currStr);
            return;
        }
        char ch = parsingString[0];
        parsingString.erase(0, 1);
        if (ch == '?') {
            find_all_possibilities(parsingString, vec, currStr.append("0"));
            currStr.erase(currStr.length()-1, 1);
            find_all_possibilities(parsingString, vec, currStr.append("1"));
            currStr.erase(currStr.length()-1, 1);
        } else {
            currStr += ch;
            find_all_possibilities(parsingString, vec, currStr);
            currStr.erase(currStr.length()-1, 1);
        }
        parsingString = ch + parsingString;
    }
};

#endif //CPPALGORITHMS_STRINGSFROMWILDCHAR_H
