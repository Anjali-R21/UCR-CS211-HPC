#!/bin/bash
#SBATCH --job-name=fq1node
#SBATCH --output=1node.txt
#SBATCH -N 1
#SBATCH -t 01:00:00

mpirun -np 32 ./sieve0 10000000000
mpirun -np 32 ./sieve1 10000000000
mpirun -np 32 ./sieve2 10000000000
mpirun -np 32 ./sieve3 10000000000