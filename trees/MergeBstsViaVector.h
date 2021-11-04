//
// Created by usman on 11/4/21.
//

#ifndef CPPALGORITHMS_MERGEBSTSVIAVECTOR_H
#define CPPALGORITHMS_MERGEBSTSVIAVECTOR_H

#include "../utils/TreeNode.h"

using namespace std;

class MergeBstsViaVector {
public:

    /**
    * in order traversal of the tree while adding its nodes into a vector
    * @param node
    * @param vec
    */
    void convertBstToVector(TreeNode * node, vector<TreeNode*> & vec) {
        if (node == nullptr) return;
        convertBstToVector(node->left_ptr, vec);
        vec.push_back(node);
        convertBstToVector(node->right_ptr, vec);
    }

    void mergeVectors(vector<TreeNode*> & vec1, vector<TreeNode*> & vec2,vector<TreeNode*> & vec3) {
        vec3.reserve(vec1.size() + vec2.size());
        int iVec1=0;
        int iVec2=0;
        while (iVec1 != vec1.size() && iVec2 != vec2.size()) {
            if (vec1[iVec1]->label < vec2[iVec2]->label) {
                vec3.push_back(vec1[iVec1++]);
            } else {
                vec3.push_back(vec2[iVec2++]);
            }
        }
        if (iVec1 < vec1.size()) {
            copy(vec1.begin() + iVec1, vec1.end(), back_inserter(vec3));
        } else {
            copy(vec2.begin() + iVec2, vec2.end(), back_inserter(vec3));
        }
    }

    TreeNode * convertVecToBst(vector<TreeNode*> & vec, int left, int right) {
        if (left > right) return nullptr;
        int mid = left + (right-left)/2;
        TreeNode * leftT = convertVecToBst(vec, left, mid-1);
        TreeNode * rightT = convertVecToBst(vec, mid+1, right);
        TreeNode * node = vec[mid];
        node->left_ptr = leftT;
        node->right_ptr = rightT;
        return node;
    }

    TreeNode * merge_two_BSTs(TreeNode *root1, TreeNode *root2) {
        vector<TreeNode *> vec1;
        vector<TreeNode *> vec2;
        convertBstToVector(root1, vec1);
        convertBstToVector(root2, vec2);
        vector<TreeNode *> vec3;
        mergeVectors(vec1, vec2, vec3);
        return convertVecToBst(vec3, 0, vec3.size()-1);
    }
};

#endif //CPPALGORITHMS_MERGEBSTSVIAVECTOR_H
