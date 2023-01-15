//
// Created by usman on 10/10/22.
//

#ifndef CPPALGORITHMS_ALLPATHSFROMSOURCETOTARGET_H
#define CPPALGORITHMS_ALLPATHSFROMSOURCETOTARGET_H

#include <vector>

using namespace std;
class AllPathsFromSourceToTarget {
public:

    void process(int index, vector<int> & curr, vector<vector<int>> & res, vector<vector<int>>& graph) {
        curr.push_back(index);
        if (index == graph.size()-1) {
            res.push_back(curr);
            curr.pop_back();
            return;
        }
        for (int vertex : graph[index]) {
            process(vertex, curr, res, graph);
        }
        curr.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> curr;
        process(0, curr, res, graph);
        return res;
    }
};

#endif //CPPALGORITHMS_ALLPATHSFROMSOURCETOTARGET_H
