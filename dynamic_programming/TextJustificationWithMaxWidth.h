//
// Created by usman on 11/8/22.
//

#ifndef CPPALGORITHMS_TEXTJUSTIFICATIONWITHMAXWIDTH_H
#define CPPALGORITHMS_TEXTJUSTIFICATIONWITHMAXWIDTH_H

#include <vector>
#include <string>
#include <iostream>
#include <iterator>
using namespace std;

class TextJustificationWithMaxWidth {
public:
    static vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> res;
        vector<string> currVec;
        int currLenWords = 0;
        for (const string &word: words) {
            if (currLenWords + word.size() + currVec.size() > maxWidth) {
                int spaces = maxWidth - currLenWords;
                int currVecSz = currVec.size();
                for (int i =0; i < spaces; i++) {
                    int index = currVecSz==1? 0 :  i % (currVec.size()-1);
                    string &str = currVec[index];
                    str += " ";
                }
                string strCombined;
                for (string &tmpW: currVec) {
                    strCombined += tmpW;
                }
                res.push_back(strCombined);
                currLenWords = 0;
                currVec.clear();
            }
            currVec.push_back(word);
            currLenWords += word.length();
        }
        string strCombined;
        for (auto & str : currVec) {
            strCombined += str;
            strCombined += " ";
        }
        if (strCombined.size() < maxWidth)
            strCombined.append(maxWidth-strCombined.size(), ' ');
        else if (strCombined.size() > maxWidth)
            strCombined = strCombined.substr(0, strCombined.size() - 1);

        if (!strCombined.empty()) {
            res.push_back(strCombined);
        }
        return res;
    }

    static void testMe() {
        vector<string> words = {"What","must","be","acknowledgment","shall","be"};
        vector<string> res = fullJustify(words, 16);
        std::copy(res.begin(), res.end() , std::ostream_iterator<string>(cout, ", "));
    }

};

#endif //CPPALGORITHMS_TEXTJUSTIFICATIONWITHMAXWIDTH_H
