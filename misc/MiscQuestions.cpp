//
// Created by usman on 11/7/21.
//

#include<iostream>
using namespace std;

#include "MiscQuestions.h"
#include "Ipv6Compress.h"

void MiscQuestions::runMiscQuestions() {
    IPV6Compress ipv6Compress;
    string comp = ipv6Compress.runCompression("2001:4860:4860:0000:0000:0000:0000:8888");
    cout << comp << endl;
}