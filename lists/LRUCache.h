//
// Created by usman on 9/18/22.
//

#ifndef CPPALGORITHMS_LRUCACHE_H
#define CPPALGORITHMS_LRUCACHE_H

#include <unordered_map>
using namespace std;

/**
 * For simplicity, the question demands :
 * 1 : Creating a place holder head and tail , and navigating data around it.
 *     This greatly reduces number of null checks needed and simplifies the code.
 * 2:  Adding helper methods :
 *     - moveToHead -- moves given node to the head
 *     - evictNode -- removes the given node (doesnt delete the node), is useful when node later needs to be reused
 *     - evictTail -- deletes the tail of the data
 *     - addToHead -- adds a node to head
 */
class LRUCache {

    struct Node {
        int key;
        int value;
        Node * next = nullptr;
        Node * previous = nullptr;
    };

    Node * head = new Node;
    Node * tail = new Node;
    int capacity;
    unordered_map<int, Node *> nodeMap;
    int currSize = 0;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->previous = head;
    }

    ~LRUCache() {
        delete head;
        delete tail;
    }

    int get(int key) {
        auto node = nodeMap.find(key);
        if (node == nodeMap.end()) {
            return -1;
        }
        moveToHead(node->second);
        return node->second->value;
    }

    void put(int key, int value) {
        auto node = nodeMap.find(key);
        if (node == nodeMap.end()) {
            if (currSize == capacity) {
                evictTail();
            }
            currSize++;
            Node * newHead = new Node(); newHead->value = value; newHead->key = key;
            nodeMap[key] = newHead;
            addHead(newHead);
        } else {
            node->second->value = value;
            moveToHead(node->second);
        }
    }

private:

    void moveToHead(Node * node) {
        evictNode(node);
        addHead(node);
    }

    void evictTail() {
        Node * newTail = tail->previous->previous;
        newTail->next = tail;
        nodeMap.erase(tail->previous->key);
        delete tail->previous;
        tail->previous = newTail;
        currSize--;
    }

    void addHead(Node * newHead ) {
        newHead->next = head->next;
        head->next->previous = newHead;
        head->next = newHead;
        newHead->previous = head;
    }

    void evictNode(Node * node) {
        node->previous->next = node->next;
        node->next->previous = node->previous;
        node->previous = nullptr;
        node->next = nullptr;
    }
};

#endif //CPPALGORITHMS_LRUCACHE_H
