//
// Created by USMAN QADIR on 11/4/22.
//

#ifndef CPPALGORITHMS_WILDCARDMATCHING_H
#define CPPALGORITHMS_WILDCARDMATCHING_H
#include <string>
#include <vector>

using namespace std;

class WildCardMatching {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(p.length(), vector<bool> (s.length()));

        for(int i=0; i <= p.length(); i++) {
            for (int j =0; j <=s.length(); j++) {
                if (p[i]=='*') {
                    if(i==0 && j==0) {
                        dp[i][j]=true;
                    } else {
                        dp[i][j] = (j > 0 ? dp[i][j-1] : false) || (i > 0 ? dp[i-1][j] : false);
                    }
                } else if (p[i]=='?') {
                    if(i ==0 && j==0) {
                        dp[i][j]=true;
                    } else {
                        dp[i][j] = (i > 0 && j > 0 ? dp[i-1][j-1] : false);
                    }
                } else if (p[i]==s[j]) {
                    if (i > 0 && j > 0)
                        dp[i][j] = dp[i-1][j-1]);
                    else if (i==0 && j ==0)
                        dp[i][j] = true;
                }
            }
        }

        return dp[p.length()-1][s.length()-1];
    }
};

#endif //CPPALGORITHMS_WILDCARDMATCHING_H
