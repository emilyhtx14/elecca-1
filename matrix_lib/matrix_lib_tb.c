/**
    Matrix library testbench.

    @file matrix_lib_tb.c
    @author
    @email
    @date
*/

#include "matrix.h"     // matrix library and includes helper
                        // ROWS, COLS defined in helper.h

/************************************************
 *  main
 ***********************************************/

int main(void)
{
// conditionally compiles this section of code
#if ((ROWS == 4) && (COLS == 4))
    float A[ROWS][COLS] = {{1, 0, 1, -7},
                           {1, 3, 0, 0},
                           {0, 2, -1, 4},
                           {0, 1, 0, -1}};
    float B[ROWS][COLS] = {{3, -2, 3, 0},
                           {-1, 1, -1, 0},
                           {-2, 2, -3, 1},
                           {0, 6, -2, 2}};
    float C[ROWS][COLS] = {{-1, 0, -1, 7},
                           {-1, -3, 0, 0},
                           {0, -2, 1, -4},
                           {0, -1, 0, 1}};
// otherwise conditionally compiles this section
#elif ((ROWS == 2) && (COLS == 2))
    float A[ROWS][COLS] = {{1, 0}, {1, 3}};
    float B[ROWS][COLS] = {{3, -2}, {-1, 1}};
    float C[ROWS][COLS] = {{-1, 0}, {-1, -3}};
    float D[ROWS][COLS] = {{1, 1}, {1, 0}};
// otherwise we need to define more data before compiling/executing
#else
    printf("No data provided for the requested dimensions.");
    exit()
#endif

    /* Uncomment test cases below as you complete the functions */

    //r0 = identity matrix
    float r0[ROWS][COLS];
    matrix_identity(r0);
    printf("\nI =\n");
    print_matrix(r0);

    // r1 = is_equal(A, C)
    int r1 = matrix_is_equal(A, C);
    printf("\nis_equal(A, C) =\n%i\n", r1);

    // r2 = max(A)
    float r2 = matrix_max(A);
    printf("\nmax(A) =\n%f\n", r2);

    // r3 = A + C
    float r3[ROWS][COLS];
    matrix_add(r3, A, C);
    printf("\nA + C =\n");
    print_matrix(r3);

    // r4 = 2 * A
    float r4[ROWS][COLS];
    matrix_scale(r4, A, (float) 2);
    printf("\n2 * A =\n");
    print_matrix(r4);

    // r5 = A - C
    float r5[ROWS][COLS];
    matrix_sub(r5, A, C);
    printf("\nA - C =\n");
    print_matrix(r5);

    // r6 = is_equal(A - C, 2 * A)
    int r6 = matrix_is_equal(r4, r5);
    printf("\nis_equal(A - C, 2 * A) =\n%i\n", r6);

    // r7 = A * B
    float r7[ROWS][COLS];
    matrix_mul(r7, A, B);
    printf("\nA * B =\n");
    print_matrix(r7);

    // r8 = dot product of A and C
    float r8 = matrix_dot(A, C);
    printf("\ndot product of A and C =\n%f\n", r8);

    // r9 = transpose(B)
    float r9[COLS][ROWS];
    matrix_transpose(r9, B);
    printf("\ntranspose(B) =\n");
    print_matrix(r9);

    // r10 = normalized(A)
    float r10[ROWS][COLS];
    matrix_norm(r10, A);
    printf("\nnormalized(A) =\n");
    print_matrix(r10);
// only test the matrix inverse for the 2x2 case
#if ((ROWS == 2) && (COLS == 2))
    // r11 = inv(D)
    float r11[ROWS][COLS];
    matrix_inverse(r11, D);
    printf("\ninv(D) =\n");
    print_matrix(r11);

    // r12 = D * inv(D)
    float r12[ROWS][COLS];
    matrix_mul(r12, D, r11);
    printf("\nD * inv(D) = \n");
    print_matrix(r12);

    // r13 = is_equal(D*inv(D), I)
    float I[ROWS][COLS];
    matrix_identity(I);
    int r13 = matrix_is_equal(I, r12);
    printf("\nis_equal(D*inv(D), I) =\n%i\n", r13);
#endif

    return 0;
}
