#include <bits/stdc++.h>
using namespace std;

int value(int i, int j, vector<int> ele)
{
    if (i == j)
        return ele[i];

    if (i > j)
        return 0;

    int first = ele[i] + max(value(i + 2, j, ele), value(i + 1, j - 1, ele));
    int second = ele[j] + max(value(i + 1, j - 1, ele), value(i, j - 2, ele));

    cout << "first : " << first << "second : " << second << "\n";

    return max(first, second);
}

int main()
{

    vector<int> ele = {5, 10, 8, 11, 6, 2, 3};

    int result = value(0, ele.size() - 1, ele);

    cout << "result : " << result << "\n";

    return 0;
}