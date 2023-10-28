#include <bits/stdc++.h>

using namespace std;

int djistra(int n, int m, vector<vector<int>> &edges, int src, int destination)
{
    vector<vector<int>> adjList[n];

    for (auto edge : edges)
    {
        adjList[edge[0]].push_back({edge[1], edge[2], edge[3]});
        adjList[edge[1]].push_back({edge[0], edge[2], edge[3]});
    }


    
}