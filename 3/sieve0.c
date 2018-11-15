#include "common.h"

int main(int argc, char **argv)
{
    double elapsedTime;
    int pid;
    int psize;
    unsigned long long int n;
    unsigned long long int low_value, high_value;
    unsigned long long int size, proc0_size;
    char *marked;
    unsigned long long int i, index, first;
    unsigned long long int prime;
    unsigned long long int count, global_count;

    /**
     * Initialize MPI
     */
    MPI_Init(&argc, &argv);
    MPI_Barrier(MPI_COMM_WORLD);
    elapsedTime = -MPI_Wtime();
    MPI_Comm_rank(MPI_COMM_WORLD, &pid);
    MPI_Comm_size(MPI_COMM_WORLD, &psize);
    if (argc != 2)
    {
        if (pid == 0)
            printf("Command line syntax error.\n");
        MPI_Finalize();
        exit(1);
    }

    /**
     * Parameters Initialization
     */
    n = atoll(argv[1]);
    low_value = 2 + BLOCK_LOW(pid, psize, n-1);
    high_value = 2 + BLOCK_HIGH(pid, psize, n-1);
    size = BLOCK_SIZE(pid, psize, n-1);
    
    /**
     * process 0 must holds all primes used
     */
    proc0_size = (n-1) / psize;
    if ((2 + proc0_size) < (int) sqrt((double) n))
    {
        if (pid == 0)
            printf("Too many processes.\n");
        MPI_Finalize();
        exit(1);
    }

    /**
     * Allocation
     */
    marked = (char*) malloc(size);
    if (marked == NULL)
    {
        printf("PID: %d - Cannot allocate enough memory.\n", pid);
        MPI_Finalize();
        exit(1);
    }
    for (i = 0; i < size; i++)
        marked[i] = 0;

    /**
     * Core Function
     */
    if (pid == 0)
        index = 0;
    prime = 2;
    
    do
    {
        if (prime * prime > low_value)
            first = prime * prime - low_value;
        else
        {
            if ((low_value % prime) == 0)
                first = 0;
            else
                first = prime - (low_value % prime);
        }
        for (i = first; i < size; i += prime)
            marked[i] = 1;
        if (pid == 0)
        {
            while(marked[++index] == 1);
            prime = index + 2;
        }
        if (psize > 1)
            MPI_Bcast(&prime, 1, MPI_INT, 0, MPI_COMM_WORLD);
    } while (prime * prime <= n);
    count = 0;
    for (i = 0; i < size; i++)
        if (marked[i] == 0)
            count++;
    if (psize > 1)
        MPI_Reduce(&count, &global_count, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    
    elapsedTime += MPI_Wtime();

    /**
     * Print the results
     */
    if (pid == 0)
        printf("The total number of primes: %lld, time: %.6lf s in %d processes.\n", global_count, elapsedTime, psize);
    MPI_Finalize();
    return 0;
}