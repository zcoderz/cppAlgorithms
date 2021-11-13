//
// Created by usman on 11/8/21.
//

#include "GraphProblems.h"

#include "../utils/graph/Vertex.h"
#include "../utils/graph/Edge.h"
#include "../utils/graph/UnionFind.h"
#include "../utils/graph/UnionFindNode.h"
#include "../utils/graph/PrimsAlgoForMinSpanningTrees.h"
#include "CountIslands.h"
#include "SearchLargestIsland.h"
#include "NumberOfConnectedComponents.h"
#include "IsATree.h"
#include "CourseDependenciesTopoSort.h"
#include "CourseDependenciesArvDepTimes.h"
#include "FriendlyGroups.h"
#include "FloodFill.h"
#include "KnightMoves.h"
#include "StringTransformation.h"
#include "CourseSchedule.h"
#include "ZombieClusters.h"
#include "CriticalConnections.h"
#include <iostream>

using namespace std;
void GraphProblems::runGraphProblems() {
    CriticalConnections criticalConnections;
    vector<vector<int>> vecCon = {{0, 1}, {0, 2},{0, 4},{1, 2},{1, 3}};
    vector<vector<int>> resVec = criticalConnections.find_critical_connections(5, vecCon);
    for (vector<int> val : resVec) {
        for (int v : val) {cout << v << " , ";}
        cout  << endl;
    }
    return;
//    ZombieClusters zombieClusters;
//    vector<string> vec = {"1100", "1110","0110", "0001"};
//    int numZ = zombieClusters.zombieCluster(vec);
//    cout << numZ << endl;
//    return;
//    CourseSchedule courseSchedule;
//    //vector<vector<int>> prerqs = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
//    vector<vector<int>> prerqs = {{1, 0}, {0, 1}};
//    vector<int> cOrder = courseSchedule.course_schedule(2, prerqs);
//    for (int course: cOrder) {
//        cout << course << endl;
//    }
//    return;
    StringTransformation stringTransformation;
    //vector<string> vec = {"cccw", "accc", "accw"};
    vector<string> vecMappings = stringTransformation.string_transformation({}, "t", "t");
    for (string str: vecMappings) {
        cout << str << endl;
    }
    return;
    KnightMoves knightMoves;
    int kRes = knightMoves.find_minimum_number_of_moves(4999, 20, 4998, 0, 4998, 19);
    cout << kRes << endl;

    vector<int> v1 = {7,6,6,4,4,0};
    vector<int> v2 = {5,5,3,3,5,5};
    FriendlyGroups friendlyGroups;
    bool  resA = friendlyGroups.can_be_divided(8, v1, v2);
    cout << resA << endl;
    CourseDependenciesTopoSort courseDependencies;
    vector<int>  a = {1, 1, 3};
    vector<int>  b = {0, 2, 1};
    int res = courseDependencies.can_be_completed(4, a, b);
    cout << res <<endl;
    CourseDependenciesArvDepTimes courseDep2;
    res = courseDep2.can_be_completed(4, a, b);
    cout << res <<endl;
    CountIslands countIslands;
    vector<vector<int>> matrix = {{1, 1, 0, 0, 0},
    {0, 1, 0, 1, 1},
    {1, 0, 0, 1, 1},
    {0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1}};
    int num = countIslands.count_islands(matrix);
    cout << num << endl;
    LargestIsland largestIsland;
    int sz = largestIsland.max_island_size(matrix);
    cout << sz << endl;
    NumberOfConnectedComponents numberOfConnectedComponents;
    vector<vector<int>> edges = {{0,1},{1,2},{0,2},{3,4}};
    sz = numberOfConnectedComponents.number_of_connected_components(5, edges);
    cout << sz << endl;
}