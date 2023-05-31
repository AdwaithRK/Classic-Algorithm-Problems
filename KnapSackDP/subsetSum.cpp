#include <bits/stdc++.h>
using namespace std;
vector<vector<bool>> Memoization(7, vector<bool>(16, false));
vector<vector<bool>> isMarked(7, vector<bool>(16, false));

vector<vector<bool>> DP(7, vector<bool>(20, false));

bool subSetSum(int set[], int n, int sum)
{
    if (sum == 0)
        return true;
    if (sum != 0 && n == 0)
        return false;

    if (isMarked[n][sum])
        return Memoization[n][sum];

    if (set[n - 1] > sum)
    {
        isMarked[n][sum] = true;
        Memoization[n][sum] = subSetSum(set, n - 1, sum);
        return Memoization[n][sum];
    }

    isMarked[n][sum] = true;
    Memoization[n][sum] = subSetSum(set, n - 1, sum) || subSetSum(set, n - 1, sum - set[n - 1]);
    return Memoization[n][sum];
}

bool subSetSumBottomUp(int set[], int n, int sum)
{

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0)
                DP[i][j] = false;

            if (j == 0)
                DP[i][j] = true;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j >= set[i - 1])
            {
                DP[i][j] = (DP[i - 1][j] || DP[i - 1][j - set[i - 1]]);
            }
            else
            {
                DP[i][j] = DP[i - 1][j];
            }
        }
    }

    return DP[n][sum];
}

int main()
{
        int set[] = {3, 34, 4, 12, 5, 2};
        int sum = 16;
    int n = sizeof(set) / sizeof(set[0]);

    cout << subSetSum(set, n, sum) << "\n";

    cout << subSetSumBottomUp(set, n, sum) << "\n";

    return 0;
}
