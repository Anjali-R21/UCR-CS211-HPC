/**
 * CS 211 Project 1 --> 1.Register Reuse --> Part 1
 * This file only includes the main function.
 */

#include "functions.h"
#include <memory.h>
#define REPEAT 1

int main()
{
    double t1, t2, t3;
    double sum1 = 0, sum2 = 0, sum3 = 0;    

    for (int i = 0; i < 6; i++)
    {
        double *a = (double*) malloc(Ns[i] * Ns[i] * sizeof(double));
        double *b = (double*) malloc(Ns[i] * Ns[i] * sizeof(double));
        double *c_origin = (double*) malloc(Ns[i] * Ns[i] * sizeof(double));
        init_matrix_randomly(&a, &b, &c_origin, Ns[i]);
        double *c1 = (double*) malloc(Ns[i] * Ns[i] * sizeof(double));
        double *c2 = (double*) malloc(Ns[i] * Ns[i] * sizeof(double));
        double *c3 = (double*) malloc(Ns[i] * Ns[i] * sizeof(double));

        for (int j = 0; j < REPEAT; j++)
        {
            memcpy(c1, c_origin, Ns[i] * Ns[i] * sizeof(double));
            memcpy(c2, c_origin, Ns[i] * Ns[i] * sizeof(double));
            memcpy(c3, c_origin, Ns[i] * Ns[i] * sizeof(double));
            t1 = dgemm0(a, b, c1, Ns[i]);
            t2 = dgemm1(a, b, c2, Ns[i]);
            t3 = dgemm2(a, b, c3, Ns[i]);
            sum1 += t1;
            sum2 += t2;
            sum3 += t3;
            bool correct = check_correct(c1, c2, Ns[i]);
            correct &= check_correct(c1, c3, Ns[i]);

            printf("When n=%d, dgemm0: %lf s, dgemm1: %lf s, dgemm2: %lf, check...%s\n", Ns[i], (double)t1, (double)t2, (double)t3, (correct?"passed":"failed"));
        }
        printf("On average, n=%d, dgemm0: %lf s, dgemm1: %lf s, dgemm2: %lf\n", Ns[i], sum1/REPEAT, sum2/REPEAT, sum3/REPEAT);
        sum1 = sum2 = sum3 = 0;
    }
    return 0;
}