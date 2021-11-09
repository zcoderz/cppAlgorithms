//
// Created by usman on 11/8/21.
//

#ifndef CPPALGORITHMS_EDGE_H
#define CPPALGORITHMS_EDGE_H
#include <memory>

class Edge {
public:

    Edge() {
    }

    Edge(int src, int dest) {
        this->src = src;
        this->dest = dest;
    }

    Edge(int src, int dest, int cost) {
        this->src = src;
        this->dest = dest;
        this->cost = cost;
    }

    int getSrc() {
        return src;
    }

    void setSrc(int src) {
        this->src = src;
    }

    int getDest() {
        return dest;
    }

    void setDest(int dest) {
        this->dest = dest;
    }

    int getCost() {
        return cost;
    }

    void setCost(int cost) {
        this->cost = cost;
    }
private:
     int src, dest, cost;
};

typedef std::shared_ptr<Edge> EdgeP;

#endif //CPPALGORITHMS_EDGE_H
