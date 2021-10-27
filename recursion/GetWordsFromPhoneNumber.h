//
// Created by usman on 10/26/21.
//

#ifndef CPPALGORITHMS_GETWORDSFROMPHONENUMBER_H
#define CPPALGORITHMS_GETWORDSFROMPHONENUMBER_H

#endif //CPPALGORITHMS_GETWORDSFROMPHONENUMBER_H
#include <vector>
#include <unordered_map>

using namespace std;

class GetWordsFromNumbers {
    unordered_map<char, vector<char>> numbers = {
            {'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}}, {'4', {'g', 'h', 'i'}}, {'5', {'j', 'k', 'l'}},
            {'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r','s'}}, {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}}};
public:
    vector<string> getWordsFromPhoneNumber(string phoneNumber) {
        vector<string> res;
        string startStr;
        processNumber(phoneNumber, 0, startStr, res);
        return res;
    }

    void processNumber(string number, int index, string & currentStr, vector<string> & res) {
        if (index == number.size()) {
            if (currentStr.empty()) {
                res.emplace_back("-1");
            } else {
                res.push_back(currentStr);
            }
            return;
        }
        auto  iter = numbers.find(number[index]);
        if (iter != numbers.end()) {
            for (int i =0; i < iter->second.size(); i++) {
                char ch = iter->second[i];
                currentStr.push_back(ch);
                processNumber(number, index+1, currentStr, res);
                currentStr.pop_back();
            }
        } else {
            processNumber(number, index+1, currentStr, res);
        }
    }

};