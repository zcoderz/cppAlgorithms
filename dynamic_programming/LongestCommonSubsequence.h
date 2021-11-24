//
// Created by usman on 11/23/21.
//

#ifndef CPPALGORITHMS_LONGESTCOMMONSUBSEQUENCE_H
#define CPPALGORITHMS_LONGESTCOMMONSUBSEQUENCE_H
#include <vector>
using namespace std;

class LongestCommonSubsequence {
public:

    int longestCommonSubsequence(string text1, string text2) {
        vector<int> dpPrior(text2.size() +1, 0);
        for (int i =1; i <= text1.size(); i++) {
            vector<int> dpCurr(text2.size() +1, 0);
            for (int j =1; j <= text2.size(); j++) {
                dpCurr[j] = max(dpCurr[j-1], dpPrior[j]);
                if (text1[i-1] == text2[j-1]) {
                    dpCurr[j] = dpPrior[j - 1] + 1;
                }
            }
            dpPrior = move(dpCurr);
        }
        return dpPrior[text2.size()];
    }

    int longestCommonSubsequenceComp2(string text1, string text2) {
        vector<int> dpPrior(text2.size() , 0);
        for (int i =0; i < text1.size(); i++) {
            vector<int> dpCurr(text2.size() , 0);
            for (int j =0; j < text2.size(); j++) {
                if (i == 0) {
                    if (text1[0] == text2[j]) {
                        dpCurr[j] = 1;
                    } else if (j > 0) {
                        dpCurr[j] = dpCurr[j-1];
                    }
                }
                if (j == 0) {
                    if (text1[i] == text2[0]) {
                        dpCurr[0] = 1;
                    } else {
                        dpCurr[0] = dpPrior[0];
                    }
                }
                if (i !=0 && j !=0) {
                    dpCurr[j] = max(dpCurr[j-1], dpPrior[j]);
                    if (text1[i] == text2[j]) {
                        dpCurr[j] = dpPrior[j - 1] + 1;
                    }
                }
            }
            dpPrior = move(dpCurr);
        }
        return dpPrior[text2.size()-1];
    }

    int longestCommonSubsequenceSlow(string text1, string text2) {
        vector<vector<int>> dp(text1.size() , vector<int> (text2.size(), 0));
        for (int i =0; i < text2.size(); i++) {
            if (text1[0] == text2[i]) {
                dp[0][i] = 1;
            } else if (i > 0) {
                dp[0][i] = dp[0][i-1];
            }
        }

        for (int i =0; i < text1.size(); i++) {
            if (text1[i] == text2[0]) {
                dp[i][0] = 1;
            } else if (i > 0) {
                dp[i][0] = dp[i-1][0];
            }
        }

        for (int i =1; i < text1.size(); i++) {
            for (int j =1; j < text2.size(); j++) {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if (text1[i] == text2[j]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
            }
        }
        return dp[text1.size()-1][text2.size()-1];
    }
};

#endif //CPPALGORITHMS_LONGESTCOMMONSUBSEQUENCE_H
