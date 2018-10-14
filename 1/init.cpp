#include "functions.h"

int Ns[] = {64, 128, 256, 512, 1024, 2048};
int Nsp3[] = {66, 132, 258, 516, 1026, 2052};

void init_matrix_randomly(double** a, double** b, double** c, int n)
{
    // Allocation
    // note: n^2
    *a = (double*) malloc(n * n * sizeof(double));
    *b = (double*) malloc(n * n * sizeof(double));
    *c = (double*) malloc(n * n * sizeof(double));
    // printf("allocated\n");

    // Initialize randomly
    int t = n * n;
    for (int i = 0; i < t; i++)
    {
        (*a)[i] = rand() % 50000;
        (*b)[i] = rand() % 50000;
        (*c)[i] = rand() % 50000;
    }
}

void uninit_matrix_with_free(double* a, double* b, double* c)
{
    free(a);
    free(b);
    free(c);
}