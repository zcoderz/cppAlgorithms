//
// Created by USMAN QADIR on 10/13/22.
//

#ifndef CPPALGORITHMS_CITYWITHSMALLESTNUMBEROFNEIGHBORS_H
#define CPPALGORITHMS_CITYWITHSMALLESTNUMBEROFNEIGHBORS_H
#include <vector>

using namespace std;
class CityWithSmallestNumberOfNeighbors {
public:
    int findTheCity(int n, vector<vector<int>> & edges, int distanceThreshold) {
        //Floyd Warshall algo
        vector<vector<int>> dist (n, vector<int> (n, 10001))
        for (int i=0; i < edges.size(); i++) {
            dist[edge[0]][edge[1]] = dist[edge[1]][edge[0]] = edge[2];
        }
        for (int k =0 ; k < n; k++) {
            for (int i =0; i < n; i++) {
                for (int j=0; j < n; j++) {
                    dist[i][j] = min(dist[i][j], disk[i][k] + dist[k][j]);
                }
            }
        }
        int smallestCnt = n;
        int smallestIndex =0;
        for (int i=0; i < n; i++) {
            int cnt =0;
            for (int j =0; j < n; j++) {
                if (dist[i][j] <= distanceThreshold) cnt++;
            }
            if (cnt <= smallestCnt) {
                smallestCnt = cnt;
                smallestIndex = i;
            }
        }
        return smallestIndex;
    }
};
#endif //CPPALGORITHMS_CITYWITHSMALLESTNUMBEROFNEIGHBORS_H
