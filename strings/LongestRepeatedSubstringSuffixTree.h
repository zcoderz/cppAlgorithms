//
// Created by USMAN QADIR on 9/24/22.
//

#ifndef CPPALGORITHMS_LONGESTREPEATEDSUBSTRINGSUFFIXTREE_H
#define CPPALGORITHMS_LONGESTREPEATEDSUBSTRINGSUFFIXTREE_H

#include <string>
#include <unordered_map>
using namespace std;

/**
 * Characteristics for performance are :
 *
 * 1 - Coalesce nodes --> a node handles a range from start to end , rather than an individual node for each of sub indexes
 */
class LongestRepeatedSubstringSuffixTree {
    /*
    * Asymptotic complexity in terms of length of `s` `n`:
    * Time: O(n).
    * Auxiliary space: O(n).
    * Total space: O(n).
    */


    int lrsLength =0;
    int lrsSuffixIndex =0;
    string suffixTreeString;
    string ALPHABET = "abcdefghijklmnopqrstuvwxyz\1";

public:

    struct Node {
        int begin;
        int end;
        int depth; // distance in characters from root to this node
        Node *parent;
        unordered_map<int, Node*> children;
        Node * suffixLink;

        Node(int begin, int end, int depth, Node * parent) {
            this->begin = begin;
            this->end = end;
            this->parent = parent;
            this->depth = depth;
        }
    };

    void print(Node * node, int offset) {
        for (int i =0 ; i < offset; i++) {
            cout << " ";
        }
        int index = suffixTreeString.size() - (node->depth + node->end - node->begin);
        int length = node->end - node->begin;
        cout << suffixTreeString.substr(index, length) << " , isLeaf : " << node->children.empty() << " depth " <<
                    node->depth ;
        cout << endl;

        for (auto & iter  : node->children) {
            print(iter.second, offset + 4);
        }
    }

    Node * buildSuffixTree(string suffixTreeString) {
        int n = suffixTreeString.size();
        vector<int> charToAlphabetOffset(n, 0);
        unordered_map<char, int> alphabetOffsetMap;
        for (int i = 0; i < ALPHABET.length(); i++) {
            alphabetOffsetMap[ALPHABET[i]] = i;
        }
        //charToAlphabetOffset contains index of the character in ALPHABET list
        for (int i = 0; i < n; i++) {
            charToAlphabetOffset[i] = alphabetOffsetMap[suffixTreeString[i]];
        }
        Node *root = new Node(0, 0, 0, nullptr);
        Node * activeNode = root;
        for (int textIndex = 0, activeLength = 0; textIndex < n; textIndex++, activeLength++) {
            Node *lastSplitNode = nullptr;
            while (activeLength >= 0) {
                //cout << "at index " << textIndex << " char is " << suffixTreeString[textIndex] <<  " activeLength = " << activeLength << endl;
                //print(root, 0);
                Node *currentChild = activeNode->children[charToAlphabetOffset[textIndex - activeLength]];
                while (currentChild != nullptr && activeLength >= currentChild->end - currentChild->begin) {
                    activeLength -= currentChild->end - currentChild->begin;
                    activeNode = currentChild;
                    currentChild = currentChild->children[charToAlphabetOffset[textIndex - activeLength]];
                }
                if (currentChild == nullptr) {
                    activeNode->children[charToAlphabetOffset[textIndex]] =
                            new Node(textIndex, n, activeNode->depth + activeNode->end - activeNode->begin, activeNode);
                    if (lastSplitNode != nullptr) lastSplitNode->suffixLink = activeNode;
                    lastSplitNode = nullptr;
                } else {
                    int activeEdge = charToAlphabetOffset[currentChild->begin + activeLength];
                    if (activeEdge == charToAlphabetOffset[textIndex]) {
                        ///*Extension Rule 3 (current character being processed is already on the edge)*/
                        if (lastSplitNode != nullptr) {
                            //If a newly created node waiting for its suffix link to be set, then set suffix link
                            //of that waiting node to current active node
                            lastSplitNode->suffixLink = activeNode;
                        }
                        break;
                    } else {
                        Node * splitNode = new Node(currentChild->begin, currentChild->begin + activeLength,
                                                    activeNode->depth + activeNode->end - activeNode->begin, activeNode);
                        splitNode->children[charToAlphabetOffset[textIndex]] = new
                                Node(textIndex, n, currentChild->depth + activeLength, splitNode);
                        splitNode->children[activeEdge] = currentChild;
                        currentChild->begin += activeLength;
                        currentChild->depth += activeLength;
                        currentChild->parent = splitNode;
                        activeNode->children[charToAlphabetOffset[textIndex - activeLength]] = splitNode;
                        if (lastSplitNode != nullptr) lastSplitNode->suffixLink = splitNode;
                        lastSplitNode = splitNode;
                    }
                }
                if (activeNode == root) {
                    --activeLength;
                } else {
                    activeNode = activeNode->suffixLink;
                }
            }
        }
        print(root, 0);
        return root;
    }

    /**
     *  longest repeated substring will end at the internal node which is farthest from the root
     *  (i.e. deepest node in the tree),
     *  because length of substring is the path label length from root to that internal node.
     * @param node
     */
    void findLRS(Node * node) {
        bool isLeaf = true;
        for (const auto& iter : node->children) {
            isLeaf = false;
            findLRS(iter.second);
        }
        // As name suggests, isLeaf will be true at this point, if it has no child

        // If node is a leaf, then suffix string formed by path from root to it's parent node is a repeated substring
        // and a candidate for longest repeated substring
        if (isLeaf) {
            int currLength = node->depth;
            // currLength here denotes path length of node.parent. i.e. node.parent.pathLength == node.depth
            if (currLength > lrsLength) {
                lrsLength = currLength;
                lrsSuffixIndex = suffixTreeString.size() - (node->depth + node->end - node->begin);
                // For a leaf node, suffixIndex(i.e. index of suffix that ends here) is nothing but (
                // (length of given string s) - path length of current node)
            }
        }
    }

    string get_longest_repeated_substring(string s) {
        //adding a unique character $ at the end ensures that all suffixes are at leaf nodes
        suffixTreeString = s + "\1";
        Node * tree = buildSuffixTree(suffixTreeString);
        lrsLength = 0;
        lrsSuffixIndex = -1;
        // findLRS will find the LRS and will populate the results in lrsLength and lrsSuffixIndex
        findLRS(tree);
        string lrs = "";
        if (lrsLength > 0) {
            lrs = suffixTreeString.substr(lrsSuffixIndex, lrsLength);
        }
        return lrs;
    }
};

#endif //CPPALGORITHMS_LONGESTREPEATEDSUBSTRINGSUFFIXTREE_H
