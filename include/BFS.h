#ifndef BFS_H
#define BFS_H

#include <vector>
#include <map>
#include <utility>


using namespace std;

vector<pair<int,int>> bfs(
    vector<vector<vector<pair<int,int>>>>& grafo,
    vector<pair<int,int>>& explorados //devuelve los explorados
);

#endif
