/**
    Source code for helper functions.

    @file helper.c
    @author Jennifer Hellar
    @email jennifer.hellar@rice.edu
    @date 04/07/2021
*/

#include "helper.h"

/*
 * Prints a formatted 2D array of fixed size ROWS x COLS
 */
void print_matrix(float a[ROWS][COLS])
{
    int i, j, k;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("%f", a[i][j]);
            if ((i != ROWS-1) || (j != COLS-1))
                printf(",\t");
        }
        printf("\n");
    }
}
