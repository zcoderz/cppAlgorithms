//
// Created by USMAN QADIR on 9/23/22.
//

#ifndef CPPALGORITHMS_JOINTOMAKEPALINDROME_H
#define CPPALGORITHMS_JOINTOMAKEPALINDROME_H

#include <vector>
#include <unordered_map>
using namespace std;

class JoinToMakePalindrome {

    bool isPalindrome(string & str) {
        int i =0, j = str.size()-1;
        while (i <j) {
            if (str[i++] != str[j--]) {
                return false;
            }
        }
        return true;
    }

    vector<string> join_words_to_make_a_palindrome(vector<string> &words) {
        unordered_map<string, int> wordMap;
        for (int i =0; i < words.size(); i++) {
            wordMap[words[i]] = i;
        }

        for (int i =0; i < words.size(); i++) {
            string & word = words[i];
            for (int j =0; j < word.size(); j++) {
                string left = word(0, j);
                string right = word(j, word.size()-j);
                if (isPalindrome(left)) {
                    string temp = right;
                    reverse(temp.begin(), temp.end());
                    auto iter = wordMap.find(temp);
                    if (iter != wordMap.end() && iter->second != i) {
                        return {word, temp};
                    }
                }
                if (isPalindrome(right)) {
                    string temp = left;
                    reverse(temp.begin(), temp.end());
                    auto iter = wordMap.find(temp);
                    if (iter != wordMap.end() && iter->second != i) {
                        return {word, temp};
                    }
                }
            }
        }
    }
    vector<string> join_words_to_make_a_palindrome_slow(vector<string> &words) {
        vector<string> res;


        for (string &word: words) {
            for (string & word2: words) {
                if (&word2 == &word) continue;
                string temp = word + word2;
                //cout << "word is " << temp << endl;
                if (isPalindrome(temp)) {
                    res.push_back(word);
                    res.push_back(word2);
                    return res;
                }
            }
        }

        // Write your code here.
        return {"NOTFOUND", "DNUOFTON"};
    }
};
#endif //CPPALGORITHMS_JOINTOMAKEPALINDROME_H
