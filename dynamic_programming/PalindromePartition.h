//
// Created by usman on 11/6/22.
//

#ifndef CPPALGORITHMS_PALINDROMEPARTITION_H
#define CPPALGORITHMS_PALINDROMEPARTITION_H

#include <vector>
#include <string>

using namespace std;

class PalindromePartition {
public:
    int isPalindrome(string &str, int left, int right) {
        while (left < right) {
            if (str[left++] != str[right--]) return 0;
        }
        return 1;
    }

    void partition(string s, int startIndex, vector<string> & currPartition, vector<vector<string>> & palindromes, vector<vector<int>> & dp) {
        if (startIndex == s.size()) {
            palindromes.push_back(currPartition);
            return;
        }

        for (int i =startIndex; i < s.size(); i++) {
            if (dp[startIndex][i] ==-1) {
                dp[startIndex][i] = isPalindrome(s, startIndex, i);
            }
            if (dp[startIndex][i]) {
                currPartition.push_back(s.substr(startIndex, i-startIndex+1));
                partition(s, i+1, currPartition, palindromes, dp);
                currPartition.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<vector<int>> dp (s.length(), vector<int> (s.length(), -1));
        vector<string> curr;
        partition(s, 0, curr, res, dp);
        return res;
    }
};

#endif //CPPALGORITHMS_PALINDROMEPARTITION_H
