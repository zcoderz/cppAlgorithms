//
// Created by usman on 9/28/22.
//

#ifndef CPPALGORITHMS_UNIONFINDEDGE_H
#define CPPALGORITHMS_UNIONFINDEDGE_H

#include <memory>

template<typename T>
class UnionFindEdge {
    T _src, _dest;
    int _cost;
public:
    using UnionFindEdgePtr = std::shared_ptr<UnionFindEdge<T>>;
    UnionFindEdge(T src, T dest) : _src(src), _dest(dest) {}

    UnionFindEdge(T src, T dest, int cost) : _src(src), _dest(dest), _cost(cost) {}

    T getSrc() const {
        return _src;
    }

    void setSrc(T src) {
        _src = src;
    }

    T getDest() const {
        return _dest;
    }

    void setDest(T dest) {
        _dest = dest;
    }

    int getCost() const {
        return _cost;
    }

    void setCost(int cost) {
        _cost = cost;
    }

};

#endif //CPPALGORITHMS_UNIONFINDEDGE_H
