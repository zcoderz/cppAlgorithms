//
// Created by usman on 11/14/22.
//

#ifndef CPPALGORITHMS_CROSSINGHANDS_H
#define CPPALGORITHMS_CROSSINGHANDS_H

#include <vector>
#include <iostream>
using namespace std;

/**
 * DINOSAUR : need to do this again!!
 */
class CrossingHands {
public:
    static int numberOfWays(int numPeople) {
        int MOD = 1000000007;
        vector<long> dp(numPeople+1);
        dp[0] = 1;
        //choose 2 people and divide the rest of people into two groups
        //one group of people is on left and the other on right
        //so for a total of 4 person. the combinations are :
        //0 on left (1&3 shake) and on right (2&4 shake)
        //0 on right (3&4 shake) and on left (1&2 shake)
        //for each number on left and that on right you multiply then to get a cross product
        //the numbers on left and right have to be even for hands to not cross.
        //hence you increment the division in even numbers
        //you work the total number of people from small to large....
        for (int personNo=2; personNo <= numPeople; personNo +=2) {
            for (int j=2; j <= personNo; j+=2) {
                int noPeopleOnLeft = j - 2;
                int noPeopleOnRight = personNo - j;
                dp[personNo] = (dp[personNo] + (dp[noPeopleOnLeft] * dp[noPeopleOnRight])) % MOD;
            }
        }
        return dp[numPeople];
    }

    static void testMe() {
        int v = numberOfWays(4);
        cout << v << endl;
    }
};

#endif //CPPALGORITHMS_CROSSINGHANDS_H
