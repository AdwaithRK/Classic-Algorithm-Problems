#include <stdio.h>

int Profit[10];
int Weight[10];

int knapsack_zero_one(int m, int n)
{
    if (m == 0 || n == 0)
        return 0;

    if (Weight[n] > m)
        knapsack_zero_one(m, n - 1);

    else
    {
        int a = knapsack_zero_one(m - Weight[n], n - 1) + Profit[n];
        int b = knapsack_zero_one(m, n - 1);
        if (a > b)
            return a;
        else
            return b;
    }
}

int main()
{
    int n, w;
    printf("\n\nEnter the number of weights\n\n");
    scanf("%d", &n);
    printf("\n\nThe capacity of the bag\n\n");
    scanf("%d", &w);

    printf("\n\n Enter weight of items\n\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &Weight[i]);
    }

    printf("\n\nEnter the profit of items\n\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &Profit[i]);
    }

    printf("%d", knapsack_zero_one(w, n - 1));
}