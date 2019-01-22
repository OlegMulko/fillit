#include "fillit.h"

void    print_int(int *arr)
{
    if (!arr)
        return;
    int i;
    int j;

    i = -1;
    j = 1;
    while (++i <= 3)
        printf("NUMBER = %d x = %d y = %d\n", j++, arr[i * 2], arr[i * 2 + 1]);
}

void    print_tetrimins_list(int **shapes, int count)
{
    int minx;
    int min;
    int maxx;
    int maxy;
    int i;
    int j;
    int k;

    i = -1;
    minx = 0;
    maxx = 0;
    maxy = 0;
    printf("\n");
    if (!shapes)
    {
        printf("SHAPES == NULL");
        return;
    }
    while (++i < count)
    {
        printf("\n");
        j = -1;
        while (++j <= 3)
        {
            if (shapes[i][j * 2] < minx)
                minx = shapes[i][j * 2];
            if (shapes[i][j * 2] > maxx)
                maxx = shapes[i][j * 2];
            if (shapes[i][j * 2 + 1] > maxy)
                maxy = shapes[i][j * 2 + 1];
        }
        j = 0;
        k = -1;
        while (++k <= maxy)
        {
            min = minx;
            while (min <= maxx && j <= 3)
            {
                if (min == shapes[i][j * 2] && k == shapes[i][j * 2 + 1])
                {
                    printf("#");
                    j++;
                }
                else
                    printf(" ");
                min++;
            }
            printf("\n");
        }
    }
}