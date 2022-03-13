#include <stdio.h>
#include <stdlib.h>

struct link
{
    int data;
    struct link *p;
};

struct link *create_list(int n)
{
    int data;
    struct link *traverse = NULL;
    struct link *node = (struct link *)malloc(sizeof(struct link));
    struct link *head = node;
    struct link *previous = NULL;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        node->data = data;
        if (previous)
            previous->p = node;
        previous = node;
        node = (struct link *)malloc(sizeof(struct link));
    }

    return head;
}

void traverse(struct link *traverse)
{
    while (traverse != NULL)
    {
        printf("%d\n", traverse->data);
        traverse = traverse->p;
    }
};

int main()
{
    int n, data;
    printf("Enter the number of nodes you want\n");
    scanf("%d", &n);
    struct link *head = create_list(n);
    traverse(head);
}