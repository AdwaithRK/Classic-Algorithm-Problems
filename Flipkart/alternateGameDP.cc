#include <bits/stdc++.h>
using namespace std;

int value(int i, int j, vector<int> ele, vector<vector<int>> &DP)
{
    if (i == j)
        return ele[i];

    if (i > j)
        return 0;

    if (DP[i][j] != -1)
        return DP[i][j];

    int first = ele[i] + min(value(i + 2, j, ele, DP), value(i + 1, j - 1, ele, DP));
    int second = ele[j] + min(value(i + 1, j - 1, ele, DP), value(i, j - 2, ele, DP));

    cout << "first : " << first << "second : " << second << "\n";

    return DP[i][j] = max(first, second);
}

int main()
{

    vector<int> ele = {1, 4, 2, 8, 3, 6};

    int result = value(0, ele.size() - 1, ele);

    cout << "result : " << result << "\n";

    return 0;
}