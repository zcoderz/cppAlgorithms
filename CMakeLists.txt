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
        utils/graph/PrimsAlgoForMinSpanningTrees.h graph/CountIslands.h graph/SearchLargestIsland.h graph/CountConnectedComponents.h graph/NumberOfConnectedComponents.h
        graph/IsATree.h graph/CourseDependenciesArvDepTimes.h graph/FriendlyGroups.h graph/FloodFill.h graph/KnightMoves.h graph/StringTransformation.h
        graph/CourseSchedule.h graph/ZombieClusters.h graph/CriticalConnections.h graph/KeysAndDoors.h graph/AlienDictionary.h graph/GraphCopy.h
        utils/GraphNode.h dynamic_programming/DynamicProgramming.h dynamic_programming/DynamicProgramming.cpp dynamic_programming/ClimbingStairs.h
        dynamic_programming/PascalTriangle.h dynamic_programming/UniquePaths.h dynamic_programming/CoinChange.h dynamic_programming/CoinChangeTwo.h
        dynamic_programming/WordBreak.h dynamic_programming/Triangle.h dynamic_programming/PartitionEqualSubset.h dynamic_programming/BurstBaloons.h
        dynamic_programming/MinCostToCutSticks.h dynamic_programming/LongestCommonSubsequence.h dynamic_programming/EditDistance.h dynamic_programming/KnapSack.h
        recursion/Power.h recursion/StringsFromWildChar.h practice/Practice.h practice/Practice.cpp sort/questions/NearestNeighbors.h trees/TreeMirrorImage.h
        trees/BinaryTreeFromPreAndInOrder.h trees/CloneBinaryTree.h trees/LargestBST.h trees/NextRightPointers.h lists/LongestValidParentheses.h lists/MinStack.h
        lists/ZipLinkedList.h lists/LinkedListGroupReverse.h lists/SlidingWindowMax.h lists/LRUCache.h lists/LinkedListAddTwoNumbers.h lists/OddEvenList.h
        lists/MergeSortLinkedList.h lists/ValidateExpression.h lists/CloneRandomLinkedList.h data_structures/SkipList.h lists/InsertionSortList.h
        lists/PartitionList.h lists/ReOrderList.h strings/ZigZagWords.h strings/LongestSubstringWithAtMostKDistinctChars.h strings/ShortestPalindrome.h
        strings/GenerateNumeronyms.h strings/RegularExpressionMatching.h data_structures/GeneralizedSuffixTree.h strings/KMPMatch.h strings/MinWindowSubstring.h
        strings/IndicesOfWordsInTextString.h data_structures/TrieNode.h data_structures/TrieBuilder.h strings/BoggleSolver.h data_structures/graph/UnionFindNode.h
        data_structures/graph/UnionFindAlgo.h data_structures/graph/UnionFindHelper.h data_structures/graph/UnionFindEdge.h data_structures/graph/PrimsAlgorithm.h
        data_structures/graph/DijkstrasShortestPath.h graph/CheapestFlightsWithKStops.h data_structures/graph/EdgeWeightedDigraph.h data_structures/graph/EdgeWeightedDirectedCycle.h
        data_structures/graph/BellmanFordShortestPath.h data_structures/graph/KosarajuStronglyConnected.h data_structures/graph/TarjansStronglyConnected.h graph/OpenLocks.h
        graph/ReconstructItinerary.h graph/NetworkDelayTime.h graph/PathWithMaxProbability.h graph/PathWithMinEffort.h graph/SlidingPuzzle.h graph/WaterAndJugProblem.h
        graph/AllPathsFromSourceToTarget.h graph/UniquePaths.h graph/MinPathSum.h graph/ParallelCourses.h graph/MinNumberOfSemesters.h graph/ParallelCoursesThree.h
        data_structures/graph/JohnsonsAlgorithm.h graph/DominoAndTromino.h dynamic_programming/DungeonGame.h dynamic_programming/UniquePathsTwo.h dynamic_programming/HouseRobber.h
        dynamic_programming/MinCostTickets.h dynamic_programming/MinCostToMergeStones.h dynamic_programming/KnightDialer.h dynamic_programming/IntegerBreak.h
        dynamic_programming/PaintFence.h dynamic_programming/StockBuyAndSellWithCoolDown.h dynamic_programming/BestTimeToBuyAndSellStockThree.h
        dynamic_programming/BestTimeToBuyAndSellStockMultipleTransactions.h dynamic_programming/MaxProductSubarray.h dynamic_programming/MaxConsecutiveOnes.h
        dynamic_programming/WiggleSubsequence.h dynamic_programming/TossStrangeCoins.h dynamic_programming/AsciTwoDeleteSum.h dynamic_programming/LongestIncreasingSubsequence.h
        dynamic_programming/NumberOfTheLongestIncreasingSubsequence.h dynamic_programming/LongestStringChain.h dynamic_programming/MaxLengthPairChain.h
        dynamic_programming/LongestDivisibleSubset.h dynamic_programming/PalindromicSubstring.h dynamic_programming/LongestPalindromicString.h
        dynamic_programming/ShortestWayToFormString.h dynamic_programming/MinPathSum.h dynamic_programming/LongestLineOfConsecutiveOnes.h
        dynamic_programming/ShortestDistanceToTargetColor.h dynamic_programming/LongestIncreasingPathInMatrix.h dynamic_programming/OutOfBoundPaths.h
        dynamic_programming/TwoKeysKeyboard.h dynamic_programming/BombEnemy.h dynamic_programming/UniqueBinarySearchTrees.h dynamic_programming/MinCostTreeFromLeafValues.h
        dynamic_programming/CombinationSum.h dynamic_programming/PerfectSquares.h dynamic_programming/TargetSum.h dynamic_programming/WildcardMatching.h
        dynamic_programming/MountainArray.h dynamic_programming/RegularExpressionDP.h dynamic_programming/PalindromePartition.h dynamic_programming/OptimalCostBinarySearchTree.h
        dynamic_programming/MatrixChainMultiplicationMinCost.h dynamic_programming/RangeSumQuery2D.h dynamic_programming/MaxSumOfRectangleNoLargerThanK.h
        dynamic_programming/LargestRectangleInHistogram.h dynamic_programming/MaximalRectangle.h dynamic_programming/MaxProfitJobScheduling.h dynamic_programming/TextJustificationWithMaxWidth.h dynamic_programming/PrettyTextJustification.h dynamic_programming/BoxStackingLengthWidthReuse.h dynamic_programming/MaxHeightByStackingCuboids.h dynamic_programming/InterleavingString.h dynamic_programming/CountNumberOfOnesInBinaryString.h dynamic_programming/PredictWinner.h dynamic_programming/SuperEggDrop.h dynamic_programming/MaxEventsThatCanBeAttended.h dynamic_programming/CrossingHands.h dynamic_programming/AllocateMailBoxes.h dynamic_programming/DistinctSubsequences.h dynamic_programming/NonoverlappingIntervals.h dynamic_programming/MinNumberOfArrowsToBurstBaloons.h dynamic_programming/LongestPalindromicSubsequenceTwo.h dynamic_programming/LongestRepeatedSubstring.h dynamic_programming/ValidPalindromeThree.h dynamic_programming/MinWindowSubsequence.h dynamic_programming/CherryPick.h dynamic_programming/CherryPickTwo.h dynamic_programming/WordBreakTwo.h dynamic_programming/AndoidUnlockPatterns.h dynamic_programming/KnightProbabilityInChessboard.h dynamic_programming/NumberOfCornerRectangles.h dynamic_programming/FourKeysKeyboard.h dynamic_programming/FindDerangement.h dynamic_programming/WaysToDistributeCandies.h dynamic_programming/SentenceScreenFitting.h dynamic_programming/PalindromeRemoval.h dynamic_programming/CombinationSumTwo.h dynamic_programming/LastStoneWeightTwo.h dynamic_programming/ProfitableSchemes.h dynamic_programming/ShortestCommonSupersequence.h dynamic_programming/StoneGameThree.h dynamic_programming/StoneGameFour.h dynamic_programming/CanIWin.h dynamic_programming/StoneGamesTwo.h dynamic_programming/PartitionToKEqualSumSubsets.h dynamic_programming/CampusBikesTwo.h dynamic_programming/NumberOfWaysForHats.h dynamic_programming/NumbersAtMostNGivenDigitset.h dynamic_programming/NonNegativeIntegersWithoutConsecutiveOnes.h dynamic_programming/DigitCountInRange.h dynamic_programming/BinaryTreeLongestConsecutiveSequence.h dynamic_programming/BinaryTreeLongestConsecutiveSequenceTwo.h dynamic_programming/LargestBSTSubtree.h dynamic_programming/DeleteTreeNodes.h dynamic_programming/MaxVacationDays.h graph/ValidTree.h graph/RedundantConnection.h graph/RedundantDirectedConnection.h graph/RemoveMaxNumberOfEdges.h graph/EarliestFriends.h graph/EquationEquality.h graph/LexicographicallySmallestEquivalent.h graph/SentenceSimilarity.h)
find_package(Boost REQUIRED COMPONENTS system filesystem REQUIRED)

include_directories(${Boost_INCLUDE_DIR})
# Note: a target should be already defined using 'add_executable' or 'add_library'
#target_link_libraries(TargetName ${Boost_LIBRARIES})
