#include <bits/stdc++.h>

using namespace std;

static bool comparatorActivites(vector<int> first, vector<int> second)
{
    return (first[1] < second[1]);
}

int conferenceCount(vector<int> start, vector<int> end, int n)
{

    vector<vector<int>> activites;

    for (int i = 0; i < n; i++)
    {
        activites.push_back({start[i], end[i]});
    }
    // Your code here

    sort(activites.begin(), activites.end(), comparatorActivites);

    int count = 1;

    int i = 0;

    for (int j = 1; j < activites.size(); j++)
    {

        if (activites[j][0] > activites[i][1])
        {
            i = j;
            count++;
        }
    }

    return count;
}