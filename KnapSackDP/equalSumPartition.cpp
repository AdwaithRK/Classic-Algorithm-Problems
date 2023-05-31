#include <bits/stdc++.h>
using namespace std;

bool subSetSumRecursive(vector<int> arr, int sum, int index)
{
    if (sum != 0 && index < 0)
        return false;
    if (sum == 0)
        return true;

    if (arr[index] <= sum)
        return subSetSumRecursive(arr, sum - arr[index], index - 1) || subSetSumRecursive(arr, sum, index - 1);

    return subSetSumRecursive(arr, sum, index - 1);
}

vector<vector<bool>> DP(5, vector<bool>(23, false));

bool subSetSumBottomUp(vector<int> arr, int sum, int index)
{
    for (int i = 0; i <= arr.size(); i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0)
                DP[i][j] = false;
            if (j == 0)
                DP[i][j] = true;
        }
    }

    for (int i = 1; i <= arr.size(); i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
            {
                DP[i][j] = DP[i - 1][j] || DP[i - 1][j - arr[i - 1]];
            }
            else
            {
                DP[i][j] = DP[i - 1][j];
            }
        }
    }

    return DP[index][sum];
}

bool equalSumPartition(vector<int> arr)
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }
    // cout << "Sum : " << sum;

    if (sum % 2 != 0)
        return false;

    return subSetSumBottomUp(arr, sum / 2, arr.size() - 1);
}

int main()
{

    vector<int> arr = {2,
                       5,
                       11,
                       5};
    // int size = sizeof(arr) / sizeof(arr[0]);

    cout << equalSumPartition(arr);

    // cout << "sub set sum : " << subSetSumBottomUp(arr, 7, 4) << "\n";

    return 0;
}