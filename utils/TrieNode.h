//
// Created by usman on 11/7/21.
//

#ifndef CPPALGORITHMS_TRIENODE_H
#define CPPALGORITHMS_TRIENODE_H

#include <memory>
#include <unordered_map>
#include <memory>
#include <vector>
#include <string>

using namespace std;

class TrieNode {
public:
    shared_ptr<TrieNode> addNode(char ch) {
        auto iter = nodeMap.find(ch);
        if ( iter == nodeMap.end()) {
            shared_ptr<TrieNode> trieN = make_shared<TrieNode>();
            nodeMap.emplace(ch, trieN);
            return trieN;
        } else {
            return iter->second;
        }
    }

    void setWord(string & wordP) {
        this->word = wordP;
    }

    string getWord() {
        return word;
    }

    shared_ptr<TrieNode> getChildNode(char ch) {
        return nodeMap[ch];
    }

    void buildTrie(vector<string> & words) {
        for (string & wordP: words) {
            buildTrie(wordP, 0);
        }
    }

    void buildTrie(string & wordP, int index) {
        char ch = wordP[index];
        shared_ptr<TrieNode> node = addNode(ch);
        if (index != wordP.size()-1) {
            node->buildTrie(wordP, index + 1);
        } else {
            this->word = wordP;
        }
    }

    bool isEmpty() {
        return nodeMap.empty();
    }

    void remove(char ch) {
        nodeMap.erase(ch);
    }

private:
    string word;
    unordered_map<char, shared_ptr<TrieNode>> nodeMap;
};

#endif //CPPALGORITHMS_TRIENODE_H
