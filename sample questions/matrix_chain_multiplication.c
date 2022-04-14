#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int matrix_chain_multiplication(int *arr, int start, int end)
{
    if (start == end)
        return 0;
    int min = INT_MAX;
    for (int k = start; k < end; k++)
    {
        int count = matrix_chain_multiplication(arr, start, k) + matrix_chain_multiplication(arr, k + 1, end) + arr[start - 1] * arr[k] * arr[end];
        if (count < min)
            min = count;
    }
    printf("minimum is %d\n", min);
    return min;
}

int main()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", (arr + i));
    }
    printf("%d", matrix_chain_multiplication(arr, 1, n - 1));
    return 0;
}