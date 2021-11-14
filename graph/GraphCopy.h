//
// Created by usman on 11/14/21.
//

#ifndef CPPALGORITHMS_GRAPHCOPY_H
#define CPPALGORITHMS_GRAPHCOPY_H

#include "../utils/GraphNode.h"
#include <unordered_map>

using namespace std;
class GraphCopy {
public:
    GNode * processGraph(GNode * node, unordered_map<GNode *, GNode *> & graphMap) {
        auto iter =graphMap.find(node);
        if (iter != graphMap.end()) return iter->second;

        auto * copyNode = new GNode(node->val);
        graphMap[node] = copyNode;
        for (GNode * neighbor : node->neighbours) {
            GNode * child = processGraph(neighbor, graphMap);
            child->neighbours.push_back(copyNode);
        }

        return copyNode;
    }

    GNode * build_other_graph(GNode * node)
    {
        unordered_map<GNode *, GNode *> graphMap;
        processGraph(node, graphMap);
        return graphMap[node];
    }
};
#endif //CPPALGORITHMS_GRAPHCOPY_H
