//
// Created by usman on 12/21/22.
//

#ifndef CPPALGORITHMS_SMALLESTSTRINGWITHSWAPS_H
#define CPPALGORITHMS_SMALLESTSTRINGWITHSWAPS_H

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

class SmallestStringWithSwaps {
public:
    vector<pair<int, int>> vertices;

    int find(int vertexId) {
        if (vertices[vertexId].first != vertexId) {
            int parent = find(vertices[vertexId].first);
            vertices[vertexId].first = parent;
        }
        return vertices[vertexId].first;
    }

    void runUnion(int vertexId1, int vertexId2) {
        vertexId1 = find(vertexId1);
        vertexId2 = find(vertexId2);

        if (vertices[vertexId1].second == vertices[vertexId2].second) {
            vertices[vertexId1].second++;
            vertices[vertexId2].first = vertexId1;
        } else if (vertices[vertexId1].second > vertices[vertexId2].second) {
            vertices[vertexId2].first = vertexId1;
        } else {
            vertices[vertexId1].first = vertexId2;
        }
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vertices.resize(s.size());
        for (int i =0; i < s.size(); i++) {
            vertices[i] = make_pair(i, 0);
        }
        for (auto & p: pairs) {
            runUnion(p[0], p[1]);
        }
        unordered_map<int, vector<int>> keyMap;
        for (int i=0; i <s.size(); i++) {
            int parent = find(i);
            keyMap[parent].push_back(i);
        }
        string retStr (s.size(), ' ');
        for (auto & item: keyMap) {
            //indexes contains set of connected indexes
            vector<int> & indexes = item.second;
            vector<char> chars;
            //copy chars at the given indexes
            for (int i =0; i < indexes.size(); i++) {
                chars.push_back(s[indexes[i]]);
            }
            //sort the chars lexicographically
            //chars are now in ascending order
            sort(chars.begin(), chars.end());

            //for each index in the connected component put the next ascending char in it
            for (int i =0; i < indexes.size(); i++) {
                retStr[indexes[i]] = chars[i];
            }
        }
        return retStr;
    }

    static void testMe() {
        SmallestStringWithSwaps sm;
        vector<vector<int>> vec = {{0,3},{1,2}};
        string res = sm.smallestStringWithSwaps("dcab", vec);
        cout << res ;

    }
};

#endif //CPPALGORITHMS_SMALLESTSTRINGWITHSWAPS_H
