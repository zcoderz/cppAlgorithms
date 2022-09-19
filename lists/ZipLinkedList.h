//
// Created by usman on 9/17/22.
//

#ifndef CPPALGORITHMS_ZIPLINKEDLIST_H
#define CPPALGORITHMS_ZIPLINKEDLIST_H
#include <vector>
using namespace std;

class ZipLinkedList {
public:
    class LinkedListNode {
    public:
        int value;
        LinkedListNode *next;

        LinkedListNode(int value) {
            this->value = value;
            this->next = nullptr;
        }
    };

    static void processZipList(LinkedListNode *currNode , LinkedListNode *&head, bool  & allLinked) {
        if (currNode == nullptr) return;
        processZipList(currNode->next, head, allLinked);

        if (allLinked) return;

        if (head->next == currNode || head == currNode) allLinked = true;

        LinkedListNode * tmp = head->next;
        head->next= currNode;
        head = tmp;
        currNode->next = tmp;

        if (allLinked) {
            currNode->next = nullptr;
        }
    }

    static LinkedListNode *zip_given_linked_list(LinkedListNode *head) {
        // Write your code here.
        LinkedListNode * startNode = head;
        bool linked = false;
        processZipList(head, startNode, linked);
        return head;
    }

    LinkedListNode *zip_given_linked_list_non_recursive(LinkedListNode *head) {
        vector<int>left, right;
        LinkedListNode *current = head;
        int n = 0;

        while(current){//iterate over the list
            n++;
            current = current->next;
        }
        int index = 0; n+=n%2;
        current = head;
        while(current){
            index++;
            if (index <= n/2){left.push_back(current->value);}
            else{right.push_back(current->value);}
            current = current->next;
        }

        int indxLeft = 0, indxRight = right.size()-1; current = head; bool flag = false;
        while(current){//iterate over the list
            if (!flag) current->value = left[indxLeft++];
            else current->value = right[indxRight--];
            flag = !flag;
            current = current->next;
        }

        return head;
    }
};

#endif //CPPALGORITHMS_ZIPLINKEDLIST_H
