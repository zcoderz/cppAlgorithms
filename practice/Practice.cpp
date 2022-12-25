//
// Created by usman on 9/14/22.
//

#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
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
#include "../strings/RegularExpressionMatching.h"
#include "../strings/LongestRepeatedSubstring.h"
#include "../strings/LongestRepeatedSubstringSuffixTree.h"
#include "../data_structures/GeneralizedSuffixTree.h"
#include "../strings/KMPMatch.h"
#include "../strings/MinWindowSubstring.h"
#include "../strings/IndicesOfWordsInTextString.h"
#include "../strings/BoggleSolver.h"
#include "../data_structures/graph/UnionFindAlgo.h"
#include "../data_structures/graph/PrimsAlgorithm.h"
#include "../data_structures/graph/DijkstrasShortestPath.h"
#include "../graph/CheapestFlightsWithKStops.h"
#include "../graph/KnightMoves.h"
#include "../graph/OpenLocks.h"
#include "../graph/ReconstructItinerary.h"
#include "../graph/NetworkDelayTime.h"
#include "../graph/PathWithMaxProbability.h"
#include "../graph/PathWithMinEffort.h"
#include "../graph/SlidingPuzzle.h"
#include "../graph/WaterAndJugProblem.h"
#include "../graph/ParallelCourses.h"
#include "../graph/MinNumberOfSemesters.h"
#include "../dynamic_programming/DungeonGame.h"
#include "../dynamic_programming/UniquePathsTwo.h"
#include "../dynamic_programming/HouseRobber.h"
#include "../dynamic_programming/MinCostToMergeStones.h"
#include "../dynamic_programming/MinCostToCutSticks.h"
#include "../dynamic_programming/BurstBaloons.h"
#include "../dynamic_programming/IntegerBreak.h"
#include "../dynamic_programming/StockBuyAndSellWithCoolDown.h"
#include "../dynamic_programming/BestTimeToBuyAndSellStockMultipleTransactions.h"
#include "../dynamic_programming/AsciTwoDeleteSum.h"
#include "../dynamic_programming/LongestIncreasingSubsequence.h"
#include "../dynamic_programming/LongestDivisibleSubset.h"
#include "../dynamic_programming/PalindromicSubstring.h"
#include "../dynamic_programming/LongestPalindromicString.h"
#include "../dynamic_programming/ShortestWayToFormString.h"
#include "../dynamic_programming/LongestLineOfConsecutiveOnes.h"
#include "../dynamic_programming/WordBreak.h"
#include "../dynamic_programming/LongestIncreasingPathInMatrix.h"
#include "../dynamic_programming/OutOfBoundPaths.h"
#include "../dynamic_programming/TwoKeysKeyboard.h"
int TwoKeys::minStepsNo=0;
#include "../dynamic_programming/PerfectSquares.h"
#include "../dynamic_programming/TargetSum.h"
#include "../dynamic_programming/WildcardMatching.h"
#include "../dynamic_programming/MountainArray.h"
#include "../dynamic_programming/RegularExpressionDP.h"
#include "../dynamic_programming/RangeSumQuery2D.h"
#include "../dynamic_programming/MaxSumOfRectangleNoLargerThanK.h"
#include "../dynamic_programming/MaxProfitJobScheduling.h"
#include "../dynamic_programming/TextJustificationWithMaxWidth.h"
#include "../dynamic_programming/PrettyTextJustification.h"
#include "../dynamic_programming/BoxStackingLengthWidthReuse.h"
#include "../dynamic_programming/MaxHeightByStackingCuboids.h"
#include "../dynamic_programming/InterleavingString.h"
#include "../dynamic_programming/CountNumberOfOnesInBinaryString.h"
#include "../dynamic_programming/PredictWinner.h"
#include "../dynamic_programming/SuperEggDrop.h"
#include "../dynamic_programming/MaxEventsThatCanBeAttended.h"
#include "../dynamic_programming/CrossingHands.h"
#include "../dynamic_programming/AllocateMailBoxes.h"
#include "../dynamic_programming/DistinctSubsequences.h"
#include "../dynamic_programming/NonoverlappingIntervals.h"
#include "../dynamic_programming/LongestPalindromicSubsequenceTwo.h"
#include "../dynamic_programming/LongestRepeatedSubstring.h"
#include "../dynamic_programming/ValidPalindromeThree.h"
#include "../dynamic_programming/MinWindowSubsequence.h"
#include "../dynamic_programming/CherryPick.h"
#include "../dynamic_programming/CherryPickTwo.h"
#include "../dynamic_programming/WordBreakTwo.h"
#include "../dynamic_programming/NumberOfCornerRectangles.h"
#include "../dynamic_programming/FourKeysKeyboard.h"
#include "../dynamic_programming/WaysToDistributeCandies.h"
#include "../dynamic_programming/SentenceScreenFitting.h"
#include "../dynamic_programming/PalindromeRemoval.h"
#include "../dynamic_programming/ProfitableSchemes.h"
#include "../dynamic_programming/MinCostTreeFromLeafValues.h"
#include "../dynamic_programming/StoneGameThree.h"
#include "../dynamic_programming/CanIWin.h"
#include "../dynamic_programming/StoneGamesTwo.h"
#include "../dynamic_programming/PartitionToKEqualSumSubsets.h"
#include "../dynamic_programming/CampusBikesTwo.h"
#include "../dynamic_programming/NumberOfWaysForHats.h"
#include "../dynamic_programming/NumbersAtMostNGivenDigitset.h"
#include "../dynamic_programming/NonNegativeIntegersWithoutConsecutiveOnes.h"
#include "../dynamic_programming/DigitCountInRange.h"
#include "../dynamic_programming/DeleteTreeNodes.h"
#include "../dynamic_programming/MaxVacationDays.h"
#include "../graph/SynonymousSentences.h"
#include "../graph/SmallestStringWithSwaps.h"
#include "../graph/EdgeConnectivityWithDistance.h"
#include "../graph/MinHeightTrees.h"
#include "../graph/AlienDictionaryTakeTwo.h"
#include "../graph/LargestColorVarianceInDirectedGraph.h"
void Practice::runPracticeCode() {
    LargestColorVarianceInDirectedGraph::testMe();
    //AlienDictionaryTakeTwo::testMe();
    //MinHeightTrees::testMe();
    //EdgeConnectivityWithDistance::testMe();
    //SmallestStringWithSwaps::testMe();
    //SynonymousSentences::testMe();
    //DungeonGame::testMe();
    //MaxVacationDays::testMe();
    //DeleteTreeNodes::testMe();
    //DigitCountInRange::testMe();
    //NonNegativeIntegers::testMe();
    //NumbersAtMostNGivenDigitSet::testMe();
    //NumberOfWaysForHats::testMe();
    //CampusBikesTwo::testMe();
    //PartitionToKEqualSumSubsets::testMe();
    //StoneGamnesTwo::testMe();
    //CanIWin::testMe();
    //StoneGameThree::testMe();
    //MinCostTreeFromLeaf::testMe();
    //ProfitableSchemes::testMe();
    //PalindromeRemoval::testMe();
    //SentenceScreenFitting::testMe();
    //CountWaysToDistributeCandies::testMe();
    //FourKeysKeyboard::testMe();
    //NumberOfCornerRectangles::testMe();
    //WordBreakTwo::testMe();
    //CherryPickTwo::testMe();
    //CherryPick::testMe();
    //MinWindowSubsequence::testMe();
    //ValidPalindrome::testMe();
    //LongestRepeatedSubstringDP::testMe();
    //LongestPalindromicSubsequenceTwo::testMe();
    //NonOverlappingIntervals::testMe();
    //DistinctSubsequences::testMe();
    //AllocateMailboxes::testMe();
    //CrossingHands::testMe();
    //MaxEventsPossible::testMe();
    //SuperEggDrop::testMe();
    //PredictWinner::testMe();
    //BinaryStringWithoutConsecutiveOnes::testMe();
    //InterleavingString::testMe();
    //MaxHeightByStackingCuboids::testMe();
    //BoxStackingLengthWidthReuse::testMe();
    //PrettyTextJustification::testMe();
    //TextJustificationWithMaxWidth::testMe();
    //MaxProfitJobScheduling::testMe();
    //MaxSumRectangleLessThanK::testMe();
    //NumMatrix::testMe();
    //RegularExpressionDP::testMe();
    //MountainArray::testMe();
    //WildCardMatching::testMe();
    //TargetSum::testMe();
    //PerfectSquares::testMe();
    //TwoKeys::testMe();
    //OutOfBoundPaths::testMe();
    //LongestIncreasingPathInMatrix::testMe();
    //WordBreak::testMe();
    //LongestLineOfConsecutiveOnes::testMe();
    //ShortestWayToFormString::testMe();
    //LongestPalindromicString::testMe();
    //PalindromicSubstring::testMe();
    //LongestDivisibleSubset::testMe();
    //LongestIncreasingSubsequence::testMe();
    //Asci2DeleteSum::testMe();
    //BestTimeBuyAndSellStock::testMe();
    //StockBuyAndSellWithCoolDown::testMe();
    //IntegerBreak::testMe();
    //BurstBaloons::testMe();
    //MinCostToCutSticks::testMe();
    //MinCostToMergeStones::testMe();
    //HouseRobber::testMe();
    //UniquePathsTwo::testMe();
    //DungeonGame::testMe();
    //MinNumberOfSemesters::testMe();
    //ParallelCourses::testMe();
    //WaterAndJugProblem::testMe();
    //SlidingPuzzle::testMe();
    //PathWithMinEffort::testMe();
    //PathWithMaxProbability::testMe();
    //NetworkDelayTime::testMe();
    //ReconstructItinerary::testMe();
    //OpenLocks::testMe();
    //KnightMoves::testMe();
    //CheapestFlightsWithinKStops::testFlights();
    //DijkstraShortestPath::testDijkstrasShortestPathAlgo();
    //UnionFindAlgo::testAlgo();
    //PrimsAlgorithm::testPrimsAlgo();
//    vector<string>  dictionary = {"hell", "lo", "lost", "ht"};
//    vector<string> mat = {"hellost"};
//    vector<string> res = BoggleSolver::boggle_solver(dictionary, mat);
//    std::copy(res.begin(), res.end() , std::ostream_iterator<string>(cout, ", "));

//    vector<vector<int>> res = IndicesOfWordsInTextStrings::find_words("you are very very smart", {"you", "are", "very", "handsome"});
//    for (vector<int> match : res) {
//        std::copy(match.begin(), match.end() , std::ostream_iterator<int>(cout, ", "));
//        cout << endl;
//    }
    //string res = MinWindowSubstring::minimum_window("AYZABOBECODXBANC", "ABC");
    //cout << res << endl;
    //vector<int> res = KMPMatch::match_pattern_in_text("wwwwwwwwwwwwwww","ww");
    //std::copy(res.begin(), res.end() , std::ostream_iterator<int>(cout, ", "));

//    LongestRepeatedSubstringSuffixTree longest;
//    //string res = longest.get_longest_repeated_substring("iabhabi");
//    string res = longest.get_longest_repeated_substring("abab");
//    cout << res << endl;

//    SuffixTree suffixTree;
//    suffixTree.buildSuffixTree("ababcfggghfhggg");
//    cout << suffixTree.getLongestRepeatedSubstring() << endl  << "------------------" << endl;
//    suffixTree.printSuffixTree();

    //suffixTree.printSuffixTree();
//    string res = LongestRepeatedSubstringSuffixTree::get_longest_repeated_substring("xyzxyaxyz$");
//    cout << res << endl;

//    typedef std::vector<char> ctnr;
//    std::set<char> le_set = { 'm', 'i', 's', 't' };
//    SuffixTree<char> stree;
//    //ctnr str = { 'M', 'i', 's', 's', 'i', 's', 's', 'i', 'p', 'i' };
//    //ctnr str2 = { 'M', 'i', 's', 's', 'o', 'u', 'r', 'i' };
//    //ctnr str3 = { 's', 'o', 'u', 'r', 'i', 's' };
//    //ctnr str4 = { 'G', 'o', 'l', 'g', 'o', 't', 'h' };
//    //ctnr str5 = { 'W', 'i', 's', 'i', 'g', 'o', 't', 'h' };
//    //ctnr suffix_test = { 'i', 'p', 'i' };
//    //stree.add_string(str.begin(), str.end());
//    //stree.add_string(str2.begin(), str2.end());
//    //stree.add_string(str3.begin(), str3.end());
//    //stree.add_string(str4.begin(), str4.end());
//    //stree.add_string(str5.begin(), str5.end());
//    //stree.add_string(le_set.rbegin(), le_set.rend());
//    ctnr test1 = { 'G'};
//    stree.add_string(test1.rbegin(), test1.rend());
//    stree.dump_tree();
//    std::cout << std::boolalpha;
    //std::cout << stree.is_suffix(suffix_test.begin(), suffix_test.end()) << std::endl;

//    bool  val = RegularExpressionMatching::isMatch("aa", "a*");
//    cout << val << endl;
//    string word = "nailed";
//    vector<string> res = Numeronyms::generate_all_numeronyms(word);
//    std::ostringstream oss;
//    std::copy(res.begin(), res.end() , std::ostream_iterator<string>(oss, ", "));
//    cout << oss.str() << endl;
    //"efabcdhefhabcdiefi"
//    string res = LongestRepeatedSubstringSuffixTree::get_longest_repeated_substring("eabhabi");
//    cout << res << endl;

//    string res = LongestRepeatedSubstring::get_longest_repeated_substring("efabcdhefhabcdiefi");
//    cout << res << endl;
//    string word = "nailed";
//    vector<string> res = Numeronyms::generate_all_numeronyms(word);
//    std::ostringstream oss;
//    std::copy(res.begin(), res.end() , std::ostream_iterator<string>(oss, ", "));
//    cout << oss.str() << endl;
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