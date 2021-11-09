//
// Created by usman on 11/8/21.
//

#ifndef CPPALGORITHMS_UNIONFINDNODE_H
#define CPPALGORITHMS_UNIONFINDNODE_H

#include <memory>


template <class T>
class UnionFindNode {

public:
    UnionFindNode(T value) {
        this->value = value;
        parent = this; // Make it its own set
        rank = 0;
    }

    T getValue() {
        return value;
    }

    bool operator== (const UnionFindNode<T> & a) const {
        return this->value == a.value;
    }
    /***
     * Finds the equivalence class of this node.
     * For all nodes a and b of the same tree, find(a) = find(b)
     *
     * collapse parents, so next find call is faster
     * @return the root node which uniquely identify this tree.
     */
     UnionFindNode<T> * find() {
        UnionFindNode<T> * node = this;
        if (node != parent) {
            node->parent = node->parent->find();
        }
        return parent;
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
    void join(UnionFindNode<T> * other) {
        other->parent = this;
    }

    /***
     * Joins two DisjointSetNodes together such that
     * for all node a and b in this and in other,
     * find(a) = find(b).
     * This is not the same as join, c.f. join documentation.
     * @param other the tree you want to join to this tree.
     */
     void runUnion(UnionFindNode<T> & other) {
        UnionFindNode<T> * p = find();
        UnionFindNode<T> * q = other.find();
        if (p == q) return;
        if (p->rank < q->rank) {
            // Swaps like p,q = q,p would
            UnionFindNode<T> * temp = p;
            p = q;
            q = temp;
        }
        // Always join a small rank (q) to a big rank (p)
        // since rank(p.join(q)) = | p.rank     if p.rank > q.rank
        //                         | p.rank+1   else
        p->join(q);
        if (p->rank == q->rank) p->rank++;
    }
private:
   T value;
   UnionFindNode<T> * parent;
   int rank;
};

#endif //CPPALGORITHMS_UNIONFINDNODE_H
