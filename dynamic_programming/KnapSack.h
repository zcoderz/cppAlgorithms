//
// Created by usman on 11/24/21.
//

#ifndef CPPALGORITHMS_KNAPSACK_H
#define CPPALGORITHMS_KNAPSACK_H

class KnapSack {
    vector<vector<int>> _dp;
    vector<pair<int, int>>  _vecVals;
    int _capacity;
public:
    int calculateOptimal(vector<pair<int, int>> & vecVals, int totalCapacity) {
        vector<vector<int>> dp(vecVals.size() +1 , vector<int> (totalCapacity +1, 0));
        _dp = move(dp);

        for (int i =1; i <= vecVals.size(); i++) {
            for (int c =0; c <= totalCapacity; c++) {
                pair<int, int> & dataPoint = vecVals[i-1];
                if (dataPoint.second > c) {
                    _dp[i][c] = _dp[i-1][c];
                } else {
                    _dp[i][c] = max(_dp[i-1][c] , _dp[i-1][c-dataPoint.second] + dataPoint.first);
                }
            }
        }
        _vecVals = vecVals;
        _capacity = totalCapacity;
        return _dp[vecVals.size()][totalCapacity];
    }

    string reconstructPath()  {
        string res;
        int remCapacity = _capacity;
        //the dp 0th index is a placeholder for alignment and hence we need to skip over the 0th index
        //item at index i-1 contributes to dp index array i. hence comparing i-2 in item vector vs i-1 in dp array
        for (int i = _dp.size()-1; i > 0 ; i-- ) {
            //if the given items capacity is less than remaining capacity
            if (_vecVals[i-1].second <= remCapacity &&
            //if the aggregated value before the given item (i-1)
            //and capacity utilized while excluding the given items capacity "remCapacity-_vecVals[i].second"
            //and the given item's value added to the previous aggregated value is greater than the aggregated
            //value while excluding the given item but keeping capacity same "_dp[i-1][remCapacity]"
            //then use the current item, otherwise skip it
            (_dp[i][remCapacity-_vecVals[i-1].second] + _vecVals[i-1].first) >=  _dp[i][remCapacity]) {
                res += to_string(i-1) + ",";
                remCapacity -= _vecVals[i-1].second;
            }
        }
        return res.substr(0, res.size()-1);
    }
};

#endif //CPPALGORITHMS_KNAPSACK_H
