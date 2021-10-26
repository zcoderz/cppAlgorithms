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
#include <fstream>

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
#include "questions/FourSum.h"
#include "questions/SortColors.h"
#include "questions/SortAllCharacters.h"
#include "questions/NearrestNeighbors.h"
#include "boost/algorithm/string.hpp"

#include <set>
#include <vector>

using namespace std;
using namespace chrono;
void SortChecks::runSortChecks(){

//    vector<vector<int>> n_points;
//    fstream file;
//    file.open("/home/usman/work/cppAlgorithms/sort/questions/data/top_k_data1.txt", ios::in);
//    if (file.is_open()) {
//        string line;
//        while (getline(file, line)) {
//            vector<string> strs;
//            boost::split(strs,line,boost::is_any_of(" "));
//            vector<int> points;
//            for (string str: strs) {
//                int val = stoi(str);
//                points.push_back(val);
//            }
//            n_points.push_back(points);
//        }
//    }
//
//
//    NearestNeighbors nearest;
//
//    int x = 0;
//    int y = 0;
//    int topNum =10;
//    vector<vector<int>> theP = nearest.nearest_neighbours(x, y, topNum, n_points);
//
//    sort(n_points.begin(), n_points.end(), [&x, &y] (vector<int> a, vector<int> b) {
//        long long diffAX = (a[0]-x); long long diffAY = (a[1]-y);
//        double d1 =  sqrt( pow(diffAX, 2) + pow(diffAY, 2));
//        long long diffBX = (b[0]-x); long long diffBY = (b[1]-y);
//        double d2 =  sqrt( pow(diffBX, 2) + pow(diffBY, 2));
//        return d1 < d2;
//    } );
//
//    set<vector<int>> setA;
//    int i =0;
//    for (vector<int> v1: n_points) {
//        if (i > topNum) break;
//        setA.insert(v1);
//        i++;
//    }
//
//    set<vector<int>> setB;
//    i =0;
//    for (vector<int> v1: theP) {
//        if (i > topNum) break;
//        setB.insert(v1);
//        i++;
//    }
//
//    vector<vector<int>> res;
//    std::set_difference(setA.begin(), setA.end(), setB.begin(), setB.end(), back_inserter(res));
//    cout.precision(17);
//    cout << "order via sort is " << endl;
//    for (int i =0; i < topNum+1; i++) {
//        cout << n_points[i][0] << "," << n_points[i][1]  << " " << NearestNeighbors::distance(n_points[i][0], n_points[i][1], 0, 0) << endl;
//    }
//
//    cout << "order via custom sort is " << endl;
//    for (int i =0; i < topNum; i++) {
//        cout << theP[i][0] << "," << theP[i][1] << " " << NearestNeighbors::distance(theP[i][0], theP[i][1], 0, 0) << endl;
//    }
//
//    cout << "Diff size is " << res.size() << endl;
//    for (int i =0; i < res.size(); i++) {
//        cout << "missing = " << res[i][0] << ", " << res[i][1] << endl;
//    }


    NearestNeighbors nearest;
    vector<int> v1 {1, 0};
    vector<int> v2 {2,  1};
    vector<int> v3 {0, 1};
//    vector<int> v4 {0, -1};
    vector<vector<int>> n_points {v1, v2, v3};
    vector<vector<int>> theP = nearest.nearest_neighbours(0, 0, 2, n_points);
    sort(n_points.begin(), n_points.end());
    for (vector<int> v : theP) {
        for (int i : v) {
            cout << i << ",";
        }
        cout << endl;
    }

//    vector<char> vecChar = {'a','z','i','#','&','l','c'};
//    SortAllCharacters sortAllCharacters;
//    sortAllCharacters.sort_array(vecChar);
//    for (char ch : vecChar) {
//        cout << ch << ",";
//    }
    //vector<int> vec = {2,2,2,2,2};
//    vector<int> vec = {-2,-1,-1,1,1,2,2};
//
//    FourSum fourSum;
//    vector<vector<int>> res = fourSum.fourSum(vec, 0, 4);
//    ThreeSum threeSum;
//    vector<vector<int>> res = threeSum.threeSum(vec);
//    for (vector<int> v : res) {
//        for (int i : v) {
//            cout << i << ",";
//        }
//        cout << endl;
//    }

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

