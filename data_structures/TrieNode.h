//
// Created by usman on 9/27/22.
//

#ifndef CPPALGORITHMS_TRIENODE_H
#define CPPALGORITHMS_TRIENODE_H

#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class TrieNode {
    unordered_map<char, TrieNode * > nodeMap;
    string word;
public:
    ~TrieNode() {
        for (auto  & iter: nodeMap) {
            delete iter.second;
        }
    }

    void addNode (char ch, TrieNode * node) {
        nodeMap[ch] = node;
    }

    TrieNode * createOrGetNode(char ch) {
        auto  iter = nodeMap.find(ch);
        if (iter == nodeMap.end()) {
            auto * node = new TrieNode;
            nodeMap[ch] = node;
            return node;
        }
        return iter->second;
    }

    TrieNode * getChildNode(char ch) {
        auto  iter = nodeMap.find(ch);
        if (iter == nodeMap.end()) {
            return nullptr;
        }
        return iter->second;
    }

    bool containsChild(char  ch) {
        return nodeMap.find(ch) != nodeMap.end();
    }

    bool hasEndWord() {
        return !word.empty();
    }

    string getWord() {
        return word;
    }

    void setWord(string & str) {
        word = str;
    }

    vector<char> getChildChars() {
        vector<char> res(nodeMap.size());
        std::transform(
                nodeMap.begin(),
                nodeMap.end(),
                std::back_inserter(res),[](auto &kv){ return kv.first;});
        return res;
    }

    bool hasNoChildren() {
        return nodeMap.empty();
    }

    void removeChar(char ch) {
        TrieNode * node = nodeMap[ch];
        nodeMap.erase(ch);
        delete node;
    }
};

#endif //CPPALGORITHMS_TRIENODE_H
