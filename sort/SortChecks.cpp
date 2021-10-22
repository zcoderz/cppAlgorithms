//
// Created by usman on 10/13/21.
//
#include <boost/sort/sort.hpp>
#include <iostream>
#include <random>
#include "SelectionSort.h"
#include "SortChecks.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "ThreeWayQuickSort.h"
#include "FourWayQuickSort.h"
#include "MergeSortBottomUp.h"
#include <unistd.h>
#include <set>
#include <chrono>

#include "questions/GroupNumbers.h"
#include "questions/MergeVectors.h"
#include "questions/DutchNationalFlag.h"
#include "questions/TwoSum.h"
#include "questions/TwoSumNonSorted.h"
#include "questions/MergeSortedSinglyLinkedLists.h"
#include "questions/AttendMeetings.h"
#include "questions/TopKFrequent.h"
#include "questions/KthLargestInStream.h"
#include "questions/KthLargestInAnArray.h"
#include "questions/OnlineMedian.h"
#include "questions/IntersectionOfThreeSortedArrays.h"
#include "questions/ThreeSum.h"
using namespace std;
using namespace chrono;
void SortChecks::runSortChecks(){
    vector<int> vec = {1,-1,-1,0};
    ThreeSum threeSum;
    vector<vector<int>> res = threeSum.threeSum(vec);
    for (vector<int> v : res) {
        for (int i : v) {
            cout << i << ",";
        }
        cout << endl;
    }

//    vector<int> valA = {1, 2};
//    vector<int> valB = {3,4};
//    vector<int> valC = {5,6};
//    IntersectionOfThreeSortedArrays intersection;
//    vector<int> res = intersection.find_intersection(valA, valB, valC);
//    for (int val : res) {
//        cout << val << "," << endl;
//    }

//    OnlineMedian median;
//    vector<int> vals = {3, 8, 5, 2};
//    vector<int> res = median.online_median(vals);
//    for (int v: res) {
//        cout << v  << ",";
//    }
//    vector<int> first = {1,1,1,1,1, 1000000000};
//    vector<int> second = {100000};
//    KthLargestInStream kth;
//    vector<int> res = kth.kth_largest(4, first, second);
//    for (int i =0; i < res.size(); i++) {
//        cout << res[i] << endl;
//    }

//    QuickSort quickSort;
//    int data[] = {1,2,2,2};
//    quickSort.runQuickSort(data, 4);
//    for (int i =0; i < 4; i++) {
//        cout << data[i] << ", ";
//    }
//    cout << endl;
//    TopKFrequent topK;
//    vector<int> vec = {1,2,3,2,4,3,1};
//    int k = 2;
//    vector<int> resVec = topK.find_top_k_frequent_elements(vec, k);
//    for (int i =0; i < resVec.size() ; i++) {
//        cout << resVec[i] << ",";
//    }
//    GroupNumbers groupNumbers;
//    vector<int> arr = {4,9,5,2,9,5,7,10};
//    arr = groupNumbers.solve(arr);
//    for (int i =0; i < arr.size(); i++) {
//        cout << arr[i] << ", " ;
//    }
//    cout << endl;
//    vector<int> arr1 = {1,2,7,14};
//    vector<int> arr2 = {2,3,5,6,0,0,0,0};
//    MergeVectors merge ;
//    merge.merger_first_into_second(arr1, arr2);
//    for (int i =0; i < arr2.size(); i++) {
//        cout << arr2[i] << ", " ;
//    }
//    cout << endl;

//    vector<int> arr1 = {15,17};
//    vector<int> arr2 = {10,11};
//    vector<int> arr3 = {2,12};
//    AttendMeetings attendMeetings;
//    vector<vector<int>> vec {arr1, arr2, arr3};
//    int res = attendMeetings.can_attend_all_meetings(vec);
//    cout << res << endl;
//    std::random_device rd; // obtain a random number from hardware
//    std::mt19937 gen(rd()); // seed the generator
//    int sz = 1000000;
//    std::uniform_int_distribution<> distr(0, sz/100); // define the range
//    int * data = new int [sz];
//    for (int i =0; i < sz; i++) {
//        data[i] = distr(gen);
//    }

//    steady_clock::time_point t1 = steady_clock::now();
//    SelectionSort selectionSort;
//    selectionSort.runSelectionSort(data, sz);
//    steady_clock::time_point t2 = steady_clock::now();
//    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
//    cout << "selection sort took " << time_span.count() << endl;
//    if (validateIssue(data, sz)) {
//        cout << "problem in comparison" << endl;
//    }
//
//    shuffle(data, data+sz, std::mt19937(std::random_device()()));
//    t1 = steady_clock::now();
//    BubbleSort bubbleSort;
//    bubbleSort.runBubbleSort(data, sz);
//    t2 = steady_clock::now();
//    time_span = duration_cast<duration<double>>(t2 - t1);
//    cout << "bubble sort took " << time_span.count() << endl;
//
//    if (validateIssue(data, sz)) {
//        cout << "problem in comparison" << endl;
//    }
//
//    shuffle(data, data+sz, std::mt19937(std::random_device()()));
//    InsertionSort insertionSort;
//    t1 = steady_clock::now();
//    insertionSort.runInsertionSort(data, sz);
//    t2 = steady_clock::now();
//    time_span = duration_cast<duration<double>>(t2 - t1);
//    cout << "insertion sort took " << time_span.count() << endl;
//
//    if (validateIssue(data, sz)) {
//        cout << "problem in comparison" << endl;
//    }

//    shuffle(data, data+sz, std::mt19937(std::random_device()()));
//    steady_clock::time_point t1 = steady_clock::now();
//    MergeSort mergeSort;
//    mergeSort.runMergeSort(data, sz);
//    steady_clock::time_point t2 = steady_clock::now();
//    duration<double>  time_span = duration_cast<duration<double>>(t2 - t1);
//    cout << "merge sort took " << time_span.count() << endl;
//
//    if (validateIssue(data, sz)) {
//        cout << "problem in comparison" << endl;
//    }
//
//    shuffle(data, data+sz, std::mt19937(std::random_device()()));
//    t1 = steady_clock::now();
//    QuickSort quickSort;
//
//    quickSort.runQuickSort(data, sz);
//
//    t2 = steady_clock::now();
//    time_span = duration_cast<duration<double>>(t2 - t1);
//    cout << "quick sort took " << time_span.count() << endl;
//    if (validateIssue(data, sz)) {
//        cout << "problem in comparison" << endl;
//    }
//    shuffle(data, data+sz, std::mt19937(std::random_device()()));
//    t1 = steady_clock::now();
//    std::sort(data, data+sz);
//    t2 = steady_clock::now();
//    time_span = duration_cast<duration<double>>(t2 - t1);
//    cout << "stl sort took " << time_span.count() << endl;
//
//    shuffle(data, data+sz, std::mt19937(std::random_device()()));
//    t1 = steady_clock::now();
//    ThreeWayQuickSort threeWayQuickSort;
//    threeWayQuickSort.runQuickSort(data, sz);
//    t2 = steady_clock::now();
//    time_span = duration_cast<duration<double>>(t2 - t1);
//    cout << "threeway quick sort took " << time_span.count() << endl;
//    if (validateIssue(data, sz)) {
//        cout << "problem in comparison" << endl;
//    }
//    shuffle(data, data+sz, std::mt19937(std::random_device()()));
//    t1 = steady_clock::now();
//    boost::sort::block_indirect_sort(data,data+sz,24);
//    t2 = steady_clock::now();
//    time_span = duration_cast<duration<double>>(t2 - t1);
//    cout << "boost block indirect sort took " << time_span.count() << endl;
//
//    shuffle(data, data+sz, std::mt19937(std::random_device()()));
//    t1 = steady_clock::now();
//    boost::sort::pdqsort(data,data+sz);
//    t2 = steady_clock::now();
//    time_span = duration_cast<duration<double>>(t2 - t1);
//    cout << "boost pdq   sort took " << time_span.count() << endl;
//
//    shuffle(data, data+sz, std::mt19937(std::random_device()()));
//    t1 = steady_clock::now();
//    FourWayQuickSort fourWayQuickSort;
//    fourWayQuickSort.runQuickSort(data, sz);
//    t2 = steady_clock::now();
//    time_span = duration_cast<duration<double>>(t2 - t1);
//    cout << "four way quick   sort took " << time_span.count() << endl;
//
//
//
//    shuffle(data, data+sz, std::mt19937(std::random_device()()));
//    t1 = steady_clock::now();
//    MergeSortBottomUp mergeSortBottomUp;
//    mergeSortBottomUp.runMergeSort(& data, sz);
//    t2 = steady_clock::now();
//    time_span = duration_cast<duration<double>>(t2 - t1);
//    cout << "merge sort bottom up " << time_span.count() << endl;
//
//    cout << "Done" << endl << flush;
    usleep(1000);
}

bool SortChecks::validateIssue(int arr[], int sz) {
    return false;
    set<int> set;
    for (int i =0; i < sz; i++) {
        int val = arr[i];
        auto  iter = lower_bound(set.begin(), set.end(), val);
        if (iter != set.end() && *iter != val) {
            return true;
        }
        if (iter == set.end()) {
            set.insert(val);
        }
    }
    return false;
}

void SortChecks::print(int arr[], int size) {
    for (int i =0; i < size ; i++) {
        cout << arr[i] << ",";
    }
    cout << endl;
}

