//
// Created by usman on 9/14/22.
//

#ifndef CPPALGORITHMS_NEARESTNEIGHBORS_H
#define CPPALGORITHMS_NEARESTNEIGHBORS_H

#include <math.h>
#include <vector>
#include <queue>
#include <tuple>
#include <c++/11/random>

using namespace std;

class NearestNeighbors {
public:


    inline static double distance(int startX, int startY, int endX, int endY) {
            long long diffA = (endX-startX);
            long long diffB = (endY-startY);
            return sqrt( pow(diffA, 2) + pow(diffB, 2));
    }


    /**
     * Complexity here is O(N)* log(k).
     * N elements and PQ insert and remove is log(K) since size of PQ is K.
     * If K is small the performance is literally O(N).
     * Since PQ is backed by vector (contiguous memory), operations on PQ are very fast.
     * @param p_x
     * @param p_y
     * @param k
     * @param n_points
     * @param nearestNeighbors
     */
    static void computeHeapBasedNearestNeighbors(int p_x, int p_y, int k, vector<vector<int>> &n_points,
                                          vector<vector<int>> & nearestNeighbors) {
        auto comp = [] (tuple<int, int, double> &a, tuple<int, int, double> &b) -> bool {
            // a < b, so that larger distances are on top.
            return get<2> (a) < get<2> (b);
        };
        priority_queue<tuple<int, int, double> , vector<tuple<int,int, double>> , decltype(comp)> pQ (comp);
        for (vector<int> & p: n_points) {
            double d = distance(p_x, p_y, p[0], p[1]);
            auto tup = tuple<int, int, double> (p[0], p[1], d);
            pQ.push(tup);
            if (pQ.size() > k) {
                pQ.pop();
            }
        }
        while (!pQ.empty()) {
            auto tup = pQ.top(); pQ.pop();
            nearestNeighbors.emplace_back(  vector<int> {get<0>(tup), get<1> (tup)});
        }
    }


    /**
     * Two way partition has a problem that if all elements are same, it will require O(N^2) calls..
     * left advances one ahead per call.
     * @param points
     * @param left
     * @param right
     * @return
     */
    static int partitionThreeWay(vector<tuple<int, int, double>> & points, int left, int right) {
        int mid = (right - left) / 2 + left;
        swap(points[mid], points[left]);
        int currLoc = left+1;
        int origLeft = left;
        double pivotDist = get<2> (points[left]);
        while (currLoc <= right) {
            if (get<2> (points[currLoc]) < pivotDist) {
                swap(points[left++], points[currLoc++]);
            } else if (get<2> (points[currLoc]) > pivotDist) {
                swap(points[right--], points[currLoc]);
            } else {
                currLoc++;
            }
        }

        return left == origLeft ? left + 1 : left;
    }


    /**
     * Two way partition has a problem that if all elements are same, it will require O(N^2) calls..
     * left advances one ahead per call.
     * @param points
     * @param left
     * @param right
     * @return
     */
    static int partitionTwoWay(vector<tuple<int, int, double>> & points, int left, int right) {
        int mid = (right - left) / 2 + left;
        swap(points[mid], points[right]);
        int currLoc = left;

        while (currLoc < right) {
            if (get<2> (points[currLoc]) < get<2> (points[right])) {
                swap(points[left++], points[currLoc++]);
            } else {
                currLoc++;
            }
        }
        swap(points[left++], points[right]);
        return left;
    }


    /**
     * Time complexity is O(N)
     * On average, the number of operations required for sorting
     * (only selective sub arrays and skipping the ones not required) turns out to be n + n/2 + n/4 + ... = 2n = O(n).
     * @param p_x
     * @param p_y
     * @param k
     * @param n_points
     * @param nearestNeighbors
     */
    static void computeQuickSelectBasedNearestNeighbors(int p_x, int p_y, int k, vector<vector<int>> &n_points,
                                                 vector<vector<int>> & nearestNeighbors) {
        vector<tuple<int, int, double>> points;
        for (vector<int> & p: n_points) {
            double d = distance(p_x, p_y, p[0], p[1]);
            auto tup = tuple<int, int, double>(p[0], p[1], d);
            points.emplace_back(tup);
        }
        int left = 0;
        int partitionIndex  = points.size() - 1;
        auto rng = std::default_random_engine {};
        std::shuffle(points.begin(), points.end(), rng);

        while (left <  partitionIndex ) {
            int index = partitionThreeWay(points, left, partitionIndex);
            //int index = partitionTwoWay(points, left, partitionIndex);
            if (index == k) {
                break;
            }
            if (index < k) {
                left = index;
            } else {
                partitionIndex = index-1;
            }
        }


        for (int i =0; i < k; i++) {
            nearestNeighbors.emplace_back(  vector<int> {get<0>(points[i]), get<1> (points[i])});
        }
    }

    vector<vector<int>> nearest_neighbours(int p_x, int p_y, int k, vector<vector<int>> &n_points) {
        // Write your code here.
        vector<vector<int>> nearestNeighbors;
        computeQuickSelectBasedNearestNeighbors(p_x, p_y, k, n_points,nearestNeighbors);
        return nearestNeighbors;
    }

};

#endif //CPPALGORITHMS_NEARESTNEIGHBORS_H
