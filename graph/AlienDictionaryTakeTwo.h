//
// Created by usman on 12/24/22.
//

#ifndef CPPALGORITHMS_ALIENDICTIONARYTAKETWO_H
#define CPPALGORITHMS_ALIENDICTIONARYTAKETWO_H

#include <vector>
#include <string>
#include <unordered_set>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class AlienDictionaryTakeTwo {
public:
    string alienOrder(vector<string>& words) {
        vector<unordered_set<int>> dependencies(26);
        vector<vector<int>> invertedDeps(26);
        unordered_set<int> uniqueLetters;
        for (int i =0; i < words.size()-1; i++) {
            string & wordA = words[i];
            string & wordB = words[i+1];
            if (wordA.size() > wordB.size() && wordA.compare(0, wordB.size(), wordB)==0) return "";
            int sz = min(wordA.size(), wordB.size());
            for (int j =0; j < sz; j++) {
                if (wordA[j] != wordB[j]) {
                    dependencies[wordA[j] - 'a'].insert(wordB[j] - 'a');
                    invertedDeps[wordB[j] - 'a'].push_back(wordA[j] - 'a');
                    //when one letter is different the others dont matter
                    //i.e. in "abcef" < "abdaa" in english because c < d.
                    break;
                }
            }
        }
        for (int i=0; i < words.size(); i++) {
            for (char ch : words[i]) {
                uniqueLetters.insert(ch-'a');
            }
        }
        unordered_set<int> leaves;
        for (int i: uniqueLetters) {
            if (dependencies[i].empty()) {
                leaves.insert(i);
            }
        }
        vector<bool> processed(26);
        string res;
        while (!leaves.empty()) {
            unordered_set<int> newLeaves;
            for (int leaf : leaves) {
                for (int reverseDep : invertedDeps[leaf]) {
                    dependencies[reverseDep].erase(leaf);
                    if (dependencies[reverseDep].empty()) {
                        newLeaves.insert(reverseDep);
                    }
                }
                res += (char) ('a' + leaf);
                processed[leaf] = true;
            }
            swap(newLeaves, leaves);
        }
        for (int letter: uniqueLetters) {
            if (!processed[letter]) return "";
        }
        reverse(res.begin(), res.end());
        return res;
    }

    static void testMe() {
        AlienDictionaryTakeTwo alien;
        vector<string> words =  {"ac","ab","zc","zb"};
        string res = alien.alienOrder(words);
        cout << res << endl;
    }
};
#endif //CPPALGORITHMS_ALIENDICTIONARYTAKETWO_H
