#include <stdio.h>

void insert_element(int *heap, int *heap_size, int element)
{
    int temp_heap_size = *heap_size;
    heap[temp_heap_size] = element;
    int now = temp_heap_size;
    temp_heap_size++;
    int temp;

    while (heap[now / 2] > heap[now])
    {
        temp = heap[now / 2];
        heap[now / 2] = heap[now];
        heap[now] = temp;
        now = now / 2;
    }

    *heap_size = temp_heap_size;
}

int delete_element(int *heap, int *heap_size)
{
    int deleted_element = heap[0];
    heap[0] = heap[*heap_size - 1];
    (*heap_size)--;
    int now = 0, min = 0, change = 1;
    while (now < *heap_size && change == 1)
    {
        change = 0;
        if (heap[2 * now + 1] < heap[now])
        {
            min = 2 * now + 1;
            change = 1;
        }

        if (heap[2 * now + 2] < heap[min])
        {
            min = 2 * now + 2;
            change = 1;
        }

        if (change == 1)
        {
            int temp = heap[min];
            heap[min] = heap[now];
            heap[now] = temp;
            now = min;
        }
    }

    return deleted_element;
}

int main()
{
    int heap[] = {8, 10, 19, 11, 12, 20, 30, 99, 100, 84, 81, 21, 39, 40, 45};

    int n_elements = sizeof(heap) / sizeof(heap[0]);

    int deleted_ele = delete_element(heap, &n_elements);

    printf("\n\nThe deleted element is :%d \n\n", deleted_ele);

    for (int i = 0; i < n_elements; i++)
    {
        printf("%d\t", heap[i]);
    }

    return 0;
}