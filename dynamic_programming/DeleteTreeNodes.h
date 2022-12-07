//
// Created by usman on 12/5/22.
//

#ifndef CPPALGORITHMS_DELETETREENODES_H
#define CPPALGORITHMS_DELETETREENODES_H

#include <vector>
#include <tuple>
#include <climits>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;


class DeleteTreeNodes {
public:

    static pair<int, int> processNodes(int id, vector<int>& parent, vector<int>& value, unordered_map<int, list<int>> & nodeMap) {
        int val = value[id];
        int noNodes = 1;

        for (int childId : nodeMap[id]) {
            auto [cVal, cNodes] = processNodes(childId, parent, value, nodeMap);
            val += cVal;
            noNodes += cNodes;
        }
        noNodes = val==0 ? 0: noNodes;
        return {val, noNodes};
    }

    static int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        unordered_map<int, list<int>> nodeMap;
        for (int i =0; i < parent.size(); i++) {
            nodeMap[parent[i]].push_back(i);
        }
        return processNodes(0, parent, value, nodeMap).second;
    }

    static void testMe() {
        vector<int> parents = {-1,7,0,2,22,25,2,0,7,14,25,22,25,14,0,22,22,2,14,14,22,14,25,2,14,0,32,2,2,32,25,22,0,2,2,22,14,14};
        vector<int> values = {-95448,-60462,-61595,68758,68709,32611,22289,-39426,-78078,91853,-56848,26101,-87072,-32610,98615,22254,-70154,86962,-93287,12168,90664,49974,-13514,23360,-12832,-64062,-54784,73509,78689,-72481,-338,81909,-63543,-88910,65612,36464,44448,-29505};
        int res = deleteTreeNodes(38, parents, values);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_DELETETREENODES_H
