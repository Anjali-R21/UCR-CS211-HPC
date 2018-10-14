/**
 * CS 211 Project 1 --> 1.Register Reuse --> Part 3
 * This file only includes the function: dgemm3
 */

#include "functions.h"

double dgemm3(int n)
{
    // Definitions
    double* a = NULL;
    double* b = NULL;
    double* c = NULL;

    // init
    init_matrix_randomly(&a, &b, &c, n);

    // the algo
    timespec begin, end;
    clock_gettime(CLOCK_MONOTONIC, &begin);
    
    for (int i = 0; i < n; i += 3)
    {
        for (int j = 0; j < n; j += 3)
        {
            register double c00 = c[i*n + j];
            register double c01 = c[i*n + j+1];
            register double c02 = c[i*n + j+2];
            register double c10 = c[(i+1)*n + j];
            register double c11 = c[(i+1)*n + j+1];
            register double c12 = c[(i+1)*n + j+2];
            register double c20 = c[(i+2)*n + j];
            register double c21 = c[(i+2)*n + j+1];
            register double c22 = c[(i+2)*n + j+2];

            for (int k = 0; k < n; k += 3)
            {
                for (int l = 0; l < 3; l++)
                {
                    register double a0 = a[i*n + k+l];
                    register double a1 = a[(i+1)*n + k+l];
                    register double a2 = a[(i+2)*n + k+l];
                    register double b0 = b[(k+l)*n + j];
                    register double b1 = b[(k+l)*n + j+1];
                    register double b2 = b[(k+l)*n + j+2];

                    c00 += a0 * b0;
                    c01 += a0 * b1;
                    c02 += a0 * b2;
                    c10 += a1 * b0;
                    c11 += a1 * b1;
                    c12 += a1 * b2;
                    c20 += a2 * b0;
                    c21 += a2 * b1;
                    c22 += a2 * b2;
                }
            }
            c[i*n + j] = c00;
            c[i*n + j+1] = c01;
            c[i*n + j+2] = c02;
            c[(i+1)*n + j] = c10;
            c[(i+1)*n + j+1] = c11;
            c[(i+1)*n + j+2] = c12;
            c[(i+2)*n + j] = c20;
            c[(i+2)*n + j+1] = c21;
            c[(i+2)*n + j+2] = c22;
        }
    }
    clock_gettime(CLOCK_MONOTONIC, &end);

    uninit_matrix_with_free(a, b ,c);

    double ret = end.tv_sec - begin.tv_sec + (end.tv_nsec - begin.tv_nsec) / 1e9;
    return ret;
}