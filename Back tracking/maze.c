#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char *append_coordinates(char *path_string, int x, int y)
{
    char co_ordinates[6];
    sprintf(co_ordinates, "%c%d,%d%c", '(', x, y, ')');
    strcat(path_string, co_ordinates);
    printf("%s", path_string);
    return path_string;
}

bool is_safe(char path[10][10], int start_X, int start_Y, int n)
{
    if (start_X < n && start_Y < n)
    {
        return true;
    }
    else if (path[start_X][start_Y] == '0')
    {
        return true;
    }
    return false;
}

void explore_path(char path[10][10], int start_X, int start_Y, char *found_T, int n)
{
    if (path[start_X][start_Y] == 'x')
    {
        printf("path towards X is!!!! : %s\n\n", found_T);
        return;
    }

    if (path[start_X][start_Y] == '0')
    {
        path[start_X][start_Y] = '1';
        if (is_safe(path, start_X + 1, start_Y, n))
        {
            char path_a[100];
            strcpy(path_a, found_T);
            append_coordinates(path_a, start_X + 1, start_Y);
            printf("\n..visiting (%d, %d)..\n", start_X + 1, start_Y);
            explore_path(path, start_X + 1, start_Y, path_a, n);
        }

        if (is_safe(path, start_X, start_Y + 1, n))
        {
            char path_b[100];
            strcpy(path_b, found_T);
            append_coordinates(path_b, start_X, start_Y + 1);
            printf("\n..visiting (%d, %d)..\n", start_X, start_Y + 1);

            explore_path(path, start_X, start_Y + 1, path_b, n);
        }

        if (is_safe(path, start_X - 1, start_Y, n))
        {
            char path_c[100];
            strcpy(path_c, found_T);
            append_coordinates(path_c, start_X - 1, start_Y);
            printf("\n..visiting (%d, %d)..\n", start_X - 1, start_Y);
            explore_path(path, start_X - 1, start_Y, path_c, n);
        }

        if (is_safe(path, start_X, start_Y - 1, n))
        {
            char path_d[100];
            strcpy(path_d, found_T);
            append_coordinates(path_d, start_X, start_Y - 1);
            printf("\n..visiting (%d, %d)..\n", start_X, start_Y - 1);
            explore_path(path, start_X, start_Y - 1, path_d, n);
        }
    }
}

int main()
{
    char path[10][10] = {
        {'0', '1', '1', '1', '1', '1', '0', '1', '1', '1'},
        {'0', '0', '0', '0', '0', '0', '0', '0', '1', '1'},
        {'0', '0', '1', '0', '1', '1', '1', '0', '1', '1'},
        {'1', '0', '1', '0', '1', '1', '1', '0', '1', '1'},
        {'1', '0', '1', '0', '0', '1', '1', '0', '1', '1'},
        {'1', '0', '1', '0', '0', '1', '1', '0', '1', '1'},
        {'1', '0', '1', '0', '0', '1', '1', '0', '0', '1'},
        {'1', '0', '1', '0', '0', '1', '1', '1', '0', '1'},
        {'1', '0', '1', '0', '0', '1', '1', '1', '0', '1'},
        {'1', '0', '0', '0', 'x', '0', '0', '0', '0', '1'}};

    char a[100];

    explore_path(path, 0, 0, a, 10);

    return 0;
}