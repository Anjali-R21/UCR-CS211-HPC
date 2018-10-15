#include "functions.h"
#include "2.algo.h"


double ijk(double* a, double* b, double* c, int n)
{
    timespec begin, end;
    clock_gettime(CLOCK_MONOTONIC, &begin);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            register double r = c[i * n + j];
            for (int k = 0; k < n; k++) {
                r += a[i * n + k] * b[k * n + j];
            }
            c[i * n + j] = r;
        }
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    double ret = end.tv_sec - begin.tv_sec + (end.tv_nsec - begin.tv_nsec) / 1e9;
    return ret;
}

double jik(double* a, double* b, double* c, int n)
{
    timespec begin, end;
    clock_gettime(CLOCK_MONOTONIC, &begin);
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            register double r = c[i * n + j];
            for (int k = 0; k < n; k++) {
                r += a[i * n + k] * b[k * n + j];
            }
            c[i * n + j] = r;
        }
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    double ret = end.tv_sec - begin.tv_sec + (end.tv_nsec - begin.tv_nsec) / 1e9;
    return ret;
}

double kij(double* a, double* b, double* c, int n)
{
    timespec begin, end;
    clock_gettime(CLOCK_MONOTONIC, &begin);
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            register double r = a[i * n + k];
            for (int j = 0; j < n; j++) {
                c[i * n + j] += r * b[k * n + j];
            }
        }
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    double ret = end.tv_sec - begin.tv_sec + (end.tv_nsec - begin.tv_nsec) / 1e9;
    return ret;
}

double ikj(double* a, double* b, double* c, int n)
{
    timespec begin, end;
    clock_gettime(CLOCK_MONOTONIC, &begin);
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            register double r = a[i * n + k];
            for (int j = 0; j < n; j++) {
                c[i * n + j] += r * b[k * n + j];
            }
        }
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    double ret = end.tv_sec - begin.tv_sec + (end.tv_nsec - begin.tv_nsec) / 1e9;
    return ret;
}

double jki(double* a, double* b, double* c, int n)
{
    timespec begin, end;
    clock_gettime(CLOCK_MONOTONIC, &begin);
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            register double r = b[k * n + j];
            for (int i = 0; i < n; i++) {
                c[i * n + j] += r * a[i * n + k];
            }
        }
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    double ret = end.tv_sec - begin.tv_sec + (end.tv_nsec - begin.tv_nsec) / 1e9;
    return ret;
}

