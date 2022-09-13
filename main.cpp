#include <iostream>
#include <iterator>

#include "bits/BitsTests.h"
#include "sort/SortChecks.h"
#include "priorityqueue/PriorityQueueTest.h"
#include "operatorchecks/OperatorChecks.h"
#include "recursion/RecursionProblems.h"
#include "trees/TreeProblems.h"
#include "misc/MiscQuestions.h"
#include "graph/GraphProblems.h"
#include "dynamic_programming/DynamicProgramming.h"
#include "recursion/Power.h"
#include "recursion/StringsFromWildChar.h"
#include "recursion/TowersOfHanoi.h"

int main() {

    Tower towerA("src");
    towerA.disks.push_back(4);
    towerA.disks.push_back(3);
    towerA.disks.push_back(2);
    towerA.disks.push_back(1);

    Tower towerB("aux");
    Tower towerC("dest");
    TowersOfHanoi::move(4, towerA, towerB, towerC);
    int j = 1;
    //    std::string str("?11?");
    //    vector<string> ret= StringTest::find_all_possibilities(str);
    //    std::copy(ret.begin(), ret.end(),  std::ostream_iterator<string> (std::cout, ", "));
    //int j = 1;
    //int val = Power::calculate_power(123, 123);
    //cout << val << endl;
    //DynamicProgramming dynamicProgramming;
    //dynamicProgramming.runDpProblems();
//    GraphProblems graphProblems;
//    graphProblems.runGraphProblems();
    //MiscQuestions miscQuestions;
    //miscQuestions.runMiscQuestions();
//    TreeProblems treeProblems;
//    treeProblems.runTreeProblems();
    //RecursionProblems recursionProblems;
    //recursionProblems.runRecursionProblems();
    //BitTests bitTests;
    //bitTests.runBitTests();
    //OperatorChecks opChecks;
    //opChecks.testOperators();
//    SortChecks sortChecks;
//    sortChecks.runSortChecks();
//    PriorityQueueTest pQTest;
//    pQTest.testPQ();
    return 0;
}

