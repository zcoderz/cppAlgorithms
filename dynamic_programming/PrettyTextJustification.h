//
// Created by usman on 11/9/22.
//

#ifndef CPPALGORITHMS_PRETTYTEXTJUSTIFICATION_H
#define CPPALGORITHMS_PRETTYTEXTJUSTIFICATION_H

#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>

using namespace std;

/**
 * DINOSAUR : This is a tricky one...need to do this again!!!
 */
class PrettyTextJustification {
public :
    static string justify(vector<string> words, int width) {
        int size = words.size();
        vector<vector<int>> cost (size, vector<int> (size, INT_MAX));
        for (int i =0; i < size; i++) {
            cost[i][i] = width - words[i].length();
            //start from the next word till the end
            for (int j = i+1; j < size; j++) {
                cost[i][j] = cost[i][j-1] - words[j].length() -1; //decrease size of the string from the cost
            }
        }
        for (int i =0; i < size; i++) {
            //modify negative to INT_MAX and square cost to accurately weigh cost based
            //on number of spaces per line rather than total spaces across lines
            for (int j = i; j < size; j++) {
                if (cost[i][j] < 0) {
                    cost[i][j] = INT_MAX;
                }  else {
                    cost[i][j] = cost[i][j] * cost[i][j] ;
                }
            }
        }
        vector<int> wCost (size);
        vector<int> endingWord (size);
        for (int i = size-1; i >=0; i--) {
            wCost[i] = cost[i][size-1] ;
            endingWord[i]= size;
            for (int j = size-1; j >i; j--) {
                if (cost[i][j-1] == INT_MAX) continue;
                //cost of adding up to j-1 on current line and j onwards on next line
                int newCost = cost[i][j-1] + wCost[j];
                if (newCost < wCost[i]) {
                    wCost[i] = newCost;
                    endingWord[i] = j; //means j is not included on current line
                }
            }
        }

        string res;

        int startIndex = 0;
        int endIndex = endingWord[startIndex];

        while(startIndex != size) {
            while (startIndex != endIndex) {
                res += words[startIndex] + " ";
                startIndex++;
            }
            res += "\n";
            if (startIndex != size)
                endIndex = endingWord[startIndex];
        }

        return res;
    }

    static void testMe() {
        //string str = "life is juicy sprinkled with lemons. what a treat to enjoy juices on a beach. dont you like to code? yay no way";
        string str = "enjoy juices on a beach";
        vector<string> strVec;
        boost::split(strVec,str,boost::is_any_of(" "));
        string res = justify(strVec, 16);
        cout << res << endl;
    }

};

#endif //CPPALGORITHMS_PRETTYTEXTJUSTIFICATION_H
