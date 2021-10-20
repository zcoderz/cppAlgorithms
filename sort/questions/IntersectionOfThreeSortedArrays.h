//
// Created by usman on 10/19/21.
//

#ifndef KICK_START_INTERSECTIONOFTHREESORTEDARRAYS_H
#define KICK_START_INTERSECTIONOFTHREESORTEDARRAYS_H

#endif //KICK_START_INTERSECTIONOFTHREESORTEDARRAYS_H

class IntersectionOfThreeSortedArrays {
public:
    vector<int> find_intersection(vector<int> arr1, vector<int> arr2, vector<int> arr3) {
        vector<int> res;
        vector<int>::iterator iterA = arr1.begin();
        vector<int>::iterator iterB = arr2.begin();
        vector<int>::iterator iterC = arr3.begin();

        while (iterA != arr1.end() && iterB != arr2.end() && iterC != arr3.end()) {
            while (*iterA < *iterB || *iterA < *iterC) {
                iterA++;
                if (iterA == arr1.end()) break;
            }
            int val = *iterA;
            while (*iterB < val) {
                iterB++;
                if (iterB == arr2.end()) break;
            }
            while (*iterC < val) {
                iterC++;
                if (iterC == arr3.end()) break;
            }
            if (*iterB == val && *iterC == val) {
                res.push_back(val);
                iterB++;
                iterC++;
                iterA++;
            }
        }

        if (res.empty()) {
            return {-1};
        } else {
            return res;
        }
    }
};