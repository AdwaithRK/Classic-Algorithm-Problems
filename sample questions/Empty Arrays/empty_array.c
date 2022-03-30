#include <stdlib.h>
#include <stdio.h>
#define ASCII_SIZE 256

void rvereseArray(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int *deleteFirstElement(int arr[], int n)
{
    int k = 0;
    int *a = (int *)malloc((n - 1) * sizeof(int));
    for (int i = 1; i < n; i++)
    {
        a[k] = arr[i];
        k++;
    }

    return a;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
}

void rotateLeft(int arr[], int n)
{
    int temp = arr[0];
    for (int i = 0; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[n - 1] = temp;
}

int main()
{
    int size, operation_count = 0;
    scanf("%d", &size);

    int *a = (int *)malloc(size * sizeof(int));
    int *b = (int *)malloc(size * sizeof(int));

    printf("\n");

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("\n");

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &b[i]);
    }

    int i = 0;
    while (size > 0)
    {

        // printf("hai hai here here");
        if (a[i] == b[i])
        {
            // printf("\nhere here\n");
            a = deleteFirstElement(a, size);
            b = deleteFirstElement(b, size);
            // printf("\nnow a is\n");
            printArray(a, size);
            // printf("\nnow b is\n");
            printArray(b, size);

            size--;
            operation_count++;
        }
        else if (a[i] != b[i])
        {
            // printf("bow bow");
            rotateLeft(a, size);
            // printf("\nnow a is\n");
            printArray(a, size);
            operation_count++;
        }
    }

    printf("\nTotal operations is %d\n", operation_count);
    return 0;
}