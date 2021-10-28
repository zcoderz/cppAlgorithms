//
// Created by usman on 10/27/21.
//

#ifndef CPPALGORITHMS_TOWERSOFHANOI_H
#define CPPALGORITHMS_TOWERSOFHANOI_H

struct Tower {
    Tower(string nameP) {
        this->name = nameP;
    }
    vector<int> disks;
    string name;
};

class TowersOfHanoi {
public:

    void move( int diskId, Tower & src, Tower & aux, Tower & dest) {
        if(diskId == 1) {
            //this is the terminating condition
            int val = src.disks.back(); src.disks.pop_back();
            cout << "moved disk " << val << " from " << src.name << " to " << dest.name << endl;
            dest.disks.push_back(val);
            return;
        }
        //alternate between destination and auxiliary in stack so plates are moved
        //to destination while keeping constraint of plate size in check
        move(diskId-1, src, dest, aux);
        //previous call moved plate to alternate destination (aux) and returned
        //now move next plate to the destination designated for this stack
        int val = src.disks.back(); src.disks.pop_back();
        cout << "moved disk " << val << " from " << src.name << " to " << dest.name << endl;
        dest.disks.push_back(val);
        //move plates from auxiliary to destination
        move(diskId-1, aux, src, dest);
    }
};

#endif //CPPALGORITHMS_TOWERSOFHANOI_H
