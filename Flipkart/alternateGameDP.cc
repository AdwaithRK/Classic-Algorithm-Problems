#include <bits/stdc++.h>
using namespace std;

int value(int i, int j, vector<int> ele)
{
    if (i == j)
        return ele[i];

    if (i > j)
        return 0;

    int first = ele[i] + min(value(i + 2, j, ele), value(i + 1, j - 1, ele));
    int second = ele[j] + min(value(i + 1, j - 1, ele), value(i, j - 2, ele));

    cout << "first : " << first << "second : " << second << "\n";

    return max(first, second);
}

int main()
{

    vector<int> ele = {1, 4, 2, 8, 3, 6};

    int result = value(0, ele.size() - 1, ele);

    cout << "result : " << result << "\n";

    return 0;
}