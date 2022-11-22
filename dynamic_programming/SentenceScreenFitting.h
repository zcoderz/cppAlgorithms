//
// Created by usman on 11/21/22.
//

#ifndef CPPALGORITHMS_SENTENCESCREENFITTING_H
#define CPPALGORITHMS_SENTENCESCREENFITTING_H

#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class SentenceScreenFitting {
public:
    static int wordsTyping(vector<string>& sentence, int rows, int cols) {
        unordered_map<int, int> nextWordMap;
        unordered_map<int, int> sentenceCountMap;

        for (int i =0; i < sentence.size(); i++) {
            int col=0;
            int currWordIndex=i;
            int numberOfSentenceCrosses = 0;
            while (col + sentence[currWordIndex].length() <=cols) { //parse the current word only if it can fit
                col = col + sentence[currWordIndex++].length() + 1; //move the word ahead
                if (currWordIndex == sentence.size()) {
                    numberOfSentenceCrosses++;
                    currWordIndex = 0;
                }
            }
            nextWordMap[i] = currWordIndex;
            sentenceCountMap[i] = numberOfSentenceCrosses;
        }

        int rowNo = 0;
        int numberOfSentences = 0;
        int wordIndex = 0;

        while (rowNo < rows) {
            numberOfSentences += sentenceCountMap[wordIndex];
            wordIndex = nextWordMap[wordIndex];
            rowNo++;
        }
        return numberOfSentences;
    }

    static void testMe() {
        vector<string> vec = {"i","had", "apple", "pie"};
        int res = wordsTyping(vec, 4, 5);
        cout << res << endl;
    }
};

#endif //CPPALGORITHMS_SENTENCESCREENFITTING_H
