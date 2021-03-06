/**
 * CS 211 Project 1 --> 1.Register Reuse --> Part 1
 * This file only include the function: dgemm1
 */

#include "functions.h"

double dgemm1(double* a, double* b, double* c, int n)
{
    // the algo
    timespec begin, end;
    clock_gettime(CLOCK_MONOTONIC, &begin);
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
    clock_gettime(CLOCK_MONOTONIC, &end);

    double ret = end.tv_sec - begin.tv_sec + (end.tv_nsec - begin.tv_nsec) / 1e9;
    return ret;
}