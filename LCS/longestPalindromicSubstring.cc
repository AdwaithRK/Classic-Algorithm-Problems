#include <bits/stdc++.h>

using namespace std;

int main()
{
    string Str = "Aalayalaperson";

    string reverStr = Str;
    reverse(reverStr.begin(), reverStr.end());

    vector<vector<int>> DP(Str.size() + 1, vector<int>(Str.size() + 1, -1));

    for (int i = 0; i <= Str.size(); i++)
    {
        for (int j = 0; j <= reverStr.size(); j++)
        {
            if (i == 0 || j == 0)
                DP[i][j] = 0;
        }
    }

    for (int i = 1; i <= Str.size(); i++)
    {
        for (int j = 1; j <= reverStr.size(); j++)
        {
            if (Str[i - 1] == reverStr[j - 1])
            {
                DP[i][j] = 1 + DP[i - 1][j - 1];
            }
            else
            {
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
        }
    }

    cout << "lenght of the longest palindromic subsequence = " << DP[Str.size()][reverStr.size()] << "\n";

    return 0;
}