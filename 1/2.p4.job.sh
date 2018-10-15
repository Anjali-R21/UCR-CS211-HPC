#!/bin/bash
#SBATCH --job-name=fq2p4
#SBATCH --output=2-p4.txt
#SBATCH -N 1
#SBATCH -n 32
#SBATCH -t 10:00:00

./2-p4-o0
./2-p4-o1
./2-p4-o2
./2-p4-o3