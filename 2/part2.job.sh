#!/bin/bash
#SBATCH --job-name=fqp2
#SBATCH --output=p2.txt
#SBATCH -N 1
#SBATCH -n 32
#SBATCH -t 1:00:00

export OPENBLAS_NUM_THREADS=1
./part2
./part2_o2