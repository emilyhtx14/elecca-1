/**
    Header file for helper functions.

    @file helper.h
    @author Jennifer Hellar
    @email jennifer.hellar@rice.edu
    @date 04/07/2021
*/

#ifndef HELPER_H
#define HELPER_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>           // for sqrt()

// Matrix dimensions
#define ROWS        4       // change these to 2 for matrix inverse case
#define COLS        4

/*
 * Prints a formatted 2D array of fixed size ROWS x COLS
 */
void print_matrix(float a[ROWS][COLS]);

#endif  // HELPER_H
