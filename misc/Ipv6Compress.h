//
// Created by usman on 11/7/21.
//

#ifndef CPPALGORITHMS_IPV6COMPRESS_H
#define CPPALGORITHMS_IPV6COMPRESS_H

#include <string>
#include <vector>

#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>

using namespace std;


class IPV6Compress{
public:
    string runCompression(string ip) {
        vector<string> strs;
        boost::split(strs,ip,boost::is_any_of(":"));
        //find the biggest range of segments that contain a "0"
        int biggestLeft=-1, biggestRight=-1;
        int left=-2;
        int right = -2;
        int maxZeros = 0;
        for (int i =0; i < strs.size(); i++) {
            string & str = strs[i];
            //remove starting chars in each segment that are 0. dont remove the last 0 char
            while (str[0]=='0' && str.size() > 1) {
                str.erase(str.begin(), str.begin()+1);
            }
            //find out which indices are infact "0"
            if (str == "0") {
                if (right == i-1) {
                    right = i;
                } else {
                    left=i;
                    right=i;
                }

                int sz = right-left+1;
                if (sz > maxZeros) {
                    maxZeros = sz;
                    biggestLeft = left;
                    biggestRight = right;
                }
            }
        }

        //for segments that fall in the 0 range, handle them with ::
        string out;
        bool colAdded = false;
        for (int i =0; i < strs.size(); i++) {
            if (i >= biggestLeft && i <= biggestRight) {
                if (!colAdded) {
                    colAdded = true;
                    out += ":";
                }
            } else {
                out += strs[i];
                if (i != strs.size()-1) {
                    out += ":";
                }
            }
        }
        return out;
    }
};

#endif //CPPALGORITHMS_IPV6COMPRESS_H
