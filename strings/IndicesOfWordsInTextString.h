//
// Created by usman on 9/27/22.
//

#ifndef CPPALGORITHMS_INDICESOFWORDSINTEXTSTRING_H
#define CPPALGORITHMS_INDICESOFWORDSINTEXTSTRING_H
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class IndicesOfWordsInTextStrings {
public:

    static vector<vector<int>> find_words(string text, vector<string> words) {
        unordered_set<string> wordSet;
        copy(words.begin(), words.end(), inserter(wordSet, wordSet.end()));
        unordered_map<string, vector<int>> wordMap;
        int index = 0;
        while (index != string::npos) {
            int nextSpace = text.find(' ', index );
            string word = nextSpace == string::npos ? text.substr(index) : text.substr(index, nextSpace-index);
            if (wordSet.find(word) != wordSet.end()) {
                wordMap[word].push_back(index);
            }
            index = nextSpace == string::npos ? nextSpace : nextSpace + 1;
        }

        vector<vector<int>> res;
        for (string & word: words) {
            auto iter = wordMap.find(word);
            if (iter != wordMap.end()) {
                res.push_back(iter->second);
            } else {
                res.push_back({-1});
            }
        }
        return res;
    }

    static vector<int> createOffsetArray(string & word) {
        vector<int> res(word.size(), 0);
        for (int i=1, j=0; i < word.length(); ) {
            if (word[i]== word[j]) {
                res[i] = j + 1;
                i++; j++;
            } else if (j > 0) {
                j = res[j-1];
            } else {
                i++;
            }
        }
        return res;
    }

    static vector<int> searchWordInString(string &text, string & word) {
        vector<int> searchOffsets = createOffsetArray(word);
        vector<int> matchIndexes;
        for (int i=0, j=0; i < text.length();) {
            if (text[i]== word[j]) {
                i++; j++;
            } else if (j > 0) {
                j = searchOffsets[j-1];
            } else {
                i++;
            }
            if (j== word.length()) {
                matchIndexes.push_back(i-word.length());
                j--;
            }
        }
        if (matchIndexes.empty()) {
            return {-1};
        } else {
            return matchIndexes;
        }
    }

    static vector<vector<int>> find_words_search(string text, vector<string> words) {
        vector<vector<int>> res;
        for (string & word: words) {
            res.push_back(searchWordInString(text, word));
        }
        return res;
    }
};

#endif //CPPALGORITHMS_INDICESOFWORDSINTEXTSTRING_H
