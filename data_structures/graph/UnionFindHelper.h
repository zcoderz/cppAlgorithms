//
// Created by usman on 9/28/22.
//

#ifndef CPPALGORITHMS_UNIONFINDHELPER_H
#define CPPALGORITHMS_UNIONFINDHELPER_H

#include <vector>
#include "UnionFindNode.h"
#include "UnionFindEdge.h"

class UnionFindHelper {
public:
    template<class T>
    static std::vector<typename UnionFindNode<T>::UnionFindNodePtr> createUnionFindNodes(std::vector<T> & vec) {
        std::vector<typename UnionFindNode<T>::UnionFindNodePtr> vecNodes;
        for (int i =0; i < vec.size(); i++) {
            vecNodes.push_back(new UnionFindNode<T> (vec[i]));
        }
        return vecNodes;
    }

    template<class T>
    static std::vector<UnionFindEdge<T>> createUnionFindNodes(std::vector<std::pair<T, T>> & vec) {
        std::vector<typename UnionFindNode<T>::UnionFindEdgePtr> vecEdges;
        for (int i =0; i < vec.size(); i++) {
            vecEdges.push_back(new UnionFindEdge<T> (vec[i].first, vec[i].second));
        }
        return vecEdges;
    }
    template<class T>
    static std::vector<UnionFindEdge<T>> createUnionFindNodes(std::vector<std::vector<T>> & vec) {
        std::vector<typename UnionFindNode<T>::UnionFindEdgePtr> vecEdges;
        for (int i =0; i < vec.size(); i++) {
            vecEdges.push_back(new UnionFindEdge<T> (vec[i][0], vec[i][0][1]));
        }
        return vecEdges;
    }
};

#endif //CPPALGORITHMS_UNIONFINDHELPER_H
