//
// Created by USMAN QADIR on 10/13/22.
//

#ifndef CPPALGORITHMS_CITYWITHSMALLESTNUMBEROFNEIGHBORS_H
#define CPPALGORITHMS_CITYWITHSMALLESTNUMBEROFNEIGHBORS_H
#include <vector>
#include <climits>

using namespace std;
class CityWithSmallestNumberOfNeighbors {
public:
    int findTheCity(int n, vector<vector<int>> & edges, int distanceThreshold) {
        //Floyd Warshall Algo
        vector<vector<int>> dist (n, vector<int> (n, INT_MAX)); //initial weights are infinity
        //1. set self connection weights to 0
        for (int i =0; i < n; i++) {
            dist[i][i]=0;
        }
        //2. set direct edge weights
        for (int i=0; i < edges.size(); i++) {
            dist[edges[i][0]][edges[i][1]] = dist[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        //k is the intermediate node that can be used as an intermediate hop while going between i and j
        for (int k =0 ; k < n; k++) {
            for (int i =0; i < n; i++) {
                for (int j=0; j < n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
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
