//
// Created by usman on 10/23/21.
//

#ifndef CPPALGORITHMS_FOURBILLION_H
#define CPPALGORITHMS_FOURBILLION_H

#include <vector>
#include <algorithm>
#include "math.h"
using namespace std;

/**
 * Questions asks that you are given 4 billion numbers, find first missing!
 * 4 billion ints will take 4*2^32 = 2^34 (4 billion is close to 2^32) which is 16GB+
 *
 */
class FourBillion {
public:
    /**
     * 1 GB solution. Construct a design where :
     * -->use bits in a char to denote 8 numbers in a range
     * -->divide the 4 billion (2^32) range into 2^32/8 ranges = 2^29 ranges
     * -->2^29 ~ 0.5GB!
     * @param arr
     * @return
     */
    long find_integer_one_gb(vector<long> &arr) {
        int numRanges = (1LL << 32)/8;
        char * totalRanges = new char [numRanges];
        fill(totalRanges, totalRanges + numRanges, 0);
        for (long val: arr) {
            long index = val/8;
            long bit = val % 8;
            totalRanges[index] |= 1 << bit;
        }

        for (int byteIndex =0; byteIndex < numRanges; byteIndex++) {
            char ch = totalRanges[byteIndex];
            for (int bitIndex =0; bitIndex < 8; bitIndex++) {
                if ((ch & 1 << bitIndex) == 0) {
                    long v = byteIndex * 8 + bitIndex;
                    delete [] totalRanges;
                    return v;
                }
            }
        }
        return 0;
    }

    /**
     *
     * less memory but multiple iterations.
     *
     * 10 MB solution.  Divide partition into chunks of 2^16.
     * In each chunk calculate the total number of data points (use int for that)
     * int * chunks = new int [2^16]
     * increment chunk count for a number as each number is found.
     * work on all chunks. find first chunk that has a number missing.
     * then allocate a boolean for each number in the 2^16 chunk.
     * find first index that is missing in the chunk and return.
     * @return
     */
    static long find_integer(vector<long> &arr) {
        int MAX_SZ = pow(2,16);
        ushort * buckets =  new ushort[MAX_SZ];
        std::fill_n(buckets, MAX_SZ, 0);
        for (long val : arr) {
            val = val >> 16;
            buckets[val]++;
        }

        bool * valBucket =  new bool [MAX_SZ];
        std::fill_n(valBucket, MAX_SZ, 0);

        for (int i =0; i < MAX_SZ; i++) {
            if (buckets[i] < MAX_SZ) {
                for (long val : arr) {
                    int bucketIndex = val >> 16;
                    if (bucketIndex == i) {
                        ushort index = val & (MAX_SZ-1);
                        valBucket[index]= true;
                    }
                }

                for (int j = 0; j < MAX_SZ ; j++) {
                    if (!valBucket[j]) {
                        long val = i << 16;
                        val += j;
                        delete [] buckets;
                        delete [] valBucket;
                        return val;
                    }
                }
            }
        }

        delete [] buckets;
        delete [] valBucket;
    }

};
#endif //CPPALGORITHMS_FOURBILLION_H