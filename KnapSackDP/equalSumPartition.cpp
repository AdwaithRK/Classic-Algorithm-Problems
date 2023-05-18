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

    return subSetSumRecursive(arr, sum / 2, arr.size() - 1);
}

int main()
{

    vector<int> arr = {1,
                       5,
                       11,
                       5};
    // int size = sizeof(arr) / sizeof(arr[0]);

    cout << equalSumPartition(arr);

    // cout << "sub set sum : " << subSetSumRecursive(arr, 6, 3) << "\n";

    return 0;
}