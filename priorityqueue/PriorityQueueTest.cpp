//
// Created by usman on 10/17/21.
//

#include "PriorityQueue.h"
#include "PriorityQueueTest.h"
#include <random>
#include <iostream>

using namespace std;
void PriorityQueueTest::testPQ() {
    PriorityQueue<int> pQ(true);

    for (int i =0; i < 100; i++) {
        std::random_device rd; // obtain a random number from hardware
        std::mt19937 gen(rd()); // seed the generator
        int sz = 1000000;
        std::uniform_int_distribution<> distr(0, sz/100); // define the range
        pQ.insert(distr(gen));
    }

//    while (!pQ.getSize() ==0) {
//        cout << pQ.getTop()  << ", ";
//    }

    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    int sz = 100;
    std::uniform_int_distribution<> distr(0, sz*100); // define the range
    int * data = new int [sz];
    for (int i =0; i < sz; i++) {
        data[i] = distr(gen);
    }

    PriorityQueue<int> pQ2(data, sz, true);
    while (!pQ2.getSize() ==0) {
        cout << pQ2.getTop()  << ", " << pQ2.getSize() << endl;
    }

}