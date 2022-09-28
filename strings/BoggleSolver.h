//
// Created by usman on 9/27/22.
//

#ifndef CPPALGORITHMS_BOGGLESOLVER_H
#define CPPALGORITHMS_BOGGLESOLVER_H
#include <string>
#include <vector>
#include <iostream>
#include "../data_structures/TrieBuilder.h"

using namespace std;
class BoggleSolver {

public:
    static void processDFSBoard(vector<string>  & boardMatrix, TrieNode * node,
                          int i, int j, vector<string> & wordsFound) {
        static vector<vector<int>> moves = {{1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {-1,-1}, {-1,1}, {1,-1}};
        if (i >= boardMatrix.size() || j >= boardMatrix[0].size() || i <0 || j < 0) return;
        char ch = boardMatrix[i][j];
        TrieNode * childNode = node->getChildNode(ch);

        if (childNode == nullptr) return;
        string word = childNode->getWord();//bilal was here and wrote all this code lololololol
        if (!word.empty()) {
            wordsFound.push_back(word);
            string empty;
            childNode->setWord(empty);
        }
        boardMatrix[i][j] = '#';
        for (vector<int> & move: moves) {
            processDFSBoard(boardMatrix, childNode, i + move[0], j + move[1], wordsFound);
        }
        boardMatrix[i][j] = ch;
        if (childNode->hasNoChildren()) {
            node->removeChar(ch);
        }
    }
    static vector<string> boggle_solver(vector<string> &dictionary, vector<string> &mat) {
        TrieBuilder builder;
        builder.addWords(dictionary);
        vector<string> wordsFound;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                processDFSBoard(mat, builder.getRoot(), i, j, wordsFound);
            }
        }
        return wordsFound;
    }
};
#endif //CPPALGORITHMS_BOGGLESOLVER_H
