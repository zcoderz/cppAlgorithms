//
// Created by usman on 12/3/22.
//

#ifndef CPPALGORITHMS_NONNEGATIVEINTEGERSWITHOUTCONSECUTIVEONES_H
#define CPPALGORITHMS_NONNEGATIVEINTEGERSWITHOUTCONSECUTIVEONES_H

#include <iostream>
using namespace std;
class NonNegativeIntegers {
public:
    /**
     * below is a very elegant algo for this problem taken from
     * https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/solutions/103749/java-solution-dp/
     *
     * if bit[i] == 1
       if bit[i + 1] == 0, there's no solutions in res that is larger than num, we go further into smaller bit and subtract.
       if bit[i + 1] == 1, we know in those res solutions it won't have any consecutive ones. when bit[i + 1] == 1,
       in one[i + 1], the i-th bit in valid solutions must be 0, which are all smaller than 'num',
       we don't need to check smaller bits and subtract, so we break form the loop.
       if bit[i] == 0
       if bit[i + 1] == 1, there's no solutions in res that is larger than num, we go further into smaller bit and subtract.
       if bit[i + 1] == 0, we know zero[i + 1] includes solutions of i-th == 0 (00***) and i-th bit == 1 (01***),
       we know the i-th bit of num is 0, so we need to subtract all the 01*** solutions because it is larger than num.
       Therefore, one[i] is subtracted from res.
     *
     * @param num
     * @return
     */
    static int findIntegers(int num) {
        vector<int> bits;
        //put the num bits into the vector from lowest to highest bit
        while (num>0) {
            bits.push_back((num & 1));
            num = (num >> 1);
        }
        int n = bits.size();
        //zeros and ones represent valid bit states for every index up to the right most 1st bit in num (thats represented by n)
        vector<int> zero(n, 0);
        vector<int> one(n, 0);
        zero[0] = 1; one[0] = 1;
        for (int i =1; i <n; i++) {
            zero[i] = zero[i-1] + one[i-1];
            one[i] = zero[i-1];
        }
        //set the total number of possibilities of valid number as total at the last bit (n-1)
        int res = one[n-1] + zero[n-1];
        int i  = n-2;
        while (i >=0) {
            //if current and next are both zero then the number of ones in the current index must be subtracted
            if (bits[i]==0 && bits[i+1]==0) {
                res -= one[i];
            }
            //if current and next are both one then we no longer need to subtract, since the number of valid options
            //can be any valid number up till the current index...i.e. 11xxx such as 10xxx or 01xxx or 00xxx
            if (bits[i]==1 && bits[i+1]==1) {
                break;
            }
            i--;
        }
        return res;
    }

    static void testMe() {
        int res = findIntegers(7);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_NONNEGATIVEINTEGERSWITHOUTCONSECUTIVEONES_H
