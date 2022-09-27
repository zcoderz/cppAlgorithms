//
// Created by usman on 9/26/22.
//

#ifndef CPPALGORITHMS_KMPMATCH_H
#define CPPALGORITHMS_KMPMATCH_H

#include <vector>
#include <string>

using namespace std;


class KMPMatch {

public:
    static vector<int> match_pattern_in_text(string text, string pattern) {
        vector<int> patternArray = createPatternArray(pattern);
        int patternIndex =0, textIndex = 0;
        vector<int> matchIndexes;
        while (textIndex < text.length()) {
            if (text[textIndex] == pattern[patternIndex]) {
                if (patternIndex == pattern.size()-1) {
                    matchIndexes.push_back(textIndex - patternIndex);
                    //patternIndex = patternIndex > 0 ? patternIndex-1 : 0;
                } else {
                    patternIndex++;
                }
                textIndex++;
            } else if (patternIndex > 0) {
                patternIndex = patternArray[patternIndex-1];
            } else {
                textIndex++;
            }
        }
        if (matchIndexes.empty()) matchIndexes.push_back(-1);
        return matchIndexes;
    }

    static vector<int> createPatternArray(string & pattern) {
        vector<int> vec (pattern.size());
        vec[0] = 0;
        int i=1, j = 0;
        while (i < pattern.size()) {
            if (pattern[i] == pattern[j]) {
                vec[i++] = ++j;
            } else {
                if (j > 0) {
                    j = vec[j-1];
                } else {
                    i++;
                }
            }
        }
        return vec;
    }
};

#endif //CPPALGORITHMS_KMPMATCH_H
