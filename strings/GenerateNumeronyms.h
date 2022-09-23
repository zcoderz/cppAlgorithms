//
// Created by usman on 9/23/22.
//

#ifndef CPPALGORITHMS_GENERATENUMERONYMS_H
#define CPPALGORITHMS_GENERATENUMERONYMS_H

#include <vector>
#include <string>

using namespace std;
class Numeronyms {

public:

    static void process(string & word, string & currStr, int index, vector<string> & res) {
        if (index >= word.size()) {
            res.push_back(currStr);
            return;
        }
        currStr = currStr + word[index];
        process(word, currStr, index+1, res);
        currStr.erase(--currStr.end());
        if (index !=0 && index != word.size()-1) {
            for (int i =2; i + index < word.size(); i++) {
                int sz = currStr.size();
                currStr +=  std::to_string(i);
                process(word, currStr, index+i, res);
                currStr.erase(sz);
            }
        }
    }

    static vector<string> generate_all_numeronyms(string &word) {
        vector<string> res;
        string currStr;
        process(word, currStr, 0, res);
        return res;
    }

};

#endif //CPPALGORITHMS_GENERATENUMERONYMS_H
