#include <stdio.h>
#include <stdlib.h>

void input_array(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", (a + i * n) + j);
        }
    }
}

void print_array(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", *(a + i * n + j));
        }
        printf("\n");
    }
}

int *rotate_array(int *a, int n, int *rotated)
{
    rotated = (int *)malloc((n * n) * sizeof(int));
    printf("here here");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            rotated[j * n + (n - 1 - i)] = a[i * n + j];
        }
    }
    return rotated;
}

int main()
{
    int n;
    printf("\nEnter N\n");
    scanf("%d", &n);

    int *a = (int *)malloc((n * n) * sizeof(int));

    int *rotated = (int *)malloc((n * n) * sizeof(int));

    input_array(a, n);
    print_array(a, n);
    rotated = rotate_array(a, n, rotated);
    print_array(rotated, n);
}