#!/bin/bash
#SBATCH --job-name=fq1p1
#SBATCH --output=1-p1.txt
#SBATCH -N 1
#SBATCH -n 32
#SBATCH -t 5:00:00

./1-p1
