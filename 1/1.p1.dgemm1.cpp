/**
 * CS 211 Project 1 --> 1.Register Reuse --> Part 1
 * This file only include the function: dgemm1
 */

#include "functions.h"

clock_t dgemm1(int n)
{
    // Definitions
    double* a = NULL;
    double* b = NULL;
    double* c = NULL;

    // init
    init_matrix_randomly(&a, &b, &c, n);

    // the algo
    clock_t begin = clock();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            register double r = c[i * n + j];
            for (int k = 0; k < n; k++)
                r += a[i * n + k] * b[k * n + j];
            c[i * n + j] = r;
        }
    }
    clock_t end = clock();

    uninit_matrix_with_free(a, b ,c);

    return end - begin;
}