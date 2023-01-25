//
// Created by usman on 1/24/23.
//

#ifndef CPPALGORITHMS_LONGESTREPEATINGSUBSTRING_H
#define CPPALGORITHMS_LONGESTREPEATINGSUBSTRING_H

#include <string>
#include <unordered_set>
using namespace std;

class LongestRepeatedSubstring {
public:

    bool possible (string & str, int mid) {
        unordered_set<string> data;
        for (int i =0; i <= str.size()-mid; i++) {
            string  subS = str.substr(i,mid);
            if (data.count(subS)) return true;
            data.insert(subS);
        }
        return false;
    }

    int longestRepeatingSubstring(string s) {
        int l =0; int r = s.size()-1;
        while (l < r) {
            int mid = l + (r-l+1)/2;
            if (possible(s, mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};

#endif //CPPALGORITHMS_LONGESTREPEATINGSUBSTRING_H
