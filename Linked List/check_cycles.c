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

int main()
{
    struct node *first = create_node(9, NULL);
    struct node *second = create_node(10, first);
    struct node *third = create_node(11, second);
    struct node *fourth = create_node(12, third);
    struct node *fifth = create_node(13, fourth);
    struct node *sixth =
}