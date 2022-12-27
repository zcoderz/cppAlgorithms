//
// Created by usman on 12/25/22.
//

#ifndef CPPALGORITHMS_GROUPDEPENDENCIES_H
#define CPPALGORITHMS_GROUPDEPENDENCIES_H

#include <vector>
#include <iostream>
#include <iterator>
using namespace std;


/**
 * Got this solution from leetcode
 * https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/solutions/402401/python-use-topologically-sorted-items-and-groups-to-get-the-desired-order/
 * Very elegant approach to this problem.
 */
class GroupDependencies {
public:

    /**
     * Simplified top sort based on in-degree (num dependencies)
     * @param itemDependencies
     * @param itemInDegree
     * @return
     */
    vector<int> getTopoOrder(vector<vector<int>> & itemDependencies, vector<int> & itemInDegree)  {
        vector<int> leaves;
        vector<int> res;
        for (int i =0; i < itemInDegree.size(); i++) {
            if (itemInDegree[i]==0) leaves.push_back(i);
        }
        while (!leaves.empty()) {
            vector<int> newLeaves;
            for (int leaf : leaves) {
                res.push_back(leaf);
                for (int item : itemDependencies[leaf]) {
                    if (--itemInDegree[item]==0) newLeaves.push_back(item);
                }
            }
            swap (leaves, newLeaves);
        }
        if (res.size()==itemInDegree.size()) return res;
        return {};
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        //give each no group item a unique group so that items without a group can be treated
        //similar to items with groups
        for (int i =0; i < n; i++) {
            if (group[i]==-1) group[i] =m++;
        }
        vector<vector<int>> itemDependencies(n);
        vector<vector<int>> groupDependencies(m);
        //in-degree means number of items a node depends on
        vector<int> itemInDegree(n);
        vector<int> groupInDegree(m);
        //invert relations for dependency based on the order in which items can be finished
        //thus you can toposort based on 0 in-degree
        for (int i =0; i < beforeItems.size(); i++) {
            int itemGroup = group[i];
            for (int dep: beforeItems[i]) {
                itemDependencies[dep].push_back(i);
                int depGroup = group[dep];
                if (depGroup != itemGroup) {
                    groupDependencies[depGroup].push_back(itemGroup);
                    groupInDegree[itemGroup]++;
                }
                itemInDegree[i]++;
            }
        }
        vector<int> itemOrder = getTopoOrder(itemDependencies, itemInDegree);
        vector<int> groupOrder = getTopoOrder(groupDependencies, groupInDegree);
        if (itemOrder.empty() || groupOrder.empty()) return {};
        //add items to relevant groups based on their individual order
        vector<vector<int>> groupItems(m);
        for (int item : itemOrder) {
            groupItems[group[item]].push_back(item);
        }
        //work through groups based on group order while utilizing ordered items within groups
        vector<int> res;
        for (int groupNo: groupOrder) {
            res.insert(res.end(), groupItems[groupNo].begin(), groupItems[groupNo].end());
        }
        return res;
    }

    static void testMe() {
        GroupDependencies dep;
        vector<int> groups = {-1,-1,1,0,0,1,0,-1};
        vector<vector<int>> bItems = {{},{6},{5},{6},{3,6},{},{},{}};
        vector<int> results = dep.sortItems(8, 2, groups, bItems);
        std::copy(results.begin(), results.end() , std::ostream_iterator<int>(cout, ", "));
    }
};

#endif //CPPALGORITHMS_GROUPDEPENDENCIES_H
