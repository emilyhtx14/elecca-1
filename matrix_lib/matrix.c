/**
    Source code for matrix computational library.

    @file matrix.c
    @author
    @email
    @date
*/

#include "matrix.h"

/* Matrix multiply: res = a * b
 *  res, a, b are fixed-size square arrays
 */
void matrix_mul(float res[ROWS][COLS], float a[ROWS][COLS], float b[ROWS][COLS])
{
    if (ROWS != COLS)
    {
        printf("Incompatible matrix dimensions. Unable to perform multiplication.\n");
        return;
    }

    int i, j, k;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            // each elem of res is the dot product of row i of A
            // with column j of B
            res[i][j] = 0;
            for (k = 0; k < COLS; k++)
            {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void matrix_identity(float res[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            // set to 1 on the diagonal
            if (i == j)
            {
                res[i][j] = 1;
            }
            // set to 0 on everywhere other than the digonal
            else{
                res[i][j] = 0;
            }
        }
    }
}

int matrix_is_equal(float a[ROWS][COLS], float b[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            // returns 0 the first instance the matrix index
            // values don't equal
            if (a[i][j] != b[i][j])
            {
                return 0;
            }
        }
    }
    return 1;
}

float matrix_max(float a[ROWS][COLS])
{
    // set the max to upper left most value in matrix
    float max = a[0][0];
    float current_value;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            // checks if the current value is greater than the max
            current_value = a[i][j];
            if (current_value > max)
            {
                max = current_value;
            }
        }
    }
    return max;
}

void matrix_add(float res[ROWS][COLS], float a[ROWS][COLS], float b[ROWS][COLS])
{
    float a_value = 0.0;
    float b_value = 0.0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            // adds the a and b values in the appropriate indices and 
            // stores in the result array
            a_value = a[i][j];
            // printf("a_value: %f\n",a_value);
            
            b_value = b[i][j];
            // printf("b_value: %f\n",b_value);
            
            res[i][j] = a_value + b_value;
        }
    }
}

void matrix_scale(float res[ROWS][COLS], float a[ROWS][COLS], float c)
{
    printf("c_value: %f\n",c);
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            // multiplies each term by the scalar
            res[i][j] =  a[i][j] * c;
        }
    }
}

void matrix_sub(float res[ROWS][COLS], float a[ROWS][COLS], float b[ROWS][COLS])
{
    
    // makes every term in b the opposite sign and assigns it 
    // to the result matrix
    matrix_scale(res, b, -1);
    
    // adds the a matrix to the b matrix
    matrix_add(res, a, res);
}

float matrix_dot(float a[ROWS][COLS], float b[ROWS][COLS])
{
    float sum = 0.0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            // adds pointwise product to sum
            sum +=  a[i][j] * b[i][j];
        }
    }
    
    return sum;
}

void matrix_transpose(float res[ROWS][COLS], float a[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            // switches the rows and columns before assignment
            res[i][j] = a[j][i];
        }
    }
}

void matrix_norm(float res[ROWS][COLS], float a[ROWS][COLS])
{
    // norm calculation
    float current_value = 0.0;
    float sum = 0.0;
    float norm = 0.0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            
            current_value = a[i][j];
            // sum of the squares of each term in a
            sum += current_value * current_value;
        }
    }
    
    // norm is the sqrt of the sum of the squares of each term in a
    norm = sqrt(sum);
    
    // multiple a by inverse of norm to get the frobenius norm
    matrix_scale(res, a, 1/norm);
}

void matrix_inverse(float res[ROWS][COLS], float a[ROWS][COLS])
{
    // compute determinant of 2x2 matrix
    float a_1 = a[0][0];
    float a_2 = a[1][1];
    float a_3 = a[0][1];
    float a_4 = a[1][0];
    
    float determinant = (a[0][0] * a[1][1]) - (a[0][1] * a[1][0]);

    // switch terms in matrix
    res[0][0] = a_2;
    res[0][1] = -a_4;
    res[1][0] = -a_3;
    res[1][1] = a_1;
    
    // multiple by inverse of determinant
    matrix_scale(res, res, 1/determinant);
}

