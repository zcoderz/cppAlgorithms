//
// Created by usman on 9/16/22.
//

#ifndef CPPALGORITHMS_BINARYTREEFROMPREANDINORDER_H
#define CPPALGORITHMS_BINARYTREEFROMPREANDINORDER_H

#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class BinaryTreeTest {
public:
    class BinaryTreeNode {
    public:
        int value;
        BinaryTreeNode *left;
        BinaryTreeNode *right;

        BinaryTreeNode(int value) {
            this->value = value;
            this->left = nullptr;
            this->right = nullptr;
        }
    };

    static BinaryTreeNode * processTree(int left, int right, vector<int> &inorder, vector<int> &preorder, int & index, unordered_map<int, int> & map) {
        //this check is critical, indicates that the data is not within bounds
        if (right < left) return nullptr;
        int val = preorder[index];
        auto mapV = map.find(val);
        index++;
        int inOrderIndex = mapV->second;

        BinaryTreeNode * node = new BinaryTreeNode(val);
        BinaryTreeNode * leftNode =  processTree(left, inOrderIndex - 1, inorder, preorder, index, map);
        node->left = leftNode;

        BinaryTreeNode * rightNode =  processTree(inOrderIndex+1, right, inorder, preorder, index, map);
        node->right = rightNode;

        return node;
    }

    static BinaryTreeNode * construct_binary_tree(vector<int> &inorder, vector<int> &preorder) {
        unordered_map<int, int> map;
        for (int i =0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }
        int index=0;
        return processTree(0, inorder.size()-1, inorder, preorder,  index, map);
    }
};

#endif //CPPALGORITHMS_BINARYTREEFROMPREANDINORDER_H
