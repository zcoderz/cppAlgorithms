//
// Created by usman on 11/11/21.
//

#ifndef CPPALGORITHMS_FRIENDLYGROUPS_H
#define CPPALGORITHMS_FRIENDLYGROUPS_H

class FriendlyGroups {
public:
    vector<int> peopleColors;
    vector<vector<int>> dislikeVec;

    bool processPeople(int personId , int color) {
        peopleColors[personId] = color;
        vector<int> & vec = dislikeVec[personId];
        int newColor = (color + 1) % 2;
        for (int j : vec) {
            if (peopleColors[j]==-1) {
                bool  ret = processPeople(j, newColor);
                if (!ret) return ret;
            } else if (peopleColors[j] ==color) {
                return false;
            }
        }
        return true;
    }

    bool can_be_divided(int num_of_people, vector<int> & dislike1, vector<int> & dislike2) {
        peopleColors.resize(num_of_people, -1);
        dislikeVec.resize(num_of_people);
        for (int i=0; i < dislike1.size(); i++) {
            dislikeVec[dislike1[i]].push_back(dislike2[i]);
            dislikeVec[dislike2[i]].push_back(dislike1[i]);
        }
        for (int i =0; i < num_of_people; i++) {
            if (peopleColors[i]==-1) {
                bool  ret = processPeople(i, 0);
                if (!ret) return ret;
            }
        }
        return true;
    }

};

#endif //CPPALGORITHMS_FRIENDLYGROUPS_H
