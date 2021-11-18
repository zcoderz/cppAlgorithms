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

#include <iostream>

using namespace std;

void DynamicProgramming::runDpProblems() {
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