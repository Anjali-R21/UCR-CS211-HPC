/**
 * CS 211 Project 1 --> 1.Register Reuse --> Part 2
 * This file only includes the function: dgemm2
 */

#include "functions.h"

clock_t dgemm2(int n)
{
    // Definitions
    double* a = NULL;
    double* b = NULL;
    double* c = NULL;

    // init
    init_matrix_randomly(&a, &b, &c, n);

    // the algo
    clock_t begin = clock();
    for (int i = 0; i < n; i += 2)
    {
        for (int j = 0; j < n; j += 2)
        {
            // define register variables for c matrix
            register double c00 = c[i*n + j];
            register double c01 = c[i*n + j+1];
            register double c10 = c[(i+1)*n + j];
            register double c11 = c[(i+1)*n + j+1];

            for (int k = 0; k < n; k += 2)
            {
                // define register variables for a, b matrix
                register double a00 = a[i*n + k];
                register double a01 = a[i*n + k+1];
                register double a10 = a[(i+1)*n + k];
                register double a11 = a[(i+1)*n + k+1];
                register double b00 = b[k*n + j];
                register double b01 = b[k*n + j+1];
                register double b10 = b[(k+1)*n + j];
                register double b11 = b[(k+1)*n + j+1];

                // compute
                c00 += a00 * b00 + a01 * b10;
                c01 += a00 * b01 + a01 * b11;
                c10 += a10 * b00 + a11 * b10;
                c11 += a10 * b01 + a11 * b11;
            }

            // store c from register to memory
            c[i*n + j] = c00;
            c[i*n + j+1] = c01;
            c[(i+1)*n + j] = c10;
            c[(i+1)*n + j+1] = c11;
        }
    }
    clock_t end = clock();

    uninit_matrix_with_free(a, b ,c);

    return end - begin;
}