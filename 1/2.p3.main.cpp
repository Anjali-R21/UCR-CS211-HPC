#include "functions.h"
#include "2.algo.h"
#include <memory.h>

int main()
{
    int n = 2048;
    int blocksizes[] = {16, 32, 64, 128, 256, 512, 1024};
    double *a, *b, *c_origin;
    init_matrix_randomly(&a, &b, &c_origin, n);
    double *cijk, *cother;
    cijk = (double*) malloc(n * n * sizeof(double));
    cother = (double*) malloc(n * n * sizeof(double));
    // double *cijk, *cjik, *cikj, *ckij, *cjki, *ckji;
    // double *cijk_block, *cjik_block, *cikj_block, *ckij_block, *cjki_block, *ckji_block;
    double tijk, tjik, tikj, tkij, tjki, tkji;
    double tijk_block, tjik_block, tikj_block, tkij_block, tjki_block, tkji_block;

    // w/o block vs w/ block
    printf("w/o block vs w/ block.......\n");
    n = 1000;
    int blocksize = 10;
    // ijk
    memcpy(cijk, c_origin, n*n*sizeof(double));
    tijk = ijk(a, b, cijk, n);
    memcpy(cother, c_origin, n*n*sizeof(double));
    tijk_block = ijk_block(a, b, cother, n, blocksize);
    bool correct = check_correct(cijk, cother, n);
    printf("ijk   w/o block: %lf, w/ block: %lf, check...%s\n", tijk, tijk_block, (correct?"passed":"failed"));
    correct = true;

    // jik
    memcpy(cother, c_origin, n*n*sizeof(double));
    tjik = jik(a, b, cother, n);
    correct &= check_correct(cijk, cother, n);
    memcpy(cother, c_origin, n*n*sizeof(double));
    tjik_block = jik_block(a, b, cother, n, blocksize);
    correct &= check_correct(cijk, cother, n);
    printf("jik   w/o block: %lf, w/ block: %lf, check...%s\n", tjik, tjik_block, (correct?"passed":"failed"));
    correct = true;

    // kij
    memcpy(cother, c_origin, n*n*sizeof(double));
    tkij = kij(a, b, cother, n);
    correct &= check_correct(cijk, cother, n);
    memcpy(cother, c_origin, n*n*sizeof(double));
    tkij_block = kij_block(a, b, cother, n, blocksize);
    correct &= check_correct(cijk, cother, n);
    printf("kij   w/o block: %lf, w/ block: %lf, check...%s\n", tkij, tkij_block, (correct?"passed":"failed"));
    correct = true;

    // ikj
    memcpy(cother, c_origin, n*n*sizeof(double));
    tikj = ikj(a, b, cother, n);
    correct &= check_correct(cijk, cother, n);
    memcpy(cother, c_origin, n*n*sizeof(double));
    tikj_block = ikj_block(a, b, cother, n, blocksize);
    correct &= check_correct(cijk, cother, n);
    printf("ikj   w/o block: %lf, w/ block: %lf, check...%s\n", tikj, tikj_block, (correct?"passed":"failed"));
    correct = true;

    // jki
    memcpy(cother, c_origin, n*n*sizeof(double));
    tjki = jki(a, b, cother, n);
    correct &= check_correct(cijk, cother, n);
    memcpy(cother, c_origin, n*n*sizeof(double));
    tjki_block = jki_block(a, b, cother, n, blocksize);
    correct &= check_correct(cijk, cother, n);
    printf("jki   w/o block: %lf, w/ block: %lf, check...%s\n", tjki, tjki_block, (correct?"passed":"failed"));
    correct = true;

    // kji
    memcpy(cother, c_origin, n*n*sizeof(double));
    tkji = kji(a, b, cother, n);
    correct &= check_correct(cijk, cother, n);
    memcpy(cother, c_origin, n*n*sizeof(double));
    tkji_block = kji_block(a, b, cother, n, blocksize);
    correct &= check_correct(cijk, cother, n);
    printf("kji   w/o block: %lf, w/ block: %lf, check...%s\n", tkji, tkji_block, (correct?"passed":"failed"));
    correct = true;

    // different block size, using ijk
    n = 2048;
    int nblocks = sizeof(blocksizes)/sizeof(blocksizes[0]);
    printf("Different block size.....\n");
    for (int i = 0; i < nblocks; i++)
    {
        memcpy(cother, c_origin, n*n*sizeof(double));
        tijk = ijk_block(a, b, cother, n, blocksizes[i]);
        correct &= check_correct(cijk, cother, n);
        printf("blocksize: %d, time: %lf\n", blocksizes[i], tijk);
    }

    // finalize
    uninit_matrix_with_free(a, b, c_origin);
    free(cijk);
    free(cother);
    return 0;
}
