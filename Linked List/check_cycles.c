#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// struct node *current = NULL;

struct node *create_node(int data, struct node *previous)
{
    struct node *link = (struct node *)malloc(sizeof(struct node));
    link->data = data;
    link->next = previous;
    return link;
}

void traverse(struct node *traverse)
{
    while (traverse != NULL)
    {
        printf("%d\t", traverse->data);
        traverse = traverse->next;
    }
    printf("\n");
};

void cycles_linked_list(struct node *first)
{
    struct node *tortoise = first;
    struct node *hare = first;
    while (hare->next != NULL)
    {
        hare = (hare->next)->next;
        tortoise = tortoise->next;
        if (hare == tortoise)
        {
            printf("cycle detected!!!");
            break;
        }
    }
}

int main()
{
    struct node *last = create_node(9, NULL);
    struct node *second_last = create_node(10, last);
    struct node *third_last = create_node(11, second_last);
    struct node *fourth_last = create_node(12, third_last);
    struct node *fifth_last = create_node(13, fourth_last);
    struct node *sixth_last = create_node(14, fifth_last);
    struct node *seventh_last = create_node(15, sixth_last);
    last->next = sixth_last;

    cycles_linked_list(seventh_last);
}