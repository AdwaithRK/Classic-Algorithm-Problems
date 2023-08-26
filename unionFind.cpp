#include <bits/stdc++.h>
using namespace std;

class Solution
{

    int find(int i, vector<int> &parent)
    {
        if (i == parent[i])
        {
            return i;
        }
        else
        {
            parent[i] = find(i, parent);

            return parent[i];
        }
    }

    bool unionSet(int i, int j, vector<int> &parent, vector<int> &rank)
    {

        int iSet = find(i, parent);
        int jSet = find(j, parent);

        if (iSet == jSet)
            return false;

        if (rank[iSet] < rank[jSet])
        {
            parent[iSet] = jSet;
        }
        else if (rank[jSet] < rank[iSet])
        {
            parent[jSet] = iSet;
        }
        else
        {
            parent[jSet] = iSet;
            rank[iSet] = rank[iSet] + 1;
        }

        return true;
    }

public:
    int countComponents(int n, vector<vector<int>> &edges)
    {

        vector<int> parent(n, 0);
        vector<int> rank(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (int i = 0; i < edges.size(); i++)
        {
            unionSet(edges[i][0], edges[i][1], parent, rank);
        }

        int count = 0;

        for (int i = 0; i < parent.size(); i++)
        {
            if (parent[i] == i)
                count++;
        }

        return count;
    }
};

int main(int argc, const char **argv)
{
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {3, 4}};

    Solution a;

    int x = a.countComponents(3, edges);

    cout << "Components count : " << x << "\n\n";

    return 0;
}