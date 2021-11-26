//
// Created by usman on 11/24/21.
//

#ifndef CPPALGORITHMS_EDITDISTANCE_H
#define CPPALGORITHMS_EDITDISTANCE_H

class EditDistance {
public:
    int minDistance(string word1, string word2) {

        //initialize boundary in case the other string is deleted to get to the given index
        vector<int> priorVals (word2.length()+1, 0);
        for (int i =1; i <= word2.length();i++) {
            priorVals[i] = i;
        }

        for (int i = 1; i <= word1.length(); i++) {
            vector<int> currVals(word2.length() + 1, 0);
            //initialize boundary in case the other string is deleted to get to the given index
            currVals[0]=i;
            for (int j = 1; j <= word2.length(); j++) {
                //val is min of upper, diagonal upper or left
                int val = min(currVals[j - 1], min(priorVals[j], priorVals[j-1]));
                if (word1[i-1] == word2[j-1]) {
                    val = priorVals[j-1]; //no edit is needed, take whatever was in prior upper
                } else {
                    val++; //an edit is needed , hence increment
                }
                currVals[j] = val;
            }
            priorVals = move(currVals);
        }
        return priorVals[word2.length()];
    }
};

#endif //CPPALGORITHMS_EDITDISTANCE_H
