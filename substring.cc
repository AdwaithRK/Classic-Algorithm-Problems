#include <bits/stdc++.h>

using namespace std;

int main()
{

    string s = "adwaith";
    string a = "tha";

    int count = 0;

    for (int i = 0; i < s.size(); i++)
    {
        int j;
        for (j = 0; j < a.size(); j++)
        {

            if (s[(i + j) % s.size()] != a[j])
            {
                break;
            }
        }

        if (j == a.size())
        {
            cout << "\nyes\n";
            break;
        }
    }

    return 0;
}