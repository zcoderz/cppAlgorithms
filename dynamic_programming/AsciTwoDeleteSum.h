//
// Created by usman on 10/25/22.
//

#ifndef CPPALGORITHMS_ASCITWODELETESUM_H
#define CPPALGORITHMS_ASCITWODELETESUM_H
#include <string>
#include <vector>
#include <iostream>
/**
 * https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/
 *
 */
using namespace std;
class Asci2DeleteSum {
public:
    int minimumDeleteSum(string s1, string s2) {
        int s1Sz = s1.size();
        int s2Sz = s2.size();
        vector<vector<int>> dp(s1Sz+1, vector<int> (s2Sz+1));
        for (int i =s1Sz-1; i >= 0; i--) {
            dp[i][s2Sz] = dp[i+1][s2Sz]+s1[i];
        }
        for (int i =s2Sz-1; i >= 0; i--) {
            dp[s1Sz][i] = dp[s1Sz][i+1]+s2[i] ;
        }

        for (int i = s1Sz-1; i >=0; i--) {
            for (int j =s2Sz-1; j >=0 ; j--) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = dp[i+1][j+1];
                } else {
                    dp[i][j] = min(dp[i+1][j]+s1[i], dp[i][j+1] + s2[j]);
                }
            }
        }
        return dp[0][0];
    }

    static string minimumDeleteSumStr(string s1, string s2) {
        int s1Sz = s1.size();
        int s2Sz = s2.size();
        vector<vector<string>> dp(s1Sz+1, vector<string> (s2Sz+1));
        for (int i =s1Sz-1; i >= 0; i--) {
            dp[i][s2Sz] = dp[i+1][s2Sz]+s1[i];
        }
        for (int i =s2Sz-1; i >= 0; i--) {
            dp[s1Sz][i] = dp[s1Sz][i+1]+s2[i] ;
        }

        for (int i = s1Sz-1; i >=0; i--) {
            for (int j =s2Sz-1; j >=0 ; j--) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = dp[i+1][j+1];
                } else {
                    dp[i][j] = (cost(dp[i+1][j]+s1[i]) > cost(dp[i][j+1] + s2[j]) ? dp[i][j+1] + s2[j] : dp[i+1][j]+s1[i]);
                }
            }
        }
        return dp[0][0];
    }

    static int cost(string str) {
        int sum=0;
        for (char c: str) {
            sum += c;
        }
        return sum;
    }

    static void testMe() {
        string str="leet";
        string str2="delete";
        string v = minimumDeleteSumStr(str, str2);
        cout << v << endl;
    }
};
#endif //CPPALGORITHMS_ASCITWODELETESUM_H
