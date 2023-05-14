#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> DP(4, vector<int>(51, -1));
vector<vector<int>> Memoization(4, vector<int>(51, -1));

int knapSack(vector<int> Wt, vector<int> Value, int w, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (i == 0 || j == 0)
                DP[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (j < Wt[i])
            {
                DP[i][j] = DP[i - 1][j];
            }
            else
            {
                DP[i][j] = max(DP[i - 1][j], Value[i] + DP[i - 1][j - Wt[i]]);
            }
        }
    }

    return DP[n][w];
}

int knapSackRecursive(vector<int> Wt, vector<int> Value, int w, int n)
{
    int result = 0;
    if (w == 0 || n == 0)
        return 0;
    if (Memoization[n][w] != -1)
        return Memoization[n][w];

    if (w < Wt[n])
    {
        Memoization[n][w] = knapSackRecursive(Wt, Value, w, n - 1);
    }
    else
    {
        Memoization[n][w] = max(knapSackRecursive(Wt, Value, w, n - 1), knapSackRecursive(Wt, Value, w - Wt[n], n - 1) + Value[n]);
    }
    return Memoization[n][w];
}

int main()
{

    vector<int> V = {60, 100, 120};
    vector<int> W = {10, 20, 30};

    int result = knapSack(W, V, 50, 3);

    cout << "Result is : " << result << "\n";

    result = knapSackRecursive(W, V, 50, 3);

    cout << "Result is : " << result << "\n";

    return 0;
}