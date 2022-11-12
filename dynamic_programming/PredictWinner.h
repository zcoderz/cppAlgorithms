//
// Created by usman on 11/11/22.
//

#ifndef CPPALGORITHMS_PREDICTWINNER_H
#define CPPALGORITHMS_PREDICTWINNER_H

#include <vector>
#include <iostream>

using namespace std;

class PredictWinner {
public:
    static bool PredictTheWinner(vector<int>& nums) {
        int sz = nums.size();
        //for the matrix pair<first,second> reflects best option in first, and second option in second
        vector<vector<pair<int,int>>> dp(sz, vector<pair<int, int>> (sz) );
        for (int i =0; i < sz; i++) {
            dp[i][i] = make_pair(nums[i], 0);
        }
        for (int l =2; l <= sz; l++) {
            for (int i=0; i <= sz-l; i++) {
                int j = i + l-1;
                int a = nums[i] + dp[i+1][j].second; //pick from beginning and second option in remaining
                int b = nums[j] + dp[i][j-1].second; //pick from end and second option in remaining
                if (a > b) {
                    //if you pick i, then opponent is going to pick best option in i+1,j
                    dp[i][j] = make_pair(a,dp[i+1][j].first);
                } else {
                    dp[i][j] = make_pair(b,dp[i][j-1].first);
                }
            }
        }
        return dp[0][sz-1].first >= dp[0][sz-1].second;
    }

    static int predictTheWinnerRecur(vector<int>& nums, int i, int j, int direction) {
        if (i==j) {
            return direction * nums[i];
        }

        //the part which is returned by the next recursion is maximized from the opponents perspective
        //the current player needs to reset the direction and maximize from its perspective ,
        //intuitively minimizing the other players action

        //this is a max min strategy --->
        //you expect min from opponent and choose the max possible value for your turn
        //by multiplying opponents return value by your direction ((recurA* direction),
        //you transform its max to your min

        int recurA = predictTheWinnerRecur(nums, i+1, j, -direction) ;
        int recurB = predictTheWinnerRecur(nums, i, j-1, -direction) ;
        int val = max (recurA* direction + nums[i], recurB*direction + nums[j]);

        return val * direction;

    }

    /**
     * if final returned value is >=0, you win , else opponent wins
     * @param nums
     * @param i
     * @param j
     * @return
     */
    static int predictTheWinnerRecurTwo(vector<int>& nums, int i, int j) {
        if (i==j) {
            return nums[i];
        }
        //this strategy is similar to the first
        //subtract the score returned by the opponent from your score
        //and choose max possible btw if you picked the first or the last -->
        //return max (nums[i]-recurA,  nums[j]-recurB);
        int recurA = predictTheWinnerRecurTwo(nums, i+1, j) ;
        int recurB = predictTheWinnerRecurTwo(nums, i, j-1) ;
        return max (nums[i]-recurA,  nums[j]-recurB);
    }

    //another way but the above DP solution "PredictTheWinner" is a lot more intuiti ve!!!
    static int predictTheWinnerDP(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int> (nums.size()+1));
        for (int i = nums.size()-1; i >=0; i--) {
            for (int j = i; j < nums.size(); j++) {
                if(i==j) {
                    dp[i][j] = nums[i];
                } else {
                    int val1 = nums[i] - dp[i+1][j];
                    int val2 = nums[j] - dp[i][j-1] ;
                    dp[i][j] = max( val1, val2);
                }
            }
        }
        return dp[0][nums.size()-1] >= 0;
    }

    static void testMe() {
        vector<int> nums = {1,5,2};
        //bool res = predictTheWinnerRecur(nums, 0, nums.size()-1, 1);
        //bool res = PredictTheWinner(nums);
        bool res = predictTheWinnerDP(nums);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_PREDICTWINNER_H
