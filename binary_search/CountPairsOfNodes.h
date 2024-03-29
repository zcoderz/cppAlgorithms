//
// Created by usman on 1/26/23.
//

#ifndef CPPALGORITHMS_COUNTPAIRSOFNODES_H
#define CPPALGORITHMS_COUNTPAIRSOFNODES_H

#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class CountPairOfNodes {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> degreeVec(n+1);
        typedef pair<int, int> ThePair;
        map<ThePair, int> sharedMap;
        //calculate in degrees and shared degree between vertices
        for (auto & vec: edges) {
            degreeVec[vec[0]]++;
            degreeVec[vec[1]]++;
            ThePair p = make_pair(min(vec[0], vec[1]), max(vec[0], vec[1]));
            sharedMap[p]++;
        }
        //store the original vertex degree
        vector<int> degreeVecOrig = degreeVec;
        //sort the vertices by degree so that we can find the vertex
        //count with desired total edges via left and right pointers
        sort(degreeVec.begin(), degreeVec.end());
        vector<int> res;
        for (int query : queries) {
            int ans=0;
            //vertices in question start from 1
            int l=1, r=n;
            while (l <r) {
                //number of vertices with count greater than that of query = r-l since r and l are vertex indices
                //we are not concerned about the vertex numbers here, just the count.
                if (degreeVec[l]+degreeVec[r] > query) {
                    ans += (r-l); r--;
                } else {
                    l++;
                }
            }
            //the question asks for edges between nodes, and we used indegree to denote edges and hence double counted
            //for example for a single edge between vertex 1 and 2. the indegree for vertex 1 will be 1 and that of vertex 2 will be 1
            //so that total indegree between the two vertices will be 2 but the right ansfer for number of edges is 1.
            //so we need to subtract out the shared edges between the vertices
            for (auto & elem : sharedMap) {
                //if the vertex pair qualified in the query using in degree but if take the
                //shared count out and the pair of vertices no longer qualifies then this pair should not have been
                //included and hence needs to be removed from the answer
                if ( (degreeVecOrig[elem.first.first] + degreeVecOrig[elem.first.second] > query) &&
                     (degreeVecOrig[elem.first.first] + degreeVecOrig[elem.first.second] - elem.second <= query)) {
                    ans--;
                }
            }
            res.push_back(ans);
        }
        return res;
    }
};

#endif //CPPALGORITHMS_COUNTPAIRSOFNODES_H
