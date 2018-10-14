/**
 * CS 211 Project 1 --> 1.Register Reuse --> Part 1
 * This file only include the function: dgemm0
 */

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "functions.h"

// simple ijk version triple loop algorithm
double dgemm0(int n)
{
    // Definitions
    double* a = NULL;
    double* b = NULL;
    double* c = NULL;

    // init
    init_matrix_randomly(&a, &b, &c, n);
    // printf("Inited0.\n");
    // printf("(0,0)=%lf\n", a[0]);
    
    // The algo
    timespec begin, end;
    clock_gettime(CLOCK_MONOTONIC, &begin);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                c[i * n + j] += a[i * n + k] * b[k * n + j];
    clock_gettime(CLOCK_MONOTONIC, &end);
    // printf("computed0\n");

    uninit_matrix_with_free(a, b ,c);

    double ret = end.tv_sec - begin.tv_sec + (double)(end.tv_nsec - begin.tv_nsec) / 1e9;
    return ret;
}