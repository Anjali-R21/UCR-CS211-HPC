CC := gcc
TARGETS := part1 part2 part2_o2
INCLUDES := -I/usr/local/opt/lapack/include -I/usr/local/opt/openblas/include
LDS := -L/usr/local/opt/lapack/lib -L/usr/local/opt/openblas/lib
LIBS := -llapacke -lopenblas

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