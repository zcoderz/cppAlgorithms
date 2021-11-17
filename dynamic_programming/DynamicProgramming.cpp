//
// Created by usman on 11/17/21.
//
#include "DynamicProgramming.h"
#include "ClimbingStairs.h"
#include "PascalTriangle.h"
#include "DynamicProgramming.h"

#include <iostream>

using namespace std;

void DynamicProgramming::runDpProblems() {
    PascalTriangle pascalTriangle;
    int res = pascalTriangle.getPascalTriangleValue(4, 2);
    cout << res << endl;
//    ClimbingStairs climbingStairs;
//    int res = climbingStairs.climbStairs(3);
//    cout << res;
}