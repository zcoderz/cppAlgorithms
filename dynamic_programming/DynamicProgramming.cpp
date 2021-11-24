//
// Created by usman on 11/17/21.
//
#include "DynamicProgramming.h"
#include "ClimbingStairs.h"
#include "PascalTriangle.h"
#include "DynamicProgramming.h"
#include "UniquePaths.h"
#include "CoinChange.h"
#include "CoinChangeTwo.h"
#include "WordBreak.h"
#include "Triangle.h"
#include "PartitionEqualSubset.h"
#include "BurstBaloons.h"
#include "MinCostToCutSticks.h"
#include "LongestCommonSubsequence.h"
#include <iostream>

using namespace std;

void DynamicProgramming::runDpProblems() {
    LongestCommonSubsequence longestCommonSubsequence;
    int sz = longestCommonSubsequence.longestCommonSubsequence("ace", "abcde");
    cout << sz << endl;
    return;

    MinCostToCutSticks minCostToCutSticks;
    vector<int> cuts = {1,3,4,5};
    int theCost = minCostToCutSticks.minCost(7, cuts);
    cout << theCost << endl;
    return;

    BurstBaloons burstBaloons;
    vector<int> nums = {3,1,5,8};
    int coinsV = burstBaloons.maxCoins(nums);
    cout << coinsV << endl;
    PartitionEqualSubset partition;
    vector<int> vecP = {3,4,2,1};
    bool  resB = partition.canPartition(vecP);
    cout << resB << endl;
    vector<vector<int>> vals = {{2},{3,4},{6,5,7},{4,1,8,3}};
    Triangle triangle;
    int res = triangle.minimumTotal(vals);
    cout << res << endl;
    WordBreak wordBreak;
    vector<string> vec = {"leet","codes"};
    string strTest = "leetcode";
    bool bres = wordBreak.wordBreak(strTest, vec);
    cout << bres << endl;
    CoinChangeTwo coinChangeTwo;
    CoinChange coinChange;
    vector<int> coins = {1,2,5};
    int min = coinChange.coinChange(coins, 11);
    cout << min << endl;
    vector<vector<int>> grid {{0,0,0},{0,1,0},{0,0,0}};
    UniquePaths uniquePaths;
    int paths = uniquePaths.uniquePathsWithObstacles(grid);
    cout << paths << endl;
//    PascalTriangle pascalTriangle;
//    int res = pascalTriangle.getPascalTriangleValue(4, 2);
//    cout << res << endl;
//    ClimbingStairs climbingStairs;
//    int res = climbingStairs.climbStairs(3);
//    cout << res;
}