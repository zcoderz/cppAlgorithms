//
// Created by usman on 12/22/22.
//

#ifndef CPPALGORITHMS_ACCOUNTSMERGE_H
#define CPPALGORITHMS_ACCOUNTSMERGE_H

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class AccountsMerge {
public:
    unordered_map<string, pair<string, int>> vertices;

    string find(string word) {
        if (vertices[word].first != word) {
            string parent = find(vertices[word].first);
            vertices[word].first = parent;
        }
        return vertices[word].first;
    }

    bool runUnion(string wordA, string wordB) {
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

    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        unordered_map<string, string> acctToEmailMap;
        for (auto &vec: accounts) {
            string acctName = vec[0];
            string firstEmail = vec[1];
            for (int i = 1; i < vec.size(); i++) {
                string email = vec[i];
                if (vertices.find(email) == vertices.end()) {
                    vertices[email] = {email, 0};
                }
                runUnion(firstEmail, email);
                acctToEmailMap[email] = acctName;
            }
        }
        unordered_map<string, vector<string>> connectedEmails;
        for (auto &email: vertices) {
            string parent = find(email.first);
            connectedEmails[parent].emplace_back(email.first);
        }
        vector<vector<string>> res;
        for (auto &component: connectedEmails) {
            vector<string> acctEmails;
            string acctName = acctToEmailMap[component.first];
            acctEmails.push_back(acctName);
            sort(component.second.begin(), component.second.end());
            acctEmails.insert(acctEmails.end(), component.second.begin(), component.second.end());
            res.push_back(acctEmails);
        }
        return res;
    }
};

#endif //CPPALGORITHMS_ACCOUNTSMERGE_H
