CXX := g++
HEADERS := functions.h
OBJ := init.o
TARGETS := 1-p1p2 1-p3 2-p3

1-p1p2: 1.p1p2.main.o 1.p1.dgemm0.o 1.p1.dgemm1.o 1.p2.dgemm2.o $(OBJ)
	$(CXX) -o $@ $^

1-p3: 1.p3.main.o 1.p1.dgemm0.o 1.p1.dgemm1.o 1.p2.dgemm2.o 1.p3.dgemm3.o $(OBJ)
	$(CXX) -o $@ $^

2-p3: 2.p3.main.o 2.algo.o $(OBJ)
	$(CXX) -o $@ $^

2-p4: 2.p4.main.o $(OBJ)
	$(CXX) -o 2-p4-o0 $^ -O0
	$(CXX) -o 2-p4-o1 $^ -O1
	$(CXX) -o 2-p4-o2 $^ -O2
	$(CXX) -o 2-p4-o3 $^ -O3

%.o: %.c functions.h
	$(CXX) -c $< -o $@

.PHONY clean:
	rm -f *.o $(TARGETS)