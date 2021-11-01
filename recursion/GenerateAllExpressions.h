//
// Created by usman on 10/29/21.
//

#ifndef CPPALGORITHMS_GENERATEALLEXPRESSIONS_H
#define CPPALGORITHMS_GENERATEALLEXPRESSIONS_H

#include <vector>
#include <set>
#include <sstream>
using namespace std;

class GenerateAllExpressions {
public:
    vector <string> generate_all_expressions(string s, long long int target) {
        vector <string> possibles;
        string str;
        generateAllPossibleCombinations(0, 0, s, 0, target, possibles, str);
        return possibles;
    }



    //void generateAllPossibleNumbers(int startIndex, string & str, set<int> & possibleDigits) {
    //void generateAllPossibleNumbers(vector<int> & possibleDigits, int lastDigit, int currentVal, int target, string & currString, vector <string> & possibles, int currLen, int origLen, bool isAdd) {
    void generateAllPossibleCombinations(int startIndex, int priorVal, string & str, long long int currentVal, long long int target, vector <string> & possibles, string & currString) {
        if (startIndex == str.length() && currentVal == target) {
            possibles.push_back(currString);
            return;
        } else if (startIndex == str.length()) {
            return;
        }
        for (int i = startIndex; i < str.length(); i++) {
            string strV = str.substr(startIndex, i - startIndex + 1);
            long long int val = stoll(strV);
            if (currString.empty()) {
                currString.append(strV);
                generateAllPossibleCombinations(i + 1, val, str, val, target, possibles, currString);
                currString.erase();
            } else {
                int strLen = currString.length();
                currString.append("+").append(strV);
                //for plus case, pass current value forward as prior value
                generateAllPossibleCombinations(i + 1, val, str, currentVal + val, target, possibles, currString);
                currString.erase(strLen);
                currString.append("*").append(strV);
                //this is very tricky to come up with!
                //for multiply need to add (priorVal * val) multiply prior value with current value and also subtract it, to not double count
                long long int newVal = currentVal + (priorVal * val) - priorVal;
                //need to pass on the priorVal * val, for multiply case as  priorVal
                generateAllPossibleCombinations(i + 1, priorVal * val, str, newVal, target, possibles, currString);
                currString.erase(strLen);
            }
        }
    }

//
//        void generatePossibles(vector<int> & possibleDigits, int lastDigit, int currentVal, int target, string & currString, vector <string> & possibles, int currLen, int origLen, bool isAdd) {
//            if (target == currentVal && currLen == origLen) {
//                possibles.push_back(currString);
//                return;
//            } else if (currentVal >= target) {
//                return;
//            }
//
//            for (auto  iter = possibleDigits.begin(); iter != possibleDigits.end();) {
//                int val = *iter;
//                int digits = 0;
//                int number = val;
//                while (number != 0) { number /= 10; digits++; }
//                iter = possibleDigits.erase(iter);
//                int strLen = currString.length();
//                if (currString.empty()) {
//                    currString.append(to_string(val));
//                    generatePossibles(possibleDigits, val, val, target, currString, possibles, currLen + digits, origLen, false);
//                } else {
//                    currString.append("*").append(to_string(val));
//                    int newVal ;
//                    if (isAdd) {
//                        newVal = (currentVal-lastDigit)+(lastDigit*val);
//                    } else {
//                        newVal =  currentVal*val;
//                    }
//                    generatePossibles(possibleDigits, val, newVal, target, currString, possibles, currLen + digits, origLen, false);
//                    currString.erase(strLen);
//                    currString.append("+").append(to_string(val));
//                    generatePossibles(possibleDigits, val, currentVal+val, target, currString, possibles, currLen + digits, origLen, false);
//                }
//                currString.erase(strLen);
//                iter = possibleDigits.insert(iter, val);
//                iter++;
//            }
//        }
};

#endif //CPPALGORITHMS_GENERATEALLEXPRESSIONS_H
