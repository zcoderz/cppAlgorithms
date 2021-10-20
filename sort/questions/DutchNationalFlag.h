//
// Created by usman on 10/18/21.
//

#ifndef KICK_START_DUTCHNATIONALFLAG_H
#define KICK_START_DUTCHNATIONALFLAG_H

#endif //KICK_START_DUTCHNATIONALFLAG_H
#include <algorithm>
using namespace std;

//this code is fairly tricky! understanding the pattern here is imp.
class DutchNationalFlag {
    void dutch_flag_sort(vector<char>& balls) {
        int currIndex = 0;
        int redIndex =0;
        int blueIndex = balls.size() -1;

        while (currIndex <= blueIndex) {
            if (balls[currIndex] == 'G') {
                //skip G, look at the below cases to understand why!
                currIndex++;
            } else if (balls[currIndex] == 'B') {
                /*
				Two cases here:

				1) 'R' or 'G' is the last character. Then after swapping we can not increment
				current_idx. Consider "RRGGBGRBB", current_idx = 4 and swap_blue_here = 6. After
				the swap it will become "RRGGRGBBB". At current_idx 'R' will be there so we can
				not skip it! In the next iteration we need to consider the same index.
				2) 'B' is the last character. Then we will swap current 'B' with that 'B' that
				will just decrement the swap_blue_here. (This might be tricky to understand
				without taking examples, better try to take some examples.)
			    */
                swap(balls[currIndex], balls[blueIndex--]);
            } else {
                /*
                Two cases here:

                1) We have encountered at least one 'G'. For that we know the solution, just swap
                'R' with left most 'G'.
                2) We have not encountered any 'G'. Consider string 'RRRRR' and current_idx = 0.
                In this case 'swap_red_here' we will be the same index as 'current_idx' that is 0.
                Here we just swap 'R' with it self! (Basically we are doing no change!)

                So either we are swapping with left most 'G' if available or we are swapping with
                itself. So both of them will maintain the structure!

                Also note that we are incrementing both the indices, current_idx and
                swap_red_here.

                To understand that also, consider both the cases:

                1) We have encountered at least one 'G'. Consider "RRGGRB", current_idx = 4 and
                swap_red_here will be 2, so after swap it will look like "RRRGGB", now index of
                left most 'G' should be incremented and also at the current index we have 'G' so
                we can skip it.
                2) We have not encountered any 'G'. Consider string 'RRRRR' and current_idx = 0.
                In this case 'swap_red_here' we will be the same index as 'current_idx' that is 0.
                So, after the swap we can increment both of them. (This might be tricky to
                understand without taking examples, better try to take some examples.)
            */
                swap(balls[currIndex++], balls[redIndex++]);
            }
        }
    }
};