#include <bits/stdc++.h>
using namespace std;

int convertPtoQ(int p, int q)
{

    if (q == 1)
        return 1;
    if (q == 0)
        return 1;

    if (p == q)
        return 0;

    if(p > q) return -1;

    int a = INT_MAX, b = INT_MAX;

    if (p + p <= q)
    {
        a = 1 + convertPtoQ(p + p, q);
    }

    if (p != 1 && p * p <= q)
    {
        b = 1 + convertPtoQ(p * p, q);
    }

    cout << a << " : " << b << "\n";

    int ans = (min(a, b) == INT_MAX) ? -1 : min(a, b);

    return ans;
}

int main()
{
    int k = convertPtoQ(5, 3);

    int ans = (k == INT_MAX) ? -1 : k;

    cout << ans;

    return 0;
}