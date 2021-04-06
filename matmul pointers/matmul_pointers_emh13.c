/**
    Matrix multiplier.

    Reference: https://en.wikipedia.org/wiki/Matrix_multiplication_algorithm

    @file matmul_pointers_emh13.c
    @author Emily Huang
    @email emh13@rice.edu
    @date 04/06/2021
*/

// standard libraries
#include <stdio.h>
#include <stdlib.h>

// user-defined file
#include "constants.h"


/************************************************
 *  global variables
 ***********************************************/

int A[A_ROWS][A_COLS];
int B[B_ROWS][B_COLS];


/************************************************
 *  function prototypes
 ***********************************************/

void load_data(void);
void print_matrix(int mat[A_ROWS][B_COLS]);


/************************************************
 *  main
 ***********************************************/
 
// points to the base address of a 2D array
// the pointers are of a 1D array type, pointing to the 
// a 1D array with the # of elements = # of columns in 2D array





// initializes final result array
int res [A_ROWS][B_COLS];

// declares and initializes pointer
int *ptr_res = &res[0][0]; 
int *ptr_a = &A[0][0]; 
int *ptr_b = &B[0][0]; 


int main(void)
{
    load_data();                // load input matrices from files

    int i, j, k;
    int sum;

    for (i = 0; i < A_ROWS; i++)
    {
        for (j = 0; j < B_COLS; j++)
        {
            // each elem of res is the dot product of row i of A
            // with column j of B
            sum = 0;
            int a_value;
            int b_value;
            for (k = 0; k < A_COLS; k++)
            {
                // add initial pointer value
                // cols*i adds row indices
                // k and/or j adds the column indices
                a_value =  *(ptr_a + A_COLS*i + k);
                b_value = *(ptr_b + B_COLS*k + j);
                sum += a_value * b_value;
            }
            
            // assign value to final result matrix
            *(ptr_res + i*B_COLS + j) = sum;
            
        }
    }
    print_matrix(res);
    return 0;
}


/************************************************
 *  loads input matrices from file system
 ***********************************************/

void load_data(void)
{
    FILE *fptr;
    int i, j;

    printf("Scanning a.txt... ");
    fptr = fopen("a.txt", "r");     // opens file for reading
    if (fptr == NULL)               // checks for error opening file
    {
        printf("Error opening a.txt");
        exit(1);
    }

    for (i = 0; i < A_ROWS; i++)
    {
        for (j = 0; j < A_COLS; j++)
        {
            // reads formatted data (integer) and stores to location in matrix
            fscanf(fptr, "%i", &A[i][j]);
        }
    }
    fclose(fptr);                   // closes file

    printf("Success\nScanning b.txt... ");
    fptr = fopen("b.txt", "r");     // opens file for reading
    if (fptr == NULL)               // checks for error opening file
    {
        printf("Error opening b.txt");
        exit(1);
    }

    for (i = 0; i < B_ROWS; i++)
    {
        for (j = 0; j < B_COLS; j++)
        {
            // reads formatted data (integer) and stores to location in matrix
            fscanf(fptr, "%i", &B[i][j]);
        }
    }
    fclose(fptr);                   // closes file

    printf("Success\n\n");

    return;
}


/************************************************
 *  prints a nicely formatted matrix
 ***********************************************/

void print_matrix(int mat[A_ROWS][B_COLS])
{
    int i, j;

    printf("Result:\n");
    for (i = 0; i < A_ROWS; i++)
    {
        for (j = 0; j < B_COLS; j++)
        {
            if ((i == A_ROWS-1) && (j == B_COLS-1))
                printf("%i", mat[i][j]);
            else
                printf("%i,\t", mat[i][j]);
        }
        printf("\n");
    }
    return;
}
