CC := g++
TARGETS := part1 part2 part2_o2
INCLUDES := -I ~/lapack-3.8.0/CBLAS/include -I ~/lapack-3.8.0/LAPACKE/include
LDS := ~/lapack-3.8.0/liblapacke.a ~/lapack-3.8.0/liblapack.a ~/lapack-3.8.0/libcblas.a /act/lib/openblas-0.2.20/lib/libopenblas.a
LIBS := -lgfortran -pthread

part1: main.o
	$(CC) -o part1 main.c -DPART_ONE $(INCLUDES) $(LDS) $(LIBS)

part2: main.o
	$(CC) -o part2 main.c -DPART_TWO $(INCLUDES) $(LDS) $(LIBS)
	rm -f *.o
	$(CC) -o part2_o2 main.c -DPART_TWO $(INCLUDES) $(LDS) $(LIBS) -O2
	rm -f *.o # avoid influence to other parts
# %.o: %.c
# 	$(CC) -c $< -o $@ -DPART_ONE $(INCLUDES) $(LDS) $(LIBS)
.PHONY: main.o

.PHONY clean:
	rm -f *.o $(TARGETS)
