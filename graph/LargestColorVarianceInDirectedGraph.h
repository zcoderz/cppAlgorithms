//
// Created by usman on 12/25/22.
//

#ifndef CPPALGORITHMS_LARGESTCOLORVARIANCEINDIRECTEDGRAPH_H
#define CPPALGORITHMS_LARGESTCOLORVARIANCEINDIRECTEDGRAPH_H

#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>
using namespace std;

class LargestColorVarianceInDirectedGraph {
public:
    int res=0;
    int process(int vertex, vector<vector<int>> & graphEdges, vector<vector<int>> & dp, vector<int> & seen, string & colors) {
        if (seen[vertex]) return -1;
        if (dp[vertex][0] != -1) return 0; //already calculated
        seen[vertex]=true;
        fill(dp[vertex].begin(), dp[vertex].end(), 0);
        for (int neighbor : graphEdges[vertex]) {
            int resV = process(neighbor, graphEdges, dp, seen, colors);
            if (resV == -1) return -1;
            for (int i =0; i < 26; i++) {
                if (i == (colors[vertex]-'a')) {
                    dp[vertex][i] = max(dp[vertex][i], dp[neighbor][i] + 1);
                } else {
                    dp[vertex][i] = max(dp[vertex][i], dp[neighbor][i]);
                }
                res = max (res, dp[vertex][i]);
            }
        }
        if (graphEdges[vertex].empty()) {
            int color = colors[vertex]-'a';
            dp[vertex][color]=1;
            res = max (res, dp[vertex][color]);
        }
        seen[vertex]=false;
        return 0;
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int numVertices=0;
        for (auto & vec: edges) {
            numVertices = max(numVertices, max(vec[0], vec[1]));
        }
        numVertices++;
        vector<vector<int>> graphEdges(numVertices);
        for (auto & vec: edges) {
            graphEdges[vec[0]].push_back(vec[1]);
        }
        vector<vector<int>> dp(numVertices, vector<int> (26, -1));
        vector<int> seen(numVertices);
        for (int i =0; i < numVertices; i++) {
            int resV = process(i, graphEdges, dp, seen,colors);
            if (resV==-1) return -1;
        }
        return res;
    }

    static void testMe() {
        LargestColorVarianceInDirectedGraph lar;
        vector<vector<int>> edges = {{4,2},{3,4},{0,3},{1,0},{2,1}};
        string colors = "rrrde";
        int res = lar.largestPathValue(colors, edges);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_LARGESTCOLORVARIANCEINDIRECTEDGRAPH_H
