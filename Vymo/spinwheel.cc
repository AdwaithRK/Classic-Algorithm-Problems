#include <bits/stdc++.h>

using namespace std;

int main()
{
    //int n = 10;

    vector<string> ans = {"137", "364", "115", "724"};

    vector<vector<int>> DP(ans.size(), vector<int>(ans[0].size(), 0));

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            DP[i][j] = ans[i][j] - '0';
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        sort(DP[i].begin(), DP[i].end(), greater<int>());
    }

    int sum = 0;

    for (int j = 0; j < DP[0].size(); j++)
    {
        int maxV = 0;
        for (int i = 0; i < DP.size(); i++)
        {
            maxV = max(maxV, DP[i][j]);
        }
        sum += maxV;
    }

    cout << "ans : " << sum << "\n";

    return 0;
}
