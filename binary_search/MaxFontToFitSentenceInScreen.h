//
// Created by usman on 1/17/23.
//

#ifndef CPPALGORITHMS_MAXFONTTOFITSENTENCEINSCREEN_H
#define CPPALGORITHMS_MAXFONTTOFITSENTENCEINSCREEN_H

#include <string>
#include <vector>

using namespace std;


class MaxFontToFitSentenceInScreen {
    class FontInfo {
    public:
        // Return the width of char ch when fontSize is used.
        int getWidth(int fontSize, char ch);

        // Return Height of any char when fontSize is used.
        int getHeight(int fontSize);
    };

public:
    /**
     * if you converge on to first index of font and it still turns out to be greater than the max allowed
     * you have to return that no fonts are possible.
     * thus you need to try once where l==r and marking whether its a success
     */
    int maxFont(string text, int w, int h, vector<int> &fonts, FontInfo fontInfo) {
        int l = 0;
        int r = fonts.size() - 1;
        bool found = false;

        while (l <= r) {
            int mid = l + (r - l + 1) / 2;
            if (fontInfo.getHeight(fonts[mid]) > h) {
                r = mid - 1;
                continue;
            }
            int width = 0;
            for (char ch: text) {
                width += fontInfo.getWidth(fonts[mid], ch);
            }
            if (width > w) {
                r = mid - 1;
            } else {
                l = mid;
                found = true;
                //see explanation above. we continue loop until l==r so that we can verify whether
                //the value indeed works or otherwise. even though we may converge at first value,
                //it may still be out of bounds
                if (l == r) break;
            }
        }

        return !found ? -1 : fonts[l];
    }
};

#endif //CPPALGORITHMS_MAXFONTTOFITSENTENCEINSCREEN_H
