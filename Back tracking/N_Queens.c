#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

bool isSafe(int row, int i, int *column_array, int n)
{
    int c;
    if (row == 0)
        return true;
    for (int j = 0; j < row; j++)
    {
        if (column_array[j] == i)
            return false;
    }

    for (int r = row - 1, c = ++i; r >= 0, i < n; r--, i++)
    {
        if (column_array[r] == i)
            return false;
    }

    for (int r = row - 1, c = --i; r >= 0, i < n; r--, i--)
    {
        if (column_array[r] == i)
            return false;
    }

    return true;
}

void printArray(int *column_array, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", column_array[i]);
    }
    printf("\n");
}

void NQueen(int row, int n, int *column_array)
{
    printf("\n Row is %d\n Array is:\n", row);
    printArray(column_array, n);
    sleep(10);
    if (row == n - 1)
    {
        printf("\nSuccess, The solution is:\t");
        for (int i = 0; i < n; i++)
        {
            printf("%d\t", i);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++)
    {
        printf("\n(%d,%d)\n", row, i);
        printf("\n\nThe column is %d\n\n", isSafe(row, i, column_array, n));
        if (isSafe(row, i, column_array, n))
        {
            column_array[row] = i;
            NQueen(row + 1, n, column_array);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int *column_array = (int *)malloc(n * sizeof(int));

    NQueen(0, n, column_array);

    return 0;
}