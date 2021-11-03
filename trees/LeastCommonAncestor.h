//
// Created by usman on 11/2/21.
//

#ifndef CPPALGORITHMS_LEASTCOMMONANCESTOR_H
#define CPPALGORITHMS_LEASTCOMMONANCESTOR_H

#include "../utils/Node.h"
#include <vector>
#include <iostream>

using namespace std;

class LeastCommonAncestor {
public:



    int lca( Node * node, Node *a, Node *b)
    {
        typedef pair<Node *, int> ThePair;
        stack<ThePair> nodeStack;
        Node * lca = nullptr;
        int NONE_DONE=2;
        int ONE_DONE=1;
        int BOTH_DONE=0;
        nodeStack.push(ThePair(node, NONE_DONE));
        bool aFound = false, bFound = false;
        while (!nodeStack.empty()) {
            ThePair & pairV = nodeStack.top();
            if(pairV.second == BOTH_DONE) {
                nodeStack.pop();
                if (lca == pairV.first) {
                    lca = nodeStack.top().first;
                }
            } else {
                if (pairV.second == NONE_DONE) {
                    if (!aFound && pairV.first->data == a->data) {
                        aFound = true;
                        if(bFound) {
                            return lca->data;
                        } else {
                            lca = pairV.first;
                        }
                    } else if (!bFound && pairV.first->data == b->data) {
                        bFound = true;
                        if(aFound) {
                            return lca->data;
                        } else {
                            lca = pairV.first;
                        }
                    }
                    pairV.second = ONE_DONE;
                    if (pairV.first->left != nullptr) {
                        nodeStack.push(ThePair(pairV.first->left, NONE_DONE));
                    }
                } else if (pairV.second == ONE_DONE) {
                    if (pairV.first->right != nullptr) {
                        nodeStack.push(ThePair(pairV.first->right, NONE_DONE));
                    }
                    pairV.second = BOTH_DONE;
                }
            }
        }
        return 0;
    }

    int lcaRecursive( Node * node, Node *a, Node *b)
    {
        if(node == nullptr) return 0;

        if (node->data == a->data || node->data == b->data) {
            //this is TRICKY!
            //if you found a node with a given value then it must be that :
            //1. this is the parent node and a child exists under it, in which case this is the LCA
            //2. this is one of the nodes and child doesnt exist under it
            //in any of the above cases, its correct to return this node here
            return node->data;
        }

        //search left and right for the vals
        int dataL = lcaRecursive(node->left, a, b);
        int dataR = lcaRecursive(node->right, a, b);

        //if one val exists on left and the other on right then this node must be the LCA
        if (dataL !=0 && dataR !=0) return node->data;
        //otherwise, one node could be the LCA or none of them. hence use max since node vals are > 0 and you return 0
        //when node isnt found (the break case above)
        return max(dataR, dataL);
    }

    int lcaPath( Node * node, Node *a, Node *b) {
        vector<int>  pathA;
        vector<int>  pathB;
        findPath(node, a->data, pathA);
        findPath(node, b->data, pathB);
        int minLen = min(pathA.size(), pathB.size());
        int lca = pathA[0];
        for (int i =0; i < minLen; i++) {
            if (pathA[i] != pathB[i]) break;
            lca = pathA[i];
        }
        return lca;
    }

    int findPath(Node * node, int target, vector<int> & path) {
        if (node == nullptr) return 0;
        path.push_back(node->data);
        if (node->data==target) return node->data;
        int data = findPath(node->left, target, path);
        if (data) return data;
        data = findPath(node->right, target, path);
        if (data) return data;
        path.pop_back();
        return 0;
    }


};

#endif //CPPALGORITHMS_LEASTCOMMONANCESTOR_H
