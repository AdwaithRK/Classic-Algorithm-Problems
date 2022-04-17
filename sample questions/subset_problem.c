#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int set[100];
int sum;

bool sub_set_sum(int sum, int set_index)
{
    if (sum == 0)
        return true;
    if (sum != 0 && set_index == 0)
        return false;
    else
    {
        return (sub_set_sum(sum, set_index - 1) | sub_set_sum(sum - set[set_index], set_index - 1));
    }
}

int main()
{
    int n;

    printf("\n\nEnter the number of elements in set\n\n");

    scanf("%d", &n);

    printf("\nEnter the sum required\n");

    scanf("%d", &sum);

    printf("\n\n Enter the elements of set \n\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &set[i]);

    bool is_sum = sub_set_sum(sum, n - 1);
    if (is_sum)
    {
        printf("\n\nSum is available as subset\n\n");
    }
    else
    {
        printf("\n\nSum is not available as subset\n\n");
    }
}