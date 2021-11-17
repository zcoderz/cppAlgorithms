//
// Created by usman on 11/17/21.
//
#include "DynamicProgramming.h"
#include "ClimbingStairs.h"
#include <iostream>

using namespace std;

void DynamicProgramming::runDpProblems() {
    ClimbingStairs climbingStairs;
    int res = climbingStairs.climbStairs(3);
    cout << res;
}