//
// Created by usman on 10/6/22.
//

#ifndef CPPALGORITHMS_RECONSTRUCTITINERARY_H
#define CPPALGORITHMS_RECONSTRUCTITINERARY_H
#include <vector>
#include <string>
#include <unordered_map>
#include <list>
#include <algorithm>
#include <functional>
#include <iterator>
#include <iostream>

using namespace std;

class ReconstructItinerary {
public:
    unordered_map<string, list<string>> sourceDestinations;
    vector<string> cities;

    inline void dfs (const string & city) {
        auto iter = sourceDestinations.find(city);
        if (iter != sourceDestinations.end()) {
            auto & cityList = iter->second;
            while (!cityList.empty()) {
                string cityTmp = *cityList.begin(); cityList.erase(cityList.begin());
                dfs(cityTmp);
                //cout << "return from city" << cityTmp << endl;
            }
        }
        //cout << "adding city " << city << endl;
        cities.push_back(city);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (vector<string> & ticket: tickets) {
            sourceDestinations[ticket[0]].push_back(ticket[1]);
        }
        for (auto iter = sourceDestinations.begin(); iter != sourceDestinations.end(); iter++) {
            iter->second.sort();
        }

        string strAirport = "JFK";
        dfs(strAirport);
        std::reverse(cities.begin(), cities.end());
        return cities;
    }

    static void testMe() {
        ReconstructItinerary reconstruct;
        vector<vector<string>> tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
        vector<string> cities = reconstruct.findItinerary(tickets);
        std::copy(cities.begin(), cities.end() , std::ostream_iterator<string>(cout, ", "));
    }
};

#endif //CPPALGORITHMS_RECONSTRUCTITINERARY_H
