#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <memory.h>
#include "functions.h"

double dgemm3_cache(double* a, double* b, double *c, int n, int blocksize)
{
    timespec begin, end;
    clock_gettime(CLOCK_MONOTONIC, &begin);
    for (int i = 0; i < n; i += blocksize) {
        for (int j = 0; j < n; j += blocksize) {
            for (int k = 0; k < n; k += blocksize) {
                int i1 = i, j1 = j, k1 = k;
                int ni = i + blocksize > n ? n : i + blocksize;
                int nj = j + blocksize > n ? n : j + blocksize;
                int nk = k + blocksize > n ? n : k + blocksize;

                for (i1 = i; i1 < ni; i1 += 3) {
                    for (j1 = j; j1 < nj; j1 += 3) {
                        int t = i1 * n + j1;
                        int tt = t + n;
                        int ttt = tt + n;
                        register double c00 = c[t];
                        register double c01 = c[t + 1];
                        register double c02 = c[t + 2];
                        register double c10 = c[tt];
                        register double c11 = c[tt + 1];
                        register double c12 = c[tt + 2];
                        register double c20 = c[ttt];
                        register double c21 = c[ttt + 1];
                        register double c22 = c[ttt + 2];

                        for (k1 = k; k1 < nk; k1 += 3) {
                            for (int l = 0; l < 3; l++) {
                                int ta = i1 * n + k1 + l;
                                int tta = ta + n;
                                int ttta = tta + n;
                                int tb = k1 * n + j1 + l * n;
                                register double a0 = a[ta];
                                register double a1 = a[tta];
                                register double a2 = a[ttta];
                                register double b0 = b[tb];
                                register double b1 = b[tb + 1];
                                register double b2 = b[tb + 2];

                                c00 += a0 * b0;
                                c01 += a0 * b1;
                                c02 += a0 * b2;
                                c10 += a1 * b0;
                                c11 += a1 * b1;
                                c12 += a1 * b2;
                                c20 += a2 * b0;
                                c21 += a2 * b1;
                                c22 += a2 * b2;
                            }
                        }
                        c[t] = c00;
                        c[t + 1] = c01;
                        c[t + 2] = c02;
                        c[tt] = c10;
                        c[tt + 1] = c11;
                        c[tt + 2] = c12;
                        c[ttt] = c20;
                        c[ttt + 1] = c21;
                        c[ttt + 2] = c22;

                    }
                }
            }
        }
    }
    clock_gettime(CLOCK_MONOTONIC, &end);

    double ret = end.tv_sec - begin.tv_sec + (end.tv_nsec - begin.tv_nsec) / 1e9;
    return ret;
}

int main()
{
    int n = 2046;
    int blocksizes[] = {6, 18, 30, 66, 126, 258, 510, 1026};
    int nblocks = sizeof(blocksizes)/sizeof(blocksizes[0]);
    double *a = (double*) malloc(n*n*sizeof(double));
    double *b = (double*) malloc(n*n*sizeof(double));
    double *c_origin = (double*) malloc(n*n*sizeof(double));
    double *cijk = (double*) malloc(n*n*sizeof(double));
    double *cother = (double*) malloc(n*n*sizeof(double));
    init_matrix_randomly(&a, &b, &c_origin, n);

    memcpy(cijk, c_origin, n*n*sizeof(double));
    double tijk = dgemm3_cache(a, b, cijk, n, blocksizes[0]);
    printf("blocksize: %d, time: %lf\n", blocksizes[0], tijk);
    for (int i = 1; i < nblocks; i++)
    {
        memcpy(cother, c_origin, n*n*sizeof(double));
        tijk = dgemm3_cache(a, b, cother, n, blocksizes[i]);
        bool correct = check_correct(cijk, cother, n);
        printf("blocksize: %d, time: %lf, check...%s\n", blocksizes[i], tijk, (correct?"passed":"failed"));
    }
}