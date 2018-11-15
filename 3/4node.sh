#!/bin/bash
#SBATCH --job-name=fq4node
#SBATCH --output=4node.txt
#SBATCH -N 4
#SBATCH -t 01:00:00

mpirun -np 128 ./sieve0 10000000000
mpirun -np 128 ./sieve1 10000000000
mpirun -np 128 ./sieve2 10000000000
mpirun -np 128 ./sieve3 10000000000