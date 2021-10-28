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
void TOH(int n,char Sour, char Aux,char Des)
{
    if(n==1)
    {
        cout<<"Move Disk "<<n<<" from "<<Sour<<" to "<<Des<<endl;
        return;
    }

    TOH(n-1,Sour,Des,Aux);
    cout<<"Move Disk "<<n<<" from "<<Sour<<" to "<<Des<<endl;
    TOH(n-1,Aux,Sour,Des);
}

void RecursionProblems::runRecursionProblems() {
    //TOH(5,'A','B','C');

    vector<int> disks = {3,2,1};
    TowersOfHanoi towers;
    Tower a("a"); Tower b("b"); Tower c("c");
    a.disks = disks;
    towers.move(3, a, b, c);
    int res = 1;
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
//            cout << str << ",";
//        }
//        cout << endl;
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
//    for (string & str: vecRes) {
//        cout << str << endl;
//    }

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
