//
// Created by usman on 10/31/21.
//

#include "TreeProblems.h"
#include "BinaryTreeTraversal.h"
#include "LevelOrderTraversal.h"
#include "LevelOrderNArray.h"
#include "DiameterOfABinaryTree.h"
#include "SortedListToBinarySearchTree.h"
#include "AllPathsThatSumToK.h"
#include "RightSideViewOfABinaryTree.h"
#include "BinaryTreeFromPreOrder.h"
#include "SortedArrayToBST.h"
#include "PathsEqualToTarget.h"
#include "BstFromInOrderAndPostOrderTraversal.h"
#include "CountUnivalueSubtrees.h"
#include "LongestUniValPath.h"
#include "IsABST.h"
#include "PrintAllPathsOfTree.h"
#include "UpsideDown.h"
#include "LeastCommonAncestor.h"
#include "BinaryTreeToDoubleLinkedList.h"
#include "MergeBsts.h"
#include "MergeBstsViaVector.h"
#include "FindHeightOfTree.h"
#include "BalancedBstFromSortedArrayTryTwo.h"
#include "KthSmallestFromBst.h"

void TreeProblems::runTreeProblems() {
    vector<int> vec = {-10,-3,0,5,9};
    BalancedBstFromSortedArrayTryTwo balanced;
    TreeNode * root = balanced.build_balanced_bst(vec);
    int j = 1;
}