#include <bits/stdc++.h>
using namespace std;

int coding_friends(int samDaily, int kellyDaily, int difference)
{

    if (kellyDaily < samDaily)
        return -1;

    if ((kellyDaily - samDaily) == 0)
    {
        return -1;
    }

    int x = ceil(difference / (kellyDaily - samDaily));

    if (x == (difference / (kellyDaily - samDaily)))
        return (x + 1);

    return x;
}