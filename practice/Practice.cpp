//
// Created by usman on 9/14/22.
//

#include <algorithm>
#include <iostream>
#include "Practice.h"
#include "../sort/questions/NearestNeighbors.h"
#include "../bits/FourBillion.h"
#include "../trees/TreeMirrorImage.h"
#include "../trees/BinaryTreeFromPreAndInOrder.h"
#include "../trees/LargestBST.h"
#include "../lists/ZipLinkedList.h"
#include "../lists/LinkedListGroupReverse.h"
#include "../lists/SlidingWindowMax.h"
#include "../lists/LRUCache.h"
#include "../lists/MergeSortLinkedList.h"

void Practice::runPracticeCode() {

    MergeSortLinkedList::ListNode node1(7);
    MergeSortLinkedList::ListNode node2(1); node1.next = &node2;
    MergeSortLinkedList::ListNode node3(5); node2.next = &node3;
    MergeSortLinkedList::ListNode node4(3); node3.next = &node4;

    auto  sortedList = MergeSortLinkedList::sortList(&node1);
    int j = 2;
//    LRUCache cache(1);
//    cache.put(2,1);
//    cache.get(2);
//    cache.put(3,2);
//    cache.get(2);
//    cache.get(3);

//    vector<int> data = {-7,-8,7,5,7,1,6,0};
//    vector<int> res = SlidingWindowMax::maxSlidingWindow(data, 4);
//    int j = 1;
//    auto * head1 = new LinkedListGroupReverse::ListNode (1);
//    auto * head2 = new LinkedListGroupReverse::ListNode (2); head1->next = head2;
//    auto * head3 = new LinkedListGroupReverse::ListNode (3); head2->next = head3;
//    auto * head4 = new LinkedListGroupReverse::ListNode (4); head3->next = head4;
//    auto * head5 = new LinkedListGroupReverse::ListNode (5); head4->next = head5;
//    auto * head6 = new LinkedListGroupReverse::ListNode (6); head5->next = head6;
//    auto * head7 = new LinkedListGroupReverse::ListNode (7); head6->next = head7;
//
//    LinkedListGroupReverse::ListNode * zipped = LinkedListGroupReverse::reverseKGroup(head1, 3);
//    int j = 1;

//    vector<int> inorder =  {3, 2, 1,5,4,6};
//    vector<int> preorder =  {1, 2, 3,4,5,6};
//    BinaryTreeTest::BinaryTreeNode  * bst = BinaryTreeTest::construct_binary_tree(inorder, preorder);
//    int j = 1;

//    NearestNeighbors nearest;
//    vector<vector<int>> n_points {{89,6},{-39,-4},{-13,91},{97,-61},{1,7},{-66,69},{-51,68},{82,-6},{-21,44},{-58,-83},{-40,73},{-88,-24}};
//    vector<vector<int>> theP = nearest.nearest_neighbours(0, 0, 3, n_points);
//    for (vector<int> v : theP) {
//        for (int i : v) {
//            cout << i << ",";
//        }
//        cout << endl;
//    }
}