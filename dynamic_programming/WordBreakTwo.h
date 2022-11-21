//
// Created by usman on 11/20/22.
//

#ifndef CPPALGORITHMS_WORDBREAKTWO_H
#define CPPALGORITHMS_WORDBREAKTWO_H

#include <vector>
#include <string>
#include <list>
using namespace std;

class WordBreakTwo {
public:
    static vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<vector<int>> dp(s.length()+1, vector<int>());
        for (int i =0; i < s.length(); i++) {
            for (int j = 0; j < wordDict.size(); j++) {
                string & word  =  wordDict[j];
                //starting index is current index - word length + 1
                int startingIndex = i - word.length() + 1;
                //starting index is either first or has been already reached
                if (((startingIndex == 0 || (startingIndex > 0 && !dp[startingIndex].empty()))
                            //and the current string matches
                            && s.substr(startingIndex, word.length()) == word)) {
                    //indicate that you have reached up the i+1 index using the jth word
                    dp[i+1].push_back(j);
                }
            }
        }
        vector<string> res;
        buildStrings(s.length(), "", res, dp, wordDict);
        return res;
    }

    /**
     * recurse until the index 0 to construct possible strings
     * @param index
     * @param str
     * @param res
     * @param dp
     * @param wordDict
     */
    static void buildStrings(int index, string str, vector<string> & res,
                             vector<vector<int>> & dp, vector<string>& wordDict) {
        //terminate at start of the string
        if (index ==0) {
            //remove the extra white space at end of the string
            res.push_back(str.substr(0, str.length()-1));
            return;
        }
        //dp index contains list of dictionary indexes that are valid at the given string index
        for (int wordIndex : dp[index]) {
            string newString = wordDict[wordIndex] + " " + str;
            //index-wordDict[wordIndex].size() move back by length of the string
            buildStrings(index-wordDict[wordIndex].size(), newString, res, dp, wordDict);
        }
    }

    static void testMe() {
        string str = "catsanddog";
        vector<string> wordDict = {"cat","cats","and","sand","dog"};
        vector<string> res = wordBreak(str, wordDict);
        std::copy(res.begin(), res.end() , std::ostream_iterator<string>(cout, ", "));
    }
};

#endif //CPPALGORITHMS_WORDBREAKTWO_H
