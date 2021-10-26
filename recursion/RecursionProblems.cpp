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

void RecursionProblems::runRecursionProblems() {
    vector<int> vec = {1, 2, 3, 4, 5};
    PermuteWithDuplicates permuteWithDuplicates;
    vector<vector<int>> res = permuteWithDuplicates.permuteIterative(vec);
//    NChooseK nChooseK;
//    vector<vector<int>> res = nChooseK.find_combinations(5,2);
    for (vector<int> & v: res) {
        for (int i : v) {
            cout << i << ",";
        }
        cout << endl;
    }
//    LetterCasePermutations letter;
//    vector<string> res = letter.letter_case_permutations("a1z");
//    RunPermutations runPermutations;
//    vector<int> vec {1,2,3};
//    runPermutations.get_permutations(vec);
}
