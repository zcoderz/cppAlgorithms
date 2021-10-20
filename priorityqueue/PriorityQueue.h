//
//
// Created by usman on 10/17/21.
//

#ifndef KICK_START_PRIORITYQUEUE_H
#define KICK_START_PRIORITYQUEUE_H

#endif //KICK_START_PRIORITYQUEUE_H

#include <algorithm>
using namespace std;

template <class T>
class PriorityQueue {
public:

    PriorityQueue(bool isMaxP) {
        capacity = 100;
        data = new int [capacity];
        numElements = 0;
        isMax = isMaxP;
    }

    PriorityQueue(T dataP[], int size, bool isMaxP) {
        data = new T[size+1];
        for (int i =0; i < size ; i++) {
            data[i+1] = dataP[i];
        }

        capacity = size;

        numElements=size;
        isMax = isMaxP;

        //start from the first possible root of the heap which will be at size / 2
        for (int k = size/2; k >=1 ; k--) {
            sink(k);
        }

    }

    //if heap already existed, it can be sorted to put top element at bottom and iteratively working
    //on the rest of the elements
    void sort() {
        int k = numElements;
        while (k > 1) {
            swap(data[1] , data[k--]);
            sink(1, k);
        }
    }

    void insert(T val) {
        if (numElements == capacity) resize(capacity*2);
        data[++numElements] = val;
        swim(numElements);
    }

    int getSize() {
        return numElements;
    }

    T getTop() {
        T val = data[1];
        swap(data[1], data[numElements--]);
        sink(1);
        return val;
    }


private:
    void resize(int newSz) {
        T * newData = new T[newSz];
        copy(data, data+sizeof(T)*capacity, newData);
        capacity = newSz;
        data = newData;
        delete [] data;
    }

    void sink(int k ) {
        sink(k, numElements);
    }

    void sink(int k, int limit ) {
        while (2*k <= limit) {
            int j = 2*k;
            if (j < numElements && compare(j+1, j) > 0) {
                j++; //pick second child if its comparable (greater/less) than j
            }
            if (compare(k, j) > 0) {
                break; //stop if data is at the correct location
            }
            swap(data[k], data[j]);
            k = j;
        }
    }

    /**
     * move the data from bottom to where it belongs
     * @param k
     */
    void swim(int k) {
        while (k > 1 && compare(k , k/2) > 0) {
            swap(data[k], data[k/2]);
            k = k/2;
        }
    }

    int compare(int i, int j) {
        if (data[i] == data[j]) {
            return 0;
        }
        if (isMax) {
            if (data[i] > data[j]) {
                return 1;
            } else {
                return -1;
            }
        } else {
            if (data[i] > data[j]) {
                return -1;
            } else {
                return 1;
            }
        }
    }

    T * data;
    int numElements;
    int capacity;
    bool  isMax;
};