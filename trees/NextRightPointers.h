//
// Created by usman on 9/16/22.
//

#ifndef CPPALGORITHMS_NEXTRIGHTPOINTERS_H
#define CPPALGORITHMS_NEXTRIGHTPOINTERS_H

#include <queue>

using namespace std;

class NextRightPointers {
    class Node {
    public:
        int val;
        Node* left;
        Node* right;
        Node* next;

        Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
        Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
        Node(int _val, Node* _left, Node* _right, Node* _next)
                : val(_val), left(_left), right(_right), next(_next) {}
    };

    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;
        queue<Node*> dataQueue;
        dataQueue.push(root);
        while (!dataQueue.empty()) {
            vector<Node *> vec;
            while (!dataQueue.empty()) {
                Node * theNode = dataQueue.front(); dataQueue.pop();
                vec.push_back(theNode);
            }
            for (int i =0; i < vec.size(); i++) {
                Node * node = vec[i];
                if (i+1 < vec.size()) {
                    node->next = vec[i+1];
                }
                if (node->left != nullptr) {
                    dataQueue.push(node->left);
                }
                if (node->right != nullptr) {
                    dataQueue.push(node->right);
                }
            }
        }
        return root;
    }

};

#endif //CPPALGORITHMS_NEXTRIGHTPOINTERS_H
