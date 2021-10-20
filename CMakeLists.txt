cmake_minimum_required(VERSION 3.20)
project(cppAlgorithms)
set(Boost_INCLUDE_DIR /home/usman/boost/boost_1_77_0)
set(Boost_LIBRARY_DIR /home/usman/boost/boost_1_77_0/stage/lib)

set(CMAKE_CXX_STANDARD 14)
#find_package(Threads REQUIRED)
#target_link_libraries(${PROJECT_NAME} Threads::Threads)
SET( CMAKE_CXX_FLAGS  " -pthread")

add_executable(kick_start main.cpp sort/SelectionSort.h sort/SortChecks.cpp sort/SortChecks.h sort/BubbleSort.h sort/InsertionSort.h sort/MergeSort.h sort/QuickSort.h sort/ThreeWayQuickSort.h sort/FourWayQuickSort.h sort/MergeSortBottomUp.h priorityqueue/PriorityQueue.h priorityqueue/PriorityQueueTest.h priorityqueue/PriorityQueueTest.cpp sort/questions/GroupNumbers.h sort/questions/MergeVectors.h sort/questions/DutchNationalFlag.h sort/questions/TwoSum.h sort/questions/TwoSumNonSorted.h sort/questions/MergeSortedSinglyLinkedLists.h sort/questions/AttendMeetings.h sort/questions/TopKFrequent.h sort/questions/KthLargestInStream.h sort/questions/KthLargestInAnArray.h sort/questions/OnlineMedian.h sort/questions/IntersectionOfThreeSortedArrays.h operatorchecks/OperatorChecks.h)

find_package(Boost REQUIRED COMPONENTS system filesystem REQUIRED)

include_directories(${Boost_INCLUDE_DIR})
# Note: a target should be already defined using 'add_executable' or 'add_library'
#target_link_libraries(TargetName ${Boost_LIBRARIES})
