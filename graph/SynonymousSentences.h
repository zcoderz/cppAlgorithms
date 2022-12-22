//
// Created by usman on 12/21/22.
//

#ifndef CPPALGORITHMS_SYNONYMOUSSENTENCES_H
#define CPPALGORITHMS_SYNONYMOUSSENTENCES_H

#include <vector>
#include <string>
#include <unordered_map>
#include <list>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iterator>

using namespace std;

class SynonymousSentences {
public:
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

    void dfs(int index, vector<string> & words, unordered_map<string, vector<string>> & rootMappings, vector<string> & current, vector<string> & result) {
        if (index == words.size()) {
            string sRes;
            for (string & str: current) {
                sRes = sRes + str + " ";
            }
            result.push_back(sRes.substr(0, sRes.size()-1));
            return;
        }
        string theWord = words[index];
        if (vertices.find(theWord) == vertices.end()) {
            current.push_back(theWord);
            dfs(index+1, words, rootMappings, current, result);
            current.pop_back();
        } else {
            vector<string> mappings = rootMappings[find(theWord)];
            for (string & word: mappings) {
                current.push_back(word);
                dfs(index+1, words, rootMappings, current, result);
                current.pop_back();
            }
        }
    }

    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        for (auto &vec: synonyms) {
            if (vertices.find(vec[0]) == vertices.end()) {
                vertices[vec[0]] = make_pair(vec[0], 0);
            }
            if (vertices.find(vec[1]) == vertices.end()) {
                vertices[vec[1]] = make_pair(vec[1], 0);
            }
            runUnion(vec[0], vec[1]);
        }
        unordered_map<string, vector<string>> rootMappings;
        for (auto iter = vertices.begin(); iter != vertices.end(); iter++) {
            string parent = find(iter->first);
            rootMappings[parent].push_back(iter->first);
        }

        for (auto iter = rootMappings.begin(); iter != rootMappings.end(); iter++) {
            sort(iter->second.begin(), iter->second.end());
        }

        stringstream ss(text);
        string buff;
        vector<string> words;
        while(ss>>buff)
            words.push_back(buff);

        vector<string> result;
        vector<string> current;
        dfs(0, words, rootMappings, current, result);
        return result;
    }

    static void testMe() {
        SynonymousSentences ss;
        string sentence = "I am happy today but was sad yesterday";
        vector<vector<string>> maps = {{"happy","joy"},{"sad","sorrow"},{"joy","cheerful"}};
        vector<string> res = ss.generateSentences(maps, sentence);
        std::ostringstream oss;
        std::copy(res.begin(), res.end() , std::ostream_iterator<string>(oss, ", "));
        cout << oss.str();

    }
};

#endif //CPPALGORITHMS_SYNONYMOUSSENTENCES_H
