//
// Created by usman on 9/28/22.
//

#ifndef CPPALGORITHMS_UNIONFINDALGO_H
#define CPPALGORITHMS_UNIONFINDALGO_H
#include "UnionFindNode.h"
#include "UnionFindEdge.h"
#include "UnionFindHelper.h"
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <assert.h>

class UnionFindAlgo {
public:
    /***
     * Finds the equivalence class of this node.
     * For all nodes a and b of the same tree, find(a) = find(b)
     *
     * collapse parents, so next find call is faster
     * @return the root node which uniquely identify this tree.
     */
    template<class T>
    static UnionFindNode<T> * find(UnionFindNode<T> * node) {
        if (node->getParent() != node) {
            node->setParent(find(node->getParent()));
        }
        return node->getParent();
    }

    /***
     * Joins two DisjointSetNodes together assuming
     * those are the heads of each DisjointSet you want.
     * Example: if you join other=B and this=3 in structures
     * A->B->C->D and 1->2->3->4, then you'll have
     * A->B->3->4 and 1->2->3->4 but C->D
     * So now find(A) = find(B) = 4 ≠ find(C) = D
     * @param other the subtree you want to join to this tree.
     */
    template<class T>
    static void join(UnionFindNode<T> * parentNode, UnionFindNode<T> * other) {
        other->setParent(parentNode);
    }

    /***
    * Joins two DisjointSetNodes together such that
    * for all node a and b in this and in other,
    * find(a) = find(b).
    * This is not the same as join, c.f. join documentation.
    * @param other the tree you want to join to this tree.
    */
    template<class T>
    static void unionNodes(UnionFindNode<T> * curr, UnionFindNode<T> * other) {
        UnionFindNode<T> * p = find(curr);
        UnionFindNode<T> * q = find(other);
        if (p == q) return;
        if (p->getRank() < q->getRank()) {
            // Swaps like p,q = q,p would
            UnionFindNode<T> * temp = p;
            p = q;
            q = temp;
        }
        // Always join a small _rank (q) to a big _rank (p)
        // since _rank(p.join(q)) = | p._rank     if p._rank > q._rank
        //                         | p._rank+1   else
        join(p, q);
        if (p->getRank() == q->getRank()) p->setRank(p->getRank() + 1);
    }

    // The main function to check whether a given graph
    // contains cycle or not
    template<class T>
    static bool isCycle(std::vector<typename UnionFindNode<T>::UnionFindNodePtr> & vertices,
                        std::vector<typename UnionFindEdge<T>::UnionFindEdgePtr> & edges) {
        using UnionPtr = typename UnionFindNode<T>::UnionFindNodePtr ;
        std::unordered_map<T, UnionPtr> vertexMap;
        for (auto & vert: vertices) {
            vertexMap[vert->getValue()] = vert;
        }

        // Iterate through all edges of graph, find subset of both
        // vertices of every edge, if both subsets are same, then
        // there is cycle in graph.
        for (int i = 0; i < edges.size(); ++i) {
            UnionFindNode<T> * x = find(vertexMap[edges[i]->getSrc()].get());
            UnionFindNode<T> * y = find(vertexMap[edges[i]->getDest()].get());
            //if two vertices that aren't yet combined roll up to the same parent then the graph
            //by definition must have a cycle.
            if (x == y)
                return true;
            unionNodes(x, y);
        }
        return false;
    }

    template<class T>
    static int numConnectedVertices(std::vector<typename UnionFindNode<T>::UnionFindNodePtr> & vertices) {
        using UnionPtr = typename UnionFindNode<T>::UnionFindNodePtr ;
        std::unordered_set<UnionFindNode<T> *> connectedComponents;
        for (int i = 0; i < vertices.size(); i++) {
            UnionFindNode<T> * parent = find(vertices[i].get());
            connectedComponents.insert(parent);
        }
        return connectedComponents.size();
    }

    template<class T>
    static int constructMinSpanningTree(std::vector<typename UnionFindNode<T>::UnionFindNodePtr> & vertices,
                                        std::vector<typename UnionFindEdge<T>::UnionFindEdgePtr> & edges) {
        int cost = 0;
        using UnionPtr = typename UnionFindEdge<T>::UnionFindEdgePtr ;
        using VertexPtr = typename UnionFindNode<T>::UnionFindNodePtr ;
        //sort the edges by the cost (smallest to largest)
        auto comp = [](UnionPtr &a, UnionPtr &b) -> bool { return a->getCost() < b->getCost(); };
        sort(edges.begin(), edges.end(), comp);
        std::unordered_map<T, VertexPtr> vertexMap;
        for (auto & vert: vertices) {
            vertexMap[vert->getValue()] = vert;
        }
        int numVertices = vertices.size();
        int seenVertices = 0;
        //break when either all edges are exhausted or when all vertices have been joined
        for (int i = 0; i < edges.size() && seenVertices < (numVertices - 1); i++) {
            UnionFindNode<T> * x = find(vertexMap[edges[i]->getSrc()].get());
            UnionFindNode<T> * y = find(vertexMap[edges[i]->getDest()].get());
            //if the two vertices belong to diff parents then union them together
            if (x != y) {
                unionNodes(x, y);
                cost += edges[i]->getCost();
                seenVertices++;
            }
        }
        if (seenVertices == numVertices - 1) {
            return cost;
        } else {
            return -1;
        }
    }

    static void testAlgo() {
        vector<vector<int>> connections = {{0, 1, 5}, {0, 2, 6}, {1, 2, 1}};
        using EdgePtr = typename UnionFindEdge<int>::UnionFindEdgePtr;
        auto edges = UnionFindHelper::createUnionFindEdgesViaVector<int>(connections);
        using VertexPtr = typename UnionFindNode<int>::UnionFindNodePtr;
        auto vertexes = UnionFindHelper::createUnionFindNodes<int>(3);
        const int cost = constructMinSpanningTree<int>(vertexes, edges);
        cout << "cost of the min spanning tree = " << cost << endl;
        assert(cost == 6);
        vector<vector<int>> edgeTreeVec = {{0, 1}, {0, 2}, {0, 3},  {1, 4}};
        auto edgesTree = UnionFindHelper::createUnionFindEdgesViaVector<int>(edgeTreeVec);
        auto vertexesTree = UnionFindHelper::createUnionFindNodes<int>(5);
        bool isACycle = isCycle<int>(vertexesTree, edgesTree);
        assert(isACycle == false);
        int noConnections = numConnectedVertices<int> (vertexesTree);
        assert(noConnections == 1);

        //1->3 creates a cycle
        vector<vector<int>> edgeTreeVecWithCycle  = {{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}};
        auto edgesTreeCycle = UnionFindHelper::createUnionFindEdgesViaVector<int>(edgeTreeVecWithCycle);
        auto vertexesTreeCycle = UnionFindHelper::createUnionFindNodes<int>(5);
        isACycle = isCycle<int>(vertexesTree, edgesTree);
        assert(isACycle == true);

    }
    
};

#endif //CPPALGORITHMS_UNIONFINDALGO_H
