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
    static std::vector<typename UnionFindNode<T>::UnionFindNodePtr> createUnionFindNodes(int noOfVertexes) {
        using VertexPtr = typename UnionFindNode<T>::UnionFindNodePtr;
        std::vector<VertexPtr> vecNodes;
        for (int i =0; i < noOfVertexes; i++) {
            vecNodes.push_back(VertexPtr(new UnionFindNode<T> (i)));
        }
        return vecNodes;
    }

    template<class T>
    static std::vector<typename UnionFindNode<T>::UnionFindNodePtr> createUnionFindNodesViaVector(std::vector<T> & vec) {
        using VertexPtr = typename UnionFindNode<T>::UnionFindNodePtr;
        std::vector<VertexPtr> vecNodes;
        for (int i =0; i < vec.size(); i++) {
            vecNodes.push_back(VertexPtr(new UnionFindNode<T> (vec[i])));
        }
        return vecNodes;
    }

    template<class T>
    static std::vector<typename UnionFindEdge<T>::UnionFindEdgePtr> createUnionFindEdgesViaPair(std::vector<std::pair<T, T>> & vec) {
        std::vector<typename UnionFindEdge<T>::UnionFindEdgePtr> vecEdges;
        for (int i =0; i < vec.size(); i++) {
            vecEdges.push_back(new UnionFindEdge<T> (vec[i].first, vec[i].second));
        }
        return vecEdges;
    }

    template<class T>
    static std::vector<typename UnionFindEdge<T>::UnionFindEdgePtr> createUnionFindEdgesViaVector(std::vector<std::vector<T>> & vec) {
        using EdgePtr = typename UnionFindEdge<T>::UnionFindEdgePtr;
        std::vector<EdgePtr> vecEdges;
        for (int i =0; i < vec.size(); i++) {
            int vecSize = vec[0].size();
            if (vecSize == 2) {
                vecEdges.push_back(EdgePtr (new UnionFindEdge<T>(vec[i][0], vec[i][1])));
            } else if (vecSize == 3) {
                vecEdges.push_back(EdgePtr (new UnionFindEdge<T>(vec[i][0], vec[i][1], vec[i][2])));
            }
        }
        return vecEdges;
    }
};

#endif //CPPALGORITHMS_UNIONFINDHELPER_H
