#!/bin/bash
#SBATCH --job-name=fq2node
#SBATCH --output=2node.txt
#SBATCH -N 2
#SBATCH -t 01:00:00

mpirun -np 64 ./sieve0 10000000000
mpirun -np 64 ./sieve1 10000000000
mpirun -np 64 ./sieve2 10000000000
mpirun -np 64 ./sieve3 10000000000