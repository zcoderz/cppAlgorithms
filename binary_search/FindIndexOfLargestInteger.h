//
// Created by usman on 1/16/23.
//

#ifndef CPPALGORITHMS_FINDINDEXOFLARGESTINTEGER_H
#define CPPALGORITHMS_FINDINDEXOFLARGESTINTEGER_H

class LargestIntegerIndex {
    class ArrayReader {
           public:
             // Compares the sum of arr[l..r] with the sum of arr[x..y]
             // return 1 if sum(arr[l..r]) > sum(arr[x..y])
             // return 0 if sum(arr[l..r]) == sum(arr[x..y])
             // return -1 if sum(arr[l..r]) < sum(arr[x..y])
             int compareSub(int l, int r, int x, int y);

             // Returns the length of the array
             int length();
         };

    int getIndex(ArrayReader &reader) {
        int len = reader.length();
        int left = 0; int right = len-1;
        int leftOutIndex=len;
        while (right > left) {
            if ((right-left+1)%2 !=0) {
                //if length is odd, make the length even and mark the right most index as left out
                //then if the two partitions are same, the right most digit must have had the larger value
                leftOutIndex = right;
                right--;
            }
            int mid = left + (right-left) / 2;
            int comp = reader.compareSub(left, mid, mid+1, right);
            if (comp==0) {
                //the two partitions are same. the larger value must be which was left out as indicated above
                return leftOutIndex;
            } else if (comp > 0) {
                right=mid;
            } else {
                left=mid+1;
            }
        }
        return left;
    }
};

#endif //CPPALGORITHMS_FINDINDEXOFLARGESTINTEGER_H
