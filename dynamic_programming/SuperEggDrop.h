//
// Created by usman on 11/12/22.
//

#ifndef CPPALGORITHMS_SUPEREGGDROP_H
#define CPPALGORITHMS_SUPEREGGDROP_H

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/**
 * DINOSAUR: This problem has very interesting other math solutions. Need to come back to these!!
 * https://leetcode.com/problems/super-egg-drop/solutions/158936/super-egg-drop/
 *
 */
class SuperEggDrop {
public:
    static int superEggDrop(int k, int n) {
        vector<vector<int>> dp (k+1, vector<int> (n+1));
        //with one egg you will need as many tries as number of floors
        for (int i =1; i <=n; i++) {
            dp[1][i] = i;
        }

        for (int e =2; e <= k; e++) {
            //e represents eggs
            for (int f =1; f <=n; f++) {
                //f represents floors
                int minVal = INT_MAX;
                for (int j=1 ; j <= f; j++) {
                    //dp[f-1][e-1] represents egg break, one less floor to search with one less egg
                    //dp[f-j][e] represents no egg break, f-j floors left to search with same no of eggs
                    minVal = min(minVal, max(dp[e-1][j - 1], dp[e][f - j]) + 1);
                }
                dp[e][f] = minVal;
            }
        }
        return dp[k][n];
    }

    /**
     * dp[e-1][x - 1] is an increasing function with increasing x
     * dp[e][N - x] is a decreasing function of X
     *
     * So to find the value of X that maximizes both of the functions, we can do a binary search
     *
     * @param k
     * @param n
     * @return
     */
    static int superEggDropFast(int k, int n) {
        vector<vector<int>> dp (k+1, vector<int> (n+1));
        //with one egg you will need as many tries as number of floors
        for (int i =1; i <=n; i++) {
            dp[1][i] = i;
        }
        for (int e =2; e <= k; e++) {
            //e represents eggs
            for (int f =1; f <=n; f++) {
                //f represents floors
                int low=1; int high = f;
                //need to stop where low and high are off by 1 because the t1 & t2 values will not exactly converge
                //since values are based off of integer and convergence would require a double
                while (high > low+1) {
                    int mid = (low + (high-low)/2);
                    int t1 = dp[e-1][mid-1];
                    int t2 = dp[e][f-mid];
                    if (t1 > t2) {
                        high=mid;
                    } else if (t1 < t2) {
                        low=mid;
                    } else {
                        high = low = mid;
                    }
                }
                int minValue = min(max(dp[e-1][low-1], dp[e][f-low]), max(dp[e-1][high-1], dp[e][f-high]));
                dp[e][f] = minValue + 1;
            }
        }
        return dp[k][n];
    }


    static void testMe() {
        int res = superEggDropFast(2,2);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_SUPEREGGDROP_H
