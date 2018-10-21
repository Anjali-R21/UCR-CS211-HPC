#include <stdio.h>
#include <stdlib.h>
#include <lapacke.h>
#include <time.h>
#include <memory.h>
#include <math.h>
#include <cblas.h>

int main(int argc, const char** argv)
{
    #ifdef PART_ONE
    int Ns[] = {1000, 2000, 3000, 4000, 5000};
    #endif
    int Nsize = 5;

    int i;
    for (i = 0; i < Nsize; i++)
    {
        // Initialization of matrixes
        printf("n=%d...\n", Ns[i]);
        double *A_lapack, *B_lapack;
        double *A_fq, *B_fq;
        double *A_fq_block, *B_fq_block;
        A_lapack = (double*) malloc(sizeof(double) * Ns[i] * Ns[i]);    // col_major
        A_fq = (double*) malloc(sizeof(double) * Ns[i] * Ns[i]);        // row_major
        A_fq_block = (double*) malloc(sizeof(double) * Ns[i] * Ns[i]);  // row_major
        B_lapack = (double*) malloc(sizeof(double) * Ns[i]);
        B_fq = (double*) malloc(sizeof(double) * Ns[i]);
        B_fq_block = (double*) malloc(sizeof(double) * Ns[i]);

        int _i, _j;
        for (_i = 0; _i < Ns[i]; _i++)
        {
            for (_j = 0; _j < Ns[i]; _j++)
            {
                A_lapack[_j*Ns[i] + _i] = A_fq[_i*Ns[i] + _j] = A_fq_block[_i*Ns[i] + _j] = (double) (abs(rand()) % 10000);
            }
            B_lapack[_i] = B_fq[_i] = B_fq_block[_i] = (double) (abs(rand()) % 10000);
        }

        /**********************************
         * LAPACK VERSION
         */
        printf("Lapack calculating...");
        struct timespec begin, end;
        clock_gettime(CLOCK_MONOTONIC, &begin);

        // LU factorization with partial pivoting (LUP)
        int info;
        int lda = Ns[i];
        int ldb = Ns[i];
        int *ipiv = (int*) malloc(sizeof(int) * Ns[i]);
        LAPACKE_dgetrf(LAPACK_COL_MAJOR, Ns[i], Ns[i], A_lapack, lda, ipiv);

        // Apply IPIV array to B
        for (_i = 0; _i < Ns[i]; _i++)
        {
            double t = B_lapack[ipiv[_i] - 1];
            B_lapack[ipiv[_i] - 1] = B_lapack[_i];
            B_lapack[_i] = t;
        }

        // forward substitution
        cblas_dtrsm(CblasColMajor, CblasLeft, CblasLower, CblasNoTrans, CblasUnit, Ns[i], 1, 1.0, A_lapack, lda, B_lapack, ldb);
        // backward substitution
        cblas_dtrsm(CblasColMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit, Ns[i], 1, 1.0, A_lapack, lda, B_lapack, ldb);

        clock_gettime(CLOCK_MONOTONIC, &end);
        double _time = end.tv_sec - begin.tv_sec + (end.tv_nsec - begin.tv_nsec) / 1e9;
        printf("%lf s\n", _time);
    }
}