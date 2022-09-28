//
// Created by usman on 9/27/22.
//

#ifndef CPPALGORITHMS_TRIEBUILDER_H
#define CPPALGORITHMS_TRIEBUILDER_H

#include "TrieNode.h"

class TrieBuilder {
    TrieNode * root = new TrieNode;

    bool search(string & word, bool prefixOnly, int index, TrieNode * node) {
        if (prefixOnly && index == word.length()) {
            return true;
        }
        TrieNode * childNode = node->getChildNode(word[index]);
        if (childNode == nullptr) return false;
        if (index == word.length()-1 && !prefixOnly) {
            return word ==  childNode->getWord();
        }
        return search(word, prefixOnly, index+1, childNode);
    }

    bool searchWithDot(string & word, int index, TrieNode * node) {
        char chIndex = word[index];
        if (chIndex == '.') {
            if (index == word.length()-1) return true;
            vector<char> nodeChildren = node->getChildChars();
            for (char & ch: nodeChildren) {
                if (searchWithDot(word, index, node->getChildNode(ch))) {
                    return true;
                }
            }
            return false;
        } else {
            TrieNode * childNode = node->getChildNode(word[index]);
            if (childNode == nullptr) return false;
            if (index == word.length()-1) {
                return word ==  childNode->getWord();
            }
            return searchWithDot(word, index+1, childNode);
        }
    }

public:

    TrieBuilder() {
    }

    ~TrieBuilder() {
        delete root;
    }

    bool searchWithDot(string & word) {
        return searchWithDot(word, 0, root);
    }

    bool search(string & word) {
        return search(word, false, 0, root);
    }

    bool searchPrefix(string & word) {
        return search(word, true, 0, root);
    }

    void addWord(string & word) {
        TrieNode * workingNode = root;
        for (char & ch : word) {
            workingNode = workingNode->createOrGetNode(ch);
        }
        workingNode->setWord(word);
    }

    void addWords(vector<string> & words) {
        for (string & word : words) {
            addWord(word);
        }
    }

    TrieNode * getRoot() {
        return root;
    }
};

#endif //CPPALGORITHMS_TRIEBUILDER_H
