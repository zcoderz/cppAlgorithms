//
// Created by usman on 11/14/21.
//

#ifndef CPPALGORITHMS_ALIENDICTIONARY_H
#define CPPALGORITHMS_ALIENDICTIONARY_H

#include <vector>

using namespace std;

/**
 * Complexity :
 * To construct the adjacency list we are comparing at worst every character in every word. And this is
 * the equivalent to number of characters in all the words. Lets call that O(C).
 * Number of edges on each comparison that gets created is 1. Hence at most there are N-1 edges, where N is number of words.
 * Assuming noOfVertices distinct characters and N-1 edges.
 * TopoSort complexity is (noOfVertices + E), Hence topo sort will take O(noOfVertices + N). Thus total complexity will be O(C+noOfVertices+N).
 * The upper bound of this is determined more heavily by C --> number of characters in all the words.
 * So the time complexity will be O(C)
 *
 * For space : We are processing at max 26 chars and have a total of N edges. Thus space is O(26 + N). At worst every character
 * can depend on every other char , so space becomes O(26^2).
 *
 */
class AlienDictionary {
public:

    bool processDependencies(char ch, vector<unordered_set<char>> & charDependencies, string & result, vector<int> & seen) {
        //cout << ch << endl;
        if (seen[ch - 'a'] == 2) {
            return true; //already processed
        }
        if (seen[ch - 'a'] == 1) {
            return false; //cycle
        }
        seen[ch - 'a'] = 1;
        for (auto iter = begin(charDependencies[ch - 'a']); iter != end(charDependencies[ch - 'a']); ++iter) {
            bool res = processDependencies(*iter, charDependencies, result, seen);
            if (!res) return false;
        }
        result.push_back(ch);
        seen[ch - 'a'] = 2;
        return true;
    }


    string find_order(vector <string> & words) {
        vector<unordered_set<char>> charDependencies(26);
        set<char> possibleChars;
        int i;
        for (i=0; i < words.size()-1; i++) {
            string & wordA = words[i];
            copy(wordA.begin(), wordA.end(), inserter(possibleChars, possibleChars.end()));
            string & wordB = words[i+1];
            if (wordA.size() > wordB.size() && (wordA.compare(0, wordB.size(), wordB)==0)) return "";
            int sz = min(wordA.size(), wordB.size());
            for (int j =0; j < sz; j++) {
                char src = wordA[j];
                char dep = wordB[j];
                if (src == dep) {
                    continue;
                }
                charDependencies[src-'a'].insert(dep);
                break;
            }
        }
        copy(words[i].begin(), words[i].end(), inserter(possibleChars, possibleChars.end()));
        //cout << "hello" << endl;
        vector<int> seen(26, 0);
        string result;
        for (auto iter = begin(possibleChars); iter != end (possibleChars); ++iter) {
            //cout << "A0" << *iter << endl;
            if (seen[*iter-'a']==2) continue;
            //cout << "A1" << endl;
            bool res = processDependencies(*iter, charDependencies, result, seen);
            if (!res) return "";
        }
        reverse(result.begin(), result.end());
        return result;
    }

};

#endif //CPPALGORITHMS_ALIENDICTIONARY_H
