#include <bits/stdc++.h>
using namespace std;

void permutation(string &s, int start, int end)
{
    if (start == end)
    {
        cout << s << " \n";
        return;
    }

    for (int i = start; i <= end; i++)
    {
        swap(s[start], s[i]);
        permutation(s, start + 1, end);
        swap(s[start], s[i]);
    }
}

int main()
{

    string s = "ABC";

    permutation(s, 0, s.size() - 1);

    return 0;
}