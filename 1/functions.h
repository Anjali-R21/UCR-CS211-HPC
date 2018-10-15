#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include <cstdlib>
#include <cstdio>
#include <ctime>

extern int Ns[];
extern int Nsp3[];

void init_matrix_randomly(double** a, double** b, double** c, int n);
void uninit_matrix_with_free(double* a, double* b, double* c);

bool check_correct(double* a, double* b, int n);

double dgemm0(double* a, double* b, double* c, int n);
double dgemm1(double* a, double* b, double* c, int n);
double dgemm2(double* a, double* b, double* c, int n);
double dgemm3(double* a, double* b, double* c, int n);
double dgemm3_cache(double* a, double* b, double *c, int n, int blocksize);

#endif