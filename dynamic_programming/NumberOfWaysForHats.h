//
// Created by usman on 12/1/22.
//

#ifndef CPPALGORITHMS_NUMBEROFWAYSFORHATS_H
#define CPPALGORITHMS_NUMBEROFWAYSFORHATS_H
#include <unordered_map>
#include <vector>
#include <string>
#include <list>
#include <cstring>
#include <iostream>

using namespace std;
class NumberOfWaysForHats {
public:

    int processHats(int personId, vector<vector<int>>& hats, string & strHats, unordered_map<string, int> & hatCount) {
        auto iter = hatCount.find(strHats);
        if (iter != hatCount.end()) {
            return iter->second;
        }
        if (personId==hats.size()) {
            return 1;
        }
        int count = 0;
        for(int hat: hats[personId]) {
            if (strHats[hat] =='1') continue;
            strHats[hat] ='1';
            count += processHats(personId+1, hats, strHats, hatCount);
            strHats[hat] ='0';
        }
        hatCount[strHats] = count;
        return count;
    }

    int numberWaysMap(vector<vector<int>>& hats) {
        string strHats;
        strHats.append('0', 41);
        unordered_map<string, int> hatCount;
        return processHats(0, hats, strHats, hatCount);
    }

    static int countOnes (int mask) {
        int cnt = 0;
        while (mask !=0) {
            mask &= (mask-1);
            cnt++;
        }
        return cnt;
    }

    static int recurseHats(int hatNo, int mask, vector<vector<int>> & vecHats, vector<vector<int>> &dp, int numPpl) {

        int cnt = countOnes(mask);
        cout <<  " ones is " << cnt <<  "mask is " << mask << endl;
        if (cnt == numPpl) {
            return 1;
        }
        if (hatNo == vecHats.size()) return 0;
        if (dp[hatNo][mask] != -1) return dp[hatNo][mask];
        int res = recurseHats(hatNo+1, mask, vecHats, dp, numPpl); //skip assigning hat to any ppl
        //int res = 0;
        for (int person: vecHats[hatNo]) {
            if ((mask & (1<<person)) != 0) continue;
            res += recurseHats(hatNo+1, mask | (1<<person), vecHats, dp, numPpl);
        }
        dp[hatNo][mask] = res;
        return res;
    }

    static int numberWays(vector<vector<int>>& hats) {
        vector<vector<int>> vecHats(41);
        int numPpl = hats.size();
        for (int i =0; i < numPpl; i++) {
            for (int hat : hats[i]) {
                vecHats[hat].push_back(i);
            }
        }
        //skip hats which are not assignable to ppl
        vector<vector<int>> vecHatsPruned;
        for (int i =0; i <41; i++) {
            if (vecHats[i].empty()) continue;
            vecHatsPruned.push_back(std::move(vecHats[i]));
        }
//        int dp[1<<numPpl];
//        memset(dp, -1, sizeof(dp));
        vector<vector<int>> dp(vecHatsPruned.size(), vector<int>(1<<numPpl, -1));
        return recurseHats(0, 0, vecHatsPruned, dp, numPpl);
    }

    /**
     * Converts people to hats into hats to ppl
     * since number of ppl are much smaller than the number of hats and a mask for people can be contained in an int
     * number of hats is 40, number of ppl is 10
     * above i contained the hat mask in a string. but since the mask was very large and a hashmap was utilized to store it
     * the solution timed out on leetcode.
     * the below solution beats 100% of others
     * @param hats
     * @return
     */
    static int numberWaysDP(vector<vector<int>>& hats) {
        static int mod = 1e9 + 7;
        vector<vector<int>> vecHats(41);
        int numPpl = hats.size();
        for (int i =0; i < numPpl; i++) {
            for (int hat : hats[i]) {
                vecHats[hat].push_back(i);
            }
        }
        //skip hats which are not assignable to ppl
        vector<vector<int>> vecHatsPruned;
        for (int i =0; i <41; i++) {
            if (vecHats[i].empty()) continue;
            vecHatsPruned.push_back(std::move(vecHats[i]));
        }
        int maxMask = 1<<numPpl;
        int dp[maxMask];
        memset(dp, 0, sizeof(dp));
        //one way to assign hats to no people
        dp[0]=1;
        //work to assign hats to people, rather than assigning people to hats
        //the number of people is much smaller than the number of hats and can be contained in an int bit mask (1<<10) max
        for (int hatNo=0; hatNo < vecHatsPruned.size(); hatNo++) {
            //go on masks in reverse to avoid double count
            for (int mask =maxMask-1; mask >=0; mask--) {
                for (int personId: vecHatsPruned[hatNo]) {
                    if ((mask & (1<<personId)) != 0) continue;
                    dp[mask|1<<personId] = (dp[mask|1<<personId] + dp[mask]) % mod;
                }
            }
        }
        return dp[maxMask-1];
    }

    static void testMe() {
        vector<vector<int>> vec = {{1,2,3,4},{1,2,3,4},{1,2,3,4},{1,2,3,4}};
        int res = numberWays(vec);
        cout << res << endl;
    }
};
#endif //CPPALGORITHMS_NUMBEROFWAYSFORHATS_H
