//
// Created by usman on 10/27/21.
//

#ifndef CPPALGORITHMS_PALINDROMEPARTITIONING_H
#define CPPALGORITHMS_PALINDROMEPARTITIONING_H

#include <vector>

using namespace std;

/**
 * https://leetcode.com/problems/palindrome-partitioning/
 *
 */
class PalindromePartitioning {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> partitions;
        vector<string> currPartition;
        string currStr;
        int len = s.size();
        vector<vector<bool>> dp (len, vector <bool> (len, false));
        identifyPalindromicPartitionsDP(0, 0, s, currPartition, partitions, dp);
        return partitions;
    }

    void identifyPalindromicPartitionsDP(int startIndex, int currIndex, string & origStr,
                                         vector<string> & currPartition, vector<vector<string>> & partitions,
                                         vector<vector<bool>> & dp) {
        if (startIndex == origStr.size()) {
            //when all partitions have been processed
            partitions.push_back(currPartition);
            return;
        } else if (currIndex == origStr.size()) {
            //this case stems from the recursion marked below in B and can be ignored
            //as any valid palindrome
            return;
        }

        if (origStr[startIndex]  == origStr[currIndex] && ( ((currIndex - startIndex) <=1 ) || (dp[startIndex+1][currIndex-1])))  {
            dp[startIndex][currIndex] = true;
            string tmp = origStr.substr(startIndex, currIndex-startIndex+1);
            currPartition.push_back(tmp);
            //recurse A : valid palindrome. mark it as such and move to the next index
            identifyPalindromicPartitionsDP(currIndex+1, currIndex + 1, origStr, currPartition, partitions, dp);
            currPartition.pop_back();
        }
        //recurse B : while including current character together with the prior characters
        identifyPalindromicPartitionsDP(startIndex, currIndex + 1, origStr, currPartition, partitions, dp);
    }


    void identifyPalindromicPartitionsSimpler(int startIndex, int currIndex, string & origStr,
                                       vector<string> & currPartition, vector<vector<string>> & partitions) {
        string tmp = origStr.substr(startIndex, currIndex-startIndex);
        if (currIndex == origStr.size()) {
            if (isPalindrome(tmp)) {
                currPartition.push_back(tmp);
                partitions.push_back(currPartition);
                currPartition.pop_back();
            }
            return;
        }
        if (isPalindrome(tmp)) {
            currPartition.push_back(tmp);
            identifyPalindromicPartitionsSimpler(currIndex, currIndex + 1, origStr, currPartition, partitions);
            currPartition.pop_back();
        }
        identifyPalindromicPartitionsSimpler(startIndex, currIndex + 1, origStr, currPartition, partitions);
    }

    bool isPalindrome(string & str) {
        if (str.empty()) return false;
        int i =0; int j = str.length()-1;
        while (i < j) {
            if (str[i++] != str[j--]) {
                return false;
            }
        }
        return true;
    }

    void identifyPalindromicPartitions(string & currString, int currIndex, string & origStr,
                                       vector<string> & currPartition, vector<vector<string>> & partitions) {
        if (currIndex == origStr.size()) {
            if (isPalindrome(currString)) {
                currPartition.push_back(currString);
                partitions.push_back(currPartition);
                currPartition.pop_back();
            } else if (currString.empty() && !currPartition.empty()) {
                partitions.push_back(currPartition);
            }
            return;
        }
        if (isPalindrome(currString)) {
            currPartition.push_back(currString);
            string newStr; newStr.push_back(origStr[currIndex]);
            identifyPalindromicPartitions(newStr, currIndex + 1, origStr, currPartition, partitions);
            currPartition.pop_back();
        }
        currString.push_back(origStr[currIndex]);
        identifyPalindromicPartitions(currString, currIndex + 1, origStr, currPartition, partitions);
        currString.pop_back();
    }
    void test() {
        vector<vector<string>> test;
        vector<string> res;
        for (vector<string> & vec : test) {
            string s;
            for (string & str: vec) {
                s += str + "|";
            }
            if (!s.empty()) {
                s.pop_back();
            }
            res.push_back(s);
        }

    }
};

#endif //CPPALGORITHMS_PALINDROMEPARTITIONING_H