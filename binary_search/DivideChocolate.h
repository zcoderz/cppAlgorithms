//
// Created by usman on 1/17/23.
//

#ifndef CPPALGORITHMS_DIVIDECHOCOLATE_H
#define CPPALGORITHMS_DIVIDECHOCOLATE_H

#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>
#include <iostream>

using namespace std;

/**
 * This is an interesting problem.
 * It appears to be an optimization problem but in fact needs a greedy/binary-search solution.
 */
class DivideChocolate {
public:
    static int maximizeSweetness(vector<int>& sweetness, int k) {
        int total = accumulate(sweetness.begin(), sweetness.end(), 0);
        int numPpl = k+1;
        //total/(numPpl) ensures the most even distribution and therefore will definitely create a viable solution
        //hence is set as max value.
        int maxValue = total/(numPpl);
        //min is set to the smallest chunk size
        int minValue = *min_element(sweetness.begin(), sweetness.end());
        //find workable solutions between min and max
        //return the highest possible such solution

        while (maxValue > minValue) {
            int currentChunk = 0;
            //+1 to round up [3,4] , mid will be 4, if 4 doesnt work, right will get reduced to 3
            int mid = minValue + (maxValue-minValue+1)/2;
            int divisions = 0;
            for (int val: sweetness) {
                currentChunk += val;
                if (currentChunk >= mid) {
                    divisions++;
                    currentChunk = 0;
                }
            }
            //the last value of currentChunk above is ignored when it is smaller than mid,
            //that's because when it's smaller than the mid, it must be merged in to the previous chunk

            //divisions indicates number of ppl who got a piece while keeping chunk boundary at mid
            //thus when the chunk value at mid is a viable solution and hence minvalue is moved to it
            //if the chunk value at mid is less than the number of people, it means that keeping chunks at size
            //mid, enough folks didn't get a bar. hence the chunk size needs be reduced in next retry.
            if (divisions >= numPpl) {
                minValue=mid;
            } else {
                maxValue = mid-1;
            }
        }
        return minValue;
    }

    static void testMe() {
        vector<int> data = {1,2,3,4,5,6,7,8,4};
        int res = maximizeSweetness(data, 5);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_DIVIDECHOCOLATE_H
