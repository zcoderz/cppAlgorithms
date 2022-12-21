//
// Created by usman on 12/21/22.
//

#ifndef CPPALGORITHMS_SENTENCESIMILARITY_H
#define CPPALGORITHMS_SENTENCESIMILARITY_H
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class SentenceSimilarity {
    unordered_map<string, pair<string, int>> vertices;

    string find(string word) {
        if (vertices[word].first != word) {
            string parent = find(vertices[word].first);
            vertices[word].first = parent;
        }
        return vertices[word].first;
    }

    bool runUnion(string  wordA, string wordB) {
        wordA = find(wordA);
        wordB = find(wordB);
        if (wordA == wordB) return false;
        if (vertices[wordA].second == vertices[wordB].second) {
            vertices[wordA].second++;
            vertices[wordB].first = wordA;
        } else if (vertices[wordA].second > vertices[wordB].second) {
            vertices[wordB].first = wordA;
        } else {
            vertices[wordA].first = wordB;
        }
        return true;
    }

    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size()) return false;
        for (auto & vec: similarPairs) {
            if (vertices.find(vec[0]) == vertices.end()) {
                vertices[vec[0]] = make_pair(vec[0], 0);
            }
            if (vertices.find(vec[1]) == vertices.end()) {
                vertices[vec[1]] = make_pair(vec[1], 0);
            }
            runUnion(vec[0], vec[1]);
        }
        for (int i =0; i < sentence1.size(); i++) {
            if (sentence1[i] == sentence2[i]) continue;
            if (vertices.find(sentence1[i]) == vertices.end()) return false;
            if (vertices.find(sentence2[i]) == vertices.end()) return false;
            string strA = find(sentence1[i]);
            string strB = find(sentence2[i]);
            if (strA == strB) continue;
            return false;
        }
        return true;
    }
};

#endif //CPPALGORITHMS_SENTENCESIMILARITY_H
