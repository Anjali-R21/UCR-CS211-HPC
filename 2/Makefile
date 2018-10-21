CC := gcc
TARGETS := main
INCLUDES := -I/usr/local/opt/lapack/include -I/usr/local/opt/openblas/include
LDS := -L/usr/local/opt/lapack/lib -L/usr/local/opt/openblas/lib
LIBS := -llapacke -lopenblas

part1: main.o
	$(CC) -o part1 main.c -DPART_ONE $(INCLUDES) $(LDS) $(LIBS)

# %.o: %.c
# 	$(CC) -c $< -o $@ -DPART_ONE $(INCLUDES) $(LDS) $(LIBS)
.PHONY: main.o

.PHONY clean:
	rm -f *.o $(TARGETS)