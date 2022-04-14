#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int LCS(char *first, char *second, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (first[m - 1] == second[n - 1])
    {

        return 1 + LCS(first, second, m - 1, n - 1);
    }
    else
    {
        return max(LCS(first, second, m, n - 1), LCS(first, second, m - 1, n));
    }
}

int main()
{
    char a[] = "adwamth";
    char b[] = "adwaith";
    printf("%d", LCS(a, b, strlen(a), strlen(b)));
    return 0;
}