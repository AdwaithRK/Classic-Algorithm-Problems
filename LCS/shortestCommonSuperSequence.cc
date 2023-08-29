#include <bits/stdc++.h>

using namespace std;

int SCSS(string A, string B, int sizeA, int sizeB)
{

    if (sizeA == 0 || sizeB == 0)
        return 0;

    if (A[sizeA - 1] == B[sizeB - 1])
    {
        return 1 + SCSS(A, B, sizeA - 1, sizeB - 1);
    }

    return 1 + min(SCSS(A, B, sizeA, sizeB - 1), SCSS(A, B, sizeA - 1, sizeB));
}

int main()
{
    string A = "ABCD";
    string B = "BDE";

    int count = SCSS(A, B, A.size(), B.size());

    cout << " Count : " << count << "\n\n";

    return 0;
}