//
// Created by usman on 11/23/21.
//

#ifndef CPPALGORITHMS_MINCOSTTOCUTSTICKS_H
#define CPPALGORITHMS_MINCOSTTOCUTSTICKS_H

#include <limits>
#include <iostream>

using namespace std;

/**
 * Dinosaur : DO Again
 */
class MinCostToCutSticks {
public:
    static int minCost(int n, vector<int>& cuts) {
        //add sentinels
        cuts.push_back(0);
        cuts.push_back(n);
        //sort the cuts so that they can be processed in order
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(cuts.size(), vector<int> (cuts.size()));
        for (int i = cuts.size()-1; i>=0; i--) {
            for (int j =i+1; j < cuts.size(); j++) {
                for (int k=i+1; k <j; k++) {
                    int cost = cuts[j] - cuts[i]; //size of the rod that was cut
                    //in addition need to include all sub cuts
                    int remainingCost = dp[i][k] + dp[k][j];
                    int totalCost = cost + remainingCost;
                    if (dp[i][j] ==0) {
                        dp[i][j] = totalCost;
                    } else {
                        dp[i][j] =  min(totalCost, dp[i][j]);
                    }
                }
            }
        }
        return dp[0][cuts.size()-1];
    }

    static int dfsuq(int i, int j, vector<int> & cuts, vector<vector<int>> & dp) {
        if (j - i <= 1) {
            //cuts which are next to each other don't have sub cuts to process
            //their cost is just the aggregated difference between them which
            //will get calculated inside the calling method (cuts[j] - cuts[i])
            return 0;
        }
        if (dp[i][j] != -1) return dp[i][j];
        cout << "processing " << cuts[i] << " and " << cuts[j] << endl;
        int minCut = numeric_limits<int>::max();
        for (int k = i + 1; k < j; k++) {
            int rec1 = dfsuq(i,k, cuts, dp);
            int rec2 = dfsuq(k,j, cuts, dp);
            int tmp = cuts[j] - cuts[i] + rec1 + rec2;
            cout << "  calculated min cost between cuts " << cuts[i] << " and " << cuts[j] << " as " << rec1 <<
                 " and " << rec2 << " and diff as " << cuts[j] - cuts[i] << " amounts to " << tmp << endl;
            minCut = min(minCut, tmp);
        }
        cout << "calculated min cost between cuts " << cuts[i] << " and " << cuts[j] << " as " << minCut << endl;
        dp[i][j] = minCut;
        return minCut;
    }

    static int minCostRec(int n, vector<int>& cuts) {
        cuts.push_back(0); cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp (n, vector<int> (n, -1));
        int val =  dfsuq(0, cuts.size()-1, cuts, dp);
        return val;
    }

    static void testMe() {
        vector<int> cuts = {1,3,4,5};
        int val = minCost(7, cuts);
        cout << val << endl;
    }
//    int dfs(vector<int>& cuts, int i, int j, vector<vector<optional<int>>> & dp) {
//        if (j - i <= 1)
//            return 0;
//        if (dp[i][j] == nullopt) {
//            dp[i][j] = numeric_limits<int>::max();
//            for (auto k = i + 1; k < j; ++k)
//                dp[i][j] = min(dp[i][j].value(),
//                               cuts[j] - cuts[i] + dfs(cuts, i, k, dp) + dfs(cuts, k, j, dp));
//        }
//        return dp[i][j].value();
//    }
//
//    int minCostRec(int n, vector<int>& cuts) {
//        cuts.push_back(0);
//        cuts.push_back(n);
//        sort(begin(cuts), end(cuts));
//        vector<vector<optional<int>>> dp(cuts.size(), vector<optional<int>> (cuts.size()));
//        return dfs(cuts, 0, cuts.size() - 1, dp);
//    }
};
#endif //CPPALGORITHMS_MINCOSTTOCUTSTICKS_H
