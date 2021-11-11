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
#include "CourseDependencies.h"

#include <iostream>
using namespace std;
void GraphProblems::runGraphProblems() {

    CourseDependencies courseDependencies;
    vector<int>  a = {1, 1, 3};
    vector<int>  b = {0, 2, 1};
    int res = courseDependencies.can_be_completed(4, a, b);
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