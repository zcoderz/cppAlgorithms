//
// Created by usman on 10/23/21.
//

#ifndef CPPALGORITHMS_NEARRESTNEIGHBORS_H
#define CPPALGORITHMS_NEARRESTNEIGHBORS_H

#include <vector>
#include <math.h>

using namespace std;

class NearestNeighbors {
public:

    vector<vector<int> > nearest_neighbours(int p_x, int p_y, int k, vector<vector<int> > &n_points) {
        vector<pair<double,int>> vecPairs;
        for (int i =0; i < n_points.size(); i++) {
            vector<int> & vec  =  n_points[i];
            long long diffA = (p_x - vec[0]);
            long long diffB = (p_y - vec[1]);
            double diff = sqrt( pow(diffA, 2) + pow(diffB, 2));
            vecPairs.emplace_back(diff, i);
        }

        auto comp = [] (pair<double, int> &a, pair<double, int> &b) -> bool { return a.first < b.first; };
        priority_queue<pair<int, int> , vector<pair<double,int>> , decltype(comp)> pQ (comp);
        for (pair<double, int> & p: vecPairs) {
            pQ.push(p);
            if (pQ.size() > k) {
                pQ.pop();
            }
        }

        vector<vector<int>> res;
        while (!pQ.empty()) {
            res.push_back(n_points[pQ.top().second]);
            pQ.pop();
        }
        return res;
    }

    vector<vector<int> > nearest_neighbours_qs(int p_x, int p_y, int k, vector<vector<int> > &n_points) {
        sort(p_x, p_y, k, n_points, 0, n_points.size()-1);
        vector<vector<int> > res;
        copy(n_points.begin(), n_points.begin() + k, back_inserter(res));
        return res;
    }

    void sort(int startX, int startY, int k, vector<vector<int>> &n_points, int left, int right) {
        if (left >= right) return;
        int partitionIndex =  partition(startX, startY, n_points, left, right);
        if (partitionIndex ==k) {
            return;
        } else if (partitionIndex < k) {
            sort(startX, startY, k, n_points, partitionIndex+1, right);
        } else {
            sort(startX, startY, k, n_points, left, partitionIndex-1);
        }
    }

    //two way
    int partition(int startX, int startY, vector<vector<int>> &n_points, int left, int right) {
        int mid = left + (right-left) /2 ;
        swap(n_points[right], n_points[mid]);
        double pivotDist = distance(startX, startY, n_points[right][0], n_points[right][1]);
        int currIndex = left;
        while (currIndex <= right) {
            double dist = distance(startX, startY, n_points[currIndex][0], n_points[currIndex][1]);
            if (dist <  pivotDist) {
                swap( n_points[left++], n_points[currIndex++]);
            } else {
                currIndex++;
            }
        }
        swap(n_points[right], n_points[left]);
        return right;
    }

    int partitionThreeWay(int startX, int startY, vector<vector<int>> &n_points, int left, int right) {
        int origLeft = left;
        int current = left+1;
        int mid = left + (right-left) /2 ;
        swap(n_points[left], n_points[mid]);
        double pivotDist = distance(startX, startY, n_points[origLeft][0], n_points[origLeft][1]);

        while (current <= right) {
            double dist = distance(startX, startY, n_points[current][0], n_points[current][1]);
            if (dist < pivotDist) {
                swap(n_points[left++], n_points[current++]);
            } else if (dist > pivotDist) {
                swap(n_points[right--], n_points[current]);
            } else {
                current++;
            }
        }
        return left;
    }

    static double distance(int startX, int startY, int endX, int endY) {
        long long diffA = (endX-startX);
        long long diffB = (endY-startY);
        return sqrt( pow(diffA, 2) + pow(diffB, 2));
    }
};

#endif //CPPALGORITHMS_NEARRESTNEIGHBORS_H