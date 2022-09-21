//
// Created by usman on 9/20/22.
//

#ifndef CPPALGORITHMS_SKIPLIST_H
#define CPPALGORITHMS_SKIPLIST_H

template <class T>
class SkipList{
private:
    // Linked list structure definition.
    class LinkedListNode {
    public:
        T value;
        // An array to hold next node of different levels.
        vector<LinkedListNode*> next;
        LinkedListNode(){}
        LinkedListNode(int _value, int level){
            value = _value;
            next.resize(level);
        }
    };
    // Max level of the skip list
    int maxLevel;
    // Head of the skip list
    LinkedListNode *head;
    // This is used to generate random number in C++.
    int randomCounter;

public:
    // Constructor to initialize the skip list
    // It takes number of queries as parameter
    SkipList(int numberOfQueries){
        // Set maximum level of the skip list may have
        maxLevel = getMaxLevel(numberOfQueries);
        // Dummy head
        head = new LinkedListNode(0, maxLevel);
        randomCounter = 1;
        // This is used as rand() of C++ behaves in static form.
        srand((unsigned)time(0));
    }

    // Function to insert element in the skip list
    void insert(T value) {
        // Head reference is copied to tmp
        LinkedListNode *tmp = head;
        // Calculate level for current element
        int newLevel = getRandomLevel(value);
        // Create a new linked list node
        LinkedListNode *newNode = new LinkedListNode(value, newLevel + 1);
        // Level start from 0, so effective max level is (maxlevel - 1)
        int currentLevel = maxLevel - 1;
        // Iterate until reach to base level (level 0)
        while(currentLevel >= 0){
            // Find out the node after which new node will be inserted in current level
            while(tmp->next[currentLevel] != NULL && tmp->next[currentLevel]->value < value){
                tmp = tmp->next[currentLevel];
            }
            // It the value present already, ignore
            if(tmp->next[currentLevel] != NULL && tmp->next[currentLevel]->value == value){
                return;
            }
            // If this is the level smaller than or equal to level of new node, insert the new node in this level
            if(currentLevel <= newLevel){
                newNode->next[currentLevel] = tmp->next[currentLevel];
                tmp->next[currentLevel] = newNode;
            }
            currentLevel--;
        }
    }

    // Check if a valueue is present in the skip list or not
    bool is_present(T value){
        LinkedListNode *tmp = head;
        int currentLevel = maxLevel - 1;
        while(currentLevel >= 0){
            while(tmp->next[currentLevel] != NULL && tmp->next[currentLevel]->value < value){
                tmp = tmp->next[currentLevel];
            }
            if(tmp->next[currentLevel] != NULL && tmp->next[currentLevel]->value == value){
                return true;
            }
            currentLevel--;
        }
        return false;
    }

    // Remove a valueue from the skip list if present
    // If the valueue does not exist, just ignore
    void remove(T value){
        LinkedListNode *tmp = head;
        int currentLevel = maxLevel - 1;
        while(currentLevel >= 0){
            while(tmp->next[currentLevel] != NULL && tmp->next[currentLevel]->value < value){
                tmp = tmp->next[currentLevel];
            }
            if(tmp->next[currentLevel] != NULL && tmp->next[currentLevel]->value == value){
                // The valueue is present in the skip list. So, remove it from the current level and go for next level.
                if(currentLevel > 0){
                    // If this is not the base level, just update the reference.
                    tmp->next[currentLevel] = tmp->next[currentLevel]->next[currentLevel];
                } else {
                    // If this is the base level, update the reference and delete the node.
                    LinkedListNode *nodeToDelete = tmp->next[currentLevel];
                    tmp->next[currentLevel] = tmp->next[currentLevel]->next[currentLevel];
                    delete(nodeToDelete);
                }
            }
            currentLevel--;
        }
    }

private:
    // Generate random level
    int getRandomLevel(int value){
        int level = 0;
        while(level < maxLevel - 1 && getRandomValue(0, 1) != 0){
            level++;
        }
        return level;
    }
    // Generate random valueue within a range
    int getRandomValue(int minRange, int maxRange){
        if(minRange > maxRange){
            return -1;
        }
        int limit = (maxRange - minRange + 1);
        return (rand() % limit + minRange);
    }
    // Calculate max level from number of queries
    // A skip list can have maximum of log(N) level as in each level, maximum half of
    // it's previous level's node can have. Otherwise, there is no difference between
    // a skip list and a singly liked list.
    int getMaxLevel(int numberOfQueries){
        int levelCount = 0;
        while(numberOfQueries > 0){
            levelCount++;
            numberOfQueries /= 2;
        }
        return levelCount;
    }
};


#endif //CPPALGORITHMS_SKIPLIST_H
