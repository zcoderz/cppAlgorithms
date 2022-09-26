//
// Created by usman on 9/23/22.
//

#ifndef CPPALGORITHMS_REGULAREXPRESSIONMATCHING_H
#define CPPALGORITHMS_REGULAREXPRESSIONMATCHING_H

#include <string>
#include <vector>
using namespace std;

/**
 * ".*" is tricky. (*) means match zero or more of preceding. when preceding is '.' any match is positive
 * "*" has to be matched in pair with its prior character
 */
class RegularExpressionMatching {
public:
    static bool isMatchDP(string & str, string & pattern, int strIndex, int patternIndex, vector<vector<int>> & dp) {
        if (dp[strIndex][patternIndex] != -1) return dp[strIndex][patternIndex];
        bool res;
        if (patternIndex == pattern.size()) {
            res =  strIndex == str.size();
        } else {
            //check if first character is a match
            bool firstMatch =
                    (strIndex < str.size()) && (str[strIndex] == pattern[patternIndex] || pattern[patternIndex] == '.');
            
            if (patternIndex < pattern.size() - 1 && pattern[patternIndex + 1] == '*') {
                //* signifies no match or one or more matches, so check for both.
                res = isMatchDP(str, pattern, strIndex, patternIndex + 2, dp) //no match
                      || (firstMatch && isMatchDP(str, pattern, strIndex + 1, patternIndex, dp)); //first char match
            } else {
                res = firstMatch && isMatchDP(str, pattern, strIndex + 1, patternIndex + 1, dp);
            }
        }
        dp[strIndex][patternIndex] = res;
        return res;
    }

    static bool isMatch(string str, string pattern) {
        vector<vector<int>> dp(str.size()+1, vector<int>(pattern.size()+1, -1));
        return isMatchDP(str, pattern, 0, 0, dp);
    }

    static bool isMatchRecursive(string str, string pattern) {
        if(pattern.empty()) return str.empty();
        //check if first character is a match
        bool firstMatch = !str.empty() && (str[0] == pattern[0] || pattern[0] == '.');

        if (pattern.length() > 1 && pattern[1] == '*') {
            //* signifies no match or one or more matches, so check for both.
            return isMatchRecursive(str, pattern.substr(2)) //no match
                        || (firstMatch && isMatchRecursive(str.substr(1), pattern)); //first char match
        } else  {
            return firstMatch && isMatchRecursive(str.substr(1), pattern.substr(1));
        }
    }

};

#endif //CPPALGORITHMS_REGULAREXPRESSIONMATCHING_H
