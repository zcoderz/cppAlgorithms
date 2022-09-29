//
// Created by usman on 9/28/22.
//

#ifndef CPPALGORITHMS_UNIONFINDNODE_H
#define CPPALGORITHMS_UNIONFINDNODE_H
#include <memory>


template <typename T>
class UnionFindNode {

private:

    T _value;
    /* This structure can contain heterogeneous template types
     *  since no operation is performed between the nodes values themselves.
     */
    UnionFindNode<T> * _parent;
    int _rank;

public:
    using UnionFindNodePtr = shared_ptr<UnionFindNode<T>>;
    UnionFindNode(T & value) : _value(value){
        _parent = this;
        _rank = 0;
    }

    T getValue() {
        return _value;
    }

    UnionFindNode<T> * getParent() {
        return _parent;
    }

    void setParent(UnionFindNode<T> * parent_) {
        _parent = parent_;
    }

    int getRank() {
        return _rank;
    }

    void setRank(int rank_) {
        _rank = rank_;
    }

};



#endif //CPPALGORITHMS_UNIONFINDNODE_H
