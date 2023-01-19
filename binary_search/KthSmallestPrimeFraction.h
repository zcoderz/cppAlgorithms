//
// Created by usman on 1/18/23.
//

#ifndef CPPALGORITHMS_KTHSMALLESTPRIMEFRACTION_H
#define CPPALGORITHMS_KTHSMALLESTPRIMEFRACTION_H

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class KthSmallestPrimeFraction {
public:

    /**
     * Method returns how many fractions in array were less than x
     * and also returns the largest such fraction.
     * fraction is considered based on arr[i]/arr[j] where j > 1
     * @param arr
     * @param x
     * @return
     */
    static vector<int> possible(vector<int> & arr , double x) {
        int cnt=0;
        int priorNum = 0; int priorDenom = 1;
        for (int i= 0; i < arr.size()-1; i++) {
            int j = arr.size()-1;
            while (i < j && arr[i] < arr[j]*x) j--;
            //j index indicates the denom index where arr[i]/arr[j] < x.
            //j is one further off to the left because of the above loop
            //hence, number of fractions where is based on how many indexes to left is j from the last index (arr.size()-1)
            int newCnt = max((int) arr.size()-1-j, 0);
            cnt += newCnt;
            //priorNum/priorDenom < num / denom can be simplified to : priorNum*denom < num * priorDenom
            //arr[i] is current numerator and arr[j] is current denominator
            //if new fraction is greater than prior then store it, so it can be returned as the largest fraction
            if (newCnt > 0 && priorNum * arr[j+1] < priorDenom * arr[i]) {
                //keep track of the largest denom in each iteration.
                priorNum = arr[i];
                priorDenom = arr[j+1];
            }
        }
        return {cnt, priorNum, priorDenom};
    }

    static vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        double lo = 0;
        double hi = 1;
        vector<int> res(2);
        //break when difference between hi and lo is less than delta 1e-9
        while ((hi-lo) > 1e-9) {
            double mid = lo + (hi-lo)/2.0;
            auto val = possible(arr, mid);
            //converge towards mid depending on whether more than k fractions are present or otherwise
            //dont need to do lo = mid+1 since the search breaks at an epsilon
            if (val[0] >= k) {
                hi = mid;
                res[0] = val[1];
                res[1] = val[2];
            } else {
                lo=mid;
            }
        }
        return res;
    }

    static void testMe() {
        vector<int> arr = {1,2,3,5}; int k = 3;
        auto res = kthSmallestPrimeFraction(arr, k);
        cout << res[0] << ", " << res[1] << endl;
    }
};

#endif //CPPALGORITHMS_KTHSMALLESTPRIMEFRACTION_H
