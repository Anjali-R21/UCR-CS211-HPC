/**
 * CS 211 Project 1 --> 1.Register Reuse --> Part 1
 * This file only includes the main function.
 */

#include "functions.h"

int main()
{
    clock_t t1, t2, t3;
    double sum1 = 0, sum2 = 0, sum3 = 0;    // Run 3 times and pick the average time
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // printf("Ns[i]=%d\n", Ns[i]);
            t1 = dgemm0(Ns[i]);
            t2 = dgemm1(Ns[i]);
            t3 = dgemm2(Ns[i]);
            sum1 += t1;
            sum2 += t2;
            sum3 += t3;

            printf("When n=%d, dgemm0: %lf s, dgemm1: %lf s， dgemm2: %lf\n", Ns[i], (double)t1/CLOCKS_PER_SEC, (double)t2/CLOCKS_PER_SEC, (double)t3/CLOCKS_PER_SEC);
        }
        printf("On average, n=%d, dgemm0: %lf s, dgemm1: %lf s, dgemm2: %lf\n", Ns[i], sum1/3/CLOCKS_PER_SEC, sum2/3/CLOCKS_PER_SEC, sum3/3/CLOCKS_PER_SEC);
        sum1 = sum2 = 0;
    }
    return 0;
}