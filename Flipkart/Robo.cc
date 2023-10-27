#include <bits/stdc++.h>
using namespace std;

class Solution
{

    int DFS(vector<vector<int>> &grid, int row, int col1, int col2, vector<vector<vector<int>>> &DP)
    {

        if (row < 0 || row >= grid.size() || col1 < 0 || col1 >= grid[0].size() || col2 < 0 || col2 >= grid[0].size())
            return 0;

        if (DP[row][col1][col2] != -1)
            return DP[row][col1][col2];

        int result = 0;

        result += grid[row][col1];

        if (col1 != col2)
            result += grid[row][col2];

        int maxAns = 0;

        for (int i = col1 - 1; i <= col1 + 1; i++)
        {
            for (int j = col2 - 1; j <= col2 + 1; j++)
            {
                maxAns = max(maxAns, DFS(grid, row + 1, i, j, DP));
            }
        }

        result += maxAns;

        return DP[row][col1][col2] = result;
    }

public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        vector<vector<vector<int>>> DP(70, vector<vector<int>>(70, vector<int>(70, -1)));

        return DFS(grid, 0, 0, grid[0].size() - 1, DP);
    }
};