//
// Created by usman on 9/22/22.
//

#ifndef CPPALGORITHMS_ZIGZAGWORDS_H
#define CPPALGORITHMS_ZIGZAGWORDS_H

#include <string>
#include <sstream>

using namespace std;

class ZigZagWords {
public:

    static void process(string & s, int rowNo, int totalRows, stringstream  &strm) {
        bool isEdge = (rowNo == 0 || rowNo == totalRows - 1);
        int currIndex = rowNo;
        bool  isDown = true;
        for (; currIndex < s.size(); ) {
            strm << s[currIndex];
            int offset = 0;
            if (isEdge) {
                int inBtwRows = totalRows  -2;
                // in between rows have chars repeated twice hence *2
                // + 2 (one for next edge, and one for moving to next char)
                offset = 2 * inBtwRows + 2;
            } else {
                //number of in between rows is different based on whether going down or above
                int inBtwRows =0;
                if (isDown) {
                    //rows btw last row and current
                    //(since rows are indexed from 0 subtract one & subtract one more to remove first row)
                    inBtwRows = totalRows - rowNo -2;
                } else {
                    inBtwRows = rowNo -1; //rows btw first row and current
                }
                offset = 2 * inBtwRows + 2;
            }
            currIndex += offset;
            isDown = !isDown;
        }
    }

    static string convert(string s, int numRows) {
        stringstream strm;
        for (int i =0; i < numRows; i++) {
            process(s, i, numRows, strm);
        }
        return strm.str();
    }

    static string convertTwo(string s, int numRows) {
        if (numRows == 1) return s;
        stringstream ret;
        int n = s.length();
        //cycle is twice number of rows -2. every row except first and last gets two repeats
        int cycleLen = 2 * numRows - 2;
        for (int i = 0; i < numRows; i++) {
            //repeat every cycleLen
            for (int j = 0; j + i < n; j += cycleLen) {
                ret << s[j+i];
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n) {
                    //this repeat is for rows except first and last
                    //its :  next repeat of first row which is j + cycleLen and then subtract how far
                    //this row is from the first row.
                    ret << s[j+cycleLen-i];
                }
            }
        }
        return ret.str();
    }


};

#endif //CPPALGORITHMS_ZIGZAGWORDS_H
