//
// Created by usman on 9/14/22.
//

#include <algorithm>
#include <iostream>
#include "Practice.h"
#include "../sort/questions/NearestNeighbors.h"
#include "../bits/FourBillion.h"

void Practice::runPracticeCode() {

    vector<long> vals{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    long ret = FourBillion::find_integer(vals);
    cout << ret << endl;
//    NearestNeighbors nearest;
//    vector<vector<int>> n_points {{89,6},{-39,-4},{-13,91},{97,-61},{1,7},{-66,69},{-51,68},{82,-6},{-21,44},{-58,-83},{-40,73},{-88,-24}};
//    vector<vector<int>> theP = nearest.nearest_neighbours(0, 0, 3, n_points);
//    for (vector<int> v : theP) {
//        for (int i : v) {
//            cout << i << ",";
//        }
//        cout << endl;
//    }
}