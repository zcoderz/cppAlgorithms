cmake_minimum_required(VERSION 3.23)
project(cppAlgorithms)
set(Boost_INCLUDE_DIR /home/usman/boost/boost_1_77_0)
set(Boost_LIBRARY_DIR /home/usman/boost/boost_1_77_0/stage/lib)

set(CMAKE_CXX_STANDARD 23)
#find_package(Threads REQUIRED)
#target_link_libraries(${PROJECT_NAME} Threads::Threads)
SET( CMAKE_CXX_FLAGS  " -pthread")

add_executable(kick_start main.cpp sort/SelectionSort.h sort/SortChecks.cpp sort/SortChecks.h sort/BubbleSort.h
        sort/InsertionSort.h sort/MergeSort.h sort/QuickSort.h sort/ThreeWayQuickSort.h sort/FourWayQuickSort.h
        sort/MergeSortBottomUp.h priorityqueue/PriorityQueue.h priorityqueue/PriorityQueueTest.h priorityqueue/PriorityQueueTest.cpp
        sort/questions/GroupNumbers.h sort/questions/MergeVectors.h sort/questions/DutchNationalFlag.h sort/questions/TwoSum.h
        sort/questions/TwoSumNonSorted.h sort/questions/MergeSortedSinglyLinkedLists.h sort/questions/AttendMeetings.h
        sort/questions/TopKFrequent.h sort/questions/KthLargestInStream.h sort/questions/KthLargestInAnArray.h
        sort/questions/OnlineMedian.h sort/questions/IntersectionOfThreeSortedArrays.h operatorchecks/OperatorChecks.h sort/questions/ThreeSum.h
        sort/questions/FourSum.h sort/questions/SortColors.h sort/questions/SortAllCharacters.h bits/FourBillion.h bits/BitsTests.h bits/BitTests.cpp
        sort/questions/NearestNeighbors.h recursion/RecursionProblems.h recursion/RecursionProblems.cpp recursion/RunPermutations.h
        recursion/LetterCasePermutations.h recursion/NChooseK.h recursion/PermuteWithDuplicates.h recursion/GetWordsFromPhoneNumber.h
        recursion/AllCombinationsWithSumQualToTarget.h recursion/CombinationSum.h recursion/SubSetsWithDuplicates.h recursion/PalindromePartitioning.h
        recursion/Parenthesis.h recursion/PascalTriangle.h recursion/TowersOfHanoi.h recursion/BSTWithNodes.h recursion/NQueens.h recursion/SolveSudoku.h
        recursion/GenerateAllExpressions.h trees/TreeProblems.h trees/TreeProblems.cpp utils/TreeNode.h trees/BinaryTreeTraversal.h
        trees/LevelOrderTraversal.h utils/TreeNodeNArray.h trees/LevelOrderNArray.h trees/DiameterOfABinaryTree.h trees/SortedListToBinarySearchTree.h
        utils/SinglyListNode.h trees/AllPathsThatSumToK.h trees/RightSideViewOfABinaryTree.h trees/BinaryTreeFromPreOrder.h trees/SortedArrayToBST.h
        trees/PathsEqualToTarget.h trees/BstFromInOrderAndPostOrderTraversal.h trees/CountUnivalueSubtrees.h trees/LongestUniValPath.h
        trees/MaxPathSum.h trees/IsABST.h trees/PrintAllPathsOfTree.h trees/UpsideDown.h trees/LeastCommonAncestor.h utils/Node.h
        trees/PostOrderWithoutRecursion.h trees/BinaryTreeToDoubleLinkedList.h trees/MergeBsts.h trees/MergeBstsViaVector.h recursion/SumEqualToTarget.h
        recursion/FindAllWellFormedBrackets.h trees/FindHeightOfTree.h trees/BalancedBstFromSortedArrayTryTwo.h trees/KthSmallestFromBst.h
        utils/TrieNode.h trie/WordSearch.h trie/TrieProblems.cpp trie/TrieProblems.h misc/MiscQuestions.h misc/Ipv6Compress.h misc/MiscQuestions.cpp
        utils/graph/Edge.h utils/graph/Vertex.h utils/graph/UnionFind.h graph/GraphProblems.h graph/GraphProblems.cpp utils/graph/UnionFindNode.h
        utils/graph/PrimsAlgoForMinSpanningTrees.h graph/CountIslands.h graph/SearchLargestIsland.h graph/CountConnectedComponents.h graph/NumberOfConnectedComponents.h graph/IsATree.h graph/CourseDependenciesArvDepTimes.h graph/FriendlyGroups.h graph/FloodFill.h graph/KnightMoves.h graph/StringTransformation.h graph/CourseSchedule.h graph/ZombieClusters.h graph/CriticalConnections.h graph/KeysAndDoors.h graph/AlienDictionary.h graph/GraphCopy.h utils/GraphNode.h dynamic_programming/DynamicProgramming.h dynamic_programming/DynamicProgramming.cpp dynamic_programming/ClimbingStairs.h dynamic_programming/PascalTriangle.h dynamic_programming/UniquePaths.h dynamic_programming/CoinChange.h dynamic_programming/CoinChangeTwo.h dynamic_programming/WordBreak.h dynamic_programming/Triangle.h dynamic_programming/PartitionEqualSubset.h dynamic_programming/BurstBaloons.h dynamic_programming/MinCostToCutSticks.h dynamic_programming/LongestCommonSubsequence.h dynamic_programming/EditDistance.h dynamic_programming/KnapSack.h recursion/Power.h recursion/StringsFromWildChar.h practice/Practice.h practice/Practice.cpp sort/questions/NearestNeighbors.h trees/TreeMirrorImage.h trees/BinaryTreeFromPreAndInOrder.h trees/CloneBinaryTree.h trees/LargestBST.h trees/NextRightPointers.h lists/LongestValidParentheses.h lists/MinStack.h lists/ZipLinkedList.h lists/LinkedListGroupReverse.h lists/SlidingWindowMax.h lists/LRUCache.h lists/LinkedListAddTwoNumbers.h lists/OddEvenList.h lists/MergeSortLinkedList.h lists/ValidateExpression.h lists/CloneRandomLinkedList.h data_structures/SkipList.h lists/InsertionSortList.h lists/PartitionList.h lists/ReOrderList.h strings/ZigZagWords.h strings/LongestSubstringWithAtMostKDistinctChars.h strings/ShortestPalindrome.h strings/GenerateNumeronyms.h strings/RegularExpressionMatching.h data_structures/GeneralizedSuffixTree.h strings/KMPMatch.h strings/MinWindowSubstring.h strings/IndicesOfWordsInTextString.h data_structures/TrieNode.h data_structures/TrieBuilder.h strings/BoggleSolver.h data_structures/graph/UnionFindNode.h data_structures/graph/UnionFindAlgo.h data_structures/graph/UnionFindHelper.h data_structures/graph/UnionFindEdge.h data_structures/graph/PrimsAlgorithm.h data_structures/graph/DijkstrasShortestPath.h graph/CheapestFlightsWithKStops.h data_structures/graph/EdgeWeightedDigraph.h data_structures/graph/EdgeWeightedDirectedCycle.h data_structures/graph/BellmanFordShortestPath.h data_structures/graph/KosarajuStronglyConnected.h)
find_package(Boost REQUIRED COMPONENTS system filesystem REQUIRED)

include_directories(${Boost_INCLUDE_DIR})
# Note: a target should be already defined using 'add_executable' or 'add_library'
#target_link_libraries(TargetName ${Boost_LIBRARIES})
