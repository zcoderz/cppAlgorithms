//
// Created by usman on 10/26/21.
//

#include <iostream>

using namespace std;

#include "RecursionProblems.h"
#include "RunPermutations.h"
#include "LetterCasePermutations.h"
#include "NChooseK.h"
#include "PermuteWithDuplicates.h"
#include "GetWordsFromPhoneNumber.h"
#include "AllCombinationsWithSumQualToTarget.h"
#include "CombinationSum.h"
#include "SubSetsWithDuplicates.h"
#include "PalindromePartitioning.h"
#include "Parenthesis.h"
#include "PascalTriangle.h"
#include "TowersOfHanoi.h"
#include "BSTWithNodes.h"
#include "NQueens.h"
#include "SolveSudoku.h"
#include "GenerateAllExpressions.h"

void RecursionProblems::runRecursionProblems() {

    GenerateAllExpressions generateAllExpressions;
    vector<string> vecRes = generateAllExpressions.generate_all_expressions("6666666666666", 6);
//    SolveSudoku solveSudoku;
//    vector<vector<int>> board = {
//    {8, 4, 9, 0, 0, 3, 5, 7, 0},
//    {0, 1, 0, 0, 0, 0, 0, 0, 0},
//    {7, 0, 0, 0, 9, 0, 0, 8, 3},
//    {0, 0, 0, 9, 4, 6, 7, 0, 0},
//    {0, 8, 0, 0, 5, 0, 0, 4, 0},
//    {0, 0, 6, 8, 7, 2, 0, 0, 0},
//    {5, 7, 0, 0, 1, 0, 0, 0, 4},
//    {0, 0, 0, 0, 0, 0, 0, 1, 0},
//    {0, 2, 1, 7, 0, 0, 8, 6, 5}};
//    solveSudoku.solve_sudoku_puzzle(board);
//    int j = 1;

//    NQueens nQueens;
//    vector<vector<string>> vecRes = nQueens.find_all_arrangements(4);
//    BSTWithNodes bst;
//    long long int res = bst.how_many_BSTs(10);
//    cout << res << endl;
//    vector<int> disks = {3,2,1};
//    TowersOfHanoi towers;
//    Tower a("a"); Tower b("b"); Tower c("c");
//    a.disks = disks;
//    towers.move(3, a, b, c);

//    PascalTriangle pascal;
//    vector<int> vecRes = pascal.getRow(4);
//    for(int v : vecRes) {
//        cout << v << ",";
//    }
//    Parenthesis parentheses;
//    vector<string> vecRes = parentheses.generateParenthesis(3);
//    PalindromePartitioning partitioning;
//    vector<vector<string>> vecRes = partitioning.partition("aab");
//    for (vector<string> & vec : vecRes) {
//        for (string & str: vec) {
//            cout << str << endl;
//        }
//        cout << "eeeeeendddddd" << endl;
//    }
//    //SubSetsWithDuplicates subSetsWithDuplicates;
    //vector<string> vecRes = subSetsWithDuplicates.get_distinct_subsets("dc");
    //CombinationSum combinationSum;
    //vector<vector<int>> res = combinationSum.combinationSum3(3, 9);
//    vector<int> v = { 1,2,3,3,4,5};
//    SumEqualToTarget sumEqualToTarget;
//    vector<vector<int>> res = sumEqualToTarget.generate_all_combinations(v, 6);
//    GetWordsFromNumbers phone;
//    vector<string> vecRes = phone.getWordsFromPhoneNumber("1010101");
    for (string & str: vecRes) {
        cout << str << endl;
    }

//    vector<int> vec = {1, 2, 2, 3};
//    PermuteWithDuplicates permuteWithDuplicates;
//    //vector<vector<int>> res = permuteWithDuplicates.permuteIterative(vec);
//    vector<vector<int>> res = permuteWithDuplicates.get_permutations(vec);
//    NChooseK nChooseK;
//    vector<vector<int>> res = nChooseK.find_combinations(5,2);
//    for (vector<int> & v: res) {
//        for (int i : v) {
//            cout << i << ",";
//        }
//        cout << endl;
//    }
//    LetterCasePermutations letter;
//    vector<string> res = letter.letter_case_permutations("a1z");
//    RunPermutations runPermutations;
//    vector<int> vec {1,2,3};
//    runPermutations.get_permutations(vec);
}
