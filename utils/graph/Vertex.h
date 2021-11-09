//
// Created by usman on 11/8/21.
//

#ifndef CPPALGORITHMS_VERTEX_H
#define CPPALGORITHMS_VERTEX_H
#include <memory>
class Vertex {
public:

    Vertex(int id, int parent, int rank) {
        this->parent = parent;
        this->rank = rank;
        this->id = id;
    }

    int getParent() {
        return parent;
    }

    void setParent(int parent) {
        this->parent = parent;
    }

    int getRank() {
        return rank;
    }

    void setRank(int rank) {
        this->rank = rank;
    }

    int getId() {
        return id;
    }
private:
    int parent;
    int rank;
    int id;
};

typedef std::shared_ptr<Vertex> VertexP;
#endif //CPPALGORITHMS_VERTEX_H
