//
// Created by usman on 1/4/23.
//

#ifndef CPPALGORITHMS_PARALLELCOUSESTWO_H
#define CPPALGORITHMS_PARALLELCOUSESTWO_H

#include <vector>
#include <iostream>
using namespace std;

/**
 * This is a very interesting problem !!
 *
 */
class ParallelCoursesTwo {
public:
    vector<int> memo;
    vector<vector<int>> dependencies;
    int k;
    int numCourses;
    int solveMin(int mask) {
        //__builtin_popcount returns number of 1 bits in an integer
        if (__builtin_popcount(mask)==numCourses) return 0; //all courses are already taken
        //use a memo to avoid repetitive work
        //example if we have courses 1,2,3. once we process course [2 & 3] , the number of ways to process course [1]
        //is same as if we had processed courses [3 & 2] and had course 1 left. assume 1 course per semester.
        if (memo[mask] != -1)  return memo[mask];
        //find courses that can be taken
        int possibles=0;
        for (int i =1; i < dependencies.size(); i++) {
            if (mask & 1<<i) continue; //already taken skip!
            bool possible = true;
            for (int j :dependencies[i]) {
                if ((mask & 1<<j)) continue;
                possible= false; //dependency not yet taken
                break;
            }
            if (possible) {
                possibles |= 1 << i;
            }
        }
        //set ans to a large number at beginning . numCourses+1 is max possible (1 course per semester + 1)
        int ans = numCourses+1;
        if (__builtin_popcount(possibles) > k) {
            //find subset of possible courses
            //(j-1) removes one bit from current for next subset.
            //& with possibles since possibles indicates universe of possible courses in this iteration
            for (int j = possibles; j > 0; j = (j-1) & (possibles)) {
                if (__builtin_popcount(j) != k) continue; //ignore subsets that are not k in length
                ans = min(ans, solveMin(mask|j)+1);
            }
        } else {
            //less than k courses left , so dont need to work through subset
            ans =  solveMin(mask | possibles) + 1;
        }
        memo[mask] = ans;
        return ans;
    }

    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        memo.resize(1<<(n+1), -1);
        dependencies.resize(n+1);
        for (auto & vec: relations) {
            dependencies[vec[1]].push_back(vec[0]);
        }
        this->k = k;
        this->numCourses = n;
        return solveMin(0);
    }

    static void testMe() {
        vector<vector<int>> courseDeps; // = {{2,1},{3,1},{4,1},{1,5}};
        ParallelCoursesTwo pCourses;
        int res = pCourses.minNumberOfSemesters(3, courseDeps, 1);
        cout << res;
    }
};

#endif //CPPALGORITHMS_PARALLELCOUSESTWO_H
