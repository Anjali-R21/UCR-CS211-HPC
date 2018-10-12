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
        t1 = dgemm0(Ns[i]);
        t2 = dgemm1(Ns[i]);

        printf("When n=%d, dgemm0 takes %ul seconds, dgemm1 takes %ul seconds\n");
    }
    return 0;
}