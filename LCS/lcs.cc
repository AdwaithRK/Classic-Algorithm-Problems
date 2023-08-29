#include <bits/stdc++.h>

using namespace std;

int LCS(string A, string B, int sizeA, int sizeB)
{

    if (sizeA == 0 || sizeB == 0)
        return 0;

    if (A[sizeA - 1] == B[sizeB - 1])
    {
        return 1 + LCS(A, B, sizeA - 1, sizeB - 1);
    }

    int a = LCS(A, B, sizeA - 1, sizeB);

    int b = LCS(A, B, sizeA, sizeB - 1);

    return max(a, b);
}

int main(int argc, const char **argv)
{

    string A = "abcdef";

    string B = "abggcde";

    vector<vector<int>> DP(A.size() + 1, vector<int>(B.size() + 1, -1));

    for (int i = 0; i < DP.size(); i++)
    {
        for (int j = 0; j < DP[0].size(); j++)
        {
            if (i == 0 || j == 0)
                DP[i][j] = 0;
        }
    }

    for (int i = 1; i < DP.size(); i++)
    {
        for (int j = 1; j < DP[0].size(); j++)
        {

            if (A[i] == B[j])
            {
                DP[i][j] = 1 + DP[i - 1][j - 1];
            }
            else
            {
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
            }
        }
    }

    // int a = LCS(A, B, A.size(), B.size());

    cout << "\nAnswer : " << DP[A.size()][B.size()] << "\n";

    return 0;
}