double kji(double* a, double* b, double* c, int n)
{
    timespec begin, end;
    clock_gettime(CLOCK_MONOTONIC, &begin);
    for (int k = 0; k < n; k++) {
        for (int j = 0; j < n; j++) {
            register double r = b[k * n + j];
            for (int i = 0; i < n; i++) {
                c[i * n + j] += r * a[i * n + k];
            }
        }
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    double ret = end.tv_sec - begin.tv_sec + (end.tv_nsec - begin.tv_nsec) / 1e9;
    return ret;
}

double ijk_block(double* a, double* b, double* c, int n, int blocksize)
{
    timespec begin, end;
    clock_gettime(CLOCK_MONOTONIC, &begin);
    for (int i = 0; i < n; i += blocksize) {
        for (int j = 0; j < n; j += blocksize) {
            for (int k = 0; k < n; k += blocksize) {
                for (int i1 = i; i1 < i + blocksize && i1 < n; i1++) {
                    for (int j1 = j; j1 < j + blocksize && j1 < n; j1++) {
                        register double r = c[i1 * n + j1];
                        for (int k1 = k; k1 < k + blocksize && k1 < n; k1++) {
                            r += a[i1 * n + k1] * b[k1 * n + j1];
                        }
                        c[i1 * n + j1] = r;
                    }
                }
            }
        }
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    double ret = end.tv_sec - begin.tv_sec + (end.tv_nsec - begin.tv_nsec) / 1e9;
    return ret;
}

double jik_block(double* a, double* b, double* c, int n, int blocksize)
{
    timespec begin, end;
    clock_gettime(CLOCK_MONOTONIC, &begin);
    for (int j = 0; j < n; j += blocksize) {
        for (int i = 0; i < n; i += blocksize) {
            for (int k = 0; k < n; k += blocksize) {
                for (int j1 = j; j1 < j + blocksize && j1 < n; j1++) {
                    for (int i1 = i; i1 < i + blocksize && i1 < n; i1++) {
                        register double r = c[i1 * n + j1];
                        for (int k1 = k; k1 < k + blocksize && k1 < n; k1++) {
                            r += a[i1 * n + k1] * b[k1 * n + j1];
                        }
                        c[i1 * n + j1] = r;
                    }
                }
            }
        }
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    double ret = end.tv_sec - begin.tv_sec + (end.tv_nsec - begin.tv_nsec) / 1e9;
    return ret;
}

double kij_block(double* a, double* b, double* c, int n, int blocksize)
{
    timespec begin, end;
    clock_gettime(CLOCK_MONOTONIC, &begin);
    for (int k = 0; k < n; k += blocksize) {
        for (int i = 0; i < n; i += blocksize) {
            for (int j = 0; j < n; j += blocksize) {
                for (int k1 = k; k1 < k + blocksize && k1 < n; k1++) {
                    for (int i1 = i; i1 < i + blocksize && i1 < n; i1++) {
                        register double r = a[i1 * n + k1];
                        for (int j1 = j; j1 < j + blocksize && j1 < n; j1++) {
                            c[i1 * n + j1] += r * b[k1 * n + j1];
                        }
                    }
                }
            }
        }
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    double ret = end.tv_sec - begin.tv_sec + (end.tv_nsec - begin.tv_nsec) / 1e9;
    return ret;
}

double ikj_block(double* a, double* b, double* c, int n, int blocksize)
{
    timespec begin, end;
    clock_gettime(CLOCK_MONOTONIC, &begin);
    for (int i = 0; i < n; i += blocksize) {
        for (int k = 0; k < n; k += blocksize) {
            for (int j = 0; j < n; j += blocksize) {
                for (int i1 = i; i1 < i + blocksize && i1 < n; i1++) {
                    for (int k1 = k; k1 < k + blocksize && k1 < n; k1++) {
                        register double r = a[i1 * n + k1];
                        for (int j1 = j; j1 < j + blocksize && j1 < n; j1++) {
                            c[i1 * n + j1] += r * b[k1 * n + j1];
                        }
                    }
                }
            }
        }
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    double ret = end.tv_sec - begin.tv_sec + (end.tv_nsec - begin.tv_nsec) / 1e9;
    return ret;
}

double jki_block(double* a, double* b, double* c, int n, int blocksize)
{
    timespec begin, end;
    clock_gettime(CLOCK_MONOTONIC, &begin);
    for (int j = 0; j < n; j += blocksize) {
        for (int k = 0; k < n; k += blocksize) {
            for (int i = 0; i < n; i += blocksize) {
                for (int j1 = j; j1 < j + blocksize && j1 < n; j1++) {
                    for (int k1 = k; k1 < k + blocksize && k1 < n; k1++) {
                        register double r = b[k1 * n + j1];
                        for (int i1 = i; i1 < i + blocksize && i1 < n; i1++) {
                            c[i1 * n + j1] += r * a[i1 * n + k1];
                        }
                    }
                }
            }
        }
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    double ret = end.tv_sec - begin.tv_sec + (end.tv_nsec - begin.tv_nsec) / 1e9;
    return ret;
}

double kji_block(double* a, double* b, double* c, int n, int blocksize)
{
    timespec begin, end;
    clock_gettime(CLOCK_MONOTONIC, &begin);
    for (int k = 0; k < n; k += blocksize) {
        for (int j = 0; j < n; j += blocksize) {
            for (int i = 0; i < n; i += blocksize) {
                for (int k1 = k; k1 < k + blocksize && k1 < n; k1++) {
                    for (int j1 = j; j1 < j + blocksize && j1 < n; j1++) {
                        register double r = b[k1 * n + j1];
                        for (int i1 = i; i1 < i + blocksize && i1 < n; i1++) {
                            c[i1 * n + j1] += r * a[i1 * n + k1];
                        }
                    }
                }
            }
        }
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    double ret = end.tv_sec - begin.tv_sec + (end.tv_nsec - begin.tv_nsec) / 1e9;
    return ret;
}