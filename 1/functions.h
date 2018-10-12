#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include <cstdlib>
#include <cstdio>
#include <ctime>

extern int Ns[];

void init_matrix_randomly(double** a, double** b, double** c, int n);
void uninit_matrix_with_free(double* a, double* b, double* c);

clock_t dgemm0(int n);
clock_t dgemm1(int n);


#endif