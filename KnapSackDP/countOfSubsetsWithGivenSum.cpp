#include <bits/stdc++.h>
using namespace std;

int countOfSubSetWithGivenSum(vector<int> arr, int sum, int index)
{
    if (sum != 0 && index < 0)
        return 0;

    if (sum == 0)
        return 1;

    if (arr[index] <= sum)
        return countOfSubSetWithGivenSum(arr, sum, index - 1) + countOfSubSetWithGivenSum(arr, sum - arr[index], index - 1);

    return countOfSubSetWithGivenSum(arr, sum, index - 1);
}

int main()
{
    vector<int> arr = {3, 3, 3, 3};
    cout << countOfSubSetWithGivenSum(arr, 6, 3) << "\n";
}