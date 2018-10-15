/**
 * CS 211 Project 1 --> 1.Register Reuse --> Part 3
 * This file only includes the main function.
 */

#include "functions.h"
#include <memory.h>
#define REPEAT 1

int main()
{
    // printf("%ld\n", CLOCKS_PER_SEC);
    double t1, t2, t3, t4;
    double sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
    for (int i = 0; i < 6; i++)
    {
        double *a = (double*) malloc(Nsp3[i] * Nsp3[i] * sizeof(double));
        double *b = (double*) malloc(Nsp3[i] * Nsp3[i] * sizeof(double));
        double *c_origin = (double*) malloc(Nsp3[i] * Nsp3[i] * sizeof(double));
        init_matrix_randomly(&a, &b, &c_origin, Nsp3[i]);
        double *c1 = (double*) malloc(Nsp3[i] * Nsp3[i] * sizeof(double));
        double *c2 = (double*) malloc(Nsp3[i] * Nsp3[i] * sizeof(double));
        double *c3 = (double*) malloc(Nsp3[i] * Nsp3[i] * sizeof(double));
        double *c4 = (double*) malloc(Nsp3[i] * Nsp3[i] * sizeof(double));

        for (int j = 0; j < REPEAT; j++)
        {
            memcpy(c1, c_origin, Nsp3[i] * Nsp3[i] * sizeof(double));
            memcpy(c2, c_origin, Nsp3[i] * Nsp3[i] * sizeof(double));
            memcpy(c3, c_origin, Nsp3[i] * Nsp3[i] * sizeof(double));
            memcpy(c4, c_origin, Nsp3[i] * Nsp3[i] * sizeof(double));
            t1 = dgemm0(a, b, c1, Nsp3[i]);
            t2 = dgemm1(a, b, c2, Nsp3[i]);
            t3 = dgemm2(a, b, c3, Nsp3[i]);
            t4 = dgemm3(a, b, c4, Nsp3[i]);
            sum1 += t1;
            sum2 += t2;
            sum3 += t3;
            sum4 += t4;
            bool correct = check_correct(c1, c2, Nsp3[i]);
            correct &= check_correct(c1, c3, Nsp3[i]);
            correct &= check_correct(c1, c4, Nsp3[i]);

            // printf("%lu %lu %lu\n", t1, t2, t3);
            printf("When n=%d, dgemm0: %lf s, dgemm1: %lf s, dgemm2: %lf, dgemm3: %lf, check...%s\n", Nsp3[i], ((double)t1), (double)t2, (double)t3, (double)t4, (correct?"passed":"failed"));
        }
        printf("On average, n=%d, dgemm0: %lf s, dgemm1: %lf s, dgemm2: %lf, dgemm3: %lf\n", Nsp3[i], sum1/REPEAT, sum2/REPEAT, sum3/REPEAT, sum4/REPEAT);
        sum1 = sum2 = sum3 = sum4 = 0;
    }
    return 0;
}