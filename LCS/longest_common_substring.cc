#include <bits/stdc++.h>

using namespace std;

int LongestCommonSubstring(string A, string B, int sizeA, int sizeB, int count)
{

    if (sizeA == 0 || sizeB == 0)
        return count;

    if (A[sizeA - 1] == B[sizeB - 1])
    {
        return LongestCommonSubstring(A, B, sizeA - 1, sizeB - 1, count + 1);
    }

    return max(count, max(LongestCommonSubstring(A, B, sizeA - 1, sizeB, 0),
                          LongestCommonSubstring(A, B, sizeA, sizeB - 1, 0)));
}

int main(int argc, const char **argv)
{
    string A = "abcdefg";
    string B = "abciabcdefdddg";
    // int a = LongestCommonSubstring(A, B, A.size(), B.size(), 0);
    // cout << "Answer : " << a << "\n";

    vector<vector<int>> DP(A.size() + 1, vector<int>(B.size() + 1, -1));

    for (int i = 0; i <= A.size(); i++)
    {
        for (int j = 0; j <= B.size(); j++)
        {
            if (i == 0 || j == 0)
                DP[i][j] = 0;
        }
    }

    int maxVal = 0;

    for (int i = 1; i <= A.size(); i++)
    {
        for (int j = 1; j <= B.size(); j++)
        {

            if (A[i - 1] == B[j - 1])
            {
                DP[i][j] = 1 + DP[i - 1][j - 1];
                maxVal = max(maxVal, DP[i][j]);
            }
            else
            {
                DP[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < DP.size(); i++)
    {
        for (int j = 0; j < DP[0].size(); j++)
        {
            cout << DP[i][j] << "\t";
        }
        cout << "\n";
    }

    cout << "ans : " << maxVal << "\n";

    return 0;
}