/**
 * CS 211 Project 1 --> 1.Register Reuse --> Part 1
 * This file only includes the main function.
 */

#include "functions.h"

int main()
{
    clock_t t1, t2;
    for (int i = 0; i < 6; i++)
    {
        // printf("Ns[i]=%d\n", Ns[i]);
        t1 = dgemm0(Ns[i]);
        t2 = dgemm1(Ns[i]);

        printf("When n=%d, dgemm0 takes %lu seconds, dgemm1 takes %lu seconds\n", Ns[i], t1/1000, t2/1000);
    }
    return 0;
}