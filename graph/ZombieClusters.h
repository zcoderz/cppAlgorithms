//
// Created by usman on 11/13/21.
//

#ifndef CPPALGORITHMS_ZOMBIECLUSTERS_H
#define CPPALGORITHMS_ZOMBIECLUSTERS_H

class ZombieClusters {
public:

    void runDfs(int zombieNum, vector<string> & zombies, vector<int>&  zombieMarker) {
        //if (zombieMarker[zombieNum] != -1) return; dont need this since checking in the caller
        zombieMarker[zombieNum]=1;
        string & str = zombies[zombieNum];
        for (int i =0; i < str.size(); i++) {
            if (i != zombieNum && str[i]=='1' && zombieMarker[i] ==-1) {
                runDfs(i, zombies, zombieMarker);
            }
        }
    }

    int zombieCluster(vector<string> & zombies) {
        int num = zombies.size();
        vector<int> zombieMarker(num, -1);
        int count = 0;
        for (int i =0; i < num; i++) {
            if (zombieMarker[i] == -1) {
                runDfs(i, zombies, zombieMarker);
                //each dfs will unify the connected zombies into a group
                //hence number of dfs calls will return number of connected components
                count++;
            }
        }
        return count;
    }

    vector<pair<int, int>> vertices;

    int find(int vertexId) {
        if (vertices[vertexId].first != vertexId) {
            int parent = find(vertices[vertexId].first);
            vertices[vertexId].first = parent;
        }
        return vertices[vertexId].first;
    }

    void runUnion(int vertexId1, int vertexId2) {
        vertexId1 = find(vertexId1);
        vertexId2 = find(vertexId2);

        if (vertices[vertexId1].second == vertices[vertexId2].second) {
            vertices[vertexId1].second++;
            vertices[vertexId2].first = vertexId1;
        } else if (vertices[vertexId1].second > vertices[vertexId2].second) {
            vertices[vertexId2].first = vertexId1;
        } else {
            vertices[vertexId1].first = vertexId2;
        }
    }

    int number_of_connected_components(int n, vector<vector<int>> & edgesP) {
        vertices.resize(n);
        for (int i =0; i < n; i++) {
            vertices[i] = make_pair(i, 0);
        }
        int numConnectedComponents = n;
        for (vector<int> & edge : edgesP) {
            int p1 = find(edge[0]);
            int p2 = find(edge[1]);
            if (p1 != p2) {
                runUnion(edge[0], edge[1]);
                numConnectedComponents--;
            }
        }
        return numConnectedComponents;
    }

    int zombieClusterUnionFind(vector<string> zombies) {
        int num = zombies.size();
        vector<vector<int>> edges;
        for(int i =0; i < zombies.size(); i++) {
            string & str = zombies[i];
            for (int j =0; j < str.size(); j++) {
                if (str[j]=='1' && i != j) {
                    edges.push_back({i,j});
                }
            }
        }
        return number_of_connected_components(num, edges);
    }

};

#endif //CPPALGORITHMS_ZOMBIECLUSTERS_H
