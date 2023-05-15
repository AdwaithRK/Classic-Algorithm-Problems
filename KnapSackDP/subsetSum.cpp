#include <bits/stdc++.h>
using namespace std;
vector<vector<bool>> Memoization(7, vector<bool>(16, false));
vector<vector<bool>> isMarked(7, vector<bool>(16, false));

bool subSetSum(int set[], int n, int sum)
{
    if (sum == 0)
        return true;
    if (sum != 0 && n == 0)
        return false;

    if (isMarked[n][sum])
        return Memoization[n][sum];

    // cout << " ( " << n << " , " << sum << " ) "
    //     << "current element :" << set[n - 1] << "\n";
    if (set[n - 1] > sum)
    {
        // cout << "subSetSum called with arguments : " << n - 1 << " " << sum << "\n";
        isMarked[n][sum] = true;
        Memoization[n][sum] = subSetSum(set, n - 1, sum);
        return Memoization[n][sum];
    }

    // cout << "subSetSum called with arguments : " << n - 1 << " " << sum << "\n";
    // cout << "subSetSum called with arguments : " << n - 1 << " " << sum - set[n - 1] << "\n";
    isMarked[n][sum] = true;
    Memoization[n][sum] = subSetSum(set, n - 1, sum) || subSetSum(set, n - 1, sum - set[n - 1]);
    return Memoization[n][sum];
}

int main()
{
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 19;
    int n = sizeof(set) / sizeof(set[0]);

    cout << subSetSum(set, n, sum);

    return 0;
}
