//
// Created by usman on 9/22/22.
//

#ifndef CPPALGORITHMS_LONGESTSUBSTRINGWITHATMOSTKDISTINCTCHARS_H
#define CPPALGORITHMS_LONGESTSUBSTRINGWITHATMOSTKDISTINCTCHARS_H

#include <string>
#include <set>
#include <map>

using namespace std;
class LongestSubstrWithDistinct {
public:


    static int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k ==0) return 0;
        map<char, int> charCountMap;
        int left=0, maxLen=0;
        for (int i =0; i < s.size(); i++) {
            charCountMap[s[i]]++;
            if (charCountMap.size() > k) {
                charCountMap[s[left]]--;
                if (charCountMap[s[left]] == 0) {
                    charCountMap.erase(s[left]);
                }
                left++;
            }
            maxLen = i-left+1;
        }
        return maxLen;
    }

    static int lengthOfLongestSubstringKDistinctN2(string s, int k) {
        if (k==0) return 0;
        int maxStrLen = 0;
        map<char, int> charIndexMap;
        set<char> distinctChars;
        int startIndex = 0;
        for (int i =0; i < s.length(); i++) {
            distinctChars.insert(s[i]);
            if (distinctChars.size() > k) {
                char charToRemove;
                int maxLen = numeric_limits<int>::min();
                for (char ch: distinctChars) {
                    if (ch == s[i]) continue;
                    if (i-charIndexMap[ch] > maxLen) {
                        maxLen = i-charIndexMap[ch];
                        charToRemove = ch;
                    }
                }
                distinctChars.erase(charToRemove);
                startIndex = charIndexMap[charToRemove] + 1;
            }
            charIndexMap[s[i]] = i;
            maxStrLen = max(maxStrLen, i-startIndex+1);
        }
        return maxStrLen;
    }
};

#endif //CPPALGORITHMS_LONGESTSUBSTRINGWITHATMOSTKDISTINCTCHARS_H
