//
// Created by usman on 11/10/22.
//

#ifndef CPPALGORITHMS_COUNTNUMBEROFONESINBINARYSTRING_H
#define CPPALGORITHMS_COUNTNUMBEROFONESINBINARYSTRING_H

#include <vector>
#include <iostream>

using namespace std;

class BinaryStringWithoutConsecutiveOnes {
public:
    static int numberOfDigitsWithoutConsecutiveOnes(int theNo) {
        vector<int> ones (theNo+1);
        vector<int> zeroes (theNo+1);
        ones[0]=1;
        zeroes[0]=1;
        for (int i =1; i <= theNo; i++) {
            zeroes[i] += (zeroes[i-1] + ones[i-1]);
            ones[i] += (zeroes[i-1] + (i-2 >=0 ? ones[i-2] : 0));
        }
        return ones[theNo] + zeroes[theNo];
    }

    static int processRecur(int no, int priorOne) {
        if (no==0) {
            return 1;
        }
        int cnt = 0;
        if (priorOne == -1) {
            cnt = processRecur(no-1, 1);
            cnt += processRecur(no-1, 0);
        } else if (priorOne == 1) {
            cnt = processRecur(no-1, 0);
        } else {
            cnt = processRecur(no-1, 1);
        }
        return cnt;
    }

    static void testMe() {
        int res = processRecur(3, -1);
        //int res = numberOfDigitsWithoutConsecutiveOnes(3);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_COUNTNUMBEROFONESINBINARYSTRING_H
