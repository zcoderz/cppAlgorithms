//
// Created by USMAN QADIR on 9/24/22.
//

#ifndef CPPALGORITHMS_LONGESTREPEATEDSUBSTRINGSUFFIXTREE_H
#define CPPALGORITHMS_LONGESTREPEATEDSUBSTRINGSUFFIXTREE_H

#include <string>
#include <unordered_map>
using namespace std;
class LongestRepeatedSubstringSuffixTree {
    /*
    * Asymptotic complexity in terms of length of `s` `n`:
    * Time: O(n).
    * Auxiliary space: O(n).
    * Total space: O(n).
    */



public:
    static const string ALPHABET;

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

   static Node * buildSuffixTree(string suffixTreeString) {
        int n = suffixTreeString.size();
        vector<int> a(n, 0);
        unordered_map<char, int> map;
        for (int i = 0; i < ALPHABET.length(); i++) {
            map[suffixTreeString[i]] = i;
        }
        // Converting CharSequence s to byte array a, using index of that char in universal string ALPHABET
        for (int i = 0; i < n; i++) a[i] = map[suffixTreeString[i]];
        Node *root = new Node(0, 0, 0, nullptr);
        Node * node = root;
        for (int i = 0, tail = 0; i < n; i++, tail++) {
            Node *last = nullptr;
            while (tail >= 0) {
                Node *ch = node->children[a[i - tail]];
                while (ch != nullptr && tail >= ch->end - ch->begin) {
                    tail -= ch->end - ch->begin;
                    node = ch;
                    ch = ch->children[a[i - tail]];
                }
                if (ch == nullptr) {
                    node->children[a[i]] = new Node(i, n, node->depth + node->end - node->begin, node);
                    if (last != nullptr) last->suffixLink = node;
                    last = nullptr;
                } else {
                    int t = a[ch->begin + tail];
                    if (t == a[i]) {
                        if (last != nullptr) last->suffixLink = node;
                        break;
                    } else {
                        Node * splitNode = new Node(ch->begin, ch->begin + tail,
                                                  node->depth + node->end - node->begin, node);
                        splitNode->children[a[i]] = new Node(i, n, ch->depth + tail, splitNode);
                        splitNode->children[t] = ch;
                        ch->begin += tail;
                        ch->depth += tail;
                        ch->parent = splitNode;
                        node->children[a[i - tail]] = splitNode;
                        if (last != nullptr) last->suffixLink = splitNode;
                        last = splitNode;
                    }
                }
                if (node == root) {
                    --tail;
                } else {
                    node = node->suffixLink;
                }
            }
        }
        return root;
    }

    static int lrsLength;
    static int lrsSuffixIndex;
    static string suffixTreeString;

    static void findLRS(Node * node) {
        bool isLeaf = true;
        for (const auto& iter : node->children) {
            isLeaf = false;
            findLRS(iter.second);
        }
        // As name suggests, isLeaf will be true at this point, if it has no child

        // If node is a leaf, then suffix string formed by path from root to it's parent node is a
        // repeated substring
        // and a candidate for longest repeated substring
        if (isLeaf) {
            int currLength = node->depth;
            // currLength here denotes path length of node.parent. i.e. node.parent.pathLength == node.depth
            if (currLength > lrsLength) {
                lrsLength = currLength;
                lrsSuffixIndex = suffixTreeString.size() - (node->depth + node->end - node->begin);
                // For a leaf node, suffixIndex(i.e. index of suffix that ends here) is nothing but (
                // (length of given
                // string s) - path length of current node)
            }
        }
    }

    static string get_longest_repeated_substring(string s) {
        // Adding a special character('\1' here) in the end of string to make it explicit suffix tree.
        // In explicit suffix tree, all the suffixes ends at a leaf
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
