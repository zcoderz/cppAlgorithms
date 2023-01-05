//
// Created by usman on 1/4/23.
//

#ifndef CPPALGORITHMS_SUMOFDISTANCESINTREE_H
#define CPPALGORITHMS_SUMOFDISTANCESINTREE_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

class SumOfDistancesInTree {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        //Solve in 2 steps
        //Step 1 (Post Order): For each node calculate count of nodes under it and including it
        //and use the count to calculate distance of the node from its children (one way parent downwards)
        //thus each child node has total distance to its child nodes and count of nodes under and including it
        //this information tickles up to calculate distance for the root of the tree correctly.

        //Step 2(Pre Order): Once the total aggregate distance for root is calculated, use it to populate
        //child distance. child distance = parent distance - child nodes (since these are 1 closer to the child) +
        //(n-childnodes) (since these are 1 further away from child)

        vector<vector<int>> connections(n);
        for (auto & vec: edges) {
            connections[vec[0]].push_back(vec[1]);
            connections[vec[1]].push_back(vec[0]);
        }
        vector<int> count(n,1);
        vector<int> ans(n,0);
        postOrderDfs(0, -1, connections, count, ans);
        preOrderDfs(0, -1, connections, count, ans);
        return ans;
    }

    void postOrderDfs(int index,  int parent, vector<vector<int>> & connections, vector<int> & count, vector<int> & ans) {
        for (int child: connections[index]) {
            if (child != parent) {
                postOrderDfs(child, index, connections, count, ans);
                count[index] += count[child];
                ans[index] += (ans[child] + count[child]);
            }
        }
    }

    void preOrderDfs(int index, int parent,  vector<vector<int>> & connections, vector<int> & count, vector<int> & ans) {
        if (parent != -1)
            ans[index] = ans[parent] - count[index] + (ans.size()-count[index]);
        for (int child: connections[index]) {
            if (child != parent)
                preOrderDfs(child, index, connections, count, ans);
        }
    }

    static void testMe() {
        vector<vector<int>> edges = {{0,1},{0,2},{2,3},{2,4},{2,5}};
        SumOfDistancesInTree sum;
        vector<int> res = sum.sumOfDistancesInTree(6, edges);
        std::copy(res.begin(), res.end() , std::ostream_iterator<int>(cout, ", "));
    }
};

#endif //CPPALGORITHMS_SUMOFDISTANCESINTREE_H
