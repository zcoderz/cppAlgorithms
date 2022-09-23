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
#include "../lists/ValidateExpression.h"
#include "../lists/CloneRandomLinkedList.h"
#include "../lists/PartitionList.h"
#include "../lists/ReOrderList.h"
#include "../data_structures/SkipList.h"
#include "../strings/ZigZagWords.h"
#include "../strings/LongestSubstringWithAtMostKDistinctChars.h"
#include "../strings/ShortestPalindrome.h"
#include "../strings/GenerateNumeronyms.h"

void Practice::runPracticeCode() {

    string word = "nailed";
    vector<string> res = Numeronyms::generate_all_numeronyms(word);
    std::ostringstream oss;
    std::copy(res.begin(), res.end() , std::ostream_iterator<string>(oss, ", "));
    cout << oss.str() << endl;
    //string res = ShortestPalindrome::shortestPalindromeKPM("aacecaaa");
    //string res = ShortestPalindrome::shortestPalindrome("adcaee");
    //cout << res << endl;
    //int sz = LongestSubstrWithDistinct::lengthOfLongestSubstringKDistinct("eceba", 2);
    //cout << sz << endl;
    //string res = ZigZagWords::convertTwo("PAYPAYISHIRING", 4);
    //cout << res << endl;
//    ReorderList::ListNode node1(1);
//    ReorderList::ListNode node2(2); node1.next = &node2;
//    ReorderList::ListNode node3(3); node2.next = &node3;
//    ReorderList::ListNode node4(4); node3.next = &node4;
//    ReorderList::reorderList(&node1);
//    int j = 1;

//    PartitionList::ListNode node1(1);
//    PartitionList::ListNode node4(4); node1.next = &node4;
//    PartitionList::ListNode node3(3); node4.next = &node3;
//    PartitionList::ListNode node2(2); node3.next = &node2;
//    PartitionList::ListNode node5(5); node2.next = &node5;
//    PartitionList::ListNode node2a(2); node5.next = &node2a;
//    auto * temp = PartitionList::partition(&node1, 3);

//    SkipList<int> skipList;
//    skipList.insert_element(1);
//    skipList.insert_element(100);
//    skipList.insert_element(1000);
//    skipList.insert_element(770);
//    skipList.insert_element(10);
//
//    bool contains = skipList.contains(10);
//    cout << "element 10 is " << contains << endl;
//    cout << "-----------------------" << endl;
//    skipList.display();
//    cout << "-----------------------" << endl;
//    skipList.delete_element(1);
//    skipList.display();


//     auto * node7 = new CloneRandomLinkedList::Node(7);
//     auto * node13 = new CloneRandomLinkedList::Node(13); node7->next = node13; node13->random = node7;
//     auto * node11 = new CloneRandomLinkedList::Node(11); node13->next = node11;
//     auto * node10 = new CloneRandomLinkedList::Node(10); node11->next = node10; node10->random = node11;
//     auto * node1 = new CloneRandomLinkedList::Node(1);   node10->next = node1; node11->random = node1; node1->random = node7;
//
//    auto * newNodes = CloneRandomLinkedList::copyRandomList(node7);
//    int j = 1;
    //string exp = "{2+1+(3+4)}";
//    string exp = "{(1+2)*3}+4";
//    bool res = ValidateExpression::is_valid(exp);
//    cout << res << endl;
//    MergeSortLinkedList::ListNode node1(7);
//    MergeSortLinkedList::ListNode node2(1); node1.next = &node2;
//    MergeSortLinkedList::ListNode node3(5); node2.next = &node3;
//    MergeSortLinkedList::ListNode node4(3); node3.next = &node4;
//
//    auto  sortedList = MergeSortLinkedList::sortList(&node1);
//    int j = 2;
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