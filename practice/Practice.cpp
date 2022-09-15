//
// Created by usman on 9/14/22.
//

#include <algorithm>
#include <iostream>
#include "Practice.h"
#include "../sort/questions/NearestNeighbors.h"

void Practice::runPracticeCode() {
    NearestNeighbors nearest;

    vector<vector<int>> n_points {{89,6},{-39,-4},{-13,91},{97,-61},{1,7},{-66,69},{-51,68},{82,-6},{-21,44},{-58,-83},{-40,73},{-88,-24}};
    vector<vector<int>> theP = nearest.nearest_neighbours(0, 0, 3, n_points);
    for (vector<int> v : theP) {
        for (int i : v) {
            cout << i << ",";
        }
        cout << endl;
    }
}