cmake_minimum_required(VERSION 3.20)
project(cppAlgorithms)
set(Boost_INCLUDE_DIR /home/usman/boost/boost_1_77_0)
set(Boost_LIBRARY_DIR /home/usman/boost/boost_1_77_0/stage/lib)

set(CMAKE_CXX_STANDARD 14)
#find_package(Threads REQUIRED)
#target_link_libraries(${PROJECT_NAME} Threads::Threads)
SET( CMAKE_CXX_FLAGS  " -pthread")

add_executable(kick_start main.cpp sort/SelectionSort.h sort/SortChecks.cpp sort/SortChecks.h sort/BubbleSort.h sort/InsertionSort.h sort/MergeSort.h sort/QuickSort.h sort/ThreeWayQuickSort.h sort/FourWayQuickSort.h sort/MergeSortBottomUp.h priorityqueue/PriorityQueue.h priorityqueue/PriorityQueueTest.h priorityqueue/PriorityQueueTest.cpp sort/questions/GroupNumbers.h sort/questions/MergeVectors.h sort/questions/DutchNationalFlag.h sort/questions/TwoSum.h sort/questions/TwoSumNonSorted.h sort/questions/MergeSortedSinglyLinkedLists.h sort/questions/AttendMeetings.h sort/questions/TopKFrequent.h sort/questions/KthLargestInStream.h sort/questions/KthLargestInAnArray.h sort/questions/OnlineMedian.h sort/questions/IntersectionOfThreeSortedArrays.h operatorchecks/OperatorChecks.h sort/questions/ThreeSum.h sort/questions/FourSum.h sort/questions/SortColors.h sort/questions/SortAllCharacters.h bits/FourBillion.h bits/BitsTests.h bits/BitTests.cpp sort/questions/NearrestNeighbors.h recursion/RecursionProblems.h recursion/RecursionProblems.cpp recursion/RunPermutations.h recursion/LetterCasePermutations.h recursion/NChooseK.h recursion/PermuteWithDuplicates.h recursion/GetWordsFromPhoneNumber.h recursion/AllCombinationsWithSumQualToTarget.h recursion/CombinationSum.h recursion/SubSetsWithDuplicates.h recursion/PalindromePartitioning.h recursion/Parenthesis.h recursion/PascalTriangle.h recursion/TowersOfHanoi.h recursion/BSTWithNodes.h recursion/NQueens.h recursion/SolveSudoku.h recursion/GenerateAllExpressions.h trees/TreeProblems.h trees/TreeProblems.cpp utils/TreeNode.h trees/BinaryTreeTraversal.h trees/LevelOrderTraversal.h utils/TreeNodeNArray.h trees/LevelOrderNArray.h trees/DiameterOfABinaryTree.h trees/SortedListToBinarySearchTree.h utils/SinglyListNode.h trees/AllPathsThatSumToK.h trees/RightSideViewOfABinaryTree.h trees/BinaryTreeFromPreOrder.h trees/SortedArrayToBST.h trees/PathsEqualToTarget.h trees/BstFromInOrderAndPostOrderTraversal.h trees/CountUnivalueSubtrees.h trees/LongestUniValPath.h trees/MaxPathSum.h trees/IsABST.h)

find_package(Boost REQUIRED COMPONENTS system filesystem REQUIRED)

include_directories(${Boost_INCLUDE_DIR})
# Note: a target should be already defined using 'add_executable' or 'add_library'
#target_link_libraries(TargetName ${Boost_LIBRARIES})
