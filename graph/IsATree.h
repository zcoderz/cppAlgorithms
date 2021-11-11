//
// Created by usman on 11/11/21.
//

#ifndef CPPALGORITHMS_ISATREE_H
#define CPPALGORITHMS_ISATREE_H
class IsATree {
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

    bool is_it_a_tree(int node_count, vector<int> edge_start, vector<int> edge_end) {
        vertices.resize(node_count);
        for (int i =0; i < node_count; i++) {
            vertices[i] = make_pair(i, 0);
        }
        int numConnectedComponents = node_count;
        for (int i =0; i < edge_start.size(); i++) {
            int start = edge_start[i];
            int end = edge_end[i];
            int p1 = find(start);
            int p2 = find(end);
            if (p1 != p2) {
                runUnion(start, end);
                numConnectedComponents--;
            } else {
                return false;
            }
        }
        return numConnectedComponents==1;
    }
};
#endif //CPPALGORITHMS_ISATREE_H
