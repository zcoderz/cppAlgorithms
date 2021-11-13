//
// Created by usman on 11/12/21.
//

#ifndef CPPALGORITHMS_STRINGTRANSFORMATION_H
#define CPPALGORITHMS_STRINGTRANSFORMATION_H

#include <vector>
#include <unordered_map>
#include <queue>
#include <memory>
using namespace std;


//#define MSV make_shared<vector<string>>

class StringTransformation {
public:

    vector<string> string_transformation_simple(vector<string> words, string start, string stop) {
        unordered_map<string, vector<string>> wordMappings;
        unordered_set<string> dict;
        dict.insert(words.begin(), words.end());
        dict.insert(stop);
        for (const string& str : dict) {
            for (int i=0; i < str.size(); i++) {
                string tickStr = str.substr(0,i) + "*" + (str.substr(i+1));
                vector<string> & vec = wordMappings[tickStr];
                vec.push_back(str);
            }
        }
        queue<string> theQueue;
        theQueue.push(start);
        unordered_map<string, string> parentMap;
        while (!theQueue.empty()) {
            string strParent = theQueue.front(); theQueue.pop();
            for (int j = 0; j < strParent.size(); j++) {
                string tickStr = strParent.substr(0, j) + "*" + strParent.substr(j + 1);
                auto iter = wordMappings.find(tickStr);
                if (iter != wordMappings.end()) {
                    for (string &str: iter->second) {
                        if (dict.find(str) != dict.end() && str != strParent) {
                            parentMap[str] = strParent;
                            if (str == stop) {
                                return constructPath(start, stop, parentMap);
                            }
                            dict.erase(str);
                            theQueue.push(str);
                        }
                    }
                }
            }
        }
        return {"-1"};
    }

    vector<string> constructPath(string & start, string & curr, unordered_map<string, string> & parentMap) {
        vector<string> vecStr;
        while (parentMap[curr] != start) {
            vecStr.push_back(curr);
            curr = parentMap[curr];
        }
        vecStr.push_back(curr);
        vecStr.push_back(start);
        reverse(vecStr.begin(), vecStr.end());
        return vecStr;
    }

    bool differByOne(const string & strA, const string & strB) {
        int cnt = 0;
        for (int i=0; i < strA.size(); i++) {
            if (strA[i] != strB[i]) {
                cnt++;
            }
            if (cnt > 1) return false;
        }
        return cnt==1;
    }

    vector<string> getNeighbors(string & startingString, unordered_set<string> & dictionary) {
        vector<string> vecStr;
        if (dictionary.size() > 26) {
            for (int i=0; i < startingString.size(); i++) {
                char orig = startingString[i];
                for (int j =0; j < 26; j++) {
                    char newChar = 'a' + j;
                    if (newChar == orig) continue;
                    startingString[i] = newChar;
                    if (dictionary.find(startingString) != dictionary.end()) {
                        vecStr.push_back(startingString);
                    }
                }
                startingString[i] = orig;
            }
        } else {
            for (const string & word : dictionary) {
                if (differByOne(startingString, word)) {
                    vecStr.push_back(word);
                }
            }
        }
        return vecStr;
    }

    vector<string> string_transformation(vector<string> words, string start, string stop) {
        unordered_set<string> dict;
        dict.insert(words.begin(), words.end());
        dict.insert(stop);
        unordered_map<string, string> parentMap;
        unordered_set<string> seen;
        queue<string> theQ;
        theQ.push(start);
        while (!theQ.empty()) {
            string strCurr = theQ.front(); theQ.pop();
            for (string & strNext: getNeighbors(strCurr, dict)) {
                if (strNext == stop) {
                    parentMap[strNext] = strCurr;
                    return constructPath(start, stop, parentMap);
                } else {
                    if (seen.find(strNext) != seen.end()) continue;
                    parentMap[strNext] = strCurr;
                    seen.insert(strNext);
                    theQ.push(strNext);
                }
            }
        }
        return {"-1"};
    }
};

#endif //CPPALGORITHMS_STRINGTRANSFORMATION_H
