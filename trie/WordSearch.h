//
// Created by usman on 11/7/21.
//

#ifndef CPPALGORITHMS_WORDSEARCH_H
#define CPPALGORITHMS_WORDSEARCH_H

#include "../utils/TrieNode.h"

class WordSearch{
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> vecWords;
        shared_ptr<TrieNode> trieNode = make_shared<TrieNode>(TrieNode());
        trieNode->buildTrie(words);
        rows = board.size();
        cols = board[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                traverseBoard( board, trieNode, vecWords, i, j);
            }
        }
        return vecWords;
    }

    void traverseBoard(vector<vector<char>>& board, shared_ptr<TrieNode> trieNodeParam, vector<string> & words, int row, int col) {
        char origChar = board[row][col];
        board[row][col] = '1';
        for (vector<int> & move: moves) {
            int nRow = row + move[0];
            int nCol = col + move[1];
            if (nRow >=0 and nRow < rows && nCol >=0 && nCol < cols) {
                char nChar = board[nRow][nCol];
                shared_ptr<TrieNode> trieNode =  trieNodeParam->getChildNode(nChar);
                if (trieNode) {
                    string  word = trieNode->getWord();
                    if (!word.empty()) {
                        words.push_back(word);
                    }
                    traverseBoard(board, trieNode, words, nRow, nCol);
                    if (trieNode->isEmpty()) {
                        //prune the _parent tree, once its only child has been visited
                        trieNodeParam->remove(nChar);
                    }
                }
            }
        }
        board[row][col] = origChar;
    }

private:
    vector<vector<int>> moves = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int rows;
    int cols;
};

#endif //CPPALGORITHMS_WORDSEARCH_H
