#include <stdlib.h>
#include <stdio.h>
#define ASCII_SIZE 256

int main()
{
    int i = 0;
    int max = 0;
    char max_char;
    char *a = "adwaith a kklkkk is here";
    int *s = (int *)calloc(ASCII_SIZE, sizeof(int));

    // scanf("%s", s);

    while (a[i] != '\0')
    {
        i++;
        s[a[i]]++;
        if (s[a[i]] > max)
        {
            max = s[a[i]];
            max_char = a[i];
        }
    }

    printf("max count is %d", max);
    printf("max character is %c", max_char);

    // printf("hai %s", s);
}
