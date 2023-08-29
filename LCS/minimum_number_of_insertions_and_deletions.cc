#include <bits/stdc++.h>

using namespace std;

int main()
{
    string A = "adwaith";
    string B = "aditya";

    vector<vector<int>> DP(A.size() + 1, vector<int>(B.size() + 1, -1));

    for (int i = 0; i <= A.size(); i++)
    {
        for (int j = 0; j <= B.size(); j++)
        {
            if (i == 0 || j == 0)
                DP[i][j] = 0;
        }
    }

    for (int i = 1; i <= A.size(); i++)
    {
        for (int j = 1; j <= B.size(); j++)
        {
            if (A[i - 1] == B[j - 1])
            {
                DP[i][j] = 1 + DP[i - 1][j - 1];
            }
            else
            {
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
        }
    }

    int lcs_size = DP[A.size()][B.size()];

    cout << "LCS Size : " << lcs_size << "\n\n";

    cout << "Deletions : " << A.size() - lcs_size << "\n\n";

    cout << "Insertions : " << B.size() - lcs_size << "\n\n";

    return 0;
}