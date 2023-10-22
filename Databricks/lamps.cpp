#include <bits/stdc++.h>

using namespace std;

vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &persons)
{
    vector<int> start, end;
    for (auto &t : flowers)
        start.push_back(t[0]), end.push_back(t[1]);
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    vector<int> res;
    for (int t : persons)
    {
        int started = upper_bound(start.begin(), start.end(), t) - start.begin();
        int ended = lower_bound(end.begin(), end.end(), t) - end.begin();
        res.push_back(started - ended);
    }
    return res;
}

int main()
{
    vector<vector<int>> k = {{1, 7}, {5, 6}, {2, 4}};

    vector<int> values = {5, 6, 3, 9, 15};

    vector<int> temp = fullBloomFlowers(k, values);


    for(auto k : temp) cout << k << "\n";

    return 0;
}