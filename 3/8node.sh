#!/bin/bash
#SBATCH --job-name=fq8node
#SBATCH --output=8node.txt
#SBATCH -N 8
#SBATCH -t 01:00:00

mpirun -np 256 ./sieve0 10000000000
mpirun -np 256 ./sieve1 10000000000
mpirun -np 256 ./sieve2 10000000000
mpirun -np 256 ./sieve3 10000000000