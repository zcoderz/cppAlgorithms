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

    /**
     * Trick here is to understand that you can move one disk from source to destination while conforming to criteria
     * The problem amounts to :
     *  ** Break the N rings into N-1. Move N-1 to auxiliary , And then move the last ring to destination.
     * recursion A: Move N-1 disks from Source to Auxiliary (keep swapping auxiliary and destination during recursion).
     * Actual Move: Move Nth disk from Source to Destination
     * recursion B: Recurse to move disks from auxiliary to destination using source as auxiliary
     *
     * Time complexity : Each recursive call does O(1) operation of work --> move from source to destination.
     * Each call can break up to 2 recursions (move all to aux) and (move aux to dest).
     * Calls repeat per disk. Since there are N disks, the number of recursive calls will be 2^N.
     * @param diskId
     * @param src
     * @param aux
     * @param dest
     */
    static void move( int diskId, Tower & src, Tower & aux, Tower & dest) {
        if(diskId == 0) {
            return;
        }
        //keep swapping dest and auxiliary.
        //move N-1 disks from src to auxiliary using destination peg as auxiliary
        move(diskId-1, src, dest, aux);
        //at this point N-1 disks are in aux
        //move Nth disk from source to destination
        int val = src.disks.back(); src.disks.pop_back();
        cout << "moved disk " << val << " from " << src.name << " to " << dest.name << endl;
        dest.disks.push_back(val);
        //swap auxiliary and source.
        //move disks from auxiliary to destination using source as auxiliary and repeat
        move(diskId-1, aux, src, dest);
    }
};

#endif //CPPALGORITHMS_TOWERSOFHANOI_H
