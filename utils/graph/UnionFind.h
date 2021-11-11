//
// Created by usman on 11/8/21.
//

#ifndef CPPALGORITHMS_UNIONFIND_H
#define CPPALGORITHMS_UNIONFIND_H

#include <vector>
#include <unordered_set>
#include <algorithm>
#include "Vertex.h"

using namespace std;


/**
 * Analysis : cost = (n-1) * cost of union + 2m * cost of find
 * the amortized cost of find = O(1) due to path compression in find fold back.
 * in absence of path compression weighted union by rank adjusts
 * rank such that rank is analogous to height of the tree and thus each find operation runs in O(log N), where n is
 * number of nodes in that tree. in addition, with path compression the amortized cost of a find operation
 * becomes O(1) (inverse Ackermann function)
 *
 * Thus the total cost of union find is 2m --> O(m) where m is the number of edges
 */
class UnionFind {
public:
    /**
     * the method does union of the vertex x & y from wikipedia : For union by rank, a node stores its rank, which is an
     * upper bound for its height. When a node is initialized, its rank is set to zero. To merge trees with roots x and
     * y, first compare their ranks. If the ranks are different, then the larger rank tree becomes the parent, and the
     * ranks of x and y do not change. If the ranks are the same, then either one can become the parent, but the new
     * parent's rank is incremented by one. While the rank of a node is clearly related to its height, storing ranks is
     * more efficient than storing heights. The height of a node can change during a Find operation, so storing ranks
     * avoids the extra effort of keeping the height correct.
     *
     * @param vertices
     * @param x
     * @param y
     */
    static void runUnion(vector<VertexP> vertices, int x, int y) {
        int xRank = vertices[find(vertices, x)]->getRank();
        int yRank = vertices[find(vertices, y)]->getRank();

        if (xRank > yRank) {
            vertices[y]->setParent(x);
        } else if (yRank > xRank) {
            vertices[x]->setParent(y);
        } else {
            vertices[x]->setParent(y);
            //rank increases only when two vertices of same rank are merged together.
            vertices[y]->setRank(vertices[y]->getRank() + 1);
        }
    }

    /**
     * The method recurses through parent of the vertex until it finds the root
     *
     * @param vertices
     * @param i
     * @return
     */
    static int find(vector<VertexP> &vertices, int i) {
        if (vertices[i]->getParent() != i) {
            //compact the parent path so that next call to parent doesnt have to recuse as deep
            vertices[i]->setParent(find(vertices, vertices[i]->getParent()));
        }
        return vertices[i]->getParent();
    }

    // The main function to check whether a given graph
    // contains cycle or not
    static int isCycle(vector<VertexP> &vertices, vector<EdgeP> &edges) {
        // Iterate through all edges of graph, find subset of both
        // vertices of every edge, if both subsets are same, then
        // there is cycle in graph.
        for (int i = 0; i < edges.size(); ++i) {
            int x = find(vertices, edges[i]->getSrc());
            int y = find(vertices, edges[i]->getDest());
            //if two vertices that arent yet combined roll up to the same parent then the graph
            //by definition must have a cycle.
            if (x == y)
                return 1;
            runUnion(vertices, x, y);
        }
        return 0;
    }

    static int constructMinSpanningTree(vector<VertexP> &vertices, vector<EdgeP> &edges) {
        int cost = 0;
        //sort the edges by the cost (smallest to largest)
        auto comp = [](EdgeP &a, EdgeP &b) -> bool { return a->getCost() < b->getCost(); };
        sort(edges.begin(), edges.end(), comp);

        int numVertices = vertices.size();
        int seenVertices = 0;
        //break when either all edges are exhausted or when all vertices have been joined
        for (int i = 0; i < edges.size() && seenVertices < (numVertices - 1); i++) {
            int x = find(vertices, edges[i]->getSrc());
            int y = find(vertices, edges[i]->getDest());
            //if the two vertices belong to diff parents then union them together
            if (x != y) {
                runUnion(vertices, x, y);
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

    static void connectVertices(vector<VertexP> &vertices, vector<EdgeP> &edges) {
        int numVertices = vertices.size();
        int seenVertices = 0;
        //break when either all edges are exhausted or when all vertices have been joined
        for (int i = 0; i < edges.size() && seenVertices < numVertices - 1; i++) {
            int x = find(vertices, edges[i]->getSrc());
            int y = find(vertices, edges[i]->getDest());
            //if the two vertices belong to diff parents then union them together
            if (x != y) {
                runUnion(vertices, x, y);
                seenVertices++;
            }
        }
    }

    static int numConnectedVertices(vector<VertexP> &vertices) {
        unordered_set<int> connectedComponents;
        for (int i = 0; i < vertices.size(); i++) {
            int parent = find(vertices, i);
            connectedComponents.insert(parent);
        }
        return connectedComponents.size();
    }

    static vector<VertexP> constructVertices(int n) {
        vector<VertexP> vertices;
        for (int i = 0; i < n; i++) {
            VertexP v = make_shared<Vertex>(Vertex(i, i, 0));
            vertices.push_back(v);
        }
        return vertices;
    }

    static vector<EdgeP> constructEdges(vector<vector<int>> &edgesParam) {
        vector<EdgeP> edges;
        for (int i = 0; i < edgesParam.size(); i++) {
            EdgeP edge = make_shared<Edge>(Edge(edgesParam[i][0], edgesParam[i][1]));
            edges.push_back(edge);
        }
        return edges;
    }
};

#endif //CPPALGORITHMS_UNIONFIND_H
