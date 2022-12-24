//
// Created by usman on 12/24/22.
//

#ifndef CPPALGORITHMS_MINHEIGHTTREES_H
#define CPPALGORITHMS_MINHEIGHTTREES_H

#include <vector>
#include <climits>
#include <sstream>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <unordered_set>
using namespace std;

/**
 * This problem is unique in that the DFS based solution has O(V^2) complexity. Even with memory memorization it times out.
 * However, if the problem is treated as a topological sort where you trim the leaves until only center nodes are left,
 * then the problem can be solved in O(V).
 */
class MinHeightTrees {
public:

    int process(vector<vector<int>> & edgeVec, int vertex, int parent, vector<vector<int>> & memo) {
        int depth = 1;
        for (int child: edgeVec[vertex]) {
            if (child != parent) {
                if (memo[vertex][child] == -1) {
                    int childSz = process(edgeVec, child, vertex, memo);
                    memo[vertex][child] = childSz;
                }
                depth = max(depth, memo[vertex][child]+1);
            }
        }
        return depth;
    }

    vector<int> findMinHeightTreesDFS(int n, vector<vector<int>>& edges) {
        vector<vector<int>> edgeVec(n);
        for (auto & vec: edges) {
            edgeVec[vec[0]].push_back(vec[1]);
            edgeVec[vec[1]].push_back(vec[0]);
        }

        vector<vector<int>> memo(n, vector<int> (n, -1));

        vector<int> mhts; int size = n;
        for (int i =0; i < n; i++) {
            int sz = process(edgeVec, i, -1, memo);
            cout << " got " << sz << " at " << i << endl;
            if (sz == size) {
                mhts.push_back(i);
            } else if (sz < size) {
                mhts.clear(); mhts.push_back(i);
                size = sz;
            }
        }
        return mhts;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> edgeVec(n);
        for (auto & vec: edges) {
            edgeVec[vec[0]].insert(vec[1]);
            edgeVec[vec[1]].insert(vec[0]);
        }
        int remainingNodeSz = n;
        vector<int> leafNodes;
        for (int i =0; i < n; i++) {
            if (edgeVec[i].size()==1)
                leafNodes.push_back(i);
        }
        while (remainingNodeSz > 2) {
            vector<int> newLeafNodes;
            remainingNodeSz -= leafNodes.size();
            for (int leafNode : leafNodes) {
                //the leaf node will have only one edge, hence the below loop will run only once
                //thus the complexity of the problem is O(V)
                for (int vertex : edgeVec[leafNode]) {
                    edgeVec[vertex].erase(leafNode);
                    if (edgeVec[vertex].size()==1)
                        newLeafNodes.push_back(vertex);
                }
            }
            swap(leafNodes, newLeafNodes);
        }
        return leafNodes;
    }

    static void testMe() {
        int n = 6;
        MinHeightTrees minH;
        vector<vector<int>> edges = {{3,0},{3,1},{3,2},{3,4},{5,4}};
        vector<int> res = minH.findMinHeightTrees(n, edges);
        std::ostringstream oss;
        std::copy(res.begin(), res.end() , std::ostream_iterator<int>(oss, ", "));
        cout << oss.str() << endl;

    }
};

#endif //CPPALGORITHMS_MINHEIGHTTREES_H
