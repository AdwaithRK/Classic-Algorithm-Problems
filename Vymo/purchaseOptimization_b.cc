#include <bits/stdc++.h>

using namespace std;

int bs(int pos, vector<int> prices, int q, int prev)
{
    if (q > prices.back())
        return prices.size() - pos + 1;

    int l, r;
    l = pos;
    r = prices.size() - 1;
    int res = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (prices[mid] - prev <= q)
        {
            res = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return res == -1 ? 0 : res - pos + 1;
}

vector<int> sol(int n, vector<int> prices, int q, vector<vector<int>> queries)
{
    vector<int> prefix(prices.size()), res(queries.size());
    prefix[0] = prices[0];

    for (int i = 1; i < prices.size(); i++)
    {
        prefix[i] = prefix[i - 1] + prices[i];
    }
    
    for (int i = 0; i < queries.size(); i++)
    {
        res[i] = bs(queries[i][0] - 1, prefix, queries[i][1], queries[i][0] == 0 ? 0: prefix[queries[i][0] - 2]);
    }
    
    return res;
}