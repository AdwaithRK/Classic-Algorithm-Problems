#include <stdio.h>
#include <stdlib.h>
#define ASCII_SIZE 256
int main()
{
    char string[50];
    char character_order[50];
    int *hash_map = (int *)calloc(ASCII_SIZE, (sizeof(char)));
    int i = 0;
    int count = 0;

    scanf("%s", string);

    printf("\nthe string scanned is %s\n", string);

    while (string[i] != '\0')
    {
        if (i == 0 || string[i] != string[i - 1])
        {
            character_order[count] = string[i];
            count++;
        }
        hash_map[string[i]]++;
        i++;
    }

    for (i = 0; i < count; i++)
    {
        printf("%c%d", character_order[i], hash_map[character_order[i]]);
    }
}