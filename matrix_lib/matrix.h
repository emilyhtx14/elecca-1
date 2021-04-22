/**
    Header file for matrix computational library.

    @file
    @author
    @email
    @date
*/

#ifndef MATRIX_H
#define MATRIX_H

#include "helper.h"     // defines ROWS, COLS

/* Matrix multiply: res = a * b
 *  res, a, b are fixed-size square arrays of dimension ROWS x COLS
 */
void matrix_mul(float res[ROWS][COLS], float a[ROWS][COLS], float b[ROWS][COLS]);
void matrix_identity(float res[ROWS][COLS]);
int matrix_is_equal(float a[ROWS][COLS], float b[ROWS][COLS]);
float matrix_max(float a[ROWS][COLS]);
void matrix_add(float res[ROWS][COLS], float a[ROWS][COLS], float b[ROWS][COLS]);
void matrix_scale(float res[ROWS][COLS], float a[ROWS][COLS], float c);
void matrix_sub(float res[ROWS][COLS], float a[ROWS][COLS], float b[ROWS][COLS]);
void matrix_mul(float res[ROWS][COLS], float a[ROWS][COLS], float b[ROWS][COLS]);
float matrix_dot(float a[ROWS][COLS], float b[ROWS][COLS]);
void matrix_transpose(float res[ROWS][COLS], float a[ROWS][COLS]);
void matrix_norm(float res[ROWS][COLS], float a[ROWS][COLS]);
void matrix_inverse(float res[ROWS][COLS], float a[ROWS][COLS]);

#endif  // MATRIX_H
