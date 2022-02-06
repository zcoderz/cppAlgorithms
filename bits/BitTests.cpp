//
// Created by usman on 10/23/21.
//

#include <iostream>

#include "BitsTests.h"
#include "FourBillion.h"

using namespace std;
void BitTests::runBitTests() {
    FourBillion fourBillion;
    vector<long> vec = {4294967295,399999999,0};
    int v = fourBillion.find_integer_one_gb(vec);
    cout << v << endl;


}