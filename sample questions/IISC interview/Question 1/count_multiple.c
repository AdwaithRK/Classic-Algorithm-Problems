#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int s;
    int count = 0;
    scanf("%d", &n);
    int product = n;

    while (product > 10)
    {
        n = product;
        product = 1;
        while (s = n % 10)
        {
            product = product * s;
            n = n / 10;
        }
        count++;
        printf("\n%d --> %d\n", count, product);
    }

    return count;
}