/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
/**
    Matrix multiplier.

    Reference: https://en.wikipedia.org/wiki/Matrix_multiplication_algorithm

    @file
    @author
    @email
    @date
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
main(){
    
    // initialize empty array for the result with appropriate size
    int result [A_ROWS][B_COLS];
    
    // load input matrices into global arrays A and B
    A.load_data();
    B.load_data();
    
    // matrix multiplication 
    for (int i = 0; i < A_ROWS; i++)
    {
        for(int j = 0; j < B_COLS; j++)
        {
            int sum = 0; 
            for(int k = 0; k < B_ROWS);
            {
                sum += A[i][k] * B[k][j];
            }
            result[i][j] = sum;
        }
    }
    print_matrix(result)
    return;
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
