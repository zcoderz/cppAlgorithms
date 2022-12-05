//
// Created by usman on 12/3/22.
//

#ifndef CPPALGORITHMS_DIGITCOUNTINRANGE_H
#define CPPALGORITHMS_DIGITCOUNTINRANGE_H

#include <iostream>

using namespace std;

/**
 * Very interesting mathematical problem.
 *
 */
class DigitCountInRange {
public:

    int digitsCount(int d, int low, int high) {
        int lowV = countDigit( low-1, d );
        int highV = countDigit( high, d );
        return highV-lowV;
    }


    static int countDigit( int value, int digit ) {
        int count = 0;
        for( int pow10 = 1; pow10 <= value; pow10 *= 10 ) {
            int divisor = pow10 * 10;
            int quotient = value / divisor;
            if( quotient > 0 ) {
                //for 34 , we have 4,14,24,34 numbers with 4
                //34/10--> returns 3 which captures 4,14,24, below check corresponds the last 34 via remainder
                count += quotient * pow10;
            }
            if( digit == 0 ) {
                //for 0, the below remainder check will kick in and add pow10.
                //to negate the affect, need to subtract pow10 here.
                count -= pow10;
            }
            int remainder = value % divisor;
            if( remainder >= digit * pow10 ) {
                //for 46 in ones digit you get one 4 (generated via min on min(std::min( ...., pow10 ), pow10 is 1
                //for 46 in 10s digit you get 7 4s. 40...47 (remainder - digit *pow10 + 1)
                //for 460 in 100s digit you get remainder as 460. 460%1000. 460-4*100+1 generates 61.
                count += std::min( remainder - digit * pow10 + 1, pow10 );
            }
        }
        return count;
    }

    static void testMe() {
        //1743
        int res = countDigit(34, 0);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_DIGITCOUNTINRANGE_H
