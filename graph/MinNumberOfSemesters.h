//
// Created by usman on 10/11/22.
//

#ifndef CPPALGORITHMS_MINNUMBEROFSEMESTERS_H
#define CPPALGORITHMS_MINNUMBEROFSEMESTERS_H

#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

/**
 * Cant do this with a PQ, need to take combinations and recuse through them
 *
 */
class MinNumberOfSemesters {
public:


    static int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        int minSemesters = numeric_limits<int>::max();
        set<int> takenCourses;
        vector<set<int>> preReqs(n+1);
        for (int i =0; i < relations.size(); i++) {
            preReqs[relations[i][1]].insert(relations[i][0]);
        }
        recurseCombinations(n, takenCourses, k, 0, minSemesters, preReqs);
        return minSemesters;
    }

    static void recurseCombinations(int totalCourses, set<int> & takenCourses, int k, int currSem, int & minSemesters, vector<set<int>> & preReqs) {
        if (takenCourses.size() == totalCourses) {
            minSemesters = min(currSem, minSemesters);
            return;
        }
        if (currSem + (int) ceil(double(totalCourses- takenCourses.size())/k) >= minSemesters) return; //minSemesters is still the best

        vector<int> availableCourses = getAvailableCourses(takenCourses, totalCourses, preReqs);
        if (availableCourses.size() <= k) {
            copy (availableCourses.begin(), availableCourses.end(), inserter(takenCourses, takenCourses.end()));
            recurseCombinations(totalCourses, takenCourses, k, currSem+1 , minSemesters, preReqs);
            return;
        }
        int numAvailableCourses = availableCourses.size();
        for (int mask =1; mask < 1 << numAvailableCourses; mask++) {
            set<int> possibleTaken;
            for (int i =0; i < numAvailableCourses; i++) {
                if ((mask & 1 << i) != 0) {
                    possibleTaken.insert(availableCourses[i]);
                }
            }
            if (possibleTaken.size() != k) continue;
            copy(takenCourses.begin(), takenCourses.end(), inserter(possibleTaken, possibleTaken.end()));
            //std::copy(possibleTaken.begin(), possibleTaken.end() , std::ostream_iterator<int>(cout, ", "));
            //cout << endl;
            recurseCombinations(totalCourses, possibleTaken, k, currSem+1, minSemesters, preReqs);
        }
    }
    /**
     * returns vector of available courses
     * @param coursesTaken
     * @param totalCourses
     * @param preReqs
     * @return
     */
    static vector<int> getAvailableCourses(set<int> coursesTaken, int totalCourses, vector<set<int>> & preReqs) {
        vector<int> availableCourses;
        for (int i =1; i <= totalCourses; i++) {
            if ((coursesTaken.find(i) == coursesTaken.end())) {
                std::vector<int> intersectionData;
                set_intersection(coursesTaken.begin(),coursesTaken.end(),preReqs[i].begin(),
                                 preReqs[i].end(), back_inserter(intersectionData));
                if (intersectionData.size() == preReqs[i].size()) {
                    availableCourses.push_back(i);
                }
            }
        }
        return availableCourses;
    }

    static void testMe() {
        int n = 13, k = 9;
        vector<vector<int>> relations = {{12,8},{2,4},{3,7},{6,8},{11,8},{9,4},{9,7},{12,4},{11,4},{6,4},{1,4},{10,7},{10,4},{1,7},{1,8},{2,7},{8,4},{10,8},{12,7},{5,4},{3,4},{11,7},{7,4},{13,4},{9,8},{13,8}};
        int res= minNumberOfSemesters(n, relations, k);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_MINNUMBEROFSEMESTERS_H
